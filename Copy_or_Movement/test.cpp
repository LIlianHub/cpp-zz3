# include "test.hpp"



// gcc test.cpp -o test

int main(){
    Test t2{2};
    std::cout << "========================\n";
    Test t = t2;
    t = t2;
    std::cout << "========================\n";
    Test v4;
    std::cout << "========================\n";
    v4 = Test{2};
}
