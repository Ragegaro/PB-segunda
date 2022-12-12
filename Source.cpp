#include <iostream>
#include<string>
#include <fstream>
using namespace std;

void main(), agregar(), modificar(), eliminar(), ver(), manual();//leer(),

struct vg {
	int id;
	string nombre;
	int anio;
	string clas;//clasfificacion
	string genero;
	string caract;// caracteristicas
	string desc; // descripcion
	float precio;
	float piva; //precio con IVA

}juego[10];
bool loopmenu = true;
char op; //opcion de menu
string ler, linea;
int cont = 0;

void main() {
	while (loopmenu == true) {
		system("cls");
		cout << "===       Bienvenido a Rage shop        ===\n";
		cout << "    Escoja la opcion que desea hacer.\n ";
		cout << "    1. Agregar un juego\n ";
		cout << "    2. Modificar los datos de un juego\n ";
		cout << "    3. Eliminar un juego\n ";
		cout << "    4. Ver juegos existentes\n ";
		cout << "    5. Lmpiar la pantalla \n ";
		cout << "    6. Salir del programa \n ";
		cout << "    7. Ver el manual de usuario \n ";
		cin >> op;
		switch (op) {
		case'1': {agregar(); break; }
		case'2': {modificar(); break; }
		case'3': {eliminar(); break; }
		case'4': {ver(); break; }
		case'5': {system("cls"); break; }
		case'6': {loopmenu = false; break; }
		case '7': {manual(); break; }
		default: {
			cout << " Opcion no valida.\n Presione una tecla para continuar e intentar nuevamente\n"; }
			   system("pause>nul");

		}
		system("cls");
	}
		
}

void agregar() {
	
	system("cls");
	system("color 0a");
	ofstream archivo("base de datos.txt", ios::app);
	juego[cont].id++;
	cin.ignore();
	cout << " Ingrese el nombre de su juego:  ";
	getline(cin, juego[cont].nombre);
	cout << "\n Introduzca el anio de lanzamiento del juego:  ";
	cin >>  juego[cont].anio;
	cin.ignore();	
	cout << "\n Introduzca la clasificacion del juego:  ";  
	getline(cin, juego[cont].clas);
	cout << "\n Introduzca el genero principal de su juego:  ";  
	getline(cin, juego[cont].genero);
	cout << "\n Introduzca algunas caracteristicas de su juego separadas por espacios: ";
	cin.ignore();  getline(cin, juego[cont].caract);
	cout << "\n Escriba una breve descripcion de su juego \n ";
	cin.ignore(); getline(cin, juego[cont].desc);
	cout << "\n Establezca un precio a su juego en peso mexicano.    NO INCLUYE IVA ";
	cin >> juego[cont].precio;
	juego[cont].piva = juego[cont].precio * 1.16;
	cout << "\n  Precio: " << "$ " << juego[cont].piva << endl;
	archivo << juego[cont].id << endl;
	archivo << juego[cont].nombre << endl;
	archivo << juego[cont].anio << endl;
	archivo << juego[cont].clas << endl;
	archivo << juego[cont].genero << endl;
	archivo << juego[cont].caract << endl;
	archivo << juego[cont].desc << endl;
	archivo << juego[cont].piva << endl << endl;
	archivo.close();
	cont++;
	system("pause");
}

void modificar() {
	//string ubicacion;
	ver();
	int buscador;
	cout << "ingrese el numero del juego que quiere modificar";
	cin >> buscador;
	//cin.ignore();
	//getline(cin,ubicacion);
	ifstream buscar;
	buscar.open("base de datos.txt");
	while (!buscar.eof()) {
		if (buscador == cont) {
		buscar.close();
			agregar();
		}
	}


	
}
/*void modificar() {
	int buscar;
	int temp=0;
	ver();
	cout << "Ingrese el numero de juego";
	cin >> buscar;
	cin.ignore();
	cout<<"Ingrese los nuevos datos:";
	cout << " Ingrese el nombre de su juego:  ";
	getline(cin, juego[temp].nombre);
	cout << "\n Introduzca el anio de lanzamiento del juego:  ";
	cin >> juego[temp].anio;
	cin.ignore();
	cout << "\n Introduzca la clasificacion del juego:  ";
	getline(cin, juego[temp].clas);
	cout << "\n Introduzca el genero principal de su juego:  ";
	getline(cin, juego[temp].genero);
	cout << "\n Introduzca algunas caracteristicas de su juego separadas por espacios: ";
	cin.ignore();  getline(cin, juego[temp].caract);
	cout << "\n Escriba una breve descripcion de su juego \n ";
	cin.ignore(); getline(cin, juego[temp].desc);
	cout << "\n Establezca un precio a su juego en peso mexicano.    NO INCLUYE IVA ";
	cin >> juego[temp].precio;
	juego[temp].piva = juego[temp].precio * 1.16;
	cout << "\n  Precio: " << "$ " << juego[temp].piva << endl;
	system("pause");
	ifstream archivo("base de datos.txt");
	ofstream archivotemp("base temp.txt");
	while (archivo >> temp) {
		
		if ( cont== buscar){
			juego[cont] = juego[temp];
		}
		archivotemp << juego << endl;
	}
	archivo.close();
	archivotemp.close();
	remove("base de datos.txt");
	rename("base temp.txt", "base de datos.txt");
	cout << "datos modifcados correctamente";
}*/

void eliminar() {
}
void ver() {
	ifstream read;
	system("cls");
	read.open("base de datos.txt", ios::in);
	while (!read.eof()) {
		getline(read, ler);
		cout << ler << endl;
	}
	
	system("pause");
	
	read.close();
}
void manual() {
	system("cls");
	cout << "\n    En esta ocacion estas en la seccion de vendedor, donde podras registrar, modificar, ver y/o eliminar tus juegos\n\n";
	system("pause");
	system("cls");
	cout << "\n   Se pueden agregar algun juego tecleando el numero 1 y presionando enter";
	cout << "\n   En esta opcion te pedira los datos del juego solo asegurate registrar correctamente el tipo de dato.";
	cout << "\n   Es especial el anio de lanzamiento y el precio deben ser numeros.\n\n";
	system("pause");
	system("cls");
	cout << "\n   Se pueden modificar los juegos existente tecleando 2 y presionando enter.";
	cout << "\n   Busque su juego. Y empiece a teclear los nuevos datos del juego\n\n";
	system("pause");
	system("cls");
	cout << "\n   Se puede eliminar algun juego registrado tecleando 3 y presionando enter.";
	cout << "\n   Busque su juego y confirme la eliminacion.\n" << endl;
	system("pause");
	system("cls");
	cout << "\n   Para simplemente buscar un juego si hacer modificaciones es presionando la tecla 4 y presionando enter";
	cout << "\n   Esto mostrara los juegos existentes\n\n";
	system("pause");
	system("cls");
	cout << "\n   En caso de que haya demsiada informacion, Presione 5 para limpiar la pantalla";
	cout << "\n   Y para salir del programa y finalizar la sesion.Presione 6.\n\n";
	system("pause");
	system("cls");
	cout << "\n   Esperamos que la experiencia de este programa sea placentera.";
	cout << "\n   Y agradecemos tu preferencia ya que el programa esta en beta.\n\n";
	system("pause");
	system("cls");
}