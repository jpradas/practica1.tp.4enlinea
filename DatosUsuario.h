#ifndef DATOSUSUARIO_H 
#define DATOSUSUARIO_H 
#include "ListaMensajes.h" 
using namespace std; 
  
typedef struct { 
    string identificador; 
    tListaMensajes ListaMensajes; 
} tDatosUsuario; 
  
void cargarUsuario(istream & archivo, tDatosUsuario & datosUsuario, string nombre); 
void guardarUsuario(ostream & archivo, tDatosUsuario & datosUsuario); 
  
#endif
