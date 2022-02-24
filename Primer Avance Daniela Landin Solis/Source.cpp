#include <iostream>
#include <string>

using namespace std;
int  num_cita = 0, hora, precio_trata, cantidad, precio_unit, total, opcion;
bool repetir = true;
string nombre, primer_apellido, segundo_apellido, tratamiento, descripcion;

void main() {

	do {
		system("cls");
		cout << "Por favor escoga una de las siguientes opciones:" << endl;
		cout << "1) Agendar cita" << endl << "2) Modificar cita" << endl << "3) Eliminar cita" << endl << "4) Lista de citas vigentes" << endl << "5) Limpiar pantalla" << endl << "6) Salir" << endl;
		cin >> opcion;

		switch (opcion)
			{

			case 1:
				cout << "Ingrese su nombre: " << endl;
				cin >> nombre;
				cout << "Ingrese su primer apellido:" << endl;
				cin >> primer_apellido;
				cout << "Ingrese su segundo apellido:" << endl;
				cin >> segundo_apellido;
				cout << "Ingrese la hora del tratamiento (En formato 24 hrs):" << endl;
				cin >> hora;
				cout << "Ingrese el nombre del tratamiento: " << endl;
				cin >> tratamiento;
				cout << "Ingrese la descripcion de su tratamiento: " << endl;
				cin >> descripcion;
				cout << "Ingrese el precio unitario de su tratamiento: " << endl;
				cin >> precio_trata;
				cout << "Ingrese la cantidad de tratamiento que ocupe: " << endl;
				cin >> cantidad;
				cout << "Ingrese el precio unitario: " << endl;
				cin >> precio_unit;
				total = precio_trata + precio_unit;
				cout << "Su cita ha sido dada de alta bajo estos criterios:" << endl;
				num_cita = num_cita + 1;
				cout << "Su numero de cita es: " << num_cita << endl;
				cout << "Su nombre es: " << nombre << " " << primer_apellido << " " << segundo_apellido << endl << "La hora de su tratamiento es: " << hora << endl << "Su tratamiento es: " << tratamiento << endl << "Con la descripcion de: " << descripcion << endl << "Un precio unitario del tratamiento de: " << precio_trata << endl << "Con una cantidad de: " << cantidad << endl << "Un precio unitario de: " << precio_unit << endl << "Y un total de: " << total << endl;
				system("pause>nul");
				break;

			case 2:
				cout << "Esta opcion no esta disponible aun." << endl;
				system("pause>nul");
				break;

			case 3:
				cout << "Esta opcion no esta disponible aun." << endl;
				system("pause>nul");
				break;

			case 4:
				cout << "Esta opcion no esta disponible aun." << endl;
				system("pause>nul");
				break;

			case 5:
				cout << "Esta opcion no esta disponible aun." << endl;
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