#include "Reactie.h"

Reactie::Reactie(){}

Reactie::~Reactie(){}

Reactie::Reactie(Articol *articol,Data *data, string uilizator, map <string,int> reactie){
    this->articol=articol;
    this->data=data;
    this->utilizator=utilizator;
    this->reactie=reactie;
}

string Reactie::getUtilizator() const{
    return utilizator;
}

Articol* Reactie::getArticol() const{
    return articol;
}

Data* Reactie::getData() const{
    return data;
}
