#include "Banco.hpp"

void Banco::TransferirDinero()
{
	int cuentaOrigen, cuentaDestino;
	double monto;
	int indiceOrigen = -1;  
	int indiceDestino = -1; 

	if (CantidadDeCuentas < 2)
	{
		cout << "Se necesitan al menos dos cuentas para realizar una transferencia." << endl;
		return;
	}

	cout << "Ingrese el numero de la cuenta de origen: ";
	cin >> cuentaOrigen;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == cuentaOrigen)
		{
			indiceOrigen = i;
			break;
		}
	}

	if (indiceOrigen == -1)
	{
		cout << "La cuenta de origen no existe." << endl;
		return;
	}

	cout << "Ingrese el numero de la cuenta de destino: ";
	cin >> cuentaDestino;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == cuentaDestino)
		{
			indiceDestino = i;
			break;
		}
	}

	if (indiceDestino == -1)
	{
		cout << "La cuenta de destino no existe." << endl;
		return;
	}

	if (indiceOrigen == indiceDestino)
	{
		cout << "La cuenta de origen y destino no pueden ser la misma." << endl;
		return;
	}

	cout << "Monto a transferir: ";
	cin >> monto;

	if (monto <= 0)
	{
		cout << "Monto no valido. Debe ser mayor que cero." << endl;
		return;
	}

	if (saldos[indiceOrigen] < monto)
	{
		cout << "Saldo insuficiente en la cuenta de origen para realizar la transferencia." << endl;
		return;
	}

	// 6. Ejecutar la transferencia (combinación de Retirar y Depositar)
	saldos[indiceOrigen] -= monto;   // Lógica de RetirarDinero()
	saldos[indiceDestino] += monto;  // Lógica de DepositarDinero()

	cout << "----------------------------------" << endl;
	cout << "Transferencia realizada con exito." << endl;
	cout << "Nuevo saldo en cuenta origen (" << cuentaOrigen << "): " << saldos[indiceOrigen] << endl;
	cout << "Nuevo saldo en cuenta destino (" << cuentaDestino << "): " << saldos[indiceDestino] << endl;
	cout << "----------------------------------" << endl;
}