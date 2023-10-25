#ifndef _FACTORIELLE
#define _FACTORIELLE


template <unsigned long N>
struct Factorielle {
    static const long valeur = N * Factorielle<N - 1>::valeur;
};

template <>
struct Factorielle<0> {
    static const long valeur = 1;
};



#endif