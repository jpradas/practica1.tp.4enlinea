#ifndef SERVIDOR_H   
#define SERVIDOR_H  
#include "ListaUsuarios.h"  
#include "ListaChats.h" 
#include "Cliente.h" 
using namespace std;  
    
typedef struct{  
    tListaUsuarios ListaUsuarios;  
}tServidor;  
    
    
void mostrarPantalla(string id);  
bool enviarMensaje();  
    
#endif
