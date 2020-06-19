#pragma once
#include "Nodo.h"
#include<iostream>
#include<string>
using namespace std;
class Matriz
{
public:
	Nodo* cabezera;
	Matriz(){
		cabezera = new Nodo("admin", 0,"admin");
	}
	void InsertarElemento(string usuario, int numero,string passW, string empresa, string departamento);
	//metodos para ingresar cabeceras
	Nodo* crearEmpr(string );
	Nodo* crearDep(string );

	Nodo* buscarEmp(string ,Nodo *);
	Nodo* buscarDep(string , Nodo * );

	bool verificarEmpresa(string, Nodo*,Nodo*);
	bool verificarDepartamento(string, Nodo*, Nodo*);
	string Graficar(Nodo*);
};



Nodo* Matriz::crearEmpr(string empresa) {
	Nodo* emp;
	emp = new Nodo(empresa, 0,"");

	Nodo* aux = cabezera;
	while (aux->down != nullptr)
		aux = aux->down;
	aux->down = emp;
	emp->up = aux;
	return emp;
}
Nodo* Matriz::crearDep(string departamento) {
	Nodo* depa;
	depa = new Nodo(departamento, 0,"");
	Nodo* aux = cabezera;
	while (aux->nextt != nullptr)
	{
		aux = aux->nextt;
	}
	aux->nextt = depa;
	depa->previous = aux;
	return depa;
}
Nodo* Matriz::buscarDep(string departamento, Nodo* inicio) {
	Nodo* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->nombre == departamento)
		{
			return aux;
		}
		aux = aux->nextt;
	}
	return nullptr;

}
Nodo* Matriz::buscarEmp(string empresa, Nodo* inicio) {
	Nodo* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->nombre == empresa)
		{
			return aux;
		}
		aux = aux->down;
	}
	return nullptr;

}
void Matriz::InsertarElemento(string usuario, int numero,string passW, string empresa, string departamento) {
	Nodo* Nusuario;
	Nodo* Nempresa;
	Nodo* Ndepartamento;
	Nusuario = new Nodo(usuario, numero,passW);

	Ndepartamento = buscarDep(departamento, cabezera);
	Nempresa = buscarEmp(empresa, cabezera);

	if (Ndepartamento == nullptr)
		Ndepartamento = crearDep(departamento);
	if (Nempresa == nullptr)
		Nempresa = crearEmpr(empresa);

	 //departamento
	if (Ndepartamento->down==nullptr)
	{
		Ndepartamento->down = Nusuario;
		Nusuario->up = Ndepartamento;
	}
	else if (Nempresa->down==nullptr)
	{
		Nodo* Nauxiliar = Ndepartamento->down;
		while (Nauxiliar->down != nullptr)
		{
			Nauxiliar=Nauxiliar->down;
			 
		}
		if (!verificarEmpresa(empresa,Nauxiliar,Nusuario)) {
			Nauxiliar->down = Nusuario;
			Nusuario->up = Nauxiliar;
		}
	}
	//enmedio
	else
	{
		Nodo* Nauxiliar = Ndepartamento;
		do
		{
			Nauxiliar = Nauxiliar->down;
			if (!verificarEmpresa(empresa, Nauxiliar, Nusuario)) {
				Nodo* auxEmpr = Nauxiliar->previous;
				while (auxEmpr->previous!=nullptr)
				{
					auxEmpr = auxEmpr->previous;
				}
				while (auxEmpr->up!=nullptr)
				{
					if (auxEmpr->nombre==empresa)
					{
						Nusuario->down = Nauxiliar;
						Nusuario->up = Nauxiliar->up;


						Nauxiliar->up->down = Nusuario;
						Nauxiliar->up = Nusuario;
						break;

					}
					auxEmpr = auxEmpr->up;
				}
			}
		} while (Nauxiliar->down!=nullptr && Nusuario->up==nullptr);

		if (Nusuario->up==nullptr && Nusuario->front==nullptr)
		{
			Nauxiliar->down = Nusuario;
			Nusuario->up = Nauxiliar;
		}
	}
	if (Nusuario->front!=nullptr)
	{
		return; 
	}

	//empresa
	if (Nempresa->nextt==nullptr)
	{
		Nempresa->nextt = Nusuario;
		Nusuario->previous = Nempresa;
	}
	else if (Ndepartamento->nextt==nullptr) {
		Nodo* Nauxiliar = Nempresa->nextt;
		while (Nauxiliar->nextt!=nullptr)
		{
			Nauxiliar = Nauxiliar->nextt;
		}
		if (!verificarDepartamento(departamento, Nauxiliar,Nusuario))
		{
			Nauxiliar->nextt = Nusuario;
			Nusuario->previous = Nauxiliar;
		}
	}
	else
	{
		Nodo* Nauxiliar = Nempresa;
		do
		{
			Nauxiliar = Nauxiliar->nextt;
			if (!verificarDepartamento(departamento,Nauxiliar,Nusuario))
			{
				Nodo* auxDepa = Nauxiliar->up;
				while (auxDepa->up!=nullptr)
				{
					auxDepa = auxDepa->up;

				}
				while (auxDepa->previous!=nullptr)
				{
					if (auxDepa->nombre == departamento)
					{
						Nusuario->nextt = Nauxiliar;
						Nusuario->previous = Nauxiliar->previous;

						Nauxiliar->previous->nextt = Nusuario;
						Nauxiliar->previous = Nusuario;
						break;
					}
					auxDepa = auxDepa->previous;
				}
			}
		} while (Nauxiliar->nextt!=nullptr && Nusuario->previous==nullptr);
		if (Nusuario->previous==nullptr && Nusuario->front==nullptr)
		{
			Nauxiliar->nextt = Nusuario;
			Nusuario->previous = Nauxiliar;
		}
	}
}

