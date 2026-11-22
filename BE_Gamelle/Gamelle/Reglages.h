#ifndef GAMELLE
#define GAMELLE

#include <Arduino.h>

namespace Reglages {
    constexpr int vitesseSerie = 115200;

    constexpr int brocheLed = LED_BUILTIN;

    //a changer si led fait l'inverse
    constexpr bool ledAllumeeAvecLow = true;

    constexpr int portionsParJour = 4;
    constexpr int portionsPourBouton = 1;

    //durées en ms

    constexpr uint32_t dureeOuverture = 700;
    constexpr uint32_t dureeFermeture = 200;
    constexpr uint32_t attenteEntrePortions = 1000;
}

#endif