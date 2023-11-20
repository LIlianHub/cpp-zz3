#ifndef VALEUR
#define VALEUR


class Valeur{
    private:
        double _valeur = 0.0;

    public:
        Valeur(){}
        Valeur(const double valeur): _valeur{valeur}{}

    public:
        double getNombre() const{return _valeur;}
        void setNombre(const double valeur){_valeur = valeur;}

};

bool operator< (const Valeur& v1, const Valeur& v2) { 
    return v1.getNombre() < v2.getNombre();
}


#endif