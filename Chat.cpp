#include "Chat.h" 
using namespace std; 
  
void cargarChat(tChat & chat, istream & archivo, string id, string nombre){ 
    cargarListaMensajes(archivo, chat.ListaMensajes); 
    chat.id = id; 
    chat.receptor = nombre; 
} 
  
void guardarChat(tChat chat, ostream & archivo){ 
    archivo << chat.receptor << endl; 
    guardarListaMensajes(archivo, chat.ListaMensajes); 
} 
  
/*--------------------------------------------------------------------------------- 
                    PARTE DE LA INTERFAZ DE USUARIO                                            */
  
void mostrarCabeceraUsuario(string id){ 
    pintarLineas(); 
    cout << setw(45) << "CHATSAPP version 1.0: Chats de " << id << endl; 
    pintarLineas(); 
} 
  
void UltimoElemento(tChat chat){ 
    consultarUltimoElemento(chat.ListaMensajes); 
    pintarLineas(); 
} 
  
/*-------------------------------------------------------------------------------- 
                    PARTE DE LA INTERFAZ DEL CHAT                                       */
  
void mostrarCabeceraChat(string receptor){ 
    pintarLineas(); 
    cout << setw(45) << "CHAT CON " << receptor << endl; 
    pintarLineas(); 
} 
  
void mostrarMensajesChat(tChat chat){ 
    int i = 0; 
    while(i < chat.ListaMensajes.contador){ 
        mostrar(chat.ListaMensajes.mensajes[i]); 
        i++; 
        pintarLineas(); 
    } 
    pintarLineas(); 
} 
  
void pintarLineas(){ 
    int lineas=0; 
    while (lineas < 80){ 
        cout << char(196); 
        lineas++; 
    } 
} 
  
void MenuChat(tChat & chat, tDatosUsuario & usuario){ 
    string texto; 
    cin.get(); 
    interfazChat(chat, texto); 
    while(texto != "$salir$"){ 
        mensajeNuevo(chat.id, chat.receptor, texto, chat.ListaMensajes.mensajes[chat.ListaMensajes.contador]); 
        chat.ListaMensajes.contador++; 
        mensajeNuevo(chat.id, chat.receptor , texto, usuario.ListaMensajes.mensajes[usuario.ListaMensajes.contador]); 
        usuario.ListaMensajes.contador++; 
        interfazChat(chat, texto); 
    } 
} 
  
void interfazChat(tChat & chat, string & texto){ 
    system("cls"); 
    mostrarCabeceraChat(chat.receptor); 
    mostrarMensajesChat(chat); 
    cout << "Escribe aqui ($salir$ para salir): "; 
    getline(cin,texto); 
}
