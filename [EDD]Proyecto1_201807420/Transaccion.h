#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class NodoLista
{
public:
	string idTr,idAc,usuario,departamento,empresa,fecha;
	int tiempo;
	NodoLista* siguiente;
	NodoLista* anterior;
	NodoLista(string i,string idA,string usu,string depa,string emp,string fec,int ti) {
		idTr = i;
		idAc = idA;
		usuario = usu;
		departamento = depa;
		empresa = emp;
		fecha = fec;
		tiempo = ti;
		siguiente = nullptr;
		anterior = nullptr;
	}

};