#include <ctime>  
#include <iomanip> 
#include "mensaje.h"  
using namespace std;   
      
void mostrarFecha(tFecha fecha){   
    tm* ltm = localtime(&fecha);   
    cout << 1990 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday;   
    cout << ", " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;   
}   
      
void cargar(istream & archivo, tMensaje & mensaje){     
    char c; 
    archivo >> mensaje.emisor;     
    archivo >> mensaje.fecha; 
    archivo.get(c); 
    getline(archivo, mensaje.texto);       
}   
      
void mostrar(tMensaje mensaje){   
    cout << setw(15) << mensaje.emisor << " " << "(";   
    mostrarFecha(mensaje.fecha);   
    cout << "): " << mensaje.texto << endl;     
}   
      
void mensajeNuevo(string emisor, string receptor, string texto, tMensaje & mensaje){   
    mensaje.emisor = emisor; 
    mensaje.receptor = receptor; 
    mensaje.texto = texto; 
    mensaje.fecha = time(0); 
} 
  
void mensajeBuzon(string emisor, string receptor, string texto, tMensaje & mensaje, int fecha){ 
    mensaje.emisor = emisor; 
    mensaje.receptor = receptor; 
    mensaje.texto = texto; 
    mensaje.fecha = fecha; 
} 
    
void guardar(ostream & archivo, tMensaje & mensaje){  
    archivo << mensaje.emisor << " ";  
    archivo << mensaje.fecha << " ";  
    archivo << mensaje.texto << endl;  
}
