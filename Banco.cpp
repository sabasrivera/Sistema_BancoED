#include <iostream>
#include "Banco.hpp"

void Banco::ListarCuentas()
{
	if (CantidadDeCuentas == 0)
	{
		cout << "No hay cuentas registradas" << endl;
		return;
	}

	cout << "\n--- LISTA DE CUENTAS REGISTRADAS ---\n";
	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		cout << i + 1 << ". Numero de cuenta: " << numerosCuenta[i]
			 << " | Titular: " << titulares[i]
			 << " | Saldo: " << saldos[i] << endl;
	}
	cout << "-----------------------------------\n";
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
{ // mostrando opsiones del menu

/*
1. Registrar nueva cuenta bancaria
2. Depositar dinero
3. Retirar dinero
4. Transferir fondos
5. Consultar saldo
6. Consultar historial de transacciones
7. Verificar estado de cuenta
8. Salir
Ingrese una opción:
    



cout << "-----OPSIOENES DEL MENU----" << endl;
	cout << "1.DEPOSITAR DINERO" << endl;
	cout << "2.RETIRAR DINERO" << endl;
	cout << "3.VER ESTADO DE CUENTA" << endl;
	cout << "4.HISTORIAL DE TRANSACCIONES" << endl;
	cout << "5.CREAR UNA CUENTA" << endl;
	cout << "6.LISTAR TODAS LAS CUENTAS" << endl;
	cout << "7.FINALIZAR PROGRAMA" << endl;
	cout << "ELIJA UNA OPERACION: ";
	cin >> opsion;
*/


	cout << "-----OPSIOENES DEL MENU----" << endl;
	cout << "1.DEPOSITAR DINERO" << endl;
	cout << "2.RETIRAR DINERO" << endl;
	cout << "3.VER ESTADO DE CUENTA" << endl;
	cout << "4.HISTORIAL DE TRANSACCIONES" << endl;
	cout << "5.CREAR UNA CUENTA" << endl;
	cout << "6.LISTAR TODAS LAS CUENTAS" << endl;
	cout << "7.FINALIZAR PROGRAMA" << endl;
	cout << "ELIJA UNA OPERACION: ";
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
	if (CantidadDeCuentas == 0)
	{
		cout << "No hay cuentas para depositar" << endl;
		return;
	}

	int numeroCuentaAdepositar;
	double Cantidad;
	int Buscando = -1;

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
	if (CantidadDeCuentas == 0)
	{
		cout << "No hay cuentas para retirar" << endl;
		return;
	}

	int numeroCuentaAretirar;
	double Cantidad;
	int Buscando = -1;

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
	if (CantidadDeCuentas == 0)
	{
		cout << "No hay ninguna cuenta." << endl;
		return;
	}

	int findCuenta;
	int indice = -1;

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
	if (opsion == 7)
	{
		cout << "--------------PROGRAMA FINALIZADO--------------" << endl;
		FinalizarPrograma();
	}
	else if (opsion == 1)
	{
		cout << "--------------DEPOSITAR DINERO--------------" << endl;
		DepositarDinero();
	}
	else if (opsion == 2)
	{
		cout << "--------------RETIRAR DINERO--------------" << endl;
		RetirarDinero(); // retirando
	}

	else if (opsion == 3)
	{
		cout << "--------------VER ESTADO DE CUENTA--------------" << endl;
		EstadoDeCuenta();
	}
	else if (opsion == 4)
	{
		cout << "--------------HISTORIAL DE TRANSACCIONES--------------" << endl;
	}
	else if (opsion == 5)
	{
		cout << "--------------REGISTRAR CUENTA--------------" << endl;
		int numACrear;
		cout << "Numero de cuenstas a crear: ";
		cin >> numACrear;

		for (int i = 0; i < numACrear; i++)
		{
			cout << "NUMERO DE LA CUENTA: ";
			cin >> numero_cuenta;
			cout << "NNOMBRE DEL TITULAR: ";
			cin >> nombre_titular;
			cout << "INGRESE EL SALDO INICIAL EN LEMPIRAS: ";
			cin >> saldo_inicial;
			CrearCuenta(numero_cuenta, nombre_titular, saldo_inicial);
		}
	}
	else if (opsion == 6)
	{
		cout << "--------------LISTANDO CUENTAS--------------" << endl;
		cout << endl;
		ListarCuentas();
	}
}
