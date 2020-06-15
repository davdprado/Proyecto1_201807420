// [EDD]Proyecto1_201807420.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"Nodo.h"
#include "Matriz.h"
using namespace std;
Nodo* buscarCoordenadas(Nodo* cabeza, string empresa, string departamento) {
    while (cabeza != nullptr)
    {
        if (cabeza->nombre == departamento)
        {
            while (cabeza != nullptr)
            {
                Nodo* aux = cabeza;
                while (aux != nullptr)
                {
                    if (aux->nombre == empresa)
                    {
                        
                        return cabeza;
                    }
                    else {
                        aux = aux->previous;
                    }
                }
                cabeza = cabeza->down;
            }
        }
        cabeza = cabeza->nextt;
    }
}
void Login(Nodo* cabeza, string usuario, string contra, string empresa, string departamento) {
    Nodo* punto = buscarCoordenadas(cabeza, empresa, departamento);
    cout<<"se encontro";
    if (punto->back==nullptr)
    {
        if (punto->nombre==usuario && punto->pass==contra)
        {
            cout << "el usuario existe bienvenido";
        }
        else
        {
            cout << "No existe en esta empresa y departamento";
        }
    }
    else
    {
        Nodo* aux = punto;
        while (aux!=nullptr)
        {
            if (aux->nombre == usuario && aux->pass == contra)
            {
                cout << "el usuario existe bienvenido";
                break;
            }
            aux = aux->back;
        }
    }
}



int main()
{
    string usl, password,departamento,empresa;
    int op;
    bool seguir = true;
    Matriz* miObjeto = new Matriz();
    miObjeto->InsertarElemento("mario", 1, "1234", "max", "Guatemala");
    miObjeto->InsertarElemento("susan", 2, "0000", "hp", "Peten");
    miObjeto->InsertarElemento("susel", 3, "1531", "hp", "Zacapa");
    miObjeto->InsertarElemento("roxana", 4, "1234", "Safo", "Zacapa");
    miObjeto->InsertarElemento("andrea", 5, "5123", "Safo", "Zacapa");
    miObjeto->InsertarElemento("sebas", 6, "51123", "Safo", "Zacapa");
    miObjeto->InsertarElemento("andres", 7, "12345", "hp", "Guatemala");
    miObjeto->InsertarElemento("willy", 8, "123456", "max", "Zacapa");
    miObjeto->InsertarElemento("lawey", 2, "0000", "hp", "Peten");
    Nodo* Inicio = miObjeto->cabezera;
        cout << "#################### L O G I N ########################" << endl;
        cout << "Usuario: ";
        cin >> usl;
        cout << "Contrasenia: ";
        cin >> password;
        cout << "Departamento: ";
        cin >> departamento;
        cout << "Empresa: ";
        cin >> empresa;
        Login(Inicio, usl, password, empresa, departamento);

    //imprime matriz
    while (Inicio!=nullptr)
    {
        Nodo* x = Inicio;
        while (x != nullptr) {
            if (x->back!=nullptr)
            {
                Nodo* lista = x;
                while (lista!=nullptr)
                {
                    cout << lista->nombre << " : ";
                    lista=lista->back;
                }
                x = x->nextt;
            }
            else {
                cout << x->nombre << "\t";
                x = x->nextt;
            }
        }
        cout << "\n";
        Inicio = Inicio->down;
    }

}


