#include<iostream>
#include<string.h>
#include"Transaccion.h"
#include<fstream>
#include <chrono>
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
	void Graficar();
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
		fin->siguiente = inicio;
		inicio->anterior = fin;
		sizelist++;

	}
}

void ListaCircular::MostrarLista() {
	if (!Vacia()) {
		NodoLista* aux = inicio;
		for (int i = 0; i < sizelist; i++)
		{
			cout<<"idTr: "<<aux->idTr<<" idA: "<<aux->idAc<<" usuario: "<<aux->usuario<<" fecha: "<<aux->fecha << " ;" << endl;
			aux = aux->siguiente;
		}
	}
	else
	{
		cout << "esta vacia " << endl;
	}
}

void ListaCircular::Graficar() {
	if (!Vacia()) {
		NodoLista* aux = inicio;
		fstream archivo;
		archivo.open("grafica.dot", ios::out);
		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			return;
		}
		archivo << "digraph G{\n";
		archivo << "rankdir=LR;\n";
		for (int i = 0; i < sizelist; i++)
		{
			archivo << aux->usuario+aux->idTr+"[label="+'"'+"ID Transaccion: "+aux->idTr+"\\n"+" ID Activo: "+ aux->idAc + "\\n" + " Usuario: "+ aux->usuario + "\\n" + "fecha: "+ aux->fecha +'"'+"]"<<endl;
			archivo << aux->usuario + aux->idTr + "->" + aux->anterior->usuario + aux->anterior->idTr+"\n";
			archivo << aux->usuario + aux->idTr + "->" + aux->siguiente->usuario + aux->siguiente->idTr+"\n";
			aux = aux->siguiente;
		}
		archivo << "}";
		archivo.close();
		system("dot -Tjpg grafica.dot -o Grafica.jpg");
	}
	else
	{
		cout << "esta vacia " << endl;

	}
}