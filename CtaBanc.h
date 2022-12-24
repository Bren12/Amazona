// Brenda Elena Saucedo González - A00829855
// 29 - Noviembre - 2020

class CtaBanc {
	// Atributos
	private:
		int clave;
		float saldo;
		
	// Metodos
	public:
		// Constructor Default
		CtaBanc();
		// Constructor con Parametros
		CtaBanc(int clv, float din);
		// Metodo de Acceso
		int getClave();
		float getSaldo();
		// Metodo de Modificacion
		void setClave(int clv);
		void setSaldo(float din);
		// Metodo para restar el saldo inicial por el precio de cada compra
		bool retirar(float cant);
		
};

CtaBanc::CtaBanc() {
	clave = 0;
	saldo = 0;
}

CtaBanc::CtaBanc(int clv, float din) {
	
	clave = clv;
	
	if (din >= 0) {
		saldo = din;
	}
	else {
		saldo = 0;
	}
	
}

int CtaBanc::getClave() {
	return clave;
}

float CtaBanc::getSaldo() {
	return saldo;
}

void CtaBanc::setClave(int clv) {
	clave = clv;
}

void CtaBanc::setSaldo(float din) {
	if (din>=0) {
		saldo = din;
	}
	else {
		saldo = 0;
	}
}

bool CtaBanc::retirar(float cant) {
	if (saldo >= cant) {
		saldo -= cant;
		return true;
	}
	else {
		return false;
	}
}
