#ifndef TRAPPESERVO
#define TRAPPESERVO

#include <Arduino.h>
#include <Servo.h>
#include "Trappe.h"

//hérite de Trappe; classe "test" avant passage au servo moteur
class TrappeServo : public Trappe {
public:

    //constructeur
    TrappeServo(/*int broche, bool allumeeAvecLow*/)
        /*: broche(broche), allumeeAvecLow(allumeeAvecLow)*/ {
    }

    //définitions obligatoires liées à l'héritage
    void demarrer() override; 
    void ouvrir() override;
    void fermer() override;

private:
    int broche;
    //bool allumeeAvecLow;
};

#endif