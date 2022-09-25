#ifndef PROJLISTAS_NODO_H
#define PROJLISTAS_NODO_H
#include <string>
using namespace std;
class Nodo{
protected:
    string usname;
    string passwr;
    Nodo* sgte;
public:
    Nodo(string User, string Pass);
    Nodo(string User, string Pass, Nodo* sgte);
    string getUsname();
    string getPasswr();
    Nodo* getSgte();
    void ponerSgte(Nodo* sgte);

};
#endif //PROJLISTAS_NODO_H