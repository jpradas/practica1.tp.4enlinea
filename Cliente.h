#ifndef CLIENTE_H  
#define CLIENTE_H  
#include <string>  
#include "ListaUsuarios.h"  
#include "ListaChats.h" 
using namespace std;  
    
typedef struct{  
    string id;  
    tListaChats ListaChats;  
}tDatosCliente;  
    
void ejecutarCliente(string identificador,tListaMensajes & ListaMensajes, tListaChats & ListaChats, tListaUsuarios & ListaUsuarios);// 
void pintarOpciones();  
void buzonToChat(tListaChats & ListaChats,tListaMensajes & ListaMensajes, string emisor); 
bool posChat(const tListaChats & ListaChats, string receptor, int & pos); 
void MenUsuario(tListaChats & ListaChats, string identificador, tListaUsuarios & ListaUsuarios); 
  
#endif
