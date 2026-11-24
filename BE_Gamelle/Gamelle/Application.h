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
    
class Application
{
  public :
    void demarrer();
    void tour();  
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);
};
#endif