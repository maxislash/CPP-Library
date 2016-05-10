#include "ressources.h"

#ifndef Num_H
#define Num_H

class Num : public Ressources{

public :
    Num();
    ~Num();

    string extension() const;
    void setExtension(const string &type);

    string chemin() const;
    void setChemin(const string &chemin);

    string taille() const;
    void setTaille(const string &taille);

    virtual void show();

protected :
    string _extension;
    string _taille;
    string _chemin;

};

#endif // Num_H
