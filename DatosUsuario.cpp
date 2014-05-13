#include "DatosUsuario.h" 
using namespace std; 
  
void cargarUsuario(istream & archivo, tDatosUsuario & datosUsuario, string nombre){ 
    datosUsuario.identificador = nombre; 
    cargarListaMensajes(archivo, datosUsuario.ListaMensajes); 
} 
  
void guardarUsuario(ostream & archivo, tDatosUsuario & datosUsuario){ 
    archivo << datosUsuario.identificador << endl; 
    guardarListaMensajes(archivo, datosUsuario.ListaMensajes); 
}
