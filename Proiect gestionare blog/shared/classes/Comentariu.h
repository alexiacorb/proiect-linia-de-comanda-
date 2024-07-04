#ifndef COMENTARIU_H
#define COMENTARIU_H
#include <string>
#include "Articol.h"
#include "Data.h"



class Comentariu
{
    private:
        string comentariu;
        string utilizator;
        Data *data;
        Articol *articol;
    public:
        Comentariu();
        Comentariu(string comentariu, string utilizator, Data *data,Articol *articol);
        virtual ~Comentariu();
        string getComentariu() const;
        string getUtilizator() const;
        Data* getData() const;
        Articol* getArticol() const;
        friend ostream & operator <<(ostream &o,const Comentariu &comentariu);
        friend istream & operator >>(istream &i, Comentariu &comentariu);
};

#endif // COMENTARIU_H