bool Matriz::verificarEmpresa(string empresa, Nodo* inicio, Nodo* usr) {
	Nodo* auxEmp = inicio->previous;
	while (auxEmp->previous != nullptr)
	{
		auxEmp = auxEmp->previous;
	}
	if (auxEmp->nombre ==empresa)
	{
		while (inicio->back!=nullptr)
		{
			inicio = inicio->back;
		}
		inicio->back = usr;
		usr->front = inicio;
		return true;
	}
	return false;
}


bool Matriz::verificarDepartamento(string empresa, Nodo* inicio, Nodo* usr) {
	Nodo* auxDep = inicio->up;
	while (auxDep->up != nullptr)
	{
		auxDep = auxDep->up;
	}
	if (auxDep->nombre == empresa)
	{
		while (inicio->back != nullptr)
		{
			inicio = inicio->back;
		}
		inicio->back = usr;
		usr->front = inicio;
		return true;
	}
	return false;
}

string Matriz::Graficar(Nodo* Inicio) {
	string grafica = "";
	Nodo* copia=Inicio;
	Nodo* otro = Inicio;
	int grupo = 1;
	while (Inicio != nullptr)
	{
		Nodo* x = Inicio;
		while (x != nullptr) {
			if (x->arbol->raiz!=nullptr)
			{
				grafica += x->nombre + to_string(x->id) + "[label=" + '"' + "Id: " + to_string(x->id) + "\\n" + "Usuario: " + x->nombre + '"' + ",style = filled, fillcolor = lightskyblue , group=" + to_string(grupo) + "];\n";
			}
			else {
				grafica += x->nombre + to_string(x->id) + "[label=" + '"' + "Id: " + to_string(x->id) + "\\n" + "Usuario: " + x->nombre + '"' + " , group=" + to_string(grupo) + "];\n";
			}
			x = x->down;
		}
		Inicio = Inicio->nextt;
		grupo++;
	}//rank
	while (otro != nullptr)
	{
		Nodo* b = otro;
		grafica += "{ rank = same; ";
		while (b != nullptr) {
			grafica += b->nombre + to_string(b->id)+"; ";
			b = b->down;
		}
		otro = otro->nextt;
		grafica += "}\n";
	}
	//hacer las uniones
	while (copia != nullptr)
	{
		Nodo* xy = copia;
		while (xy != nullptr) {
			if (xy->nextt != nullptr) {
				grafica += xy->nombre + to_string(xy->id) + "->" + xy->nextt->nombre + to_string(xy->nextt->id)+"\n";
				if (xy->previous != nullptr) {
					grafica += xy->nombre + to_string(xy->id) + "->" + xy->previous->nombre + to_string(xy->previous->id) + "\n";
				}
			}
			if (xy->down != nullptr) {
				grafica += xy->nombre + to_string(xy->id) + "->" + xy->down->nombre + to_string(xy->down->id) + "\n";
				if (xy->up != nullptr) {
					grafica += xy->nombre + to_string(xy->id) + "->" + xy->up->nombre + to_string(xy->up->id) + "\n";
				}
			}
			xy = xy->nextt;
		}
		
		copia = copia->down;
	}
	return grafica;
 }

