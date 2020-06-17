#include<iostream>
#include<string.h>
#include"Transaccion.h"
using namespace std;

class ListaCircular
{
public:
	int sizelist = 0;
	NodoLista* inicio;
	NodoLista* fin;
	bool Vacia();
	void InsertarInicio(string i, string idA, string usu, string depa, string emp, string fec, int ti);
	void InsertarFinal(string i, string idA, string usu, string depa, string emp, string fec, int ti);
	void MostrarLista();
};

bool ListaCircular::Vacia() {
	return(sizelist == 0);
}

void  ListaCircular::InsertarInicio(string i, string idA, string usu, string depa, string emp, string fec, int ti) {
	NodoLista* nuevo = new NodoLista(i, idA, usu, depa, emp, fec, ti);
	if (Vacia()) {
		inicio = nuevo;
		fin = nuevo;
		inicio->siguiente = fin;
		fin->siguiente = inicio;
		inicio->anterior = fin;
		fin->anterior = inicio;

		sizelist++;
	}
	else
	{
		NodoLista* aux = inicio;
		nuevo->siguiente = aux;
		aux->anterior = nuevo;
		inicio = nuevo;
		sizelist++;

	}
}

void  ListaCircular::InsertarFinal(string i, string idA, string usu, string depa, string emp, string fec, int ti) {
	NodoLista* nuevo = new NodoLista(i,idA,usu,depa,emp,fec,ti);
	if (Vacia()) {
		inicio = nuevo;
		fin = nuevo;
		inicio->siguiente = fin;
		fin->siguiente = inicio;
		inicio->anterior = fin;
		fin->anterior = inicio;

		sizelist++;
	}
	else
	{
		NodoLista* aux = fin;
		aux->siguiente = nuevo;
		nuevo->anterior = aux;
		fin = nuevo;
		sizelist++;

	}
}

void ListaCircular::MostrarLista() {
	if (!Vacia()) {
		NodoLista* aux = inicio;
		for (int i = 0; i < sizelist; i++)
		{
			cout << aux->idTr << endl;
			aux = aux->siguiente;
		}
	}
	else
	{
		cout << "esta vacia " << endl;
	}
}