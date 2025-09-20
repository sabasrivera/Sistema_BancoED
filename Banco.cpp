#include <iostream>
#include "Banco.hpp"

void Banco::ListarCuentas()
{
	if (CantidadDeCuentas == 0)
	{
		cout << "No hay cuentas registradas" << endl;
		return;
	}else{
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
			
			
		}
		cout << "-----------------------------------\n";
	}

	
}

void Banco::CrearCuenta(int numero, string titular, double saldoInicial)
{
	numerosCuenta[CantidadDeCuentas] = numero;
	saldos[CantidadDeCuentas] = saldoInicial;
	titulares[CantidadDeCuentas] = titular;
	CantidadDeCuentas++;
	cout << "Cuenta creada exitosamente para " << titular
		 << " con numero " << numero
		 << " y saldo inicial: " << saldoInicial << endl;
}

int Banco::OpsionesMenu()
{ 
	cout << "-----Opciones del Menu----" << endl;
	cout << "1. Registrar nueva cuenta bancaria" << endl;
	cout << "2. Depositar dinero" << endl;
	cout << "3. Retirar dinero" << endl;
	cout << "4. Transferir fondos" << endl;
	cout << "5. Consultar saldo" << endl;
	cout << "6. Consultar historial de transacciones" << endl;
	cout << "7. Verificar estado de cuenta" << endl;
	cout << "8. Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> opsion;
	return opsion;
}

void Banco::FinalizarPrograma()
{
	cout << "PROGRAMA FINALIZADO" << endl;
	exit(0);
}

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

void Banco::CondicionMenu()
{ // opsiones elijiendo  del menu
	int numACrear;
	switch (opsion)
	{
	case 1:
		cout << "--------------Registrar Cuenta--------------" << endl;
		cout << "Numero de cuentas a crear: ";
		cin >> numACrear;
		

		for (int i = 0; i < numACrear; i++)
		{
			cout << "Numero de la cuenta: ";
			cin >> numero_cuenta;
			cout << "Nombre del titular de la cuenta: ";
			cin >> nombre_titular;
			cout << "Ingrese el saldo inicial: ";
			cin >> saldo_inicial;

			CrearCuenta(numero_cuenta, nombre_titular, saldo_inicial);
		}
		break;
	case 2:
		//--------------Depositar Dinero--------------
		DepositarDinero();
		break;
	case 3:
		// --------------Retirar Dinero--------------
		RetirarDinero(); // retirando
		break;
	case 4:
		//--------------Transferir Dinero--------------
		TransferirDinero();
		break;
	case 5:
		//--------------Consultar Saldo--------------"
		ListarCuentas();
		break;
	case 6:
		cout << "--------------Historial de Transacciones--------------" << endl;
		// Pendiente de Agregar
		break;
	case 7:
		cout << "--------------Verificar Estado de Cuenta--------------" << endl;
		EstadoDeCuenta();
		break;
	case 8:
		cout << "--------------Programa Finalizado--------------" << endl;
		FinalizarPrograma();
		break;
	default:
		cout << "--------------Opcion invalida--------------" << endl;
		break;
	}
}

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