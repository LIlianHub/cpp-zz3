#include "cartesien.hpp"
#include <cmath>

Cartesien::Cartesien(double x, double y) : _x{x}, _y{y}{

}

Cartesien::Cartesien(){}

Cartesien::Cartesien(const Polaire & p){
    _x = p.getDistance() * std::cos(p.getAngle() * M_PI / 180);
    _y = p.getDistance() * std::sin(p.getAngle() * M_PI / 180);
}

void Cartesien::afficher(std::ostream & flux) const{
    flux << "(x=" << _x << ";y=" << _y << ")";
}

double Cartesien::getX() const{
    return _x;
}

double Cartesien::getY() const{
    return _y;
}


void Cartesien::setX(const double x){
    _x = x;
}
void Cartesien::setY(const double y){
    _y = y;
}


void Cartesien::convertir(Polaire & p) const{
    p.setAngle(std::atan2(getY(), getX()) * 180 / M_PI);
    p.setDistance(std::hypot(getX(), getY()));
}

void Cartesien::convertir(Cartesien & c) const{
    c.setX(_x);
    c.setY(_y);
}