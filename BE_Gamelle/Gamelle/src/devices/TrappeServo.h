#ifndef TRAPPESERVO
#define TRAPPESERVO

#include <Arduino.h>
#include <Servo.h>
#include "Trappe.h"

//hérite de Trappe; classe "test" avant passage au servo moteur
class TrappeServo : public Trappe {
public:

    //constructeur
    TrappeServo(int broche, int angleFerme, int angleOuvert) {
        this->broche=broche;
        this->angleFerme=angleFerme;
        this->angleOuvert=angleOuvert;
    }

    //définitions obligatoires liées à l'héritage
    void demarrer() override {
        servo.attach(broche);
        fermer();
    }; 

    void ouvrir() override {
        servo.write(angleOuvert);
    };

    void fermer() overrid {
        servo.write(angleFerme);
    };

private:
    int broche;
    int angleFerme;
    int angleOuvert;
    //appel à la bibliothèque pour créer un objet Servo
    Servo Moteur;
};

#endif