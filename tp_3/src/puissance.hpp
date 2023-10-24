#ifndef _PUISSANCE
#define _PUISSANCE


template <long P>
struct Puissance {
    static const double valeur(const double & n){
        return Puissance<P-1>::valeur(n) * n;
    }

};

template <>
struct Puissance<0> {
    static const double valeur(const double & n){
        return 1;
    }
};


#endif