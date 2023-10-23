#ifndef _EXPONENTIELLE
#define _EXPONENTIELLE

template <unsigned long P>
struct Exponentielle {
    static const unsigned long valeur(const double & n){
        return Exponentielle<P-1>::valeur(n) * n;
    }

};

template <>
struct Exponentielle<0> {
    static const unsigned long valeur(const double & n){
        return 1;
    }
};

#endif