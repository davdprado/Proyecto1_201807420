#include<iostream>
#include <string>
using namespace std;
class Usuario
{
private:
	//atributos
	int id;
	string usuario;
	string password;
	string name;
//metodos
public:
	void imprimirUsuario();
	Usuario(int _id, std::string _usuario,std::string _password, std::string _name);
};


void Usuario::imprimirUsuario() {
	cout << "ID: " << id << "Usuario: " << usuario << "Password: " << password << "Nombre: " << name;
}


