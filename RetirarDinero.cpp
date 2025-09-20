#include "Banco.hpp"
using namespace std;


void Banco::RetirarDinero()
{
	int numeroCuentaAretirar;
	double Cantidad;
	int Buscando = -1;

	if (CantidadDeCuentas == 0)
	{
		cout << "No hay cuentas para retirar" << endl;
		return;
	}


	cout << "Ingrese el numero de la cuenta  a  Retirar: ";
	cin >> numeroCuentaAretirar;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == numeroCuentaAretirar)
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
		cout << "Monto a retirar: ";
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
		saldos[Buscando] -= Cantidad;
		cout << "El Retiro se realizo con exito" << endl;
	}
}
