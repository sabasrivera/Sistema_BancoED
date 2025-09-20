#include "Banco.hpp"
using namespace std;


void Banco::EstadoDeCuenta()
{
	int findCuenta;
	int indice = -1;
	if (CantidadDeCuentas == 0)
	{
		cout << "No hay ninguna cuenta." << endl;
		return;
	}
	cout << "Ingrese el numero de la cuenta para verificarla: ";
	cin >> findCuenta;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == findCuenta)
		{
			indice = i;
			break;
		}
	}
	if (indice == -1)
	{
		cout << "La cuenta no existe" << endl;
		return;
	}
	cout << "--------------------------------" << endl;
	cout << "Titular: " << titulares[indice] << endl;
	cout << "Numero de cuenta: " << numerosCuenta[indice] << endl;
	cout << "Saldo actual: " << saldos[indice] << endl;

	if (saldos[indice] < 0)
	{
		cout << "ADVERTENCIA: El saldo es negativo" << endl;
	}
	cout << "--------------------------------" << endl;
}
