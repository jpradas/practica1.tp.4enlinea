#include "ListaMensajes.h"  
#include <iostream>  
#include <fstream>  
using namespace std;  
    
  
void añadirMensajeFinal(istream & archivo, tListaMensajes & ListaMensajes){  
    cargar(archivo, ListaMensajes.mensajes[ListaMensajes.contador]);  
    ListaMensajes.contador++; 
}  
  
void consultarUltimoElemento(tListaMensajes & ListaMensajes){  
    mostrar(ListaMensajes.mensajes[ListaMensajes.contador - 1]); 
}  
  
void cargarListaMensajes(istream & archivo, tListaMensajes & ListaMensajes){        // Cargamos la lista del txt a memoria  
    ListaMensajes.contador = 0;  
    int num = 0; 
    archivo >> num; 
    while(ListaMensajes.contador < num){ 
        añadirMensajeFinal(archivo, ListaMensajes);         
    } 
}  
  
void guardarListaMensajes(ostream & archivo, tListaMensajes & ListaMensajes){       // Guardamos la lista de memoria a txt  
    archivo << ListaMensajes.contador << endl; 
    int num = 0; 
    while(num < ListaMensajes.contador){  
        guardar(archivo, ListaMensajes.mensajes[num]);  
        num++;  
    }  
}
