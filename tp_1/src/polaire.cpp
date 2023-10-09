#include "polaire.hpp"
#include <cmath>

Polaire::Polaire(double angle, double distance) : _angle{angle}, _distance{distance}{

}

Polaire::Polaire(){}

void Polaire::afficher(std::ostream & flux) const{
    flux << "(a=" << _angle << ";d=" << _distance << ")";
}

Polaire::Polaire(const Cartesien & c){
    _angle = std::atan2(c.getY(), c.getX()) * 180 / M_PI;
    _distance = std::hypot(c.getX(), c.getY());
}

double Polaire::getAngle() const{
    return _angle;
}


double Polaire::getDistance() const{
    return _distance;
}


void Polaire::setDistance(const double distance){
    _distance = distance;
}
        

void Polaire::setAngle(const double angle){
    _angle = angle;
}


void Polaire::convertir(Cartesien & c) const{
    c.setX(getDistance() * std::cos(getAngle() * M_PI / 180));
    c.setY(getDistance() * std::sin(getAngle() * M_PI / 180));
    
}

void Polaire::convertir(Polaire & p) const{
    p.setAngle(_angle);
    p.setDistance(_distance);
}