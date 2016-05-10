#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <iostream>
#include <fstream>
#include "../Includes/mediatheque.h"

using namespace std;

class Utilisateur {

public:
    Utilisateur();
    void Add(string type);
    ~Utilisateur();

    void load(string filename);
    void reconnaissanceAction(string action, Mediatheque* currentMed);

    string nomUtilisateur() const;
    void setNomUtilisateur(const string &nomUtilisateur);

    string motPasseAdmin() const;
    void setMotPasseAdmin(const string &motPasseAdmin);

    bool estAdmin() const;
    void setEstAdmin(bool estAdmin);

protected :
    string _nomUtilisateur;
    string _motPasseAdmin;
    bool _estAdmin;

};

#endif // UTILISATEUR_H
