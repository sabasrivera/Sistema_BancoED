#include "Banco.hpp"
using namespace std;

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
