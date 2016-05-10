#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <string>
#include "ressources.h"
#include "livre.h"
#include "cd.h"
#include "article.h"
#include "num.h"
#include "revue.h"
#include "vhs.h"
#include "dvd.h"

using namespace std;

class Mediatheque {

public:
    Mediatheque();
    ~Mediatheque();

    string nomMed() const;
    void setNomMed(const string &nomMed);

    void bye() __attribute__ ((noreturn));
    void help();
    void add(string type);
    void load(string filename);
    void save(string filename);
    void search(string recherche);
    void clear();
    void reset();
    void list();
    void show(string id);
    void deleteId(string id);

protected :
    string _nomMed;
    vector<Ressources *> _baseDonnées; //Base de données de la médiathèque
    vector <Ressources *> _baseRecherche; //Base de recherche courante
};

#endif // MEDIATHEQUE_H
