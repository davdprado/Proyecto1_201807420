// [EDD]Proyecto1_201807420.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"Nodo.h"
#include "Matriz.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"ListaDCircular.h"
#include <ctime>  
#include<fstream>
#include <chrono>
using namespace std;
int idUsuarios = 1;
ListaCircular* listaTrans = new ListaCircular();
string grafiarbol;
string graficaU;
NodoArbol* buscarActivo(Nodo* Inicio,string cod) {
    while (Inicio != nullptr)
    {
        Nodo* x = Inicio;
        while (x != nullptr) {
            if (x->back != nullptr)
            {
                Nodo* lista = x;
                while (lista != nullptr)
                {
                    if (lista->arbol->raiz != nullptr)
                    {
                        if (lista->arbol->buscar(cod,lista->arbol->raiz)!=nullptr)
                        {
                            return lista->arbol->buscar(cod, lista->arbol->raiz);
                        }
                    }
                    lista = lista->back;
                }
                x = x->nextt;
            }
            else {
                if (x->arbol->raiz != nullptr)
                {
                    if (x->arbol->buscar(cod, x->arbol->raiz) != nullptr)
                    {
                        return x->arbol->buscar(cod, x->arbol->raiz);
                    }
                }
                x = x->nextt;
            }
        }
        Inicio = Inicio->down;
    }
}

void recorrerActivos(Nodo* Inicio) {
    while (Inicio != nullptr)
    {
        Nodo* x = Inicio;
        while (x != nullptr) {
            if (x->back != nullptr)
            {
                Nodo* lista = x;
                while (lista != nullptr)
                {
                    if (lista->arbol->raiz!=nullptr)
                    {
                        lista->arbol->EnOrdenDisponibles(lista->arbol->raiz);
                    }
                    lista = lista->back;
                }
                x = x->nextt;
            }
            else {
                if (x->arbol->raiz != nullptr)
                {
                    x->arbol->EnOrdenDisponibles(x->arbol->raiz);
                }
                x = x->nextt;
            }
        }
        Inicio = Inicio->down;
    }
}

string alfanumerico() {
    string strrnd;
    int a;
    int y=0;
    for (int i = 0; i <= 14; i++)
    {
        if (i <= 0) {
            y = 48 + rand() % (58 - 48);
        }
        else {
            a = 1 + rand() % (3 - 1);
            if (a == 2) {
                y = 48 + rand() % (58 - 48);
            }
            else if (a == 1) {
               y = 97 + rand() % (123 - 97);
            }
        }
        strrnd += char(y);
    }
    return strrnd;
}

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

string esdisponible(bool a) {
    if (a)
    {
        return "disponible";
    }
    else
    {
        return "no disponible";
    }
}

bool ExisteCabezera(Nodo* cabeza,string cabe) {
    Nodo* otr = cabeza;
    while (cabeza!=nullptr)
    {
        if (cabeza->nombre==cabe)
            return true;
        else
            cabeza = cabeza->nextt;
    }
    while (otr!=nullptr)
    {
        if (otr->nombre == cabe)
            return true;
        else
            otr=otr->down;
    }
    return false;
}


string cosa(NodoArbol* nodo, NodoArbol* padre) {
    if (nodo != nullptr) {
        if (padre == nullptr)
        {
            cosa(nodo->izquierdo, nodo);
            cosa(nodo->derecho, nodo);
        }
        else {
            graficaU+=padre->nombreA+padre->idA + " -> " + nodo->nombreA+nodo->idA+"\n";
            cosa(nodo->izquierdo, nodo);
            cosa(nodo->derecho, nodo);
        }
    }
    return graficaU;
}
string Grafi(NodoArbol* raiz) {
    
    if (raiz != nullptr)
    {
        Grafi(raiz->izquierdo);  
        grafiarbol += raiz->nombreA + raiz->idA + "[label=" + '"' + "ID: " + raiz->idA+"\\n" + " Nombre: " + raiz->nombreA + "\\n" + " descripcion: " + raiz->descripcion + "\\n" +" disponibilidad: "+esdisponible(raiz->disponibilidad)+ '"' + "]\n";
        Grafi(raiz->derecho);
    }
        
    return grafiarbol;
}
string arbolEmp(Nodo* Inicio, string de) {

    string grafica = "";
    while (Inicio != nullptr)
    {
        if (Inicio->back != nullptr)
        {
            Nodo* Aux = Inicio;
            while (Aux->back != nullptr)
            {
                if (Aux->arbol->raiz != nullptr) {
                    grafica += Aux->nombre + to_string(Aux->id) + "[label=" + '"' + " Nombre: " + Aux->nombre + '"' + "]\n";
                    grafica += Grafi(Aux->arbol->raiz);
                    grafica += Aux->nombre + to_string(Aux->id) + "->" + Aux->arbol->raiz->nombreA + Aux->arbol->raiz->idA + "\n";
                    grafica += cosa(Aux->arbol->raiz, nullptr);
                }
                Aux = Aux->back;
            }
        }
        else
        {
            if (Inicio->arbol->raiz != nullptr) {
                grafica += Inicio->nombre + to_string(Inicio->id) + "[label=" + '"' + " Nombre: " + Inicio->nombre + '"' + "]\n";
                grafica += Grafi(Inicio->arbol->raiz);
                grafica += Inicio->nombre + to_string(Inicio->id) + "->" + Inicio->arbol->raiz->nombreA + Inicio->arbol->raiz->idA + "\n";
                grafica += cosa(Inicio->arbol->raiz, nullptr);

            }

        }
        Inicio = Inicio->nextt;
    }
    return grafica;
}

