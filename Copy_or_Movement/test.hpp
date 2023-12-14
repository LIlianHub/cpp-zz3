#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class Test{
    private:
        int _value = 0;

    public:
        int getValue() const{return _value;}
    public:
        Test(){std::cout << "constru par default\n";}
        ~Test(){};
        Test(int value) : _value{value}{std::cout << "constru adhoc\n";}
        Test(const Test& t) : _value{t.getValue()}{std::cout << "constru copy\n";}
        Test(const Test &&t) : _value{t.getValue()}{std::cout << "constru mouvement\n";}
        const Test& operator=(const Test & t){ 
            std::cout << "affecta copy\n";
            this->_value = t.getValue();
            return *this;
        };
        const Test& operator=(const Test && t){ 
            std::cout << "affecta mouvement\n";
            this->_value = t.getValue();
            return *this;
        };

};

#endif