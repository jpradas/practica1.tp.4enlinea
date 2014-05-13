#ifndef LISTACHATS_H  
#define LISTACHATS_H  
    
#include <string> 
#include "Chat.h"
using namespace std;  
    
typedef tChat tChats [10];  
    
typedef struct {  
    tChats chats;  
    int contador;  
} tListaChats;  
    
void cargarListaChats(tListaChats & chats, string id);  
void guardarListaChats(tListaChats chats);  
bool buscarChat(tListaChats & chats, int & pos, string nombre);  
void EliminarPorPosicion(int & pos, tListaChats & chats); 
void moverAlFinal(int & pos, tListaChats & chats);
void ordenarPorNombre(tListaChats & chats);
void ordenarPorFecha(tListaChats & chats);
void mostrarChats(tListaChats & ListaChats);
void NuevoChat(tListaChats & chats, tListaMensajes & ListaMensajes, string identificador);
    
    
#endif
