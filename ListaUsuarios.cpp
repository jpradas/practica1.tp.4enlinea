#include "ListaUsuarios.h" 
using namespace std; 
  
bool cargarUsuarios(tListaUsuarios & ListaUsuarios){ 
    string nombre; 
    ifstream archivo; 
    ListaUsuarios.contador = 0; 
    bool bien = true; 
    archivo.open("usuarios.txt"); 
    if (!archivo.is_open()){ 
        bien = false; 
    } 
    else{ 
        archivo >> nombre; 
        while(nombre != "XXX"){ 
            cargarUsuario(archivo, ListaUsuarios.usuarios[ListaUsuarios.contador], nombre); 
            ListaUsuarios.contador++; 
            archivo >> nombre; 
        } 
    } 
    archivo.close(); 
    ordenarUsuarios(ListaUsuarios); 
    return bien; 
} 
  
void guardarUsuarios(tListaUsuarios & ListaUsuarios){ 
    ofstream archivo; 
    archivo.open("usuarios.txt"); 
    int i = 0; 
    while(i < ListaUsuarios.contador){ 
        guardarUsuario(archivo, ListaUsuarios.usuarios[i]); 
        i++; 
    } 
    archivo << "XXX"; 
    archivo.close(); 
} 
  
bool buscarUsuario(tListaUsuarios & listaUsuarios, string id, int & pos){ 
    int ini = 0, fin = listaUsuarios.contador - 1, mitad; 
    bool encontrado = false; 
    while((ini <= fin) && !encontrado){ 
        mitad = (ini + fin) / 2; 
        if(id < listaUsuarios.usuarios[mitad].identificador) fin = mitad -1; 
        else if(listaUsuarios.usuarios[mitad].identificador < id) ini = mitad +1; 
        else encontrado = true; 
    } 
    if(encontrado) pos = mitad; 
    else pos = ini; 
  
    return encontrado; 
} 
  
void ordenarUsuarios(tListaUsuarios & listaUsuarios){  
    tDatosUsuario tmp;  
    int pos;  
    for (int i = 1; i < listaUsuarios.contador; i++){  
        pos = i;  
        while ((pos > 0) && (listaUsuarios.usuarios[pos - 1].identificador > listaUsuarios.usuarios[pos].identificador)){  
            tmp = listaUsuarios.usuarios[pos];  
            listaUsuarios.usuarios[pos] = listaUsuarios.usuarios[pos - 1];  
            listaUsuarios.usuarios[pos - 1] = tmp;  
            pos--;  
        }  
    }  
}
