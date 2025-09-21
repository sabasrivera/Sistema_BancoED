#include "Banco.hpp"

void Banco::TransferirDinero()
{
	int cuentaOrigen, cuentaDestino;
	double cantidad;
	int indiceOrigen = -1;
	int indiceDestino = -1;

	if (CantidadDeCuentas < 2)
	{
		cout << "----------------------------------" << endl;
		cout << "Se necesitan al menos 2 cuentas para poder transferir." << endl;
		cout << "----------------------------------" << endl;
		return;
	}
	system("cls");
	cout << "--------------Realizar Transferencia--------------" << endl;

	// Bucle para validar la cuenta de origen. Se repetirá hasta que se encuentre una válida.
	do {
		cout << "Ingrese el numero de la cuenta de origen: ";
		cin >> cuentaOrigen;

		indiceOrigen = -1; // Reiniciamos por si el usuario se equivocó antes
		for (int i = 0; i < CantidadDeCuentas; i++)
		{
			if (numerosCuenta[i] == cuentaOrigen)
			{
				indiceOrigen = i; // La cuenta es válida, guardamos su índice
				break;
			}
		}

		if (indiceOrigen == -1) // Si el índice no cambió, la cuenta no existe
		{
			cout << "Error: La cuenta de origen no existe. Intente de nuevo." << endl;
		}
	} while (indiceOrigen == -1); // Repetir mientras no se haya encontrado la cuenta

	// Bucle para validar la cuenta de destino.
	do {
		cout << "Ingrese el numero de la cuenta de destino: ";
		cin >> cuentaDestino;
		
		indiceDestino = -1; // Reiniciamos
		for (int j = 0; j < CantidadDeCuentas; j++)
		{
			if (numerosCuenta[j] == cuentaDestino)
			{
				indiceDestino = j; // La cuenta existe
				break;
			}
		}

		if (indiceDestino == -1)
		{
			cout << "Error: La cuenta de destino no existe. Intente de nuevo." << endl;
		}
		else if (indiceDestino == indiceOrigen) // Verificamos que no sea la misma cuenta
		{
			cout << "Error: No puede transferir a la misma cuenta de origen. Intente de nuevo." << endl;
			indiceDestino = -1; // Forzamos a que el bucle se repita
		}
	} while (indiceDestino == -1); // Repetir si la cuenta no se encontró o es la misma que el origen

	// Bucle para validar el monto.
	do {
		cout << "Monto a transferir (Saldo disponible: " << saldos[indiceOrigen] << "): ";
		cin >> cantidad;

		if (cantidad <= 0)
		{
			cout << "Error: El monto debe ser un valor positivo. Intente de nuevo." << endl;
		}
		
	} while (cantidad <= 0 ); // Repetir si el monto es inválido o insuficiente

	saldos[indiceOrigen] -= cantidad;
	saldos[indiceDestino] += cantidad;

	agregarTransaccion(cuentaOrigen, cantidad, 0.0, saldos[indiceOrigen]);
	agregarTransaccion(cuentaDestino, 0.0, cantidad, saldos[indiceDestino]);
	
	cout << "----------------------------------" << endl;
	cout << "Transferencia realizada con exito." << endl;
	cout << "Nuevo saldo en cuenta origen (" << cuentaOrigen << "): " << saldos[indiceOrigen] << endl;
	cout << "Nuevo saldo en cuenta destino (" << cuentaDestino << "): " << saldos[indiceDestino] << endl;
	cout << "----------------------------------" << endl;
}