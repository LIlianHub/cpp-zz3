#ifndef COMPARATEUR
#define COMPARATEUR

#include <classe.hpp>

template<typename T>
struct ComparateurQuantite{
    bool operator()(const T &c1, const T &c2) const
    {
        if(c1.getQuantite() == c2.getQuantite()) 
            return c1 < c2;
        return c1.getQuantite() > c2.getQuantite();
    }
};

#endif