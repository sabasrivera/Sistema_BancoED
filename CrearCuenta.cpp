#include "Banco.hpp"
#include <iostream> 

void Banco::CrearCuenta()
{
	int numACrear;
	system("cls");
	cout << "--------------Registrar Cuenta--------------" << endl;
	cout << "Numero de cuentas a crear: ";
	cin >> numACrear;

	for (int i = 0; i < numACrear; i++)
	{
		bool cuentaExiste;

		do {
			cuentaExiste = false; 
			cout << "\n(" << i + 1 << "/" << numACrear << ") Ingrese el numero de la nueva cuenta: ";
			cin >> numero_cuenta;

			for (int j = 0; j < CantidadDeCuentas; j++)
			{
				if (numerosCuenta[j] == numero_cuenta)
				{
					cout << "----------------------------------" << endl;
					cout << "Error: El numero de cuenta ya existe! Intente otro." << endl;
					cout << "----------------------------------" << endl;
					cuentaExiste = true; 
					break; 
				}
			}
		} while (cuentaExiste); 

		numero_cuenta = numero_cuenta;

		cout << "Nombre del titular de la cuenta: ";
		cin >> nombre_titular;
		cout << "Ingrese el saldo inicial: ";
		cin >> saldo_inicial;

		numerosCuenta[CantidadDeCuentas] = numero_cuenta;
		saldos[CantidadDeCuentas] = saldo_inicial;
		titulares[CantidadDeCuentas] = nombre_titular;
		CantidadDeCuentas++; 

		system("cls");
		cout << "----------------------------------" << endl;
		cout << "Cuenta creada exitosamente para " << nombre_titular << endl;
		cout << "Con numero " << numero_cuenta << endl;
		cout << "Saldo inicial: " << saldo_inicial << endl;
		cout << "----------------------------------" << endl;
	}
}