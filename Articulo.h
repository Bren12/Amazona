// Brenda Elena Saucedo González - A00829855
// 29 - Noviembre - 2020

#include<iostream>
#include<string>
using namespace std;

class Articulo {
	// Atributos
	private:
		string nombreArt;
		float precio;
		int cantidad;
		
	public:
		// Constructor Default
		Articulo();
		// Constructor con Parametros
		Articulo(string nom, float p, int cant);
		// Metodos de Acceso
		string getNombreArt();
		float getPrecio();
		int getCantidad();
		// Metodos de Modificacion
		void setNombreArt(string nom);
		void setPrecio(float p);
		void setCantidad(int cant);
		void setTotal(float tot);
		// Metodo para ver cada articulo del carrito
		void carrito();
		// Metodo para calcular el total a pagar por articulo
		float total();
};

Articulo::Articulo() {
	nombreArt = "N/A";
	precio = 0;
	cantidad = 0;
}

Articulo::Articulo(string nom, float p, int cant) {
	nombreArt = nom;
	
	if (p >= 0) {
		precio = p;
	}
	else {
		precio = 0;
	}
	
	if (cant >= 0) {
		cantidad = cant;
	}
	else {
		cantidad = 0;
	}
	
}

string Articulo::getNombreArt() {
	return nombreArt;
}

float Articulo::getPrecio() {
	return precio;
}

int Articulo::getCantidad() {
	return cantidad;
}

void Articulo::setNombreArt(string nom) {
	nombreArt = nom;
}

void Articulo::setPrecio(float p) {
	if (p >= 0) {
		precio = p;
	}
	else {
		precio = 0;
	}
}

void Articulo::setCantidad(int cant) {
	if (cant >= 0) {
		cantidad = cant;
	}
	else {
		cantidad = 0;
	}
}

void Articulo::carrito() {
	if (cantidad == 1) {
		cout << " - " << cantidad << " articulo de " << nombreArt << " con un precio de $" << precio << endl;
	}
	else {
		cout << " - " << cantidad << " articulos de " << nombreArt << " con un precio de $" << precio << " cada uno" << endl;
	}
}

float Articulo::total() {
	return precio*cantidad;
}
