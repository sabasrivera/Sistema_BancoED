#include "Banco.hpp"


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
