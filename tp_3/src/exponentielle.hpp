#ifndef _EXPONENTIELLE
#define _EXPONENTIELLE

#include <puissance.hpp>
#include <factorielle.hpp>

template <unsigned long K>
struct Exponentielle {
    static const double valeur(const long double & x){
        return Exponentielle<K - 1>::valeur(x) + (Puissance<K>::valeur(x) / Factorielle<K>::valeur);
    }

};

template <>
struct Exponentielle<0> {
    static const double valeur(const long double & x){
        return 1;
    }
};

#endif