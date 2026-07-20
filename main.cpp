#include <iostream>
#include "instrumentos.h"
using namespace std;

int main(int argc, char** argv) {
	
	int opcion;
	do{
		mostrarMenu();
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		cin.ignore(1000, '\n');
		switch (opcion) {
		case 1:
			registrarInstrumento();
			break;
		case 2:
			mostrarInstrumento();
			break;
		case 3:
			buscarInstrumento();
			break;
		case 4:
			prestarInstrumento();
			break;
		case 5:
			devolverInstrumentos();
			break;
		case 6:
			cout<<"Saliendo....."<<endl;
			break;
		default:
			cout<<"Opcion invalida"<<endl;
			break;
		}
	}while(opcion != 6 );
	

	
	return 0;
	
}
