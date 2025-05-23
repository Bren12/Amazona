// Brenda Elena Saucedo Gonz�lez - A00829855
// 29 - Noviembre - 2020

#include"Cliente.h"
#include"Articulo.h"
#include<iostream>
#include<string>
using namespace std;

// Funcion para desplegar los datos de los clientes registrados y sus cuentas
void opcion5(Cliente personas[]) {
	
	cout << "\nClientes registrados: " << endl;
	// Ciclo para desplegar los datos
	for (int i = 0; i < 5; i++) {
		if (personas[i].getNombre() != "N/A") {
			cout << i+1 << ". Cliente: " << personas[i].getNombre();
			cout << "  |  Direccion: " << personas[i].getDireccion();
			cout << "  |  Clave bancaria: " << personas[i].getTarjeta().getClave();
			cout << "  |  Saldo actual: $" << personas[i].getTarjeta().getSaldo() << endl;
		}
	}
}

// Funcion para pagar
void opcion4(Cliente personas[], float subtotal, int contP, int &cont, Articulo art[]) {
	
	// Ciclo que calcula el precio final de todos los articulos
	for (int i = 0; i < 5; i++) {
		if (art[i].getNombreArt() != "N/A") {
			subtotal += art[i].total();
		}
	}
	
	// Si el saldo es mayor que el precio final, se descuenta el precio final del saldo
	// En caso contrario, despliega un mensaje que no hay saldo suficiente para hacer el pago
	CtaBanc temp = personas[contP].getTarjeta();
	bool respuesta = temp.retirar(subtotal);
	personas[contP].setTarjeta(temp);
	
	if (respuesta == true) {
		
		cout << "\nPago realizado con exito!" << endl;
		cout << "Sus pedidos llegaran dentro de 5 dias habiles a " << personas[contP].getDireccion() << endl;
		
		// Al momento de pagar se reinician los articulos a sus valores iniciales
		cont = 0;
		for (int i = 0; i < 5; i++) {
			Articulo temp;
			art[i].setNombreArt( temp.getNombreArt() );
			art[i].setPrecio( temp.getPrecio() );
			art[i].setCantidad( temp.getCantidad() );
		}
	}
	else {
		cout << "\nEl pago no se pudo realizar correctamente" << endl;
		cout << "El subtotal a pagar es de $" << subtotal << endl;
		cout << "En su cuenta bancaria usted cuenta con $" << personas[contP].getTarjeta().getSaldo() << endl;
	}
}

// Funcion para mostrar los articulos que hay en el carrito
void opcion3(Articulo art[], float subtotal) {
	
	cout << "\nEn el carrito hay: " << endl;
	// Ciclo que muestra los datos de cada articulo
	for (int i = 0; i < 5; i++) {
		if (art[i].getNombreArt() != "N/A") {
			art[i].carrito();
			// Se va registrando el precio total de cada articulo
			subtotal += art[i].total();
		}
	}
	
	cout << "El subtotal a pagar es de $" << subtotal << endl;
	
}

// Funcion para retirar articulos del carrito
void opcion2(Articulo art[], int &cont1, float subtotal) {
	
	string articulo;
	int cant, pos = -1;
	
	cout << "\nNombre del articulo que desea retirar: ";
	cin >> articulo;
	
	// Ciclo que busca el nombre del articulo en el arreglo
	for (int i = 0; i < 5; i++) {
		if (art[i].getNombreArt() == articulo) {
			// Se guarda la posicion en caso de encontrar el articulo
			pos = i;
		}
	}
	
	if (pos >= 0) {
		
		// Se recorren los datos de cada articulo en el arreglo a una posicion anterior, empezando desde la posicion guardada
		for (int i = pos; i < 4; i++) {
			art[i].setNombreArt( art[i+1].getNombreArt() );
			art[i].setPrecio( art[i+1].getPrecio() );
			art[i].setCantidad( art[i+1].getCantidad() );
		}
		
		// Se borrar los datos almacenados en el ultima posicion del arreglo
		Articulo temp;
		art[4].setNombreArt( temp.getNombreArt() );
		art[4].setPrecio( temp.getPrecio() );
		art[4].setCantidad( temp.getCantidad() );
		
		// Se actualiza el contador
		cont1--;
		cout << "Articulo retirado del carrito con exito" << endl;
	}
	else {
		cout << "No existe un articulo con ese nombre en el carrito" << endl;
	}
	
}

// Funcion para agregar articulos al carrito
void opcion1(Articulo art[], int cont) {
	string articulo;
	float precio;
	int cant;
	
	cout << "\nNombre del articulo que se desea comprar: ";
	cin >> articulo;
	cout << "Cual es el precio del articulo? ";
	cin >> precio;
	cout << "Cantidad de articulos que desea cargar al carrito: ";
	cin >> cant;
	
	art[cont].setNombreArt(articulo);
	art[cont].setPrecio(precio);
	art[cont].setCantidad(cant);
	cout << endl;
}

