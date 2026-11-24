#ifndef DISTRIBUTION
#define DISTRIBUTION

#include <stdint.h>
#include "../devices/Trappe.h"
#include "Quota.h"

class Distribution {
public:
    Distribution(Trappe& trappe, uint32_t dureeOuverture, uint32_t dureeFermeture);
    bool enCours() const;
    void lancer(Demande demande, uint32_t maintenant);
    bool avancer(uint32_t maintenant, Demande& demandeFinie);

private:
    enum class Etat { Repos, Ouverte, Fermeture };

    Trappe& trappe;
    uint32_t dureeOuverture;
    uint32_t dureeFermeture;

    Etat etat = Etat::Repos;
    Demande demandeEnCours = Demande::Arrivee;
    uint32_t debutEtape = 0;
};

#endif