#include "servidor.h"  
#include <iostream>  
#include <string>  
#include <iomanip>  
using namespace std;  
    
    
    
int main(){  
    tServidor servidor;  
    tListaChats ListaChats;  
    string id;  
    int pos=0;  
    if(!cargarUsuarios(servidor.ListaUsuarios))  
        cout << "Problema al cargar la lista de usuarios" << endl;  
    else{  
        cout << "Introduce tu nombre de usuario : ";  
        cin >> id;  
        while( id != "0" ){  
            if(!buscarUsuario(servidor.ListaUsuarios, id, pos)){  
                cout << "No existe ningún usuario con este nombre" << endl; 
                system("pause"); 
            } 
            else{  
                ejecutarCliente(servidor.ListaUsuarios.usuarios[pos].identificador,servidor.ListaUsuarios.usuarios[pos].ListaMensajes,ListaChats, servidor.ListaUsuarios);  
            }  
            guardarUsuarios(servidor.ListaUsuarios); 
            system("cls");  
            cout << "Introduce tu nombre de usuario : ";  
            cin >> id;  
        }  
    }  
    return 0;  
}
