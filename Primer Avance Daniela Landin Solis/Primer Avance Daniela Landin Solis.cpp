#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

using namespace std;

void main() {
	int  num_cita = 0, hora, precio_trata, cantidad, precio_unit, total, opcion;
	bool repetir = true;
	char nombre[100], tratamiento[100], descripcion[100];

	setlocale(LC_ALL, "spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	do {
		system("cls");
		cout << "Por favor escoga una de las siguientes opciones:" << endl;
		cout << "1) Agendar cita" << endl << "2) Modificar cita" << endl << "3) Eliminar cita" << endl << "4) Lista de citas vigentes" << endl << "5) Limpiar pantalla" << endl << "6) Salir" << endl;
		cin >> opcion;

		switch (opcion)
			{

			case 1:
				cout << "-----------------------------------------------------------" << endl;
				cout << "Ingrese su nombre completo: " << endl;
				cin.ignore(1000, '\n');
				cin.getline(nombre, 99);
				cout << "Ingrese la hora del tratamiento (En formato 24 hrs):" << endl;
				cin >> hora;
				cout << "Ingrese el nombre del tratamiento: " << endl;
				cin.ignore(1000, '\n');
				cin.getline(tratamiento, 99);
				cout << "Ingrese la descripción de su tratamiento: " << endl;
				cin.getline(descripcion, 99);
				cout << "Ingrese el precio unitario de su tratamiento: " << endl;
				cin >> precio_trata;
				cout << "Ingrese la cantidad de tratamiento que ocupe: " << endl;
				cin >> cantidad;
				cout << "Ingrese el precio unitario: " << endl;
				cin >> precio_unit;
				total = precio_trata + precio_unit;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Su cita ha sido dada de alta bajo estos criterios:" << endl;
				num_cita = num_cita + 1;
				cout << "Su número de cita es: " << num_cita << endl;
				cout << "Su nombre es: " << nombre << endl << "La hora de su tratamiento es: " << hora << endl << "Su tratamiento es: " << tratamiento << endl << "Con la descripcion de: " << descripcion << endl << "Un precio unitario del tratamiento de: " << precio_trata << endl << "Con una cantidad de: " << cantidad << endl << "Un precio unitario de: " << precio_unit << endl << "Y un total de: " << total << endl;
				system("pause>nul");
				break;

			case 2:
				cout << "Esta opción no está disponible aún." << endl;
				system("pause>nul");
				break;

			case 3:
				cout << "Esta opción no está disponible aún." << endl;
				system("pause>nul");
				break;

			case 4:
				cout << "Esta opción no está disponible aún." << endl;
				system("pause>nul");
				break;

			case 5:
				cout << "Esta opción no está disponible aún." << endl;
				system("pause>nul");
				break;

			case 6:
				repetir = false;

			default:
				break;
			}
	} while (repetir);

	
	


	system("pause");

}