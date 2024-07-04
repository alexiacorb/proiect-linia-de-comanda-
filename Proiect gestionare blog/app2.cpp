#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "shared/classes/Articol.h"
#include "shared/classes/Reactie.h"
#include "shared/classes/Comentariu.h"
#include "shared/classes/Data.h"

using namespace std;

vector<Articol*> articol;
vector<Reactie*> reactie;
vector<Comentariu*>comentarii;

void citire_articole() {
    ifstream fin("shared/files/postari.txt");
    
    if (!fin.is_open()) {
        cout << "Eroare la deschiderea fisierului postari.txt" << endl;
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



void scriere_fisier() {
    ofstream fout("shared/files/reactii.txt");
    if (!fout.is_open()) {
        cout << "Eroare la deschiderea fisierului reactii.txt" << endl;
        return;
    }

    fout << reactie.size() << endl;
    for (size_t i = 0; i < reactie.size(); ++i) {
        fout << reactie[i]->getArticol()->getTitlu() << endl;
        fout << reactie[i]->getArticol()->getAutor() << endl;
        fout << reactie[i]->getUtilizator() << endl;

        map<string, int> reactii = reactie[i]->getReactii();
        fout << "like: " << reactii["like"] << " ";
        fout << "love: " << reactii["love"] << " ";
        fout << "dislike: " << reactii["dislike"] << endl;

        fout << reactie[i]->getData()->getZi() << " " << reactie[i]->getData()->getLuna() << " " << reactie[i]->getData()->getAn() << endl;
    }
    fout.close();
}



void adaugare_reactie(string titlu, int zi, int luna , int an,string autor, string utilizator, string tipReactie) {
    Articol* articolCurent = nullptr;
    bool gasit = false;
    
    for (size_t i = 0; i < articol.size(); i++) {
        if (articol[i]->getTitlu() == titlu && articol[i]->getAutor() == autor) {
            articolCurent = articol[i];
            gasit = true;
            break;
        }
    }

    if (!gasit) {
        cout << "Articolul la care se vrea adaugarea reactiei nu a putut fi gasit: " << titlu << " - " << autor << endl;
        return;
    }

    if (tipReactie != "like" && tipReactie != "love" && tipReactie != "dislike") {
        cout << "Introduceti o reactie reala" << endl;
        return;
    }

    bool existaReactie = false;
    for (size_t i = 0; i < reactie.size(); i++) {
        if (reactie[i]->getArticol()->getTitlu() == titlu && reactie[i]->getUtilizator() == utilizator) {
            map<string, int> reactii = reactie[i]->getReactii();
            reactii[tipReactie]++;
            reactie[i]->setReactie(reactii);
            existaReactie = true;
            break;
        }
    }

    if (!existaReactie) {
        map<string, int> reactieMap = {{"like", 0}, {"love", 0}, {"dislike", 0}};
        reactieMap[tipReactie]++;
        Data* data = new Data(zi, luna, an); 
        Reactie* reactieNoua = new Reactie(articolCurent, data, utilizator, reactieMap);
        reactie.push_back(reactieNoua);
    }
    cout<<"Reactie adaugata cu succes";
    scriere_fisier();
}

void vizualizare_reactie(string titlu) {
    Articol* articolCurent = nullptr;
    bool gasit = false;

    for (size_t i = 0; i < articol.size(); i++) {
        if (articol[i]->getTitlu() == titlu) {
            articolCurent = articol[i];
            gasit = true;
            break;
        }
    }

    if (!gasit) {
        cout << "Articolul la care se vrea vizualizarea reactiei nu a putut fi gasit: " << endl;
        return;
    }

    else{
    cout<<endl;
    cout << "----------------------" << articolCurent->getTitlu() << "----------------------" << endl;
    cout<<endl;
    for (size_t i = 0; i < reactie.size(); ++i) {
        if (reactie[i]->getArticol()->getTitlu() == titlu) {
            map<string, int> reactii = reactie[i]->getReactii();
            cout << "\033[1;34m like: " << reactii["like"] << "\033[1;0m ";
            cout << "\033[1;31m love: " << reactii["love"] << "\033[1;0m ";
            cout << " \033[1;33m dislike: " << reactii["dislike"] <<" \033[1;0m"<<endl;

            cout << reactie[i]->getData()->getZi() << " " << reactie[i]->getData()->getLuna() << " " << reactie[i]->getData()->getAn() << endl;
        }
    }
    cout<<endl;
    cout << "--------------------------------------------" << endl;
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



void scriere_com(){
    ofstream fout("shared/files/comentarii.txt");
    if (!fout.is_open()) {
        cout << "Eroare la deschiderea fisierului reactii.txt" << endl;
        return;
    }

    fout << comentarii.size() << endl;
    for (size_t i = 0; i < comentarii.size(); ++i) {
        fout << comentarii[i]->getArticol()->getTitlu() << endl;
        fout << comentarii[i]->getArticol()->getAutor() << endl;
        fout << comentarii[i]->getUtilizator() << endl;

        fout <<comentarii[i]->getComentariu()<<endl;

        fout << comentarii[i]->getData()->getZi() << " " << comentarii[i]->getData()->getLuna() << " " << comentarii[i]->getData()->getAn() << endl;
    }
    fout.close();
}


void adaugare_comentariu(string titlu, string autor, string utilizator_comentariu, string comentariu, int zi, int luna, int an) {
    Articol* articolCurent = nullptr;
    bool gasit = false;

    for (size_t i = 0; i < articol.size(); i++) {
        if (articol[i]->getTitlu() == titlu && articol[i]->getAutor() == autor) {
            articolCurent = articol[i];
            gasit = true;
            break;
        }
    }

    if (!gasit) {
        cout << "Articolul la care se vrea adaugarea comentariului nu a putut fi gasit: " << titlu << " - " << autor << endl;
        return;
    }

    Data* dataComentariu = new Data(zi, luna, an);
    Comentariu* comentariuNou = new Comentariu(comentariu, utilizator_comentariu, dataComentariu, articolCurent);
    comentarii.push_back(comentariuNou);

    cout << "Comentariul a fost adaugat cu succes!" << endl;
    scriere_com();
}

void vizualizare_comentarii(string titlu) {
    bool gasit = false;

    for (size_t i = 0; i < articol.size(); ++i) {
        if (articol[i]->getTitlu() == titlu) {
            gasit = true;
            cout << "----------------------\033[1;34m " << articol[i]->getTitlu() << " - " << articol[i]->getAutor() << "\033[0m----------------------" << endl;

            for (size_t j = 0; j < comentarii.size(); ++j) {
                if (comentarii[j]->getArticol()->getTitlu() == titlu) {
                    cout << "Comentariu adaugat de " <<"\033[1;32m"<< comentarii[j]->getUtilizator() << ": \033[0m" << comentarii[j]->getComentariu() << endl;
                    cout << "Data adaugarii: \033[1;35m" << comentarii[j]->getData()->getZi() << "." << comentarii[j]->getData()->getLuna() << "." << comentarii[j]->getData()->getAn() << "\033[0m" << endl;
                    cout << endl;
                }
            }

            break;
        }
    }

    if (!gasit) {
        cout << "Nu au fost gasite comentarii pentru articolul cu titlul: " << titlu << endl;
    }
}




int main(int argc, char** argv) {
    citire_articole();
    citire_reactii();
    citire_comentarii();

    if (argc == 1) {
        return 0;
    }

    if (strcmp(argv[1], "adaugare_reactie") == 0) {
        if (argc != 9) {
            cout << "Argumente insuficiente pentru adaugare_reactie" << endl;
            return 1;
        }
        string titlu = argv[2];
        string autor = argv[3];
        string utilizator = argv[4];
        string tipReactie = argv[5];
        int zi = atoi(argv[6]);
        int luna = atoi(argv[7]);
        int an = atoi(argv[8]);
        adaugare_reactie(titlu, zi, luna, an, autor, utilizator, tipReactie);
    }

    if (strcmp(argv[1], "vizualizare_reactie") == 0) {
        if (argc != 3) {
            cout << "Argumente insuficiente pentru vizualizare_reactie" << endl;
            return 1;
        }
        string titlu = argv[2];
        vizualizare_reactie(titlu);
    }

    if (strcmp(argv[1], "adaugare_comentariu") == 0) {
        if (argc != 9) {
            cout << "Argumente insuficiente pentru adaugare_comentariu" << endl;
            return 1;
        }
        string titlu = argv[2];
        string autor = argv[3];
        string utilizator_comentariu = argv[4];
        string comentariu  = argv[5];
        int zi = atoi(argv[6]);
        int luna = atoi(argv[7]);
        int an = atoi(argv[8]);
        adaugare_comentariu(titlu, autor, utilizator_comentariu, comentariu, zi, luna, an);
    }

    if (strcmp(argv[1], "vizualizare_comentarii") == 0) {
        if (argc != 3) {
            cout << "Argumente insuficiente pentru vizualizare_comentarii" << endl;
            return 1;
        }
        string titlu = argv[2];
        vizualizare_comentarii(titlu);
    }

    for (size_t i = 0; i < articol.size(); ++i) {
        delete articol[i];
    }

    for (size_t i = 0; i < reactie.size(); ++i) {
        delete reactie[i];
    }

    for (size_t i = 0; i < comentarii.size(); ++i) {
        delete comentarii[i];
    }

    articol.clear();
    reactie.clear();
    comentarii.clear();

    return 0;
}
