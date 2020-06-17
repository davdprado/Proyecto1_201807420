#pragma once
#include<iostream>
#include"ArbolAVLAc.h"
using namespace std;
class Nodo
{
public:
	Nodo* nextt;
	Nodo* previous;
	Nodo* up;
	Nodo* down;
	Nodo* front;
	ArbolA* Activos;
	Nodo* back;
	string nombre;
	string pass;
	int id;
	Nodo(string name, int dat,string dato) {
		nextt = nullptr;
		previous = nullptr;
		up = nullptr;
		down = nullptr;
		front = nullptr;
		Activos = nullptr;
		back = nullptr;
		nombre = name;
		id = dat;
		pass = dato;
	}

};

