#pragma once
#include <iostream>


class Nodo
{
private:

	int valor;
	Nodo* HijoIzq;
	Nodo* hijoDer;
public:
	Nodo();
	int getValor();
	void setValor(int valor);

	Nodo* getHijoIzq();
	void setHijoIzq(Nodo* hijoIzq);

	Nodo* getHijoDer();
	void setHijoDer(Nodo* hijoDer);

	~Nodo();

	
};
