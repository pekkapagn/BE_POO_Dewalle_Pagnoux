/*********************************************************************
 * @file  Apllication.h
 * @author Pablo Pagnoux et Claire Dewalle
 * @brief Application pour un prototype de gamelle connectée basée sur un ESP8266
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Reglages.h"
#include "src/devices/TrappeLed.h"
#include "src/feeder/Quota.h"
#include "src/feeder/Distribution.h"
    
class Application{
public :
  void demarrer();
  void tour();
private:  
  void demanderPortion(Demande demande, uint32_t maintenant);
  void afficherCompteur() const;
  TrappeLed trappe {Reglages::brocheLed, Reglages::ledAllumeeAvecLow};
  Quota quota{Reglages::portionsParJour,Reglages::portionsPourBouton,Reglages::attenteEntrePortions};
  Distribution distribution{trappe, Reglages::dureeOuverture,Reglages::dureeFermeture{};
  bool prete = false;
};
#endif