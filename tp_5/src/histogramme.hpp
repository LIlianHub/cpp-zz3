#ifndef HISTO
#define HISTO

#include <classe.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include <echantillon.hpp>

class Histogramme
{
private:
    std::vector<Classe> _classes;

public:
    Histogramme(double min, double max, double quantite)
    {
        double pas = (max - min) / quantite;
        for (double i = min; i < max; i += pas)
        {
            Classe c(i, i + pas);
            _classes.push_back(c);
        }
    }

public:
    std::vector<Classe> getClasses() const { return _classes; }

    void ajouter(Echantillon echantillon)
    {
        for (int i = 0; i < (int)echantillon.getTaille(); i++)
        {
            const double &echantillon_value = echantillon[i].getNombre();

            auto goodClasse = std::find_if(
                _classes.begin(),
                _classes.end(),
                [&echantillon_value](const Classe &classe)
                {
                    return echantillon_value >= classe.getBorneInf() && echantillon_value < classe.getBorneSup();
                });

            goodClasse->ajouter();
        }
    }
    
};

#endif