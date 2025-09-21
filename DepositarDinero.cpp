#include "Banco.hpp"


void Banco::DepositarDinero()
{ // para depositar
	int numeroCuentaAdepositar;
	double Cantidad;

	if (CantidadDeCuentas == 0)
	{
		cout << "----------------------------------" << endl;
		cout << "No hay cuentas para depositar" << endl;
		cout << "----------------------------------" << endl;
		return;
	}
	system("cls");
	cout << "--------------Realizar Deposito--------------" << endl;
	cout << "Ingrese el numero de la cuenta a depositar: ";
	cin >> numeroCuentaAdepositar;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == numeroCuentaAdepositar)
		{
			cout << "Monto a depositar: ";
			cin >> Cantidad;
			if (Cantidad <= 0)
			{
				cout << "----------------------------------" << endl;
				cout << "Error: Monto no valido" << endl;
				cout << "----------------------------------" << endl;
				i--;
			}else{
				saldos[i] += Cantidad;
				agregarTransaccion(numeroCuentaAdepositar, 0.0, Cantidad, saldos[i]);
				cout << "----------------------------------" << endl;
				cout << "El Deposito se realizo con exito" << endl;
				cout << "A nombre de: " << titulares[i] << endl;
				cout << "Un monto de L. : " << Cantidad << endl;
				cout << "Nuevo Saldo: L. " << saldos[i] << endl;
				cout << "----------------------------------" << endl;
				break;
			}
			
			
		}else {
				cout << "----------------------------------" << endl;
				cout << "Error: La cuenta no existe" << endl;
				cout << "----------------------------------" << endl;

		}
	}
		
}
