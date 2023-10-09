#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include <iterator>
#include <iterator>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

class Nuage{
    private:
        std::vector<Point*> points;
    
    public:
        Nuage();
        void ajouter(Point &);
        size_t size() const;
        std::vector<Point*>::const_iterator begin() const;
        std::vector<Point*>::const_iterator end() const;

    public:
        using const_iterator = std::vector<Point*>::const_iterator;
        

};


// Barycentre

Cartesien barycentre(const Nuage &);

class BarycentreCartesien{
    public:
        Cartesien operator()(const Nuage &) const;
};

class BarycentrePolaire{
    public:
        Polaire operator()(const Nuage &) const;
};
 


#endif