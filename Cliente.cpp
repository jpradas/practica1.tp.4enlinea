#include "Cliente.h"  
using namespace std;  
//ejemplo de branch    
    
void ejecutarCliente(string identificador,tListaMensajes & ListaMensajes, tListaChats & ListaChats, tListaUsuarios & ListaUsuarios){  
    cargarListaChats(ListaChats,identificador); 
    buzonToChat(ListaChats,ListaMensajes,identificador); 
    MenUsuario(ListaChats, identificador, ListaUsuarios); 
    guardarListaChats(ListaChats); 
}  
  
void MenUsuario(tListaChats & ListaChats, string identificador, tListaUsuarios & ListaUsuarios){ 
    char opcion = ' '; 
    int num; 
    while(opcion != 's'){ 
        system("cls"); 
        mostrarCabeceraUsuario(identificador); 
        mostrarChats(ListaChats); 
        pintarOpciones(); 
        cin.get(opcion); 
        if(opcion == 'c'){ 
            cin >> num; 
            while(num > ListaChats.contador){ 
                cout << "Numero de chat inexistente, introduzca un nuevo valor: "; 
                cin >> num; 
            } 
            int pos = 0; 
            buscarUsuario(ListaUsuarios, ListaChats.chats[num-1].receptor, pos); 
            MenuChat(ListaChats.chats[num-1], ListaUsuarios.usuarios[pos]); 
            ordenarPorFecha(ListaChats); 
        } 
        else if(opcion == 'e'){ 
            cin >> num; 
            EliminarPorPosicion(num, ListaChats); 
        } 
        else if(opcion == 'o'){ 
            cin.get(opcion); 
            cin.get(opcion); 
            if (opcion == 'f'){ 
                ordenarPorFecha(ListaChats); 
            } 
            else if(opcion == 'n'){ 
                ordenarPorNombre(ListaChats); 
            } 
        } 
        else if(opcion == 'n'){ 
            string receptor; 
            int pos = 0; 
            cout << "Nombre de la persona con la que comenzar chat: "; 
            cin >> receptor; 
            if(buscarUsuario(ListaUsuarios, receptor, pos) && !buscarChat(ListaChats, pos, receptor) && (receptor != identificador)){ 
                anadirAlFinal(ListaChats, receptor, identificador); 
            } 
            else{ 
                cout << "No existe el usuario o ya hay chat abierto con el" << endl; 
                system("pause"); 
            } 
        } 
    } 
} 
    
    
void pintarOpciones(){ 
    pintarLineas(); 
    cout << "Entrar al chat N: c N <intro>"  << right << setw(13) <<" "  << "Crear nuevo chat: n <intro>" << endl;  
    cout << "Eliminar el chat N: e N <intro>"  << right << setw(11) <<" "  << "Ordenar chats por nombre: o n <intro>" << endl;  
    cout << "Ordenar chats por fecha: o f <intro>"  << right << setw(6) <<" " << "salir: s <intro>" << endl;  
    pintarLineas(); 
}  
  
void buzonToChat(tListaChats & ListaChats,tListaMensajes & ListaMensajes, string identificador){ 
    int pos=0,contador=0; 
    while(contador < ListaMensajes.contador){ 
        if(buscarChat(ListaChats, pos, ListaMensajes.mensajes[contador].emisor)){ 
            mensajeBuzon(ListaMensajes.mensajes[contador].emisor,identificador,ListaMensajes.mensajes[contador].texto,ListaChats.chats[pos].ListaMensajes.mensajes[ListaChats.chats[pos].ListaMensajes.contador], ListaMensajes.mensajes[contador].fecha); 
            ListaChats.chats[pos].ListaMensajes.contador++; 
            contador++; 
        } 
        else{ 
            NuevoChat(ListaChats, ListaMensajes.mensajes[contador].emisor, identificador, ListaMensajes.mensajes[contador].fecha); 
        } 
    } 
    ListaMensajes.contador = 0; 
}
