#ifndef QUOTA
#define QUOTA

#include <stdint.h>

enum class Demande { Arrivee, Bouton };
enum class Reponse { Oui, QuotaAtteint, ReserveBouton, TropTot };

class Quota {
private:
    int maxParJour;
    int reserveBouton;
    uint32_t attente;

    int total = 0;
    int portionsAuto = 0;
    uint32_t dernierePortion = 0;
    bool dejaDistribue = false;

public:
    void nouveauJour() {
        total = 0;
        portionsAuto = 0;
        //on remet les compteurs à zéro (pas le délai entre deux portions)
        //au cas ou la derniere portion aurait été distribuée tard le jour precedent
    }
    
    Quota(int maxjour, int resbtn, uint32_t att){
        this->maxParJour=maxjour;
        this->reserveBouton=resbtn;
        this->attente=att;
    }

    bool reglagesValides() const {
        return (maxParJour > 0 && reserveBouton >= 0 && reserveBouton <= maxParJour);
    }

    Reponse verifier(Demande demande, uint32_t maintenant) const {
        if (total >= maxParJour) {
            return Reponse::QuotaAtteint;
        }

        int maxAuto = maxParJour - reserveBouton;
        if (demande == Demande::Arrivee && portionsAuto >= maxAuto) {
            return Reponse::ReserveBouton;
        }

        if (dejaDistribue && (maintenant - dernierePortion < attente)) {
            return Reponse::TropTot;
        }

        return Reponse::Oui;
    }

    void compter(Demande demande, uint32_t maintenant) {
        total++;

        if (demande == Demande::Arrivee) {
            portionsAuto++;
        }

        dernierePortion = maintenant;
        dejaDistribue = true;
    }

    int portionsDonnees() const {
        return total;
    }
};

#endif