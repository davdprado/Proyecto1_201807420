#include<iostream>
#include<string.h>
#include"Activo.h"
using namespace std;
class ArbolA
{
public:
	NodoActivo* raiz;
	ArbolA() {
		raiz = nullptr;
	}
	//Buscar un nodo en el arbol;
	NodoActivo* buscar(string, NodoActivo*);
	//Obtener el factor de equilibrio
	int obtenerFE(NodoActivo*);
	//rotacion SI
	NodoActivo* rotaizq(NodoActivo*);
	//Mayor de dos numeros xd
	int Mayor(int, int);
	//rotacion SD
	NodoActivo* rotaDer(NodoActivo*);
	//rotacion DI
	NodoActivo* rotaDobleIzq(NodoActivo*);
	//rotacion DD
	NodoActivo* rotaDobleDer(NodoActivo*);
	//Insertar Nodo
	NodoActivo* Insertar(NodoActivo*, NodoActivo*);
	//crear
	void Crear(string,string,string);
	//Recorrer ArbolA
	void EnOrden(NodoActivo*);
};

int ArbolA::Mayor(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}
NodoActivo* ArbolA::buscar(string d, NodoActivo* raiz) {
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

int ArbolA::obtenerFE(NodoActivo* r) {
	if (r == nullptr)
	{
		return -1;
	}
	else
	{
		return r->fe;
	}
}

NodoActivo* ArbolA::rotaizq(NodoActivo* raiz) {
	NodoActivo* aux = raiz->izquierdo;
	raiz->izquierdo = aux->derecho;
	aux->derecho = raiz;
	raiz->fe = Mayor(obtenerFE(raiz->izquierdo), obtenerFE(raiz->derecho)) + 1;
	aux->fe = Mayor(obtenerFE(aux->izquierdo), obtenerFE(aux->derecho)) + 1;
	return aux;
}

NodoActivo* ArbolA::rotaDer(NodoActivo* raiz) {
	NodoActivo* aux = raiz->derecho;
	raiz->derecho = aux->izquierdo;
	aux->izquierdo = raiz;
	raiz->fe = Mayor(obtenerFE(raiz->izquierdo), obtenerFE(raiz->derecho)) + 1;
	aux->fe = Mayor(obtenerFE(aux->izquierdo), obtenerFE(aux->derecho)) + 1;
	return aux;
}
NodoActivo* ArbolA::rotaDobleIzq(NodoActivo* raiz) {
	NodoActivo* aux;
	raiz->izquierdo = rotaDer(raiz->izquierdo);
	aux = rotaizq(raiz);
	return aux;
}
NodoActivo* ArbolA::rotaDobleDer(NodoActivo* raiz) {
	NodoActivo* aux;
	raiz->derecho = rotaizq(raiz->derecho);
	aux = rotaDer(raiz);
	return aux;
}

NodoActivo* ArbolA::Insertar(NodoActivo* nuevo, NodoActivo* sub) {
	NodoActivo* padre = sub;
	if (nuevo->idA < sub->idA)
	{
		if (sub->izquierdo == nullptr) {
			sub->izquierdo = nuevo;
		}
		else
		{
			sub->izquierdo == Insertar(nuevo, sub->izquierdo);
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
	//corregir el fe
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

void ArbolA::Crear(string i,string n,string desc) {
	NodoActivo* nuevo = new NodoActivo(i,desc,n);
	if (raiz == nullptr)
		raiz = nuevo;
	else
		raiz = Insertar(nuevo, raiz);
}

void ArbolA::EnOrden(NodoActivo* raiz) {
	if (raiz != nullptr) {
		EnOrden(raiz->izquierdo);
		cout << raiz->idA << " , ";
		EnOrden(raiz->derecho);
	}
}