// Funcion que despliega las opciones del menu
void menu(Cliente personas[], int &contP, Articulo art[]) {
	int opcion, cont1 = 0;
	float subtotal = 0;
	
	do {
		
		// Variable para la opcion 6 que es la salida del programa cuando se tienen articulos en el carrito sin pagar
		int respuesta6 = 0;
		
		cout << "\n---------------MENU---------------" << endl;
		cout << "1) Agregar un articulo al carrito" << endl;
		cout << "2) Retirar un articulo del carrito" << endl;
		cout << "3) Mostrar el carrito" << endl;
		cout << "4) Pagar" << endl;
		cout << "5) Mostrar lista de clientes" << endl;
		cout << "6) Salir" << endl;
		
		cout << "\nElija una opcion del menu: ";
		cin >> opcion;
		
		switch (opcion) {
			case 1: {
				// Condicional que verifica que no se sobrepase la cantidad del arreglo Cliente personas
				if (cont1 < 5) {
					opcion1(art,cont1);
					// Actualizar contador
					cont1++;
				}
				else {
					cout << "\nSe ha sobrepasado el limite de articulos en el carrito!" << endl;
				}
				break;
			}
			
			case 2: {
				opcion2(art,cont1,subtotal);
				break;
			}
			
			case 3: {
				opcion3(art,subtotal);
				break;
			}
			
			case 4: {
				opcion4(personas,subtotal,contP,cont1,art);
				break;
			}
			
			case 5: {
				opcion5(personas);
				break;
			}
			
			case 6: {
				// En caso de haber un articulo sin pagar le pregunta al usuario si en verdad quiere salir
				if (art[0].getNombreArt() != "N/A") {
					while ((respuesta6 < 1) || (respuesta6 > 2)) {
						cout << "\nEn su carrito hay articulos sin pagar, desea salir sin realizar ninguna compra?" << endl;
						cout << "1) SI\n2) NO" << endl << "Opcion -> ";
						cin >> respuesta6;
						
						// En caso que no quiera salir se cambia el numero de opcion del menu para que pueda regresar a el
						if (respuesta6 == 2) {
							opcion = 1;
						}
						else {
							if (respuesta6 != 1) {
								cout << "Opcion incorrecta!" << endl;
							}
						}
					}
				}
				
				if ((art[0].getNombreArt() == "N/A") || (respuesta6 == 1)) {
					cout << "\nGracias por confiar en nosotros, que tenga un buen dia! :D" << endl << endl;
					contP++;
					for (int i = 0; i < 5; i++) {
						Articulo temp;
						art[i].setNombreArt( temp.getNombreArt() );
						art[i].setPrecio( temp.getPrecio() );
						art[i].setCantidad( temp.getCantidad() );
					}
				}
				break;
			}
			
			default: {
				cout << "Opcion incorrecta";
				break;
			}
		}
	} while (opcion != 6);
	
}

// Funcion para que el cliente registre sus datos
void registrar(string &nombre, string &direccion, int &clave, float &saldo, int &cont, Cliente personas[], CtaBanc cuenta[]) {
	
	cout << "Registrese para poder continuar" << endl;
	cout << "Teclee su nombre: ";
	cin >> nombre;
	cout << "Tecle la direccion a la que van a llegar sus pedidos: ";
	cin >> direccion;
	cout << "Teclee los digitos de la clave de su cuenta bancaria: ";
	cin >> clave;
	cout << "Teclee el saldo actual de su cuenta bancaria: ";
	cin >> saldo;
	
	personas[cont].setNombre(nombre);
	personas[cont].setDireccion(direccion);
	cuenta[cont].setClave(clave);
	cuenta[cont].setSaldo(saldo);
	personas[cont].setTarjeta(cuenta[cont]);
}

int main() {
	
	Cliente personas[10];
	CtaBanc cuenta[10];
	Articulo art[5];
	int num, clave, cont = 0;
	string nombre, direccion;
	float saldo;
	
	// Ciclo que se repite mientras el usuario no teclee un numero entre 1-10
	do {
		cout << "Cuantas personas van a hacer compras online (maximo 10)? ";
		cin >> num;
	} while ((num > 10) || (num < 0));
	
	for (int i = 0; i < num; i++) {
		cout << "\nBienvenido a la Tienda Online Amazona!" << endl << endl;
		
		registrar(nombre,direccion,clave,saldo,cont,personas,cuenta);
		
		menu(personas,cont,art);
	}
	
	return 0;
}

/*/////////////////////////////////////// Descripcion del Programa //////////////////////////////////////////

Aplicacion que ejecuta las clases CtaBanc (control sobre la cuenta bancaria del cliente),
Cliente (control sobre los datos del cliente), Articulo (control sobre los datos del articulo).

En esta aplicacion podra registrarse un maximo de 10 clientes y 5 articulos, la diferencia con los articulos,
es que a la hora de pagar, se vacia el carrito y se podra volver a llenar. Luego de que se registre un cliente
se desplegara un menu enumerando las opciones que puede elegir, como lo es el agregar un articulo al carrito,
retirar un articulo del carrito, mostrar los articulos que hay en el carrito y el precio final, pagar,
desplegar los datos de los clientes que se han registrado por el momento y salir del programa.

*/
