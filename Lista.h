#ifndef PROJLISTAS_LISTA_H
#define PROJLISTAS_LISTA_H
#include "Archivo.h"
#include "Nodo.h"
#include <string.h>

class Lista{
protected:
    Nodo* primer;
public:
    Lista(){primer=NULL;}
    Archivo file;
    void insertar(string User, string Pass);
    void insertarA(string User, string Pass);
    Nodo* ultimo();
    void eliminar(string User);
    bool validar(string User, string Pass);
    void mostrarUsers(bool mostrar);

    void buscar(string User, string Pass);
    void trydelete(string User, string Pass);
    void listaAFile();
    void leerArchivo(string file);

};
#endif //PROJLISTAS_LISTA_H