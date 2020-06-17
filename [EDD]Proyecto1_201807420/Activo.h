#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class NodoActivo
{
public:
	string idA,descripcion,nombre;
	int fe;
	bool disponibilidad;
	NodoActivo* izquierdo;
	NodoActivo* derecho;
	NodoActivo(string id, string desc, string n) {
		idA = id;
		nombre = n;
		descripcion = desc;
		fe = 0;
		disponibilidad = true;
		izquierdo = nullptr;
		derecho = nullptr;
	}

};
