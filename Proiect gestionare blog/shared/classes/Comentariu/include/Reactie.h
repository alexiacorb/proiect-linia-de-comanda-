#ifndef REACTIE_H
#define REACTIE_H

#include <string>
#include <list>
#include <map>
#include "Articol.h"
#include "Data.h"

using namespace std;

class Reactie
{
    private:
        Articol *articol;
        Data *data;
        string utilizator;
        map<string, int> reactie;    //////        list<string> reactii = {"like", "love", "dislike"};
    public:
        Reactie();
        Reactie(Articol *articol,Data *data, string uilizator, map <string,int> reactie);
        virtual ~Reactie();
        string getUtilizator() const ;
        Articol * getArticol() const;
        Data * getData() const;
};


#endif // REACTIE_H
