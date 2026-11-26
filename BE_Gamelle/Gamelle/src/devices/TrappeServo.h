#ifndef TRAPPELED
#define TRAPPELED

#include <Arduino.h>
#include "Trappe.h"

//hérite de Trappe; classe "test" avant passage au servo moteur
class TrappeServo : public Trappe {
public:

    //constructeur
    TrappeServo(/*int broche, bool allumeeAvecLow*/)
        /*: broche(broche), allumeeAvecLow(allumeeAvecLow)*/ {
    }

    //définitions obligatoires liées à l'héritage
    void demarrer() override {
        pinMode(broche, OUTPUT);
        fermer();
    }

    void ouvrir() override {
        //fonction de la configuration du servo?
        /*
        if (allumeeAvecLow){
            digitalWrite(broche, LOW);
        } else {
            digitalWrite(broche, HIGH);
        }*/
        
    }
   
    void fermer() override {
        //fonction de la configuration du servo?
        /*
        if (allumeeAvecLow){
            digitalWrite(broche, HIGH);
        } else {
           digitalWrite(broche, LOW);
        }*/
    }

private:
    int broche;
    //bool allumeeAvecLow;
};

#endif