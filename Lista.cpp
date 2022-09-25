#include "Lista.h"
#include "Nodo.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


void Lista::insertar(string User, string Pass){
    if(primer==NULL){
        primer=new Nodo(User, Pass);
    }
    else{Nodo* ultimo=this->ultimo();
        ultimo->ponerSgte(new Nodo(User, Pass));}

}
void Lista::insertarA(string User, string Pass){
    insertar(User, Pass);
    if(file.longLastLine()==true){
        file.AddInFile2("","usuarios.txt");
    }
    file.AddInFile(User,Pass,"usuarios.txt");
}
Nodo* Lista::ultimo(){
    Nodo* p=primer;
    if(p==NULL) throw "Lista no existe";
    while(p->getSgte()!=NULL){
        p=p->getSgte();
    }

    return p;
}
void Lista::eliminar(string User){
    Nodo* actual=primer;
    Nodo* anterior=NULL;
    bool encontrado=false;
    while(actual!=NULL && !encontrado){
        encontrado=(actual->getUsname()==User);
        if(!encontrado){
            anterior=actual;
            actual=actual->getSgte();
        }
    }
    if(actual!=NULL){
        if(actual==primer){
            primer=primer->getSgte();
        }else{
            anterior->ponerSgte(actual->getSgte());
        }
        delete actual;
    }
}
bool Lista::validar(string User, string Pass){
    Nodo* actual=primer;
    bool encontrado=false;
    while(actual!=NULL && !encontrado){
        encontrado=(actual->getUsname()==User && actual->getPasswr()==Pass);
        if(!encontrado){
            actual=actual->getSgte();
        }
    }
    return encontrado;
}

void Lista::mostrarUsers(bool mostrar){
    Nodo* actual=primer;
    while(actual!=NULL){
        cout<<actual->getUsname()<<" ";
        if(mostrar==true){
            cout<<actual->getPasswr()<<endl;
        }
        else{
            string s=actual->getPasswr();
            for(int i=0;i<s.length();i++){
                cout<<"*";
            }
            cout<<endl;
        }
        actual=actual->getSgte();
    }
}

void Lista::buscar(string User, string Pass){
    if(validar(User, Pass)){
        cout<<"Bienvenido"<<endl;}
    else{
        cout<<"No se encontro el usuario"<<endl;
    }
}
void Lista::trydelete(string User, string Pass){
    if(validar(User, Pass)){
        eliminar(User);
        cout<<"Usuario eliminado"<<endl;
        listaAFile();
    }else{
        cout<<"No se encontro ese usuario"<<endl;
    }
}
void Lista::leerArchivo(string file){
    ifstream archivo;
    archivo.open(file, ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){
        string user;
        string pass;
        getline(archivo, user);
        getline(archivo, pass);
        insertar(user,pass);
    }
    archivo.close();
}
void Lista::listaAFile(){
    Nodo* actual=primer;
    string state="";
    while(actual!=NULL){
        if(actual->getSgte()==NULL){
            state=state+actual->getUsname()+"\n"+actual->getPasswr();
        }
        else{
            state=state+actual->getUsname()+"\n"+actual->getPasswr()+"\n";
        }
        actual=actual->getSgte();
    }
    file.Actualizar(state);
}
