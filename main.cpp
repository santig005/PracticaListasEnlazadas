#include "Lista.h"

#include <iostream>
using namespace std;
int main(){

    Lista* l = new Lista();
    l->leerArchivo("usuarios.txt");
    int n;
    cout<<"1-Ingresar un nuevo usuario\n2-Buscar usuario\n3-Eliminar Usuario\n4-Mostrar Lista\n5-Salir\n";
    do{
        cin>>n;
        if(n==1){
            string u,p;
            cout<<"Ingrese usuario: ";
            cin>>u;
            cout<<"Ingrese contraseña: ";
            cin>>p;
            l->insertarA(u,p);
        }
        else if(n==2){
            string u,p;
            cout<<"Ingrese usuario: ";
            cin>>u;
            cout<<"Ingrese contraseña: ";
            cin>>p;
            l->buscar(u,p);
        }
        else if(n==3){
            string u,p;
            cout<<"Ingrese usuario: ";
            cin>>u;
            cout<<"Ingrese contraseña: ";
            cin>>p;
            l->trydelete(u,p);
        }
        else if(n==4){
            cout<<"1-Ver usuarios con contraseña oculta\n2-Ver usarios con contraseña visible"<<endl;
            int i;
            cin>>i;
            if(i==1){
                l->mostrarUsers(false);
            }
            else if(i==2){
                l->mostrarUsers(true);
            }
        }
        else if(n==5){}
        else{cout<<"Digite una opcion valida: ";}
    }while(n!=5);
}
