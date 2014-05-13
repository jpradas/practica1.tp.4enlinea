#ifndef MENSAJE_H  
#define MENSAJE_H  
    
#include <iostream>   
#include <string>  
#include <fstream>   
using namespace std;  
    
typedef time_t tFecha;   
      
typedef struct {   
    string emisor;   
    string receptor;   
    tFecha fecha;   
    string texto;   
} tMensaje;   
    
void mostrarFecha(tFecha fecha);   
void mensajeNuevo(string emisor, string receptor, string texto, tMensaje & mensaje);   
void mostrar(tMensaje mensaje);   
void cargar(istream & archivo, tMensaje & mensaje);   
void guardar(ostream & archivo, tMensaje & mensaje); 
void mensajeBuzon(string emisor, string receptor, string texto, tMensaje & mensaje, int fecha); 
    
    
#endif
