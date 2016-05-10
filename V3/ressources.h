#include <iostream>

#ifndef RESSOURCES_H
#define RESSOURCES_H

using namespace std;

class Ressources{ //Classe de base de toutes les ressources

public :
    Ressources();
    virtual ~Ressources();

    string nom() const;
    void setNom(const string &nom);

    string auteur() const;
    void setAuteur(const string &auteur);

    string id() const;
    void setId(const string &id);

    string type() const;
    void setType(const string &type);

    virtual void show();

    void list();


protected :
    string _nom;
    string _auteur;
    string _id;
    string _type;
};


#endif // RESSOURCES_H







