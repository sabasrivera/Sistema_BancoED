#include "Banco.hpp"

void Banco::CrearCuenta(int numero, string titular, double saldoInicial)
{
	numerosCuenta[CantidadDeCuentas] = numero;
	saldos[CantidadDeCuentas] = saldoInicial;
	titulares[CantidadDeCuentas] = titular;
	CantidadDeCuentas++;
	cout << "Cuenta creada exitosamente para " << titular
		 << " con numero " << numero
		 << " y saldo inicial: " << saldoInicial << endl;
}
