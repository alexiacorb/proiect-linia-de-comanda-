#include "Articol.h"
#include <string>
using namespace std;


Articol::Articol(): data(nullptr) {}

Articol::~Articol() {
    delete data;
}

Articol::Articol(string titlu, string continut, string autor, Data* data) {
    this->titlu = titlu;
    this->continut = continut;
    this->autor = autor;
    this->data = data;
}

string Articol::getTitlu() const {
    return titlu;
}

string Articol::getContinut() const {
    return continut;
}

string Articol::getAutor() const {
    return autor;
}

Data* Articol::getData() const {
    return data;
}

ostream& operator <<(ostream &o, const Articol &a) {
    o << "Titlul articolului este " << a.getTitlu()
      << " cu continutul " << a.getContinut()
      << " publicat la data " << a.getData()->getZi() << "/"
      << a.getData()->getLuna() << "/" << a.getData()->getAn()
      << " de utilizatorul " << a.getAutor() << endl;
    return o;
}

istream& operator >>(istream &i, Articol &a) {
    string titlu, continut, autor;
    int zi, luna, an;
    i >> titlu >> continut >> autor >> zi >> luna >> an;
    a.titlu = titlu;
    a.continut = continut;
    a.autor = autor;
    a.data = new Data(zi, luna, an);
    return i;
}
