#pragma once
#include<iostream>
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
	string nombre;
	int id;
	Nodo(string name, int dat) {
		nextt = nullptr;
		previous = nullptr;
		up = nullptr;
		down = nullptr;
		front = nullptr;
		back = nullptr;
		nombre = name;
		id = dat;

	}

};

