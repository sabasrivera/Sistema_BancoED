#ifndef BANCO_HPP
#define BANCO_HPP
#include <iostream>

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
		void CrearCuenta(int numero, string titular, double saldoInicial);//crear cuentas
		void ListarCuentas(); //para listar cuentas 
		void DepositarDinero(); // deposita
		void RetirarDinero(); //retirar dinero
		void EstadoDeCuenta();
		void HistorialTransacciones();


};


class extra{


};
#endif