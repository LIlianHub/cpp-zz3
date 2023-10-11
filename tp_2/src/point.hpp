#ifndef POINT_H
#define POINT_H

#include <iostream>

class Cartesien;
class Polaire;

class Point{
    public:
        virtual void afficher(std::ostream &) const = 0;
        virtual ~Point() = default;
        virtual void convertir(Cartesien &) const = 0;
        virtual void convertir(Polaire &) const = 0;

};

std::ostream & operator<<(std::ostream &, const Point &);


#endif