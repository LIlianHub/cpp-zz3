#ifndef HISTO
#define HISTO

#include <classe.hpp>
#include <set>
#include <algorithm>
#include <iostream>
#include <echantillon.hpp>
#include <map>

template <typename Comparateur = std::less<Classe>>
class Histogramme
{
private:
    std::set<Classe, Comparateur> _classes;
    std::multimap<Classe,Valeur> _multimap;

public:
    Histogramme(double min, double max, double quantite)
    {
        double pas = (max - min) / quantite;
        for (double i = min; i < max; i += pas)
        {
            _classes.insert(Classe{i, i + pas});
        }
    }

    template <class Comparator2>
    Histogramme(const Histogramme<Comparator2> &h2)
    {
        std::copy(h2.getClasses().begin(), h2.getClasses().end(),std::inserter(_classes,_classes.end()));
    }

public:
    const std::set<Classe, Comparateur> &getClasses() const { return _classes; }
    const std::multimap<Classe,Valeur> &getValeurs() const { return _multimap; }

    void ajouter(Echantillon &echantillon)
    {
        for (int i = 0; i < (int)echantillon.getTaille(); i++)
        {
            const double &echantillon_value = echantillon[i].getNombre();
            ajouter(echantillon_value);
        }
    }

    void ajouter(const double &value)
    {
        const auto goodClasse = std::find_if(
            _classes.begin(),
            _classes.end(),
            [&value](const Classe &classe)
            {
                return value >= classe.getBorneInf() && value < classe.getBorneSup();
            });

        if (goodClasse != _classes.end())
        {
            Classe temp = *goodClasse;
            _classes.erase(goodClasse);
            temp.ajouter();
            _classes.insert(temp);
            _multimap.insert(std::make_pair(temp,value));
        }
    }
};

#endif