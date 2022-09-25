#include "Nodo.h"

Nodo::Nodo(string User, string Pass){
    usname=User;
    passwr=Pass;
    sgte=NULL;
}
string Nodo::getUsname(){
    return usname;
}
string Nodo::getPasswr(){
    return passwr;
}
Nodo* Nodo::getSgte(){
    return sgte;
}
void Nodo::ponerSgte(Nodo* s){
    sgte=s;
}
