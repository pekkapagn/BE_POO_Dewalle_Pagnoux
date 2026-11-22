#ifndef TRAPPE
#define TRAPPE

class Trappe {
public:
    virtual ~Trappe() = default;

    //on déclare ces fonctions pour que toutes
    //les classes héritières soient obligées de les déclarer
    virtual void demarrer() = 0;
    virtual void ouvrir() = 0;
    virtual void fermer() = 0;
};

#endif