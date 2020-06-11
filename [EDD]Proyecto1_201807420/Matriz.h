#pragma once
#include "Nodo.h"
#include<iostream>
using namespace std;
class Matriz
{
public:
	Nodo* cabezera;
	Matriz(){
		cabezera = new Nodo("admin", -1);
	}
	void InsertarElemento(string usuario, int numero, string empresa, string departamento);
	//metodos para ingresar cabeceras
	Nodo* crearEmpr(string departamento);
	Nodo* crearDep(string empresa);
};

