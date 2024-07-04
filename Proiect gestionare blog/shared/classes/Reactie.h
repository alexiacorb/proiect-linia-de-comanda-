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
        map<string, int> reactie;    
    public:
        Reactie();
        Reactie(Articol *articol,Data *data, string uilizator, map <string,int> reactie);
        virtual ~Reactie();
        string getUtilizator() const ;
        Articol * getArticol() const;
        Data * getData() const;

        map<string, int> getReactii() const;

        void setUtilizator(string utilizator);
        void setArticol(Articol *articol);
        void setData(Data *data);
        void setReactie(map<string, int> reactie);
        friend ostream& operator<<(ostream& os, const Reactie& reactie);

};


#endif // REACTIE_H
