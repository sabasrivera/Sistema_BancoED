#include "Banco.hpp"
#include <iomanip> 


void Banco::agregarTransaccion(int numCuenta, double debito, double credito, double saldoRes)
{
	if (cantidadTransacciones >= 1000)
	{
		cout << "Advertencia: El historial de transacciones está lleno." << endl;
		return;
	}

	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	char buf[20];

	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now_time));

	historial[cantidadTransacciones].fechaHora = buf;
	historial[cantidadTransacciones].numeroCuenta = numCuenta;
	historial[cantidadTransacciones].debito = debito;
	historial[cantidadTransacciones].credito = credito;
	historial[cantidadTransacciones].saldoResultante = saldoRes;

	cantidadTransacciones++;
}

void Banco::HistorialTransacciones()
{
	int numeroCuentaConsulta;
	int indiceCuenta = -1;
	bool transaccionesEncontradas = false;

	if (CantidadDeCuentas == 0)
	{
		cout << "----------------------------------" << endl;
		cout << "No hay cuentas registradas." << endl;
		cout << "----------------------------------" << endl;
		return;
	}

	system("cls");
	cout << "--------------Historial de Transacciones--------------" << endl;
	cout << "Ingrese el numero de la cuenta a consultar: ";
	cin >> numeroCuentaConsulta;

	for (int i = 0; i < CantidadDeCuentas; i++)
	{
		if (numerosCuenta[i] == numeroCuentaConsulta)
		{
			indiceCuenta = i;
			break;
		}
	}

	if (indiceCuenta == -1)
	{
		cout << "----------------------------------" << endl;
		cout << "Error: La cuenta no existe." << endl;
		cout << "----------------------------------" << endl;
		return;
	}

	cout << "\nHistorial para la cuenta No. " << numeroCuentaConsulta << " a nombre de " << titulares[indiceCuenta] << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << left << setw(22) << "Fecha y Hora"
		 << right << setw(15) << "Debito (L.)"
		 << setw(15) << "Credito (L.)"
		 << setw(15) << "Saldo (L.)" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	for (int i = 0; i < cantidadTransacciones; i++)
	{
		if (historial[i].numeroCuenta == numeroCuentaConsulta)
		{
			cout << left << setw(22) << historial[i].fechaHora
				 << right << setw(15) << fixed << setprecision(2) << historial[i].debito
				 << setw(15) << fixed << setprecision(2) << historial[i].credito
				 << setw(15) << fixed << setprecision(2) << historial[i].saldoResultante << endl;
			transaccionesEncontradas = true;
		}
	}

	if (!transaccionesEncontradas)
	{
		cout << "No se encontraron transacciones para esta cuenta." << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;
}
