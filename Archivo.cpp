#include <fstream>
#include "Archivo.h"

void Archivo::AddInFile(string u,string p,string file){
    ofstream archivo;
    archivo.open(file,ios::app);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo<<u+"\n"+p;
    archivo.close();
}
void Archivo::AddInFile2(string s,string file){
    ofstream archivo;
    archivo.open(file,ios::app);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo<<s+"\n";
    archivo.close();
}
void Archivo::Actualizar(string actual){
    ofstream archivo;
    archivo.open("usuarios.txt",ios::out);
    if(archivo.fail()){cout<<"No se pudo abrir el archivo"; exit(1);}
    archivo<<actual;
    archivo.close();
}
bool Archivo::longLastLine(){
    bool hay=false;
    ifstream archivo;
    archivo.open("usuarios.txt", ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){
        string text;
        getline(archivo,text);
        if(text.length()>0){
            hay=true;
        }
    }
    return hay;
    archivo.close();
}