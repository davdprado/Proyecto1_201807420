#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class NodoArbol
{

public:
	string idA, descripcion, nombreA;
	int fe,tiempo;
	bool disponibilidad;
	NodoArbol* izquierdo;
	NodoArbol* derecho;
	NodoArbol(string id, string desc, string n) {
		idA = id;
		nombreA = n;
		descripcion = desc;
		fe = 0;
		tiempo = 0;
		disponibilidad = true;
		izquierdo = nullptr;
		derecho = nullptr;
	}
};