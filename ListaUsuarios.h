#ifndef LISTAUSUARIOS_H 
#define LISTAUSUARIOS_H 
  
#include "DatosUsuario.h" 
using namespace std; 
  
typedef tDatosUsuario tArrayUsuarios [10]; 
  
typedef struct { 
    tArrayUsuarios usuarios; 
    int contador; 
} tListaUsuarios; 
  
bool cargarUsuarios(tListaUsuarios & ListaUsuarios); 
void guardarUsuarios(tListaUsuarios & ListaUsuarios); 
bool buscarUsuario(tListaUsuarios & listaUsuarios, string id, int & pos); 
bool insertarUsuario(tListaUsuarios & ListaUsuarios); 
void ordenarUsuarios(tListaUsuarios & listaUsuarios); 
  
  
#endif
