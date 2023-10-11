#include "vecteur.hpp"

// Implémentation des méthodes de la classe Vecteur

Vecteur::Vecteur() : _tableau(nullptr), _taille(0) {}

Vecteur::Vecteur(const Vecteur& autre) : _taille(autre._taille) {
    _tableau = new int[_taille];
    for (int i = 0; i < _taille; i++) {
        _tableau[i] = autre._tableau[i];
    }
}

Vecteur::Vecteur(const int taille, const int* tab){
    _taille = taille;
    _tableau = new int[_taille];
    for(int i = 0; i < taille; i++){
        _tableau[i] = tab[i];
    }
}


Vecteur::~Vecteur() {
    if(_tableau != nullptr){
        delete[] _tableau;
    }
}

Vecteur& Vecteur::operator=(const Vecteur& autre) {
    if (this != &autre) {
        delete[] _tableau;
        _taille = autre._taille;
        _tableau = new int[_taille];
        for (int i = 0; i < _taille; i++) {
            _tableau[i] = autre._tableau[i];
        }
    }
    return *this;
}

int& Vecteur::operator[](int index) {
    if(index < _taille && index >= 0){
        return _tableau[index];
    }
    throw InvalidAccesDataVector();
}

const int& Vecteur::operator[](int index) const {
    if(index < _taille && index >= 0){
        return _tableau[index];
    }
    throw InvalidAccesDataVector();
}

int Vecteur::size() const {
    return _taille;
}


int Vecteur::operator*(const Vecteur& autre) const {
    if(_taille == autre._taille){
        int produit = 0;
        for (int i = 0; i < _taille; i++) {
            produit += _tableau[i] * autre._tableau[i];
        }
        return produit;
    }
    throw SizeVectorException();
}

Vecteur Vecteur::operator+(const Vecteur& autre) const {
    if (_taille == autre._taille) {
        Vecteur somme;
        somme._taille = _taille;
        somme._tableau = new int[_taille];
        for (int i = 0; i < _taille; i++) {
            somme._tableau[i] = _tableau[i] + autre._tableau[i];
        }
        return somme;
    }
    throw SizeVectorException();

}

// vecteur standalone

std::ostream& operator<<(std::ostream& os, const Vecteur& v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i < v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


// Iterateur

Iterateur::Iterateur(int* p) : _ptr(p) {}

Iterateur Vecteur::begin() {
    return Iterateur(_tableau);
}

Iterateur Vecteur::end() {
    return Iterateur(_tableau + _taille);
}

Iterateur& Iterateur::operator++() {
    // Implémentation de l'opérateur de pré-incrémentation
    ++_ptr; // Déplace le pointeur vers l'élément suivant
    return *this;
}

Iterateur Iterateur::operator++(int) {
    // Implémentation de l'opérateur de post-incrémentation
    Iterateur temp = *this; // Copie de l'itérateur actuel
    ++_ptr; // Déplace le pointeur vers l'élément suivant
    return temp; // Retourne la copie de l'itérateur avant l'incrémentation
}

int Iterateur::operator*() {
    // Implémentation de l'opérateur d'accès
    return *_ptr; // Retourne la valeur pointée par le pointeur
}

bool Iterateur::operator==(const Iterateur& autre) const{
    return _ptr == autre._ptr;
}

bool Iterateur::operator!=(const Iterateur& autre) const{
    return _ptr != autre._ptr;
}