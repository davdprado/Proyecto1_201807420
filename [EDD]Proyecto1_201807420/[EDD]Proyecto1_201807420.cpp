// [EDD]Proyecto1_201807420.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"Nodo.h"
#include "Matriz.h"
using namespace std;
int idUsuarios = 1;
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

bool ExisteCabezera(Nodo* cabeza,string depart,string empre) {
    Nodo* otr = cabeza;
    while (cabeza!=nullptr)
    {
        if (cabeza->nombre==depart)
            return true;
        else
            cabeza = cabeza->nextt;
    }
    while (otr!=nullptr)
    {
        if (otr->nombre == empre)
            return true;
        else
            otr=otr->down;
    }
    return false;
}

void menuAdministrador(Nodo* cabeza, Matriz* matrizD) {
    int op;
    do {
        op = 0;
        system("cls");
        cout << "%%%%%%%%%%%%%%% Menu Administrador %%%%%%%%%%%%%%%%%%" << endl;
        cout << "1. Registrar Usuario" << endl;
        cout << "2. Reporte Matriz dispersa" << endl;
        cout << "3. Activos disponibles d un departamento" << endl;
        cout << "4. Activos disponibles de una empresa" << endl;
        cout << "5. Reporte de transacciones" << endl;
        cout << "6. Reporte de activos por usuario" << endl;
        cout << "7 Ordenar transacciones" << endl;
        cout << "8. Salir" << endl<<"Elija su opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            string dp, empre, us, contra;
            bool dpa, empr;
            system("cls");
            cout << "%%%%%%%%%%%%%% Ingresar Usuario nuevo %%%%%%%%%%%"<<endl;
            cout << "Ingrese Departamento: ";
            cin >> dp;
            dpa = ExisteCabezera(cabeza, dp, empre);
            cout << "Ingrese Empresa: ";
            cin >> empre;
            empr = ExisteCabezera(cabeza, dp, empre);
            cout << "Ingrese Usuario: ";
            cin >> us;
            cout << "Ingrese Contrasenia: ";
            cin >> contra;
            if (dpa && empr)
            {
                Nodo* listaUs=buscarCoordenadas(cabeza, empre, dp);
                if (listaUs->back==nullptr && listaUs->nombre==us)
                    cout << "El usuario ya existe en este departamento y empresa";
                else if (listaUs->back!=nullptr)
                {
                    Nodo* aux = listaUs;
                    while (aux != nullptr)
                    {
                        if (aux->nombre == us)
                        {
                            cout << "el usuario ya existe en este departamento y empresa";
                            break;
                        }
                        aux = aux->back;
                    }
                }
                else
                {
                    matrizD->InsertarElemento(us, idUsuarios, contra, empre, dp);
                    idUsuarios++;
                }

            }
            else {
                matrizD->InsertarElemento(us, idUsuarios, contra, empre, dp);
                idUsuarios++;
            }
            break;
        }
    } while (op!=8);
}
void menuUsuario(Nodo* cabezera,string nuser,string departamento,string empresa,Matriz* matrizD) {
    int op;
    do {
        op = 0;
        system("cls");
        cout << "%%%%%%%%%%%%%%% "<<nuser<<" %%%%%%%%%%%%%%%%%%" << endl;
        cout << "1. Agregar Activo" << endl;
        cout << "2. Eliminar Activo" << endl;
        cout << "3. Modificar Activo" << endl;
        cout << "4. Rentar Activo" << endl;
        cout << "5. Activos rentados" << endl;
        cout << "6. Mis activos rentados" << endl;
        cout << "7. Salir" << endl << "Elija su opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            break;
        }
    } while (op != 7);
}




void Login(Nodo* cabeza, string usuario, string contra, string empresa, string departamento,Matriz* matrizD) {
    Nodo* punto = buscarCoordenadas(cabeza, empresa, departamento);
    cout<<"se encontro";
    if (usuario=="admin" && contra=="admin")
    {
        menuAdministrador(cabeza,matrizD);
    }
    if (punto->back==nullptr)
    {
        if (punto->nombre==usuario && punto->pass==contra)
        {
            cout << "el usuario existe bienvenido";
            menuUsuario(cabeza, usuario, departamento, empresa,matrizD);
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
                menuUsuario(cabeza, usuario, departamento, empresa,matrizD);
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
    miObjeto->InsertarElemento("mario", idUsuarios, "1234", "max", "Guatemala");
    idUsuarios++;
    miObjeto->InsertarElemento("susan", idUsuarios, "0000", "hp", "Peten");
    idUsuarios++;
    miObjeto->InsertarElemento("susel", idUsuarios, "1531", "hp", "Zacapa");
    idUsuarios++;
    miObjeto->InsertarElemento("roxana", idUsuarios, "1234", "Safo", "Zacapa");
    idUsuarios++;
    miObjeto->InsertarElemento("andrea", idUsuarios, "5123", "Safo", "Zacapa");
    idUsuarios++;
    miObjeto->InsertarElemento("sebas", idUsuarios, "51123", "Safo", "Zacapa");
    idUsuarios++;
    miObjeto->InsertarElemento("andres", idUsuarios, "12345", "hp", "Guatemala");
    idUsuarios++;
    miObjeto->InsertarElemento("willy", idUsuarios, "123456", "max", "Zacapa");
    idUsuarios++;
    miObjeto->InsertarElemento("lawey", idUsuarios, "0000", "hp", "Peten");
    idUsuarios++;
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
        Login(Inicio, usl, password, empresa, departamento,miObjeto);


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