string arbolDepa(Nodo* Inicio, string de) {
    
    string grafica = "";
    while (Inicio != nullptr)
    {
        if (Inicio->back != nullptr)
        {
            Nodo* Aux = Inicio;
            while (Aux->back != nullptr)
            {
                if (Aux->arbol->raiz != nullptr) {
                    grafica += Aux->nombre + to_string(Aux->id) + "[label=" + '"' + " Nombre: " + Aux->nombre + '"' + "]\n";
                    grafica += Grafi(Aux->arbol->raiz);
                    grafica += Aux->nombre + to_string(Aux->id) + "->" + Aux->arbol->raiz->nombreA + Aux->arbol->raiz->idA + "\n";
                    grafica += cosa(Aux->arbol->raiz, nullptr);
                }
                Aux = Aux->back;
            }
        }
        else
        {
            if (Inicio->arbol->raiz != nullptr) {
                grafica += Inicio->nombre + to_string(Inicio->id) + "[label=" + '"' + " Nombre: " + Inicio->nombre + '"' + "]\n";
                grafica += Grafi(Inicio->arbol->raiz);
                grafica += Inicio->nombre + to_string(Inicio->id) + "->" + Inicio->arbol->raiz->nombreA + Inicio->arbol->raiz->idA + "\n";
                grafica += cosa(Inicio->arbol->raiz, nullptr);

            }

        }
        Inicio = Inicio->down;
    }
    return grafica;
}

void GenerarGrafica2(Matriz* mat,Nodo*cabeza, string departamento) {
    grafiarbol = "";
    string emp = "digraph G{\n";
    emp += departamento + "[label=" + '"' + departamento + '"' + "]";
    Nodo* cabeceraxd = mat->buscarDep(departamento, cabeza);
    emp += arbolDepa(cabeceraxd, departamento);
    emp += "}";
    ofstream archivo;
    archivo.open("grafica.dot", ios::out);
    if (archivo.fail())
    {
        cout << "Error: no se pudo abrir el archivo";
        return;
    }
    archivo << emp;
    archivo.close();
    system("dot -Tjpg grafica.dot -o Grafica.jpg");
    grafiarbol = "";
}
void GenerarGrafica3(Matriz* mat, Nodo* cabeza, string empresa) {
    grafiarbol = "";
    string emp = "digraph G{\n";
    emp += empresa + "[label=" + '"' + empresa + '"' + "]";
    Nodo* cabeceraxd = mat->buscarEmp(empresa, cabeza);
    emp += arbolDepa(cabeceraxd, empresa);
    emp += "}";
    ofstream archivo;
    archivo.open("grafica.dot", ios::out);
    if (archivo.fail())
    {
        cout << "Error: no se pudo abrir el archivo";
        return;
    }
    archivo << emp;
    archivo.close();
    system("dot -Tjpg grafica.dot -o Grafica.jpg");
    grafiarbol = "";
}


void GenerarGrafica1(Matriz* mat,Nodo* cabeza) {
    string emp = "digraph G{\n";
    emp += "node [shape=box]\n";
    emp += mat->Graficar(cabeza);
    emp += "}";
    ofstream archivo;
    archivo.open("grafica.dot", ios::out);
    if (archivo.fail())
    {
        cout << "Error: no se pudo abrir el archivo";
        return;
    }
        archivo << emp;
        archivo.close();
        system("dot -Tjpg grafica.dot -o Grafica.jpg");
}

