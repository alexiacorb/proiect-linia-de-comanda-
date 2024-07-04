#ifndef ARTICOL_H
#define ARTICOL_H
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;

class Articol {
private:
    string titlu;
    string continut;
    string autor;
    Data *data;  

public:
    Articol();
    Articol(string titlu, string continut, string autor, Data* data);
    virtual ~Articol();
    friend ostream& operator <<(ostream &o, const Articol &articol);
    friend istream& operator >>(istream &i, Articol &articol);
    string getTitlu() const;
    string getContinut() const;
    string getAutor() const;
    Data* getData() const;
    void setContinut(string continut_nou){this->continut=continut_nou;};
};

#endif // ARTICOL_H
