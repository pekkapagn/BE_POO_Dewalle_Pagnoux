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

