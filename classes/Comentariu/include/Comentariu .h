#ifndef COMENTARIU _H
#define COMENTARIU _H
#include <string>
#include "D:\Utilizator Windows10\Desktop\Proiect final PP\shared\classes\Articol.h"


class Comentariu
{
    private:
        string comentariu;
        string utilizator;
        Data *data;
        Articol *articol;
    public:
        Comentariu ();
        Comentariu (string comentariu,string utilizator,Data *data,Articol *articol);
        virtual ~Comentariu ();

};

#endif // COMENTARIU _H
