#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "shared/classes/Articol.h"
#include "shared/classes/Data.h"
#include "shared/classes/Reactie.h"
#include "shared/classes/Comentariu.h"
using namespace std;

vector<Articol*> articol;
vector<Reactie*> reactie;
vector<Comentariu*>comentarii;

void citire_reactii() {
    ifstream fin("shared/files/reactii.txt");
    if (!fin.is_open()) {
        return;
    }

    int nrReactii;
    fin >> nrReactii;
    fin.ignore();

    for (int i = 0; i < nrReactii; ++i) {
        string titlu, autor, utilizator, temp;
        int zi, luna, an, nrLike, nrLove, nrDislike;

        getline(fin, titlu);
        getline(fin, autor);
        getline(fin, utilizator);

        fin >> temp >> nrLike >> temp >> nrLove >> temp >> nrDislike;
        fin.ignore();

        fin >> zi >> luna >> an;
        fin.ignore();

        bool gasit = false;
        Articol* articolCurent = nullptr;
        for (size_t j = 0; j < articol.size(); j++) {
            if (articol[j]->getTitlu() == titlu && articol[j]->getAutor() == autor) {
                articolCurent = articol[j];
                gasit = true;
                break;
            }
        }

        if (!gasit) {
            cout << "Articolul la care se vrea adaugarea reactiei nu a putut fi gasit: " << titlu << " - " << autor << endl;
            continue;
        }

        map<string, int> reactii = {{"like", nrLike}, {"love", nrLove}, {"dislike", nrDislike}};
        Data* data = new Data(zi, luna, an);
        Reactie* reactieNoua = new Reactie(articolCurent, data, utilizator, reactii);
        reactie.push_back(reactieNoua);
    }
    fin.close();
}



void citire_articole() {
    ifstream fin("shared\\files\\postari.txt");
    if (!fin.is_open()) {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }

    int nrArticole;
    fin >> nrArticole;
    fin.ignore();

    for (int i = 0; i < nrArticole; ++i) {
        string titlu, autor, continut;
        int zi, luna, an;
        getline(fin, titlu);
        getline(fin, autor);
        getline(fin, continut);
        fin >> zi >> luna >> an;
        fin.ignore();

        Data* data = new Data(zi, luna, an);
        Articol* articolNou = new Articol(titlu, continut, autor, data);
        articol.push_back(articolNou);
    }

    fin.close();
}

void scriere_fisier() {
    ofstream fout("shared/files/postari.txt");
    if (!fout.is_open()) {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }

    fout << articol.size() << endl;

    for (size_t i = 0; i < articol.size(); i++) {
        fout << articol[i]->getTitlu() << endl;
        fout << articol[i]->getAutor() << endl;
        fout << articol[i]->getContinut() << endl;
        fout << articol[i]->getData()->getZi() << " " << articol[i]->getData()->getLuna() << " " << articol[i]->getData()->getAn() << endl;
    }

    fout.close();
}


void adaugare_articol(string titlu, string autor, string continut, int zi, int luna, int an) {
    for(size_t i = 0; i < articol.size(); i++){
        if(articol[i]->getTitlu()==titlu && articol[i]->getAutor()==autor){
            cout << "Articolul exista deja" << endl;
            return;
        }
    }
    
    Data* data = new Data(zi, luna, an);
    articol.push_back(new Articol(titlu, continut, autor, data));
    scriere_fisier();
    cout<<"Articolul a fost adaugat cu succes";
}

void editare_articol(string titlu, string autor, string continut_nou){
    for(size_t i=0;i<articol.size();i++){
        if(articol[i]->getTitlu()==titlu && articol[i]->getAutor()==autor){
            articol[i]->setContinut(continut_nou);
            cout << "Articol editat cu succes" << endl;
            scriere_fisier();
            return;
        }
    }
    cout << "Articolul nu a fost gasit pentru editare" << endl;
}

void sterge_articol(string titlu) {
    bool gasit = false;
    for (size_t i = 0; i < articol.size(); ++i) {
        if (articol[i]->getTitlu() == titlu ) {
            delete articol[i]; 
            articol.erase(articol.begin() + i); 
            gasit = true;
            cout << "Articolul a fost sters cu succes" << endl;
            break;
        }
    }
    if (!gasit) {
        cout << "Nu s-a gasit articolul cu titlul '" << titlu << endl;
    }
    scriere_fisier();
}

