// vecteur.hpp
#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>

class Iterateur;

class Vecteur {
private:
    int* tableau;
    int taille;
public:
    // Constructeurs
    Vecteur(); // Constructeur par défaut
    Vecteur(const Vecteur& autre); // Constructeur par copie
    // Destructeur
    ~Vecteur();
    // Opérateur de copie
    Vecteur& operator=(const Vecteur& autre);

    // Méthodes pour la classe Vecteur
    int& operator[](int index);
    const int& operator[](int index) const;
    int size() const;

    // Opérateurs
    int operator*(const Vecteur& autre) const;

    // Méthodes pour les itérateurs
    Iterateur begin();
    Iterateur end();
};

class Iterateur {
private:
    int* ptr;
public:
    // Constructeur
    Iterateur(int* p) : ptr(p) {}
    
    // Méthodes pour la classe Iterateur
    Iterateur& operator++(); // Préfixe
    Iterateur operator++(int); // Postfixe
    int operator*();
    bool operator==(const Iterateur& autre) const;
};

#endif // VECTEUR_HPP