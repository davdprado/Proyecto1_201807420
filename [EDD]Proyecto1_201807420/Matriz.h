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
	Nodo* crearEmpr(string );
	Nodo* crearDep(string );

	Nodo* buscarEmp(string ,Nodo *);
	Nodo* buscarDep(string , Nodo * );



};
Nodo* Matriz::crearEmpr(string empresa) {
	Nodo* emp;
	emp = new Nodo(empresa, -1);

	Nodo* aux = cabezera;
	while (aux->down != nullptr)
		aux = aux->down;
	aux->down = emp;
	emp->up = aux;
	return emp;
}
Nodo* Matriz::crearDep(string departamento) {
	Nodo* depa;
	depa = new Nodo(departamento, -1);
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
void Matriz::InsertarElemento(string usuario, int numero, string empresa, string departamento) {
	Nodo* Nusuario;
	Nodo* Nempresa;
	Nodo* Ndepartamento;
	Nusuario = new Nodo(usuario, numero);

	Ndepartamento = buscarDep(departamento, cabezera);
	Nempresa = buscarEmp(empresa, cabezera);

	if (Ndepartamento == nullptr)
		Ndepartamento = crearDep(departamento);
	if (Nempresa == nullptr)
		Nempresa = crearEmpr(empresa);

	 
}
