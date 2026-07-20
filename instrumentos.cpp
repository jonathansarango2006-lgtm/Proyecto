#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include "instrumentos.h"

using namespace std;
void mostrarMenu(){
	cout<<"Sistema de instrumentacion"<<endl;
	cout<<"1.Registrar instrumento\n";
	cout<<"2.Mostrar instrumento\n";
	cout<<"3.Buscar instrumento\n";
	cout<<"4.Prestar instrumento\n";
	cout<<"5.Devolver instrumento\n";
	cout<<"6.Salir del sistema\n";
	
}
string convertirMayusculas(string texto){
	transform(
			  texto.begin(),
			  texto.end(),
			  texto.begin(),
			  ::toupper
				);
	return texto;	  
	
}
bool campoVacio(const std::string & texto){
	return texto.empty();
	
}
bool codigoExiste(const std::string&codigo){
	ifstream archivo("instrumentos.txt");
	string linea;
	string codigoArchivo;
	while(getline(archivo, linea)){
		stringstream datos(linea);
		getline(datos, codigoArchivo, ';');
		
		if(convertirMayusculas(codigoArchivo)== convertirMayusculas(codigo)){
			archivo.close();
			
			return true; 
		}
	}
	archivo.close();
	return false;
	
}
void registrarInstrumento(){
	string codigo,nombre,marca,categoria,estado;
	int anio;
	cout<<"Registrar Instrumento"<<endl;
	cout<<"Codigo: "<<endl;
	getline(cin, codigo);
	if(campoVacio(codigo)){
		cout<<"Error el campo no puede estar vacio"<<endl;
		return;
	}
	codigo = convertirMayusculas(codigo);
	if(codigoExiste(codigo)){
		cout<<"El codigo ya existe"<<endl;
		return;
	}
	cout<<"Nombre: "<<endl;
	getline(cin, nombre);
	if(campoVacio(nombre)){
		cout<<"Error el campo no puede estar vacio"<<endl;
		return;
	}
	cout<<"Marca: "<<endl;
	getline(cin, marca);
	if(campoVacio(marca)){
		cout<<"Error el campo no puede estar vacio"<<endl;
		return;
	}
	cout<<"Categoria: "<<endl;
	getline(cin, categoria);
	if(campoVacio(categoria)){
		cout<<"Error el campo no puede estar vacio"<<endl;
		return;
	}
	
	cout<<"Estado(DISPONIBLE/PRESTADO): "<<endl;
	getline(cin, estado);
	estado = convertirMayusculas(estado);
	if ( estado != "DISPONIBLE" && estado != "PRESTADO"){
		cout<<"Error: estado incorrecto."<<endl;
		return;
	}
	if(campoVacio(estado)){
		cout<<"Error el campo no puede estar vacio"<<endl;
		return;
	}
	cout<<"Año de adquisicion: "<<endl;
	cin>>anio;
	cin.ignore(1000,'\n');
	if(anio<2000 && anio > 2026){
		cout<<"El año debe estar entre 2000 y 2026"<<endl;
		return;
	}
	nombre = convertirMayusculas(nombre);
	marca = convertirMayusculas(marca);
	categoria = convertirMayusculas(categoria);
	ofstream archivo("instrumentos.txt", ios::app);
	if(!archivo.is_open()){
		cout<<"Error al abrir el archivo.";
		return;
	}
	archivo<<codigo<<';'
	<<nombre<<';'
	<<marca<<';'
	<<categoria<<';'
	<<estado<<';'
	<<anio<<"\n";
	archivo.close();
	cout<<"Instrumento registrado correctamente."<<endl;
	
}
void mostrarInstrumento(){
	ifstream archivo("instrumentos.txt");
	if(!archivo.is_open()){
		cout<<"Error al abrir el archivo.";
		return;
	}
	string linea;
	bool existenDisponibles = false;
	cout<<"\n INSTRUMENTOS DISPONIBLES \n";
	while(getline(archivo, linea)){
		stringstream datos(linea);
		string codigo, nombre, marca, categoria, anio, estado;
		getline(datos.codigo, ';');
		getline(datos.nombre, ';');
		getline(datos.marca, ';');
		getline(datos.categoria, ';');
		getline(datos.estado, ';');
		getline(datos.anio, "\n");
		if(convertirMayusculas(estado)== "DISPONIBLE"){
			existenDisponibles = true;
			cout<<"Codigo: "<<codigo<<"\n";
			cout<<"Nombre: "<<convertirMayusculas(nombre)<<"\n";
			cout<<"Marca: "<<convertirMayusculas(marca)<<"\n";
			cout<<"Categoria: "<<convertirMayusculas(categoria)<<"\n";
			cout<<"Estado: "<<convertirMayusculas(estado)<<"\n";
			cout<<"Anio: "<<anio<<"\n";
		}
		if(!existenDisponibles){
			cout<<"No existen instrumentos disponibles";
		}
		archivo.close();
	}
	
}
void buscarInstrumento(){
	ifstream archivo("instrumentos.txt");
	if(!archivo.is_open()){
		cout<<"Error al abrir el archivo";
		return;
	}
	string busqueda;
	cout<<"Ingrese el codigo del instrumento a buscar: ";
	getline(cin, busqueda);
	if((campoVacio(busqueda))){
		cout<<"La busqueda no puede estar vacia.";
		archivo.close();
		return;
	}
	
	busqueda = convertirMayusculas((busqueda));
	string linea;
	bool encontrado = false;
	while(getline(archivo, linea)){
		stringstream datos(linea);
		string nombre;
		string marca;
		string categoria;
		string estado;
		string anio;
		
		getline(datos.codigo);
		getline(datos.nombre);
		getline(datos.marca);
		getline(datos.categoria);
		getline(datos.estado);
		getline(datos.anio);
		
		string nombreMayuscula = convertirMayusculas(nombre);
		if(codigoMayuscula == busqueda || nombreMayuscula.find(busqueda) != string::npos){
			encontrado = true;
			cout<<"Instrumento encontreado"<<endl;
			cout<<"Codigo: "<<codigo<<"\n";
			cout<<"Nombre: "<<nombre<<"\n";
			cout<<"Marca: "<<marca<<"\n";
			cout<<"Categoria: "<<categoria<<"\n";
			cout<<"Estado: "<<estado<<"\n";
			cout<<"Anio: "<<anio<<"\n";
		}
		if(!encontrado){
			cout<<"No se encontro el instrumento"<<endl;
		}
		archivo.close();
	}
}
