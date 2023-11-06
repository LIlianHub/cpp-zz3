#ifndef _USINE_
#define _USINE_

#include <memory>
#include <iostream>
#include <carte.hpp>

class UsineCarte{
    private:
        unsigned int _next_value = 0;
        unsigned int _max_card = 52;

    public:
        UsineCarte(){}
        UsineCarte(unsigned int max_card): _max_card{max_card}{}

    private:
        UsineCarte(const UsineCarte&) = delete;

    private:
        UsineCarte& operator= (const UsineCarte&) = delete;

    public:
        std::unique_ptr<Carte> getCarte(){
            if(_next_value > (_max_card - 1))
                return nullptr;
            return std::unique_ptr<Carte>(new Carte(_next_value++));
        }

};

#endif