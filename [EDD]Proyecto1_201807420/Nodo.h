#pragma once
#include<iostream>
#include"Arbol2.h"
using namespace std;
class Nodo
{
public:
	Nodo* nextt;
	Nodo* previous;
	Nodo* up;
	Nodo* down;
	Nodo* front;
	Nodo* back;
	Arbol* arbol;
	Arbol* renta;
	string nombre;
	string pass;
	int id;
	Nodo(string name, int dat,string dato) {
		nextt = nullptr;
		previous = nullptr;
		up = nullptr;
		down = nullptr;
		front = nullptr;
		back = nullptr;
		arbol = new Arbol();
		renta = new Arbol();
		nombre = name;
		id = dat;
		pass = dato;
	}

};

