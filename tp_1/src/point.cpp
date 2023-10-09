#include "point.hpp"


std::ostream & operator<<(std::ostream & stream, const Point & p){
    p.afficher(stream);
    return stream;
}
