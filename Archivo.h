#ifndef PROJLISTAS_ARCHIVO_H
#define PROJLISTAS_ARCHIVO_H
#include <iostream>
#include <string>
using namespace std;
class Archivo{
public:

    void AddInFile(string u,string p, string archivo);
    void AddInFile2(string s, string archivo);
    void Actualizar(string actual);
    bool longLastLine();
};
#endif PROJLISTAS_ARCHIVO_H