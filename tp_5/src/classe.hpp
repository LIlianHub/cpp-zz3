#ifndef CLASSE
#define CLASSE

class Classe
{
private:
    double _inf = 0.0;
    double _sup = 0.0;
    unsigned int _quantite = 0;

public:
    Classe() {}
    Classe(double a, double b) : _inf{a}, _sup{b} {}

public:
    double getBorneInf() const { return _inf; }
    double getBorneSup() const { return _sup; }
    double getQuantite() const { return _quantite; }

    void setBorneInf(const double &inf) { _inf = inf; }
    void setBorneSup(const double &sup) { _sup = sup; }
    void setQuantite(const double &quantite) { _quantite = quantite; }

    void ajouter() { _quantite++; }
};

#endif