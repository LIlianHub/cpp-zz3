#ifndef _CARTE_
#define _CARTE_

class UsineCarte;

class Carte{
    private:
        unsigned int _value = 0;
        // cpp17
        inline static unsigned int _cpt_creation = 0;

    private:
        Carte() { _cpt_creation ++;}
        Carte(unsigned int value):_value{value}{ _cpt_creation ++; }
        Carte(const Carte&) = delete;

    private:
        Carte& operator= (const Carte&) = delete;
    
    public:
        ~Carte() { _cpt_creation --;}
        unsigned int getValeur(){ return _value; }

    public:
        static unsigned int getCompteur(){ return _cpt_creation;}

    friend class UsineCarte;
};

//unsigned int Carte::_cpt_creation = 0;


#endif