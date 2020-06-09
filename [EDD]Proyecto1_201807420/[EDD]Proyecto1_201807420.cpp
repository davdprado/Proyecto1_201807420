// [EDD]Proyecto1_201807420.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Usuario.h";
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
    Usuario user1 = Usuario(1, "Beto", "algo", "Minombre");
    user1.imprimirUsuario();

}


