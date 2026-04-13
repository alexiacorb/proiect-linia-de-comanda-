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

map<string, int> Reactie::getReactii() const {
    return reactie;
}

void Reactie::setUtilizator(string utilizator) {
    this->utilizator = utilizator;
}

void Reactie::setArticol(Articol *articol) {
    this->articol = articol;
}

void Reactie::setData(Data *data) {
    this->data = data;
}

void Reactie::setReactie(map<string, int> reactie) {
    this->reactie = reactie;
}

std::ostream& operator<<(std::ostream& os, const Reactie& reactie) {
    os << "Utilizator: " << reactie.utilizator << "\n";
    os << "Articol: ";
    if (reactie.articol != nullptr) {
        os << *(reactie.articol) << "\n";
    } else {
        os << "N/A\n";
    }
    os << "Data: ";
    if (reactie.data != nullptr) {
        os << *(reactie.data) << "\n"; 
    } else {
        os << "N/A\n";
    }
    os << "Reactie:\n";
    for (const auto& pair : reactie.reactie) {
        os << pair.first << ": " << pair.second << "\n";
    }
    return os;
}