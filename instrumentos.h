#ifndef INSTRUMENTOS_H
#define INSTRUMENTOS_H
#include <string>

void mostrarMenu();
void registrarInstrumento();
void mostrarInstrumento();
void buscarInstrumento();
void prestarInstrumento();
void devolverInstrumentos();
bool codigoExiste(const std::string&codigo);
std::string convertirMayusculas(std::string texto);
bool campoVacio(const std:: string& texto);



#endif

