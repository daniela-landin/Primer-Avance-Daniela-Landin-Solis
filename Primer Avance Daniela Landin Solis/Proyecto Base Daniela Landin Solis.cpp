#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>

using namespace std;

int opcion;
int i = 0;
int id_cita = 0;
int id_usuario;
char confirmacion_cita;
bool repetir = true;
bool validez_todas;
char limpiar_op;

struct info {
	string correo;
	char hora[100];
	int cantidad;
	string precio_unit;
	int precio_unit_int;
	int id_cita;
	char nombre[100];
	char tratamiento[100];
	char descripcion[100];
	float total;
	float iva;
	float total_iva;
	bool validez;
}datos[50];



void main() {

	ofstream archivo;
	archivo.open("Lista de Citas Vigentes.txt");
	
	
	setlocale(LC_ALL, "spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	for (int a = 0; a < 50; a++) {
		datos[a].validez = false;
	}
	
		do {
			
			system("cls");
			cout << "Por favor escoga una de las siguientes opciones:" << endl;
			cout << "1) Agendar cita" << endl << "2) Modificar cita" << endl << "3) Eliminar cita" << endl << "4) Lista de citas vigentes" << endl << "5) Limpiar pantalla" << endl << "6) Salir" << endl;
			cin >> opcion;

			switch (opcion)
			{

			case 1:
				for (i; i < 50; i++) {
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese su nombre completo: " << endl;
					cin.ignore(100, '\n');
					cin.getline(datos[i].nombre, 99);
					cout << "Ingrese su correo electrónico: " << endl;
					getline(cin, datos[i].correo);
					datos[i].correo.erase(remove(datos[i].correo.begin(), datos[i].correo.end(), ' '), datos[i].correo.end());
					cout << "Ingrese la hora del tratamiento (En formato 24 hrs):" << endl;
					cin.getline(datos[i].hora, 99);
					cout << "Ingrese el nombre del tratamiento: " << endl;
					cin.getline(datos[i].tratamiento, 99);
					cout << "Ingrese el precio unitario de su tratamiento: " << endl;
					getline(cin, datos[i].precio_unit);
					datos[i].precio_unit.resize(remove_if(datos[i].precio_unit.begin(), datos[i].precio_unit.end(), [](char x) {return !isalnum(x) && !isspace(x); }) - datos[i].precio_unit.begin());
					datos[i].precio_unit_int = stoi(datos[i].precio_unit);
					if (datos[i].precio_unit_int > 9999) {
						cout << "Ingrese un numero menor a 5 cifras" << endl;
						system("pause>nul");
						break;
					}
					cout << "Ingrese la descripción de su tratamiento: " << endl;
					cin.getline(datos[i].descripcion, 99);
					cout << "Ingrese la cantidad de tratamiento que ocupe: " << endl;
					cin >> datos[i].cantidad;			
					datos[i].total = datos[i].precio_unit_int * datos[i].cantidad;
					datos[i].iva = datos[i].total * 0.16;
					datos[i].total_iva = datos[i].total + datos[i].iva;
					datos[i].validez = true;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Su cita ha sido dada de alta bajo estos criterios:" << endl;
					id_cita = id_cita + 1;
					datos[i].id_cita = id_cita;
					cout << "Su ID de cita es: " << datos[i].id_cita << endl << "Su nombre es: " << datos[i].nombre << endl << "Su correo es: " << datos[i].correo << endl << "La hora de su tratamiento es: " << datos[i].hora << endl << "Su tratamiento es: " << datos[i].tratamiento << endl << "Con la descripcion de: " << datos[i].descripcion << endl << "Con una cantidad de: " << datos[i].cantidad << endl << "Un precio unitario de: " << datos[i].precio_unit << endl << "Lo que da un subtotal de: " << datos[i].total << endl << "Con un IVA de: " << datos[i].iva << endl << "Y un total con IVA de: " << datos[i].total_iva << endl;
					i = i + 1; 
					system("pause>nul");
					break;
				}

				break;
					
			case 2:
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
					cout << "¿Quiere modificar esta cita?" << endl;
					cout << "Nombre: " << datos[id_usuario].nombre << endl;
					cout << "ID de cita: " << datos[id_usuario].id_cita << endl;
					cout << "Correo: " << datos[id_usuario].correo << endl;
					cout << "Hora: " << datos[id_usuario].hora << endl;
					cout << "Nombre del tratamiento: " << datos[id_usuario].tratamiento << endl;
					cout << "Precio unitario del tratamiento: " << datos[id_usuario].precio_unit_int << endl;
					cout << "Descripción del tratamiento: " << datos[id_usuario].descripcion << endl;
					cout << "Cantidad de tratamiento: " << datos[id_usuario].cantidad << endl;
					cout << "Subtotal: " << datos[id_usuario].total << endl;
					cout << "IVA: " << datos[id_usuario].iva << endl;
					cout << "Total: " << datos[id_usuario].total_iva << endl;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese 'Y' para confirmar, 'N' para negar" << endl;
					cin >> confirmacion_cita;
					if (confirmacion_cita == 'Y' or confirmacion_cita == 'y') {
						cout << "-----------------------------------------------------------" << endl;
						cout << "Ingrese los datos nuevamente" << endl;
						cout << "-----------------------------------------------------------" << endl;
						cout << "Ingrese su nombre completo: " << endl;
						cin.ignore(100, '\n');
						cin.getline(datos[id_usuario].nombre, 99);
						cout << "Ingrese su correo electrónico: " << endl;
						getline(cin, datos[id_usuario].correo);
						datos[id_usuario].correo.erase(remove(datos[id_usuario].correo.begin(), datos[id_usuario].correo.end(), ' '), datos[id_usuario].correo.end());
						cout << "Ingrese la hora del tratamiento (En formato 24 hrs):" << endl;
						cin.getline(datos[id_usuario].hora, 99);
						cout << "Ingrese el nombre del tratamiento: " << endl;
						cin.getline(datos[id_usuario].tratamiento, 99);
						cout << "Ingrese el precio unitario de su tratamiento: " << endl;
						getline(cin, datos[id_usuario].precio_unit);
						datos[id_usuario].precio_unit.resize(remove_if(datos[id_usuario].precio_unit.begin(), datos[id_usuario].precio_unit.end(), [](char x) {return !isalnum(x) && !isspace(x); }) - datos[id_usuario].precio_unit.begin());
						datos[id_usuario].precio_unit_int = stoi(datos[id_usuario].precio_unit);
						if (datos[id_usuario].precio_unit_int > 9999) {
							cout << "Ingrese un numero menor a 5 cifras" << endl;
							system("pause>nul");
							break;
						}
						cout << "Ingrese la descripción de su tratamiento: " << endl;
						cin.getline(datos[id_usuario].descripcion, 99);
						cout << "Ingrese la cantidad de tratamiento que ocupe: " << endl;
						cin >> datos[id_usuario].cantidad;
						datos[id_usuario].total = datos[id_usuario].precio_unit_int * datos[id_usuario].cantidad;
						datos[id_usuario].iva = datos[id_usuario].total * 0.16;
						datos[id_usuario].total_iva = datos[id_usuario].total + datos[id_usuario].iva;
						datos[id_usuario].validez = true;
						cout << "-----------------------------------------------------------" << endl;
						cout << "Su cita ha sido dada de alta bajo estos criterios:" << endl;
						cout << "Su ID de cita es: " << datos[id_usuario].id_cita << endl << "Su nombre es: " << datos[id_usuario].nombre << endl << "Su correo es: " << datos[id_usuario].correo << endl << "La hora de su tratamiento es: " << datos[id_usuario].hora << endl << "Su tratamiento es: " << datos[id_usuario].tratamiento << endl << "Con la descripcion de: " << datos[id_usuario].descripcion << endl << "Con una cantidad de: " << datos[id_usuario].cantidad << endl << "Un precio unitario de: " << datos[id_usuario].precio_unit << endl << "Lo que da un subtotal de: " << datos[id_usuario].total << endl << "Con un IVA de: " << datos[id_usuario].iva << endl << "Y un total con IVA de: " << datos[id_usuario].total_iva << endl;
						system("pause>nul");
						break;
					}
					else if (confirmacion_cita == 'N' or confirmacion_cita == 'n') {
						cout << "No se modificará esa cita" << endl;
						system("pause>nul");
						break;
					}
					else {
						cout << "Ingrese una opción correcta" << endl;
						system("pause>nul");
						break;
					}
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
					cout << "ID de cita: " << datos[id_usuario].id_cita << endl;
					cout << "Correo: " << datos[id_usuario].correo << endl;
					cout << "Hora: " << datos[id_usuario].hora << endl;
					cout << "Nombre del tratamiento: " << datos[id_usuario].tratamiento << endl;
					cout << "Precio unitario del tratamiento: " << datos[id_usuario].precio_unit_int << endl;
					cout << "Descripción del tratamiento: " << datos[id_usuario].descripcion << endl;
					cout << "Cantidad de tratamiento: " << datos[id_usuario].cantidad << endl;
					cout << "Subtotal: " << datos[id_usuario].total << endl;
					cout << "IVA: " << datos[id_usuario].iva << endl;
					cout << "Total: " << datos[id_usuario].total_iva << endl;
					cout << "-----------------------------------------------------------" << endl;
					cout << "Ingrese 'Y' para confirmar, 'N' para negar" << endl;
					cin >> confirmacion_cita;
					if (confirmacion_cita == 'Y') {
						datos[id_usuario].validez = false;
						datos[id_usuario].nombre == "eliminado";
						datos[id_usuario].hora == "eliminado";
						datos[id_usuario].tratamiento == "eliminado";
						datos[id_usuario].descripcion == "eliminado";
						datos[id_usuario].cantidad = 0;
						datos[id_usuario].precio_unit_int = 0;
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

				for ( int j=0; j < 50; j++) {
					if (datos[j].validez == true) {
						cout << "-----------------------------------------------------------" << endl;
						cout << "Nombre: " << datos[j].nombre << endl;
						cout << "ID de cita: " << datos[j].id_cita << endl;
						cout << "Correo: " << datos[j].correo << endl;
						cout << "Hora: " << datos[j].hora << endl;
						cout << "Nombre del tratamiento: " << datos[j].tratamiento << endl;
						cout << "Precio unitario del tratamiento: " << datos[j].precio_unit_int << endl;
						cout << "Descripción del tratamiento: " << datos[j].descripcion << endl;
						cout << "Cantidad de tratamiento: " << datos[j].cantidad << endl;
						cout << "Subtotal: " << datos[j].total << endl;
						cout << "IVA: " << datos[j].iva << endl;
						cout << "Total: " << datos[j].total_iva << endl;
					}
				}
				
			

				system("pause>nul");
				break;

			case 5:
				cout << "-----------------------------------------------------------" << endl;
				cout << "¿Quiere limpiar la pantalla?" << endl << "Ingrese 'Y' para confirmar, 'N' para negar" << endl;
				cin >> limpiar_op;
				if (limpiar_op == 'Y' or limpiar_op == 'y') {
					system("cls");
					system("pause>nul");
					break;
				}
				else if (limpiar_op == 'N' or limpiar_op == 'n') {
					cout << "-----------------------------------------------------------" << endl;
					cout << "No se limpiará la pantalla" << endl;
					system("pause>nul");
					break;
				}
				

			case 6:
				for ( int j=0; j < 50; j++) {
					if (datos[j].validez == true) {
						
						archivo << "----------------------------------------------------------- \n";
						
						archivo << "Nombre: ";
						archivo << datos[j].nombre << endl;
						
						archivo << "ID de cita: ";
						archivo << datos[j].id_cita << endl;
					
						archivo << "Correo: ";
						archivo << datos[j].correo << endl;
					
						archivo << "Hora: ";
						archivo << datos[j].hora << endl;
						
						archivo << "Nombre del tratamiento: ";
						archivo << datos[j].tratamiento << endl;
					
						archivo << "Precio unitario del tratamiento: ";
						archivo << datos[j].precio_unit_int << endl;
						
						archivo << "Descripción del tratamiento: ";
						archivo << datos[j].descripcion << endl;
						
						archivo << "Cantidad de tratamiento : ";
						archivo << datos[j].cantidad << endl;
						
						archivo << "Subtotal ";
						archivo << datos[j].total << endl;
						
						archivo << "IVA: ";
						archivo << datos[j].iva << endl;
						
						archivo << "Total: ";
						archivo << datos[j].total_iva << endl;
					}
				}
				
				archivo.close();
			
				repetir = false;

			default:
				break;
			}
		} while (repetir);



	system("pause");

}