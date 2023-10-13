#ifndef _NUAGE
#define _NUAGE

#include <vector>

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
};

template <typename U>
U barycentre_v1(const Nuage<U> & nuage)
{
    double sum_x = 0;
    double sum_y = 0;
    double nb_element = 0.0;

    Nuage::const_iterator it = nuage.begin();
    Cartesien cartesien;

    for (it; it != nuage.end(); it++)
    {

        if (!(point_cartesien = dynamic_cast<const Cartesien>(*it)))
            cartesien = Cartesien(*it);
        else
            cartesien = (*it)
        

        sum_x += cartesien->getX();
        sum_y += cartesien->getY();
        nb_element ++;
    }
}

#endif