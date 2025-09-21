#include "Banco.hpp"
using namespace std;

void Banco::ListarCuentas()
{
	if (CantidadDeCuentas == 0)
	{
		cout << "----------------------------------" << endl;
		cout << "No hay cuentas registradas" << endl;
		cout << "----------------------------------" << endl;
		return;
	}
	else
	{
		system("cls");
		cout << "--------------Consultar Saldo--------------" << endl;
		cout << "Numero de cuenta a consultar: ";
		cin >> numero_cuenta;
		for (int i = 0; i < CantidadDeCuentas; i++)
		{
			if (numerosCuenta[i] == numero_cuenta)
			{
				cout << i + 1 << ". Numero de cuenta: " << numerosCuenta[i]
					 << " | Titular: " << titulares[i]
					 << " | Saldo: " << saldos[i] << endl;
			}
			else
			{
				cout << "----------------------------------" << endl;
				cout << "Error: La cuenta no existe" << endl;
				cout << "----------------------------------" << endl;
			}
		}
		cout << "-----------------------------------\n";
	}
}