/*********************************************************************
 * @file  Apllication.cpp
 * @author Pablo Pagnoux et Claire Dewalle
 * @brief Fichier source de l'application pour un prototype de gamelle connectée basée sur un ESP8266
 *********************************************************************/
#include "Application.h"

void Application::demarrer() {
  trappe.demarrer();
  Serial.begin(Reglages::vitesseSerie);

  prete=quota.reglagesValides();
  if (!prete) {
    Serial.println("Verifie le quota et la reserve dans Reglages.h.");
    return;
  }
  Serial.println("Gamelle : mode demo");
  Serial.println("a = arrivee, m = bouton, n = lendemain, ? = compteur");
  afficherCompteur();
}

void Application::tour() {
  if (!prete) {
    return;
  }
  uint32_t maintenant = millis();
  Demande demandeFinie;
  if (distribution.avancer(maintenant, demandeFinie)) {
    quota.compter(demandeFinie, maintenant);
    Serial.println("Distribution terminee.");
    afficherCompteur();
  } if (Serial.available() == 0) {
    return;
  } switch (Serial.read()) {
    case 'a':
        demanderPortion(Demande::Arrivee, maintenant);
        break;

    case 'm':
        demanderPortion(Demande::Bouton, maintenant);
        break;

    case 'n':
        if (distribution.enCours()) {
            Serial.println("Attends que la trappe se ferme.");
        } else {
            quota.nouveauJour();
            Serial.println("On passe au lendemain.");
            afficherCompteur();
        }
        break;

    case '?':
        afficherCompteur();
        break;
  }
}


void Application::demanderPortion(Demande demande, uint32_t maintenant) {}

void Application::afficherCompteur() const {
  Serial.print("Portions : ");
  Serial.print(quota.portionsDonnees());
  Serial.print('/');
  Serial.println(Reglages::portionsParJour);
}

