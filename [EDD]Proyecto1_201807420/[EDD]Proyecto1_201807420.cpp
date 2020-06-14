// [EDD]Proyecto1_201807420.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"Nodo.h"
#include "Matriz.h"
using namespace std;
int main()
{
    int idU = 0;
    string user, pass;
    cout << "############ Renta de Activos ################";
    cout << "################## Login ######################\n Usuario: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;
    Matriz *miObjeto = new Matriz();
    miObjeto->InsertarElemento("mario", 1, "max", "Guatemala");
    miObjeto->InsertarElemento("andres", 7, "hp", "Guatemala");
    miObjeto->InsertarElemento("susan", 2, "hp", "Peten");
    miObjeto->InsertarElemento("susel", 3, "hp", "Zacapa");
    miObjeto->InsertarElemento("roxana", 4, "Safo", "Zacapa");
    miObjeto->InsertarElemento("andrea", 5, "Safo", "Zacapa");
    miObjeto->InsertarElemento("sebas", 6, "Safo", "Zacapa");
    miObjeto->InsertarElemento("willy", 8, "max", "Zacapa");
    miObjeto->InsertarElemento("mario", 1, "Safo", "Guatemala");

}


