# 🚀 Blogging System CLI
Un sistem modular de blogging dezvoltat în **C++**, conceput pentru gestionarea articolelor și interacțiunea cu utilizatorii prin intermediul liniei de comandă. Proiectul simulează fluxul complet al unui blog: de la publicarea conținutului până la primirea de reacții și comentarii.

---

## 🚀 Funcționalități Principale

Sistemul este împărțit în două module logice pentru o separare clară a responsabilităților:

### 🛠️ Modulul 1: Administrare (Admin)
Permite controlul total asupra conținutului editorial prin operațiuni de tip CRUD:
* **Creare**: Adăugarea articolelor noi cu titlu, conținut și data postării.
* **Vizualizare**: Citirea unui articol specific sau a întregii liste de postări.
* **Editare**: Modificarea conținutului articolelor deja publicate.
* **Ștergere**: Eliminarea postărilor din sistem.

### 💬 Modulul 2: Interacțiune (Utilizator)
Facilitează engagement-ul cititorilor:
* **Comentarii**: Adăugarea și vizualizarea părerilor utilizatorilor pentru fiecare articol.
* **Reacții**: Sistem de feedback rapid (Love, Like, Dislike) cu incrementare automată a contorului.

---

## 🏗️ Structura Datelor (OOP)

Proiectul utilizează concepte de Programare Orientată pe Obiecte pentru o structură robustă:

* **Clasa Articol**: Gestionează informațiile de bază precum titlu, conținut și data publicării.
* **Clasa Data**: O clasă utilitară pentru manipularea timpului (zi, lună, an).
* **Clasa Comentariu**: Include textul comentariului, utilizatorul, data și asocierea cu articolul.
* **Clasa Reacție**: Gestionează tipurile de reacții și numărul acestora folosind structuri de date de tip map și list.

---

## 💻 Utilizare din Terminal

### 🔧 Administrare (App 1)
* **Vizualizarea tuturor articolelor**: `./app_1.exe vizualizare_articole`
* **Adăugarea unui articol nou**: `./app_1.exe adaugare_articol <titlu> <continut> <zi> <luna> <an>`
* **Editare**: `./app_1.exe editare_articol <titlu> <continut_nou>`
* **Ștergere**: `./app_1.exe stergere_articol <titlu>`

### 🤝 Interacțiune (App 2)
* **Vizualizarea comentariilor**: `./app_2.exe vizualizare_comentarii <titlu>`
* **Adăugarea unui comentariu**: `./app_2.exe adaugare_comentariu <titlu> <text> <utilizator> <data>`
* **Adăugarea unei reacții**: `./app_2.exe adaugare_reactie <titlu> <tip_reactie>`

---

## 📂 Persistența Datelor
Informațiile sunt salvate permanent în fișiere text structurate:

* **postări.txt**: Stochează numărul de articole și detaliile fiecăruia (titlu, conținut, dată).
* **comentarii.txt**: Jurnalul comentariilor organizate pe titluri de articole.
* **reactii.txt**: Evidența reacțiilor și a utilizatorilor care au interacționat.

---

## 🛠️ Instalare și Compilare

1. **Obținerea surselor**: Descarcă și dezarhivează fișierele proiectului.
2. **Compilare Modul Admin**: Rulează comanda `g++ main_admin.cpp -o app_1.exe`
3. **Compilare Modul User**: Rulează comanda `g++ main_user.cpp -o app_2.exe`
4. **Lansare**: Utilizează executabilele generate conform ghidului de utilizare de mai sus.
