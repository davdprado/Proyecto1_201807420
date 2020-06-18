#pragma once
#include<iostream>
#include<string.h>
#include"Nodo2.h"
using namespace std;
class Arbol {
public:
	NodoArbol* raiz;
	Arbol() {
		raiz = nullptr;
	}
	//Buscar un nodo en el arbol;
	NodoArbol* buscar(string d, NodoArbol* raiz) {
		if (raiz == nullptr)
		{
			return nullptr;
		}
		else if (raiz->idA == d)
		{
			return raiz;
		}
		else if (raiz->idA < d)
		{
			return buscar(d, raiz->derecho);
		}
		else if (raiz->idA > d)
		{
			return buscar(d, raiz->izquierdo);
		}
	}
	//fucn para borrar;
	//Obtener el factor de equilibrio
	int obtenerFE(NodoArbol* r) {
		if (r == nullptr)
		{
			return -1;
		}
		else
		{
			return r->fe;
		}
	}
	//rotacion SI
	//Mayor de dos numeros xd
	int Mayor(int a, int b) {
		if (a >= b)
			return a;
		else
			return b;
	}
	NodoArbol* rotaizq(NodoArbol* raiz) {
		NodoArbol* aux = raiz->izquierdo;
		raiz->izquierdo = aux->derecho;
		aux->derecho = raiz;
		raiz->fe = Mayor(obtenerFE(raiz->izquierdo), obtenerFE(raiz->derecho)) + 1;
		aux->fe = Mayor(obtenerFE(aux->izquierdo), obtenerFE(aux->derecho)) + 1;
		return aux;
	}

	NodoArbol* rotaDer(NodoArbol* raiz) {
		NodoArbol* aux = raiz->derecho;
		raiz->derecho = aux->izquierdo;
		aux->izquierdo = raiz;
		raiz->fe = Mayor(obtenerFE(raiz->izquierdo), obtenerFE(raiz->derecho)) + 1;
		aux->fe = Mayor(obtenerFE(aux->izquierdo), obtenerFE(aux->derecho)) + 1;
		return aux;
	}
	NodoArbol* rotaDobleIzq(NodoArbol* raiz) {
		NodoArbol* aux;
		raiz->izquierdo = rotaDer(raiz->izquierdo);
		aux = rotaizq(raiz);
		return aux;
	}
	NodoArbol* rotaDobleDer(NodoArbol* raiz) {
		NodoArbol* aux;
		raiz->derecho = rotaizq(raiz->derecho);
		aux = rotaDer(raiz);
		return aux;
	}
	//Insertar Nodo
	NodoArbol* Insertar(NodoArbol* nuevo, NodoArbol* sub) {
		NodoArbol* padre = sub;
		if (nuevo->idA < sub->idA)
		{
			if (sub->izquierdo == nullptr) {
				sub->izquierdo = nuevo;
			}
			else
			{
				sub->izquierdo = Insertar(nuevo, sub->izquierdo);
				if ((obtenerFE(sub->izquierdo) - obtenerFE(sub->derecho)) == 2)
				{
					if (nuevo->idA < sub->izquierdo->idA)
						padre = rotaizq(sub);
					else
						padre = rotaDobleIzq(sub);
				}
			}
		}
		else if (nuevo->idA > sub->idA)
		{
			if (sub->derecho == nullptr) {
				sub->derecho = nuevo;
			}
			else
			{
				sub->derecho = Insertar(nuevo, sub->derecho);
				if ((obtenerFE(sub->derecho) - obtenerFE(sub->izquierdo)) == 2)
				{
					if (nuevo->idA > sub->derecho->idA)
						padre = rotaDer(sub);
					else
						padre = rotaDobleDer(sub);
				}
			}
		}
		else
		{
			cout << "El Nodo ya existe";
		}
		//corregir el FE
		if (sub->izquierdo == nullptr && sub->derecho != nullptr)
		{
			sub->fe = sub->derecho->fe + 1;

		}
		else if (sub->derecho == nullptr && sub->izquierdo != nullptr)
		{
			sub->fe = sub->izquierdo->fe + 1;
		}
		else
		{
			sub->fe = Mayor(obtenerFE(sub->izquierdo), obtenerFE(sub->derecho)) + 1;
		}
		return padre;
	}
	//crear
	void Crear(string dato, string desc, string na) {
		NodoArbol* nuevo = new NodoArbol(dato, desc, na);
		if (raiz == nullptr)
			raiz = nuevo;
		else
			raiz = Insertar(nuevo, raiz);
	}
	//Recorrer Arbol
	void EnOrden(NodoArbol* raiz) {
		if (raiz != nullptr) {
			EnOrden(raiz->izquierdo);
			cout<<"ID: " << raiz->idA << " Nombre: "<<raiz->nombreA<<" Descripcion: "<<raiz->descripcion<<endl;
			EnOrden(raiz->derecho);
		}
	}
	void EnOrdenD(NodoArbol* raiz) {
		if (raiz != nullptr) {
			EnOrdenD(raiz->izquierdo);
			cout << "ID: " << raiz->idA << " Nombre: " << raiz->nombreA << " Descripcion: " << raiz->descripcion <<" Tiempo de Renta: "<<raiz->tiempo<<"(dias);"<< endl;
			EnOrdenD(raiz->derecho);
		}
	}
	void EnOrdenDisponibles(NodoArbol* raiz) {
		if (raiz != nullptr) {
			EnOrdenDisponibles(raiz->izquierdo);
			if (raiz->disponibilidad == true) {
				cout << "ID: " << raiz->idA << " Nombre: " << raiz->nombreA << " Descripcion: " << raiz->descripcion << endl;
			}EnOrdenDisponibles(raiz->derecho);
		}
	}
	void EnOrdenNoDisponibles(NodoArbol* raiz) {
		if (raiz != nullptr) {
			EnOrdenNoDisponibles(raiz->izquierdo);
			if (raiz->disponibilidad == false) {
				cout << "ID: " << raiz->idA << " Nombre: " << raiz->nombreA << " Descripcion: " << raiz->descripcion << endl;
			}EnOrdenNoDisponibles(raiz->derecho);
		}
	}

	
};











