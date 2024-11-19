#include <iostream>
#include "Nodo.h"

Nodo::Nodo(int valor){ 
    this->valor = valor; 
    this->hijoIzq = nullptr; 
    this -> hijoDer = nullptr; 
    }
    
int Nodo::getValor() { return this->valor; }
void Nodo::setValor(int valor) { this->dato = dato; }
Nodo* Nodo::getHijoIzq() { return this->hijoIzq; }
void Nodo::setHijoIzq(Nodo* hijoIzq) { this->hijoIzq = hijoIzq; }

Nodo* Nodo::getHijoDer() { return this->hijoDer; }
void Nodo::setHijoDer(Nodo* hijoIzq) { this->hijoDer = hijoDer; }

Nodo::~Nodo() { std::count << "se destruye el nodo con valor: " << this->valor << std::endl; }