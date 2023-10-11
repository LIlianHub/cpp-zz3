// vecteur.hpp
#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>


class SizeVectorException : public std::invalid_argument
{
public:
    SizeVectorException() : std::invalid_argument("Les vecteurs n'ont pas la même taille") {}
};

class InvalidAccesDataVector : public std::invalid_argument
{
public:
    InvalidAccesDataVector() : std::invalid_argument("Impossible d'accéder à cet indice du vecteur") {}
};


class Iterateur;

class Vecteur {
private:
    int* _tableau;
    int _taille;
public:
    // Constructeurs
    Vecteur(); // Constructeur par défaut
    Vecteur(const Vecteur&); // Constructeur par copiec
    Vecteur(const int, const int*);
    // Destructeur
    ~Vecteur();
    // Opérateur de copie
    Vecteur& operator=(const Vecteur&);

    // Méthodes pour la classe Vecteur
    int& operator[](int);
    const int& operator[](int) const;

    int size() const;

    // Opérateurs
    int operator*(const Vecteur&) const;
    Vecteur operator+(const Vecteur&) const;

    // Méthodes pour les itérateurs
    Iterateur begin();
    Iterateur end();
};

std::ostream& operator<<(std::ostream&, const Vecteur&);

class Iterateur {
private:
    int* _ptr;
public:
    // Constructeur
    Iterateur(int*);
    
    // Méthodes pour la classe Iterateur
    Iterateur& operator++(); // Préfixe
    Iterateur operator++(int); // Postfixe
    int operator*();
    bool operator==(const Iterateur& autre) const;
    bool operator!=(const Iterateur& autre) const; 
};

#endif // VECTEUR_HPP