#ifndef ARTICOL_H
#define ARTICOL_H
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;
class Articol
{
private:
    string titlu;
    string continut;
    string autor;
    Data *data;   /// vom utiliza relatia de compozitie numita agregare, fiecare articol de pe blog avand o data
    public:
        Articol();
        Articol(string titlu,string continut, string autor, Data* data);
        virtual ~Articol();
        friend ostream& operator <<(ostream &o, const Articol &articol);
        friend istream& operator >>(istream &i,Articol &articol);
        string getTitlu() const;
        string getContinut() const;
        string getAutor() const;
        Data * getData() const;

};


#endif // ARTICOL_H
