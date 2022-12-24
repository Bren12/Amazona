// Brenda Elena Saucedo González - A00829855
// 29 - Noviembre - 2020

#include"CtaBanc.h"
#include<string>
using namespace std;

class Cliente {
	
	// Atributos
	private:
		string nombre;
		string direccion;
		CtaBanc tarjeta;
		
	// Metodos
	public:
		// Constructor Default
		Cliente();
		// Constructor con Parametros
		Cliente(string nom, string ubi, CtaBanc tar);
		// Metodos de Acceso
		string getNombre();
		string getDireccion();
		CtaBanc getTarjeta();
		// Metodos de Modificacion
		void setNombre(string nom);
		void setDireccion(string ubi);
		void setTarjeta(CtaBanc tar);
		
};

Cliente::Cliente() {
	CtaBanc tar;
	nombre = "N/A";
	direccion = "N/A";
	tarjeta = tar;
}

Cliente::Cliente(string nom, string ubi, CtaBanc tar) {
	nombre = nom;
	direccion = ubi;
	tarjeta = tar;
}

string Cliente::getNombre() {
	return nombre;
}

string Cliente::getDireccion() {
	return direccion;
}

CtaBanc Cliente::getTarjeta() {
	return tarjeta;
}

void Cliente::setNombre(string nom) {
	nombre = nom;
}

void Cliente::setDireccion(string ubi) {
	direccion = ubi;
}

void Cliente::setTarjeta(CtaBanc tar) {
	tarjeta = tar;
}