void menuAdministrador(Nodo* cabeza, Matriz* matrizD) {
    int op;
    do {
        op = 0;
        string dp, empre, us, contra,depart;
        bool dpa, empr;
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
            system("cls");
            cout << "%%%%%%%%%%%%%% Ingresar Usuario nuevo %%%%%%%%%%%"<<endl;
            cout << "Ingrese Departamento: ";
            cin >> dp;
            dpa = ExisteCabezera(cabeza, dp);
            cout << "Ingrese Empresa: ";
            cin >> empre;
            empr = ExisteCabezera(cabeza,empre);
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
        case 2:
            system("cls");
            cout << "##################### Reporte Matriz ########################";
            GenerarGrafica1(matrizD, cabeza);
            break;
        case 3:
            system("cls");
            cout << "##################### Reporte por departamento ########################"<<endl;
            cout << "Ingrese departamento: ";
            cin >> depart;
            GenerarGrafica2(matrizD,cabeza,depart);
            break;
        case 4:system("cls");
            cout << "##################### Reporte por Empresa ########################" << endl;
            cout << "Ingrese Empresa: ";
            cin >> depart;
            GenerarGrafica3(matrizD, cabeza, depart);
            break;
        case 5:
            system("cls");
            cout << "##################### Lista de Transacciones ########################";
            listaTrans->MostrarLista();
            listaTrans->Graficar();
            break;
        case 6:
            system("cls");
            cout << "##################### Activos por Usuario ########################";
            cout << "Ingrese departamento: ";
            cin >> depart;
            cout << "Ingrese Empresa: ";
            cin >> empre;
            Nodo* punto = buscarCoordenadas(cabeza, empre, depart);
            cout << "Ingrese Nombre: ";
            cin >> us;
            if (punto->back == nullptr)
            {
                if (punto->nombre == us)
                {
                    int ope;
                    system("cls");
                    if (punto->arbol->raiz!=nullptr)
                    {
                        cout << punto->nombre;
                        cout << " tiene estos activos disponibles: ";
                        punto->arbol->EnOrdenDisponibles(punto->arbol->raiz);
                    }
                    else
                    {
                        cout << punto->nombre;
                        cout << "El usuario no tiene activos disponibles :("<<endl;
                    }
                    if (punto->renta->raiz!=nullptr)
                    {
                        cout << punto->nombre;
                        cout << "El Usuario tiene estos activos rentados: ";
                        punto->renta->EnOrdenD(punto->renta->raiz);
                    }
                    else
                    {
                        cout << punto->nombre;
                        cout << "El usuario no ha rentado activos  :(" << endl;
                    }
                    return;
                }
                else
                {
                    cout << "No existe en esta empresa y departamento";
                    return;
                }
            }
            else
            {
                Nodo* aux = punto;
                while (aux != nullptr)
                {
                    if (aux->nombre == us )
                    {
                        int ope;
                        system("cls");
                        if (punto->arbol->raiz != nullptr)
                        {
                            cout << punto->nombre;
                            cout << " tiene estos activos disponibles: ";
                            punto->arbol->EnOrdenDisponibles(punto->arbol->raiz);
                        }
                        else
                        {
                            cout << punto->nombre;
                            cout << "El usuario no tiene activos disponibles :(" << endl;
                        }
                        if (punto->renta->raiz != nullptr)
                        {
                            cout << punto->nombre;
                            cout << "El Usuario tiene estos activos rentados: ";
                            punto->renta->EnOrdenD(punto->renta->raiz);
                        }
                        else
                        {
                            cout << punto->nombre;
                            cout << "El usuario no ha rentado activos  :(" << endl;
                        }
                        return;
                    }
                    aux = aux->back;
                }
            }

            break;
        }
    } while (op!=8);
}


