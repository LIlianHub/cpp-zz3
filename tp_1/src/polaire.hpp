#ifndef POLAIRE_H
#define POLAIRE_H

#include "point.hpp"
#include "cartesien.hpp"

class Cartesien;

class Polaire : public Point {
    private:
        double _angle = 0.0;
        double _distance = 0.0;

    public:
        Polaire(double, double);
        Polaire();
        Polaire(const Cartesien &);
        void afficher(std::ostream &) const override;
        double getAngle() const;
        double getDistance() const;
        void setDistance(const double);
        void setAngle(const double);
        void convertir(Cartesien &) const override;
        void convertir(Polaire &) const override;

};


#endif