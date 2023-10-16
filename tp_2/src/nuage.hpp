#ifndef _NUAGE
#define _NUAGE

#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

template <typename T>

class Nuage
{
    // attributes
private:
    typename std::vector<T> _points;

    // vector methods
public:
    typename std::vector<T>::const_iterator begin() const
    {
        return _points.begin();
    }

    typename std::vector<T>::const_iterator end() const
    {
        return _points.end();
    }

    unsigned int size() const
    {
        return _points.size();
    }

    // class method
public:
    void ajouter(const T &point)
    {
        _points.push_back(point);
    }

    // iterator
public:
    using const_iterator = typename std::vector<T>::const_iterator;

    // value type pour avoir le même membre que vector
    using value_type = T;
};


// QUESTION 2 A décommenter avec les tests correspondant 4a et 4b
/*template <typename GeneriquePoint>
GeneriquePoint barycentre_v1(const Nuage<GeneriquePoint> & nuage)
{
    if(nuage.size() == 0){
        return GeneriquePoint(Cartesien(0.0, 0.0));
    }

    double sum_x = 0.0;
    double sum_y = 0.0;
    double nb_element = 0.0;

    // typename Nuage<U>::const_iterator it = nuage.begin();

    // on enleve it car pas necessaire
    //for (; it != nuage.end(); it++)
    for(const GeneriquePoint & point: nuage)
    {
        const Cartesien cartesien = Cartesien(point);
        sum_x += cartesien.getX();
        sum_y += cartesien.getY();
        nb_element ++;
    }

    return GeneriquePoint(Cartesien(sum_x / nb_element, sum_y / nb_element));
}*/

// QUESTION 3 : test 5
template <typename GeneriquePoint>
GeneriquePoint barycentre_v1(const Nuage<GeneriquePoint> & nuage)
{
    if(nuage.size() == 0){
        return GeneriquePoint(Polaire(0.0, 0.0));
    }

    double sum_angle = 0.0;
    double sum_distance = 0.0;

    // typename Nuage<U>::const_iterator it = nuage.begin();

    // on enleve it car pas necessaire
    //for (; it != nuage.end(); it++)
    for(const GeneriquePoint & point: nuage)
    {
        const Polaire polaire = Polaire(point);
        sum_angle += polaire.getAngle();
        sum_distance += polaire.getDistance();
        //std::cout << polaire << std::endl;
    }

    //std::cout << sum_angle / nuage.size() << " " << sum_distance / nuage.size() << std::endl;

    return GeneriquePoint(Polaire(sum_angle / nuage.size(), sum_distance / nuage.size()));
}

template <typename Conteneur>
typename Conteneur::value_type barycentre_v2(const Conteneur & conteneur)
{
    if(conteneur.size() == 0){
        return typename Conteneur::value_type(0.0, 0.0);
    }

    double sum_x = 0.0;
    double sum_y = 0.0;

    for(const typename Conteneur::value_type & point: conteneur)
    {
        const Cartesien cartesien = Cartesien(point);
        sum_x += cartesien.getX();
        sum_y += cartesien.getY();
    }

    return typename Conteneur::value_type(Cartesien(sum_x / conteneur.size(), sum_y / conteneur.size()));
}



#endif