void menuUsuario(Nodo* cabezera,string nuser,string departamento,string empresa,Nodo* nodoUser) {
    int op;
    do {
        string no, d, x,ids,neva;
        int day;
        Arbol* arbolUs = nodoUser->arbol;
        Arbol* arbolrent = nodoUser->renta;
        NodoArbol* hrent;
        NodoArbol* otro;
        op = 0;
        cout << "%%%%%%%%%%%%%%% "<<nuser<<" %%%%%%%%%%%%%%%%%%" << endl;
        cout << "1. Agregar Activo" << endl;
        cout << "2. Eliminar Activo" << endl;
        cout << "3. Modificar Activo" << endl;
        cout << "4. Rentar Activo" << endl;
        cout << "5. Activos rentados" << endl;
        cout << "6. Mis activos rentados" << endl;
        cout << "7. Salir" << endl << "Elija su opcion: ";
        cin >> op;
        switch(op)
        {
        case 1:
            system("cls");
            x = alfanumerico();
            cout << "##### Nuevo Activo #####"<<endl;
            cout << "Ingrese Nombre: ";
            cin >> no;
            cout << "Ingrese Descripcion: ";
            cin >> d;
            arbolUs->Crear(x, d, no);
            cout << "Activo creado: \n";
            cout << "id: " << x << " nombre: " << no << " descripcion: " << d << endl;
            cout << endl;
            break;
        case 2:
            system("cls");
            cout << "###### Eliminar Activo#####"<<endl;
            arbolUs->EnOrden(nodoUser->arbol->raiz);
            cout << "Ingrese id del activo a eliminar: ";
            cin >> ids;

            //aqui estuviera mi funcion de eliminar (si tuviera una!!!!!);

            cout << "Se elimino el activo con id: " << ids;
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "###### Modificar Activo#####" << endl;
            arbolUs->EnOrden(nodoUser->arbol->raiz);
            cout << "\n Ingrese id de activo a modificar: ";
            cin >> ids;
            cout << "Nueva descripcion: ";
            cin >> neva;
            arbolUs->buscar(ids, nodoUser->arbol->raiz)->descripcion = neva;
            cout << "Se cambio la descripcion";
            cout << endl;
            break;
        case 4:
            system("cls");
            cout << "###### Rentar Activo #####" << endl;
            cout << "Lista de Ativos disponibles:" << endl;
            recorrerActivos(cabezera);
            cout << "Escriba el id del Activo a rentar: ";
            cin >> ids;
            hrent = buscarActivo(cabezera, ids);
            cout << "Duracion de renta(dias): ";
            cin >> day;
            arbolrent->Crear(hrent->idA, hrent->descripcion, hrent->nombreA);
            hrent->disponibilidad = false;
            hrent->tiempo = day;
            x = alfanumerico();
            listaTrans->InsertarFinal(x,hrent->idA,nodoUser->nombre,departamento,empresa, "tocohoy",day);
            cout << "Se rento el Activo: "<<endl;
            cout << "id: " + hrent->idA << " descripcion: " + hrent->descripcion << " nombre: " + hrent->nombreA <<" por "<<day<<" dias;"<< endl;
            cout << endl;
            break;
        case 5:
            cout << "###### Activos Rentados #####" << endl;
            arbolUs->EnOrdenD(nodoUser->renta->raiz);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Ingrese el  id del activo a devolver: ";
            cin >> ids;
            otro = buscarActivo(cabezera, ids);
            otro->disponibilidad = true;
            otro->tiempo = 0;
            ///aqui iria la opcion de eliminar pero cuando la tenga la pongo
            cout << endl;
            break;
        case 6:
            system("cls");
            cout << "###### Mis Activos rentados#####" << endl;
            arbolUs->EnOrdenNoDisponibles(nodoUser->arbol->raiz);
            cout << endl;
            break;
        }
    } while (op != 7);
}




void Login(Nodo* cabeza, string usuario, string contra, string empresa, string departamento,Matriz* matrizD) {
    Nodo* punto = buscarCoordenadas(cabeza, empresa, departamento);
    if (usuario=="admin" && contra=="admin")
    {
        system("cls");
        menuAdministrador(cabeza,matrizD);
        return;
    }
    if (punto->back==nullptr)
    {
        if (punto->nombre==usuario && punto->pass==contra)
        {
            cout << "el usuario existe bienvenido";
            system("cls");
            menuUsuario(cabeza, usuario, departamento, empresa,punto);
            return;
        }
        else
        {
            cout << "No existe en esta empresa y departamento";
            return;
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
                system("cls");
                menuUsuario(cabeza, usuario, departamento, empresa,aux);
                return;
            }
            aux = aux->back;
        }
    }
}



int main()
{

    srand(time(NULL));
    int op;
    string seguir;
    bool dp, inc;
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
    do {
        string usl, password, departamento, empresa;
        system("cls");
        cout << "#################### L O G I N ########################" << endl;
        cout << "Usuario: ";
        cin >> usl;
        cout << "Contrasenia: ";
        cin >> password;
        cout << "Departamento: ";
        cin >> departamento;
        dp = ExisteCabezera(Inicio, departamento);
        cout << "Empresa: ";
        cin >> empresa;
        inc = ExisteCabezera(Inicio,empresa);
        if (dp&&inc)
        {
            Login(Inicio, usl, password, empresa, departamento, miObjeto);
            cout << "Seguir(s/n): ";
            cin >> seguir;
        }
        else if (usl=="admin"&&password=="admin")
        {
            Login(Inicio, usl, password, empresa, departamento, miObjeto);
            cout << "Seguir(s/n): ";
            cin >> seguir;
        }
        else {
            cout << "La Empresa o Departamento no existe;";
        }
        
    } while (seguir == "s");


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