void vizualizare_articole() {
    for (size_t i = 0; i < articol.size(); i++) {
        cout << endl;
        cout << "----------------------Articol " << i << "----------------------------" << endl;
        cout<<"|"<<endl;
        cout << "| Titlu: " << articol[i]->getTitlu() << endl;
        cout << "| Autor: " << articol[i]->getAutor() << endl;
        cout << "| Continut: " << articol[i]->getContinut()<<endl;
        cout << "| Data: " << articol[i]->getData()->getZi() << "/" << articol[i]->getData()->getLuna() << "/" << articol[i]->getData()->getAn() << endl;

        map<string, int> reactii = {{"like", 0}, {"love", 0}, {"dislike", 0}};
        for (size_t j = 0; j < reactie.size(); j++) {
            if (reactie[j]->getArticol()->getTitlu() == articol[i]->getTitlu() && reactie[j]->getArticol()->getAutor() == articol[i]->getAutor()) {
                map<string, int> reactieMap = reactie[j]->getReactii();
                for (auto &r : reactieMap) {
                    reactii[r.first] += r.second;
                }
            }
        }

        cout << "| Reactii:" << endl;
        cout<<"| love"<<": "<<reactii["love"] <<"          "<<"like: " << reactii["like"]<< "            dislike: " << reactii["dislike"] << endl;

        cout<<"|"<<"\033[1;31m"<<" ..   ..   "<<"\033[0m"<< "       \033[1;34m"<<".."<<"\033[0m"<< "       \033[1;33m"<<"           ......"<<"\033[0m"<<"\n"<<
            "|"<<"\033[1;31m"<<".... .... "<<"\033[0m"<< "        \033[1;34m"<<".."<<"\033[0m"<< "       \033[1;33m"<<"           ......"<<"\033[0m"<<"\n"<<
            "|"<<"\033[1;31m"<<" .......  "<<"\033[0m"<< "        \033[1;34m"<<"......"<<"\033[0m"<< "       \033[1;33m"<<"       ......"<<"\033[0m"<<"\n"<<
            "|"<<"\033[1;31m"<<"  .....   "<<"\033[0m"<< "        \033[1;34m"<<"......"<<"\033[0m"<< "       \033[1;33m"<<"       ......"<<"\033[0m"<<"\n"<<
            "|"<<"\033[1;31m"<<"   ...    "<<"\033[0m"<< "        \033[1;34m"<<"......"<<"\033[0m"<< "       \033[1;33m"<<"       .."<<"\033[0m"<<"\n"<<
            "|"<<"\033[1;31m"<<"    .    "<<"\033[0m"<< "        \033[1;34m"<<" ......"<<"\033[0m"<< "       \033[1;33m"<<"       .."<<"\033[0m"<<"\n";
        cout << "------------------------------------------------------------" << endl;
        bool gasitComentarii = false;
        for (size_t k = 0; k < comentarii.size(); ++k) {
            if (comentarii[k]->getArticol()->getTitlu() == articol[i]->getTitlu() && comentarii[k]->getArticol()->getAutor() == articol[i]->getAutor()) {
                cout << "| Comentariu adaugat de " << comentarii[k]->getUtilizator() << ": " << comentarii[k]->getComentariu() << endl;
                cout << "| Data adaugarii: " << comentarii[k]->getData()->getZi() << "." << comentarii[k]->getData()->getLuna() << "." << comentarii[k]->getData()->getAn() << endl;
                gasitComentarii = true;
            }
        }
        if (!gasitComentarii) {
            cout << "| Nu au fost gasite comentarii pentru acest articol." << endl;
        }

        cout << "------------------------------------------------------------" << endl;
    }
}


void citire_comentarii() {
    ifstream fin("shared/files/comentarii.txt");
    if (!fin.is_open()) {
        cout << "Eroare la deschiderea fisierului comentarii.txt" << endl;
        return;
    }

    int nrComentarii;
    fin >> nrComentarii;
    fin.ignore();

    for (int i = 0; i < nrComentarii; ++i) {
        string titlu, autor, utilizator_comentariu, comentariu, temp;
        int zi, luna, an;

        getline(fin, titlu);
        getline(fin, autor);
        getline(fin, utilizator_comentariu);
        getline(fin, comentariu);

        fin >> zi >> luna >> an;
        fin.ignore();

        bool gasit = false;
        Articol* articolCurent = nullptr;
        for (size_t j = 0; j < articol.size(); j++) {
            if (articol[j]->getTitlu() == titlu && articol[j]->getAutor() == autor) {
                articolCurent = articol[j];
                gasit = true;
                break;
            }
        }

        if (!gasit) {
            cout << "Articolul la care se vrea adaugarea comentariului nu a putut fi gasit: " << titlu << " - " << autor << endl;
            continue;
        }

        Data* dataComentariu = new Data(zi, luna, an);
        Comentariu* comentariuNou = new Comentariu(comentariu, utilizator_comentariu, dataComentariu, articolCurent);
        comentarii.push_back(comentariuNou);
    }

    fin.close();
}


int main(int argc, char** argv) {
    citire_articole();
    citire_reactii();
    citire_comentarii();
    
    if (argc == 1) {
        return 0;
    }
    
    if (strcmp(argv[1], "Adaugare articol") == 0) {
        if (argc != 8) {
            cout << "Numar incorect de argumente pentru adaugare articol." << endl;
            return 1;
        }
        string titlu = argv[2];
        string autor = argv[3];
        string continut = argv[4];
        int zi = atoi(argv[5]);
        int luna = atoi(argv[6]);
        int an = atoi(argv[7]);
        adaugare_articol(titlu, autor, continut, zi, luna, an);
    }
    
    if (strcmp(argv[1], "Editare articol") == 0) {
        if (argc != 5) {
            cout << "Numar incorect de argumente pentru editare articol." << endl;
            return 1;
        }
        string titlu = argv[2];
        string autor = argv[3];
        string continut_nou = argv[4];
        editare_articol(titlu,autor,continut_nou);
    }

    if (strcmp(argv[1], "stergere_articol") == 0) {
        if (argc != 3) {
            cout << "Numar incorect de argumente pentru stergere articol." << endl;
            return 1;
        }
        string titlu = argv[2];
        sterge_articol(titlu);
    }
    

    if (strcmp(argv[1], "Vizualizare articole") == 0) {
       if (argc != 2) {
            cout << "Numar incorect de argumente pentru vizualizare articole." << endl;
            return 1;
        }
        vizualizare_articole();
    }
    for (size_t i = 0; i < articol.size(); ++i) {
        delete articol[i];
    }
    articol.clear();    
    return 0;
}
