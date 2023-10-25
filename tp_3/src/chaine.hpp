#ifndef _CHAINE
#define _CHAINE

#include <iostream>
#include <sstream>
#include <demangle.hpp>

// Declaration

template <typename... MULTIPLE_ARGS>
std::string chaine(const MULTIPLE_ARGS&... args);

template <typename... ARGS>
std::string chaine(const std::tuple<ARGS...> & t);

// question 1

class ExceptionChaine : public std::exception {
private:
    std::string msg;
public:
    ExceptionChaine(std::string _type) : msg{"Conversion en chaine impossible pour '" + demangle(_type) + "'"} {}
    const char* what() const throw() {
        return msg.c_str();
    }
    std::string getMsg() const{
        return msg;
    }
};



template <typename T>
std::string chaine(const T & x){
    throw ExceptionChaine(typeid(x).name());
}

// question 2

std::string chaine(const std::string & x){
    return x;
}

std::string chaine(const double & x){
    return std::to_string(x);
}

std::string chaine(const int & x){
    std::stringstream ss;
    ss << x;
    return ss.str();
}

// question 3

template <typename... MULTIPLE_ARGS>
std::string chaine(const MULTIPLE_ARGS&... args) {
    return ((chaine(args) + " ") + ...);
}

// question 4

template <typename T, size_t... Is>
std::string chaine_tuple(const T & t, std::index_sequence<Is...>) {
    return chaine(std::get<Is>(t)...);
}

template <typename... ARGS>
std::string chaine(const std::tuple<ARGS...> & t) {
    return chaine_tuple(t, std::make_index_sequence<sizeof...(ARGS)>());
}







#endif