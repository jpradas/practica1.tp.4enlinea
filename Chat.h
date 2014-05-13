#ifndef CHAT_H 
#define CHAT_H 
  
#include "DatosUsuario.h" 
#include <iomanip> 
using namespace std; 
  
typedef struct { 
    string receptor; 
    string id; 
    tListaMensajes ListaMensajes; 
} tChat; 
  
void guardarChat(tChat chat, ostream & archivo); 
void cargarChat(tChat & chat, istream & archivo, string id, string nombre); 
void mostrarCabeceraUsuario(string id); 
void mostrarMensajesChat(tChat chat); 
void pintarLineas(); 
void UltimoElemento(tChat chat); 
void MenuChat(tChat & chat, tDatosUsuario & usuario); 
void interfazChat(tChat & chat, string & texto); 
  
#endif
