

#include "Banco.hpp"

void Banco::RetirarDinero()
{ // para depositar
	int numeroCuentaAretirar;
	double Cantidad;

	if (CantidadDeCuentas == 0)
	{
		cout << "----------------------------------" << endl;
		cout << "No hay cuentas para retirar" << endl;
		cout << "----------------------------------" << endl;
		return;
	}
	system("cls");
	cout << "--------------Realizar Retiro--------------" << endl;
	cout << "Ingrese el numero de la cuenta a retiro: ";
	cin >> numeroCuentaAretirar;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == numeroCuentaAretirar)
		{
			cout << "Monto a retirar: ";
			cin >> Cantidad;
			if (Cantidad == 0)
			{
				cout << "----------------------------------" << endl;
				cout << "Error: Monto no valido" << endl;
				cout << "----------------------------------" << endl;
				i--;
			}
			else
			{
				saldos[i] -= Cantidad;
				agregarTransaccion(numeroCuentaAretirar, Cantidad, 0.0, saldos[i]);
				cout << "----------------------------------" << endl;
				cout << "El Retiro se realizo con exito" << endl;
				cout << "A nombre de: " << titulares[i] << endl;
				cout << "Un monto de L. : " << Cantidad << endl;
				cout << "Nuevo Saldo: L. " << saldos[i] << endl;
				cout << "----------------------------------" << endl;
				break;
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
