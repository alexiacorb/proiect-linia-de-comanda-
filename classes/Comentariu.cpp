#include "Comentariu.h"
using namespace std;
Comentariu::Comentariu():data(nullptr),articol(nullptr){}

Comentariu::~Comentariu(){}

Comentariu::Comentariu(string comentariu, string utilizator, Data *data,Articol *articol){
    this->comentariu=comentariu;
    this->utilizator=utilizator;
    this->data=data;
    this->articol=articol;
}

string Comentariu::getComentariu() const {
    return comentariu;
}

string Comentariu::getUtilizator() const{
    return utilizator;
}

Data* Comentariu::getData() const{
    return data;
}

Articol* Comentariu::getArticol() const{
    return articol;
}

ostream & operator <<(ostream &o,const Comentariu &com){
    o << "Comentariu adaugat de " << com.getUtilizator() << " este " << com.getComentariu() << " adaugat in data " << com.getData()->getZi() << "." << com.getData()->getLuna() << "." << com.getData()->getAn();
    return o;
}

