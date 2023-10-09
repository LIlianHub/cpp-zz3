#include "nuage.hpp"

Nuage::Nuage(){}

void Nuage::ajouter(Point & p){
    points.push_back(&p);
}

size_t Nuage::size() const{
    return points.size();
}

std::vector<Point*>::const_iterator Nuage::begin() const{
    return points.begin();
}

std::vector<Point*>::const_iterator Nuage::end() const{
    return points.end();
}

Cartesien barycentre(const Nuage & n){
    double sum_x = 0;
    double sum_y = 0;
    double nb_element = 0.0;

    const Cartesien * point_cartesien;

    Nuage::const_iterator it = n.begin();

    while (it!=n.end()){
            if((point_cartesien = dynamic_cast<const Cartesien*>(*it))){
                sum_x += point_cartesien->getX();
                sum_y += point_cartesien->getY();
                nb_element ++;
            it++;
            } 
    }

    return Cartesien(sum_x / nb_element, sum_y / nb_element);
}


Cartesien BarycentreCartesien::operator()(const Nuage & n) const{
    return barycentre(n);
}

Polaire BarycentrePolaire::operator()(const Nuage & n) const{
    Cartesien cartesien = barycentre(n);
    Polaire polaire;
    cartesien.convertir(polaire);
    return polaire;
}
