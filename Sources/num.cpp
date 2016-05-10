#include "../Includes/Num.h"

using namespace std;


Num::Num() : Ressources(){

}



Num::~Num(){

}

string Num::extension() const
{
    return _extension;
}

void Num::setExtension(const string &extension)
{
    _extension = extension;
}



string Num::chemin() const
{
    return _chemin;
}

void Num::setChemin(const string &chemin)
{
    _chemin = chemin;
}

string Num::taille() const
{
    return _taille;
}

void Num::setTaille(const string &taille)
{
    _taille = taille;
}

void Num::show() {

    Ressources::show();
    cout << "Type de fichier : " << _extension << endl;
    cout << "Taille du fichier : " << _taille << endl;
    cout << "Chemin du fichier : " << _chemin << endl;

}
