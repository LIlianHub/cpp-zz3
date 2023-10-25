#ifndef _COSINUS
#define _COSINUS

#include <puissance.hpp>
#include <factorielle.hpp>

template <unsigned long K>
struct Cosinus {
    static const double valeur(const long double &x) {
        return Cosinus<K - 1>::valeur(x) + (Puissance<K>::valeur(-1) * (Puissance<2 * K>::valeur(x) / Factorielle<2 * K>::valeur));
    }
};

template <>
struct Cosinus<0> {
    static const double valeur(const long double &x) {
        return 1;
    }
};

#endif