#ifndef TRAPPELED
#define TRAPPELED

#include <Arduino.h>
#include "Trappe.h"

//hérite de Trappe; classe "test" avant passage au servo moteur
class TrappeLed : public Trappe {
public:

    //constructeur
    TrappeLed(int broche, bool allumeeAvecLow)
        : broche(broche), allumeeAvecLow(allumeeAvecLow) {
    }

    //définitions obligatoires liées à l'héritage
    void demarrer() override {
        pinMode(broche, OUTPUT);
        fermer();
    }

    //ouvrir <=> allumer la led
    void ouvrir() override {
        //fonction de la configuration de la led
        if (allumeeAvecLow){
            digitalWrite(broche, LOW);
        } else {
            digitalWrite(broche, HIGH);
        }
        
    }
   
    //fermer <=> eteindre la led
    void fermer() override {
        //fonction de la configuration de la led
        if (allumeeAvecLow){
            digitalWrite(broche, HIGH);
        } else {
            digitalWrite(broche, LOW);
        }
    }

private:
    int broche;
    bool allumeeAvecLow;
};

#endif