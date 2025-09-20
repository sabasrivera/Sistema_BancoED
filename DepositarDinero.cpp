#include "Banco.hpp"


void Banco::DepositarDinero()
{ // para depositar
	int numeroCuentaAdepositar;
	double Cantidad;
	int Buscando = -1;

	if (CantidadDeCuentas == 0)
	{
		cout << "No hay cuentas para depositar" << endl;
		return;
	}
	cout << "Ingrese el numero de la cuenta a depositar: ";
	cin >> numeroCuentaAdepositar;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == numeroCuentaAdepositar)
		{
			Buscando = i;
			break;
		}
	}
	if (Buscando == -1)
	{
		cout << "La cuenta no existe" << endl;
	}
	else
	{
		cout << "Monto a depositar: ";
		cin >> Cantidad;
	}

	if (Cantidad <= 0)
	{
		cout << "Monto no valido" << endl;
		return;
	}
	else
	{
		// haciendo el deposito
		saldos[Buscando] += Cantidad;
		cout << "El Deposito se realizo con exito" << endl;
	}
}
