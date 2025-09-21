#ifndef BANCO_HPP
#define BANCO_HPP
#include <iostream>
#include <chrono> // Necesario para la fecha y hora
#include <ctime>  // Necesario para formatear la fecha y hora

using namespace std;


class Banco
{
public:
	private:
		//datos de los duenos de las cuentas 
		int numerosCuenta[100];      
    	double saldos[100];          
    	string titulares[100];       
   		int CantidadDeCuentas = 0;
		struct Transaccion
		{
			string fechaHora;
			int numeroCuenta;
			double debito;
			double credito;
			double saldoResultante;
		};

		Transaccion historial[1000]; 
		int cantidadTransacciones = 0;
		void agregarTransaccion(int numCuenta, double debito, double credito, double saldoRes);

	public:
		int opsion; //pra las opsones menu 

		//para usar en el buble opsion 8
		int numero_cuenta;
		string nombre_titular;
		   int saldo_inicial;
		
	
		//metodos 
		int OpsionesMenu(); //viendo el menu 
		void CondicionMenu(); //hace algo con el menu 
		void FinalizarPrograma(); //finaluzar el programa
		void CrearCuenta();//crear cuentas
		void ListarCuentas(); //para listar cuentas 
		void DepositarDinero(); // deposita
		void RetirarDinero(); //retirar dinero
		void EstadoDeCuenta();
		void HistorialTransacciones();
		void TransferirDinero();


};


class extra{


};
#endif