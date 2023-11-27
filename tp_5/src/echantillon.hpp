#ifndef ECHANTILLON
#define ECHANTILLON

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <valeur.hpp>
#include <vector>

class EchantillonExceptionDomain : public std::domain_error {
public:
    EchantillonExceptionDomain(): std::domain_error("No Value") {}
};

class EchantillonExceptionOutOfRange : public std::out_of_range {
public:
    EchantillonExceptionOutOfRange(): std::out_of_range("Out of range") {}
};

class Echantillon
{
private:
    std::vector<Valeur> _data;

public:
    Echantillon() {}

public:
    unsigned int getTaille() const { return _data.size(); }
    void ajouter(const Valeur &value) { _data.push_back(value); }
    Valeur getMinimum() const
    {
        auto position = std::min_element(_data.begin(), _data.end());
        if (position != _data.end())
            return *(position);
        throw EchantillonExceptionDomain();
    }

    Valeur getMaximum() const
    {
        auto position = std::max_element(_data.begin(), _data.end());
        if (position != _data.end())
            return *(position);
        throw EchantillonExceptionDomain();
    }

    Valeur &operator[](std::size_t index)
    {
        if (index >= getTaille())
        {
            throw EchantillonExceptionOutOfRange();
        }
        return _data[index];
    }

    Valeur getValeur(std::size_t index) const{
        if (index >= getTaille())
        {
            throw EchantillonExceptionOutOfRange();
        }
        return _data[index]; 
    }
};

#endif