#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

using namespace std;

int opcion;
int i = 0;
int total;
int id_cita = 0;
int id_usuario;
char confirmacion_cita;
bool repetir = true;

struct info {
	int hora;
	int precio_trata;
	int cantidad;
	int precio_unit;
	char nombre[100];
	char tratamiento[100];
	char descripcion[100];
	bool validez;
}datos[3];

void main() {
	
	datos[0].validez = false;
	datos[1].validez = false;
	datos[2].validez = false;
	

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
				for (i; i < 3; i++) {
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese su nombre completo: " << endl;
					cin.ignore(100, '\n');
					cin.getline(datos[i].nombre, 99);
					cout << "Ingrese la hora del tratamiento (En formato 24 hrs):" << endl;
					cin >> datos[i].hora;
					cout << "Ingrese el nombre del tratamiento: " << endl;
					cin.ignore(100, '\n');
					cin.getline(datos[i].tratamiento, 99);
					cout << "Ingrese la descripción de su tratamiento: " << endl;
					cin.getline(datos[i].descripcion, 99);
					cout << "Ingrese el precio unitario de su tratamiento: " << endl;
					cin >> datos[i].precio_trata;
					cout << "Ingrese la cantidad de tratamiento que ocupe: " << endl;
					cin >> datos[i].cantidad;
					cout << "Ingrese el precio unitario: " << endl;
					cin >> datos[i].precio_unit;
					total = datos[i].precio_trata + datos[i].precio_unit;
					datos[i].validez = true;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Su cita ha sido dada de alta bajo estos criterios:" << endl;
					id_cita = id_cita + 1;
					cout << "Su ID de cita es: " << id_cita << endl;
					cout << "Su nombre es: " << datos[i].nombre << endl << "La hora de su tratamiento es: " << datos[i].hora << endl << "Su tratamiento es: " << datos[i].tratamiento << endl << "Con la descripcion de: " << datos[i].descripcion << endl << "Un precio unitario del tratamiento de: " << datos[i].precio_trata << endl << "Con una cantidad de: " << datos[i].cantidad << endl << "Un precio unitario de: " << datos[i].precio_unit << endl << "Y un total de: " << total << endl;
					i = i + 1; 
					system("pause>nul");
					break;
				}

				break;
					
			case 2:
				cout << "Ingrese su ID de cita:" << endl;
				cin >> id_usuario;
				id_usuario = id_usuario - 1;
				cout << "-----------------------------------------------------------" << endl;
				cout << "¿Quiere modificar esta cita?" << endl;
				cout << "Nombre: " << datos[id_usuario].nombre << endl;
				cout << "Hora: " << datos[id_usuario].hora << endl;
				cout << "Nombre del tratamiento: " << datos[id_usuario].tratamiento << endl;
				cout << "Descripción del tratamiento: " << datos[id_usuario].descripcion << endl;
				cout << "Precio unitario del tratamiento: " << datos[id_usuario].precio_trata << endl;
				cout << "Cantidad de tratamiento: " << datos[id_usuario].cantidad << endl;
				cout << "Precio unitario: " << datos[id_usuario].precio_unit << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Ingrese 'Y' para confirmar, 'N' para negar" << endl;
				cin >> confirmacion_cita;
				if (confirmacion_cita == 'Y') {
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese los datos nuevamente" << endl;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese su nombre completo: " << endl;
					cin.ignore(100, '\n');
					cin.getline(datos[id_usuario].nombre, 99);
					cout << "Ingrese la hora del tratamiento (En formato 24 hrs):" << endl;
					cin >> datos[id_usuario].hora;
					cout << "Ingrese el nombre del tratamiento: " << endl;
					cin.ignore(100, '\n');
					cin.getline(datos[id_usuario].tratamiento, 99);
					cout << "Ingrese la descripción de su tratamiento: " << endl;
					cin.getline(datos[id_usuario].descripcion, 99);
					cout << "Ingrese el precio unitario de su tratamiento: " << endl;
					cin >> datos[id_usuario].precio_trata;
					cout << "Ingrese la cantidad de tratamiento que ocupe: " << endl;
					cin >> datos[id_usuario].cantidad;
					cout << "Ingrese el precio unitario: " << endl;
					cin >> datos[id_usuario].precio_unit;
					total = datos[id_usuario].precio_trata + datos[id_usuario].precio_unit;
					datos[id_usuario].validez = true;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Su cita ha sido modificada bajo estos criterios:" << endl;
					cout << "Su ID de cita es: " << id_usuario + 1 << endl;
					cout << "Su nombre es: " << datos[id_usuario].nombre << endl << "La hora de su tratamiento es: " << datos[id_usuario].hora << endl << "Su tratamiento es: " << datos[id_usuario].tratamiento << endl << "Con la descripcion de: " << datos[id_usuario].descripcion << endl << "Un precio unitario del tratamiento de: " << datos[id_usuario].precio_trata << endl << "Con una cantidad de: " << datos[id_usuario].cantidad << endl << "Un precio unitario de: " << datos[id_usuario].precio_unit << endl << "Y un total de: " << total << endl;
					system("pause>nul");
					break;
				}
				else if (confirmacion_cita == 'N') {
					cout << "No se modificará esa cita" << endl;
					system("pause>nul");
					break;
				}
				else {
					cout << "Ingrese una opción correcta" << endl;
					system("pause>nul");
					break;
				}

			case 3:
				cout << "Ingrese su ID de cita:" << endl;
				cin >> id_usuario;
				id_usuario = id_usuario - 1;
				if (datos[id_usuario].validez == false) {
					cout << "Esta cita no existe" << endl;
					system("pause>nul");
					break;
				}
				else {
					cout << "-----------------------------------------------------------" << endl;
					cout << "¿Quiere eliminar esta cita?" << endl;
					cout << "Nombre: " << datos[id_usuario].nombre << endl;
					cout << "Hora: " << datos[id_usuario].hora << endl;
					cout << "Nombre del tratamiento: " << datos[id_usuario].tratamiento << endl;
					cout << "Descripción del tratamiento: " << datos[id_usuario].descripcion << endl;
					cout << "Precio unitario del tratamiento: " << datos[id_usuario].precio_trata << endl;
					cout << "Cantidad de tratamiento: " << datos[id_usuario].cantidad << endl;
					cout << "Precio unitario: " << datos[id_usuario].precio_unit << endl;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese 'Y' para confirmar, 'N' para negar" << endl;
					cin >> confirmacion_cita;
					if (confirmacion_cita == 'Y') {
						datos[id_usuario].validez = false;
						datos[id_usuario].nombre == "eliminado";
						datos[id_usuario].hora = 0;
						datos[id_usuario].tratamiento == "eliminado";
						datos[id_usuario].descripcion == "eliminado";
						datos[id_usuario].precio_trata = 0;
						datos[id_usuario].cantidad = 0;
						datos[id_usuario].precio_unit = 0;
						cout << "-----------------------------------------------------------" << endl;
						cout << "ID de cita eliminada" << endl;
						cout << "-----------------------------------------------------------" << endl;
						system("pause>nul");
						break;
					}
					else if (confirmacion_cita == 'N') {
						cout << "No se eliminará esa cita" << endl;
						system("pause>nul");
						break;
					}
					else {
						cout << "Ingrese una opción correcta" << endl;
						system("pause>nul");
						break;
					}
				}


			case 4:
				for ( int j=0; j < 3; j++) {
					if (datos[j].validez == true) {
						cout << "-----------------------------------------------------------" << endl;
						cout << "Nombre: " << datos[j].nombre << endl;
						cout << "Hora: " << datos[j].hora << endl;
						cout << "Nombre del tratamiento: " << datos[j].tratamiento << endl;
						cout << "Descripción del tratamiento: " << datos[j].descripcion << endl;
						cout << "Precio unitario del tratamiento: " << datos[j].precio_trata << endl;
						cout << "Cantidad de tratamiento: " << datos[j].cantidad << endl;
						cout << "Precio unitario: " << datos[j].precio_unit << endl;
					}
				}

				if (datos[0].validez == false && datos[1].validez == false && datos[2].validez == false) {
					cout << "No hay citas vigentes" << endl;
					}

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