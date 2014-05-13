#ifndef LISTAMENSAJES_H  
#define LISTAMENSAJES_H  
    
#include "mensaje.h"  
using namespace std;  
    
    
typedef tMensaje tMensajes [50];  
    
typedef struct {  
    tMensajes mensajes;  
    int contador;  
} tListaMensajes;  
     
void añadirMensajeFinal(istream & archivo, tListaMensajes & ListaMensajes);  
void consultarUltimoElemento(tListaMensajes & ListaMensajes);  
void cargarListaMensajes(istream & archivo, tListaMensajes & ListaMensajes); 
void guardarListaMensajes(ostream & archivo, tListaMensajes & ListaMensajes); 
    
#endif
