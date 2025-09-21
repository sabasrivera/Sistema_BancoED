#include "Banco.hpp"
using namespace std;


void Banco::EstadoDeCuenta()
{
	if (CantidadDeCuentas == 0)
	{
		cout << "----------------------------------" << endl;
		cout << "No hay cuentas para retirar" << endl;
		cout << "----------------------------------" << endl;
		return;
	}
	else
	{
		system("cls");
		cout << "--------------Verificar cuenta--------------" << endl;
		cout << "Numero de cuenta a verificar: ";
		cin >> numero_cuenta;
		for (int i = 0; i < CantidadDeCuentas; i++)
		{
			if (numerosCuenta[i] == numero_cuenta)
			{
				cout << "----------------------------------" << endl;
				cout << "Titular: " << titulares[i] << endl;
				cout << "Numero de cuenta: " << numerosCuenta[i] << endl;
				cout << "Saldo actual: " << saldos[i] << endl;
				cout << "----------------------------------" << endl;

				if (saldos[i] < 0)
				{
					cout << "Advertencia: La cuenta esta en negativo" << endl;
					cout << "----------------------------------" << endl;
				}
			}
			else
			{
				cout << "----------------------------------" << endl;
				cout << "Error: La cuenta no existe" << endl;
				cout << "----------------------------------" << endl;
			}
		}
	}
}