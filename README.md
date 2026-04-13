# 🚀 Blogging System CLI
Un sistem modular de blogging dezvoltat în **C++**, conceput pentru gestionarea articolelor și interacțiunea cu utilizatorii prin intermediul liniei de comandă. Proiectul simulează fluxul complet al unui blog: de la publicarea conținutului până la primirea de reacții și comentarii.

---

## 🚀 Funcționalități Principale

Sistemul este împărțit în două module logice pentru o separare clară a responsabilităților:

### 🛠️ Modulul 1: Administrare (Admin)
Permite controlul total asupra conținutului editorial prin operațiuni de tip **CRUD**:
* **Creare**: Adăugarea articolelor noi cu titlu, conținut și data postării.
* **Vizualizare**: Citirea unui articol specific sau a întregii liste de postări.
* **Editare**: Modificarea conținutului articolelor deja publicate.
* **Ștergere**: Eliminarea postărilor din sistem.

### 💬 Modulul 2: Interacțiune (Utilizator)
Facilitează engagement-ul cititorilor:
* **Comentarii**: Adăugarea și vizualizarea părerilor utilizatorilor pentru fiecare articol.
* **Reacții**: Sistem de feedback rapid (**Love, Like, Dislike**) cu incrementare automată a contorului.

---

## 🏗️ Structura Datelor (OOP)

Proiectul utilizează concepte de Programare Orientată pe Obiecte pentru o structură robustă:

* **Clasa `Articol`**: Gestionează informațiile de bază (Titlu, Conținut, Data).
* **Clasa `Data`**: O clasă utilitară pentru manipularea timpului (Zi, Lună, An).
* **Clasa `Comentariu`**: Face legătura între utilizator și un articol specific.
* **Clasa `Reacție`**: Utilizează `std::map` pentru a contoriza tipurile de reacții primite.

---

## 💻 Utilizare din Terminal

### 🔧 Administrare (App 1)
```bash
# Vizualizarea tuturor articolelor
./app_1.exe vizualizare_articole

# Adăugarea unui articol nou
./app_1.exe adaugare_articol "Titlu" "Continut" zi luna an

# Editarea unui articol
./app_1.exe editare_articol "Titlu" "Continut_Nou"

🤝 Interacțiune (App 2)

# Vizualizarea comentariilor
./app_2.exe vizualizare_comentarii "Titlu_Articol"

# Adăugarea unei reacții
./app_2.exe adaugare_reactie "Titlu_Articol" "love"

Sigur că da! Iată codul sursă complet pentru fișierul README.md. Tot ce trebuie să faci este să copiezi blocul de mai jos (cu tot cu simboluri) și să îl pui într-un fișier nou pe GitHub numit exact README.md.

Markdown
# 🚀 Blogging System CLI
![C++](https://img.shields.io/badge/C++-17-blue.svg) ![License](https://img.shields.io/badge/License-MIT-green.svg)

Un sistem modular de blogging dezvoltat în **C++**, conceput pentru gestionarea articolelor și interacțiunea cu utilizatorii prin intermediul liniei de comandă. Proiectul simulează fluxul complet al unui blog: de la publicarea conținutului până la primirea de reacții și comentarii.

---

## 👤 Autor
* **Corb Alexia-Gabriela**

---

## 🚀 Funcționalități Principale

Sistemul este împărțit în două module logice pentru o separare clară a responsabilităților:

### 🛠️ Modulul 1: Administrare (Admin)
Permite controlul total asupra conținutului editorial prin operațiuni de tip **CRUD**:
* **Creare**: Adăugarea articolelor noi cu titlu, conținut și data postării.
* **Vizualizare**: Citirea unui articol specific sau a întregii liste de postări.
* **Editare**: Modificarea conținutului articolelor deja publicate.
* **Ștergere**: Eliminarea postărilor din sistem.

### 💬 Modulul 2: Interacțiune (Utilizator)
Facilitează engagement-ul cititorilor:
* **Comentarii**: Adăugarea și vizualizarea părerilor utilizatorilor pentru fiecare articol.
* **Reacții**: Sistem de feedback rapid (**Love, Like, Dislike**) cu incrementare automată a contorului.

---

## 🏗️ Structura Datelor (OOP)

Proiectul utilizează concepte de Programare Orientată pe Obiecte pentru o structură robustă:

* **Clasa `Articol`**: Gestionează informațiile de bază (Titlu, Conținut, Data).
* **Clasa `Data`**: O clasă utilitară pentru manipularea timpului (Zi, Lună, An).
* **Clasa `Comentariu`**: Face legătura între utilizator și un articol specific.
* **Clasa `Reacție`**: Utilizează `std::map` pentru a contoriza tipurile de reacții primite.

---

## 💻 Utilizare din Terminal

### 🔧 Administrare (App 1)
```bash
# Vizualizarea tuturor articolelor
./app_1.exe vizualizare_articole

# Adăugarea unui articol nou
./app_1.exe adaugare_articol "Titlu" "Continut" zi luna an

# Editarea unui articol
./app_1.exe editare_articol "Titlu" "Continut_Nou"
🤝 Interacțiune (App 2)
Bash
# Vizualizarea comentariilor
./app_2.exe vizualizare_comentarii "Titlu_Articol"

# Adăugarea unei reacții
./app_2.exe adaugare_reactie "Titlu_Articol" "love"
📂 Persistența Datelor
Informațiile sunt salvate permanent în fișiere text structurate:

postări.txt - Baza de date a articolelor.

comentarii.txt - Jurnalul comentariilor.

reactii.txt - Evidența reacțiilor pe fiecare articol.

🛠️ Instalare și Compilare
Clonează repository-ul.

Compilează codul sursă folosind un compilator C++ (ex: g++):

Bash
g++ main_admin.cpp -o app_1.exe
g++ main_user.cpp -o app_2.exe

### Ce trebuie să faci acum ca să arate profi pe GitHub:
1. Mergi la repository-ul tău pe GitHub.
2. Apasă pe **Add file** -> **Create new file**.
3. Numește fișierul `README.md`.
4. Lipeste codul de mai sus.
5. Apasă pe **Commit changes**.

