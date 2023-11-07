#ifndef _RESSOURCE_
#define _RESSOURCE_

#include <vector>
#include <memory>
#include <iostream>

class Ressource{
    private:
        int _stock = 0;
    public:
        Ressource(){}
        Ressource(int stock): _stock{stock}{}

    public:
        void consommer(int conso){ 
            _stock -= conso; 
            if(_stock < 0) _stock = 0;
        }
        int getStock(){ return _stock; }

};

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

std::ostream& operator<<(std::ostream& os, const ressources_t& ressources) {
    for(const std::weak_ptr<Ressource>& ressource : ressources){
        if(ressource.expired())
            os << "- ";
        else
            os << ressource.lock().get()->getStock() << " ";
    }
    return os;
}

#endif