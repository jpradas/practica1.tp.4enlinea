#include "ListaChats.h"  
using namespace std;   
  
void cargarListaChats(tListaChats & chats, string id){   
    ifstream archivo;   
    archivo.open(id+"_chats.txt");   
    if (archivo.is_open()){ 
        string nombre;   
        chats.contador = 0;   
        archivo >> nombre;   
        while(nombre != "XXX"){   
                cargarChat(chats.chats[chats.contador], archivo, id, nombre);   
                chats.contador++;   
                archivo >> nombre;   
            } 
    } 
    else{ 
        chats.contador = 0; 
    } 
    archivo.close();   
}   
      
void guardarListaChats(tListaChats chats){   
    ofstream archivo;   
    archivo.open(chats.chats[0].id+"_chats.txt");   
    int i = 0;   
    while (i < chats.contador){   
        guardarChat(chats.chats[i], archivo);   
        i++;   
    }   
    archivo << "XXX";   
    archivo.close();   
} 
  
void anadirAlFinal(tListaChats & chats, string receptor, string identificador){ 
    string texto = "Chat iniciado por "+identificador; 
    chats.chats[chats.contador].id = identificador; 
    chats.chats[chats.contador].receptor = receptor; 
    mensajeNuevo(identificador, receptor, texto, chats.chats[chats.contador].ListaMensajes.mensajes[0]); 
    chats.chats[chats.contador].ListaMensajes.contador = 1; 
    chats.contador++; 
} 
  
void NuevoChat(tListaChats & chats, string receptor, string identificador, int fecha){ 
    chats.chats[chats.contador].ListaMensajes.mensajes[0].texto = "Chat iniciado por "+receptor; 
    chats.chats[chats.contador].id = identificador; 
    chats.chats[chats.contador].ListaMensajes.mensajes[0].receptor = identificador; 
    chats.chats[chats.contador].receptor = receptor; 
    chats.chats[chats.contador].ListaMensajes.mensajes[0].emisor = receptor; 
    chats.chats[chats.contador].ListaMensajes.mensajes[0].fecha = fecha; 
    chats.chats[chats.contador].ListaMensajes.contador = 1; 
    chats.contador++; 
} 
      
bool buscarChat(tListaChats & chats, int & pos, string nombre){   
    int i = 0;   
    bool fin = false;   
    while((i < chats.contador) && !fin){   
        if (chats.chats[i].receptor == nombre){   
            pos = i;   
            fin = true;   
        }   
        i++;   
    }   
    return fin; 
}  
    
void EliminarPorPosicion(int & pos, tListaChats & chats){  
    for(int i = pos; i < chats.contador; i++){  
        chats.chats[i-1] = chats.chats[i];  
    }  
    chats.contador--; 
} 
  
void moverAlFinal(int & pos, tListaChats & chats){ 
    tChat tmp; 
    for (int i = pos; i < chats.contador; i++){ 
        tmp = chats.chats[i-1]; 
        chats.chats[i-1] = chats.chats[i]; 
        chats.chats[i] = tmp; 
    } 
} 
  
void ordenarPorNombre(tListaChats & chats){ 
    bool inter = true; 
    int i = 0; 
    while((i < chats.contador - 1) && inter){ 
    inter = false; 
        for(int j = chats.contador - 1;j > i; j--){ 
            if(chats.chats[j].receptor < chats.chats[j-1].receptor){ 
                tChat tmp; 
                tmp = chats.chats[j]; 
                chats.chats[j] = chats.chats[j - 1] ; 
                chats.chats[j - 1] = tmp; 
                inter = true; 
            } 
        } 
        if(inter){ 
            i++; 
        } 
    } 
} 
  
void ordenarPorFecha(tListaChats & chats){ 
    bool inter = true; 
    int i = 0; 
    while((i < chats.contador - 1) && inter){ 
    inter = false; 
        for(int j = chats.contador - 1; j > i; j--){ 
            int h = chats.chats[j].ListaMensajes.contador, y = chats.chats[j-1].ListaMensajes.contador; 
            if(chats.chats[j].ListaMensajes.mensajes[h-1].fecha < chats.chats[j-1].ListaMensajes.mensajes[y-1].fecha){ 
                tChat tmp; 
                tmp = chats.chats[j]; 
                chats.chats[j] = chats.chats[j - 1] ; 
                chats.chats[j - 1] = tmp; 
                inter = true; 
            } 
        } 
        if(inter){ 
            i++; 
        } 
    } 
} 
  
void mostrarChats(tListaChats & ListaChats){ 
    for (int i = 0; i < ListaChats.contador; i++){ 
        cout << i + 1 << ": " << ListaChats.chats[i].receptor << endl; 
        UltimoElemento(ListaChats.chats[i]); 
    } 
} 
