#include "vecteur.hpp"

// Implémentation des méthodes de la classe Vecteur

Vecteur::Vecteur() : tableau(nullptr), taille(0) {}

Vecteur::Vecteur(const Vecteur& autre) : taille(autre.taille) {
    tableau = new int[taille];
    for (int i = 0; i < taille; i++) {
        tableau[i] = autre.tableau[i];
    }
}

Vecteur::~Vecteur() {
    delete[] tableau;
}

Vecteur& Vecteur::operator=(const Vecteur& autre) {
    if (this != &autre) {
        delete[] tableau;
        taille = autre.taille;
        tableau = new int[taille];
        for (int i = 0; i < taille; i++) {
            tableau[i] = autre.tableau[i];
        }
    }
    return *this;
}

int& Vecteur::operator[](int index) {
    return tableau[index];
}

const int& Vecteur::operator[](int index) const {
    return tableau[index];
}

int Vecteur::size() const {
    return taille;
}


int Vecteur::operator*(const Vecteur& autre) const {
    int produit = 0;
    for (int i = 0; i < taille; i++) {
        produit += tableau[i] * autre.tableau[i];
    }
    return produit;
}


// Iterateur

Iterateur Vecteur::begin() {
    return Iterateur(tableau);
}

Iterateur Vecteur::end() {
    return Iterateur(tableau + taille);
}

Iterateur& Iterateur::operator++() {
    // Implémentation de l'opérateur de pré-incrémentation
    ++ptr; // Déplace le pointeur vers l'élément suivant
    return *this;
}

Iterateur Iterateur::operator++(int) {
    // Implémentation de l'opérateur de post-incrémentation
    Iterateur temp = *this; // Copie de l'itérateur actuel
    ++ptr; // Déplace le pointeur vers l'élément suivant
    return temp; // Retourne la copie de l'itérateur avant l'incrémentation
}

int Iterateur::operator*() {
    // Implémentation de l'opérateur d'accès
    return *ptr; // Retourne la valeur pointée par le pointeur
}

bool Iterateur::operator==(const Iterateur& autre) const{
    return ptr == autre.ptr;
}