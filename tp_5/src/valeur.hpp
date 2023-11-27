#ifndef VALEUR
#define VALEUR


class Valeur{
    private:
        double _valeur = 0.0;
        std::string _etudiant = "inconnu";


    public:
        Valeur(){}
        Valeur(const double valeur): _valeur{valeur}{}
        Valeur(const double valeur, std::string nom): _valeur{valeur}, _etudiant{nom}{}

    public:
        double getNombre() const{return _valeur;}
        double getNote() const{return getNombre();}
        void setNombre(const double valeur){_valeur = valeur;}
        void setNote (const double valeur){setNombre(valeur);}
        std::string getEtudiant() const{return _etudiant;}
        void setEtudiant(const std::string etudiant){_etudiant = etudiant;}

};

bool operator< (const Valeur& v1, const Valeur& v2) { 
    return v1.getNombre() < v2.getNombre();
}


#endif