#include "Distribution.h"

Distribution::Distribution(Trappe& tr, uint32_t durOuv, uint32_t durFer):
    trappe(tr)
{
    dureeOuverture=durOuv;
    dureeFermeture=durFer;
}

bool Distribution::enCours() const {
    return etat != Etat::Repos;
}

void Distribution::lancer(Demande demande, uint32_t maintenant) {
    if (enCours()) {
        return;
    }
    demandeEnCours = demande;
    trappe.ouvrir();
    etat = Etat::Ouverte;
    debutEtape = maintenant;
}

bool Distribution::avancer(uint32_t maintenant, Demande& demandeFinie) {
    uint32_t tempsPasse = maintenant - debutEtape;

    if (etat == Etat::Ouverte && tempsPasse >= dureeOuverture) {
        trappe.fermer();
        etat = Etat::Fermeture;
        debutEtape = maintenant;
        return false;
    }
    if (etat == Etat::Fermeture && tempsPasse >= dureeFermeture) {
        etat = Etat::Repos;
        demandeFinie = demandeEnCours;
        return true;
    }
    return false;
}
