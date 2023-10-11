#ifndef CARTESIEN_H
#define CARTESIEN_H

#include "point.hpp"
#include "polaire.hpp"

class Polaire;

class Cartesien : public Point {
    private:
        double _x = 0.0;
        double _y = 0.0;

    public:
        Cartesien();
        Cartesien(double, double);
        Cartesien(const Polaire &);
        void afficher(std::ostream &) const override;
        double getX() const;
        double getY() const;
        void setX(const double);
        void setY(const double);
        void convertir(Polaire &) const override;
        void convertir(Cartesien &) const override;


};



#endif