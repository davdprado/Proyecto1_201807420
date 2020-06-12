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
    miObjeto->InsertarElemento("Sisi", 1, "hp", "Peten");
    miObjeto->InsertarElemento("Alf", 1, "hp", "Zacapa");
    miObjeto->InsertarElemento("Sxc", 1, "Safo", "Peten");

}


