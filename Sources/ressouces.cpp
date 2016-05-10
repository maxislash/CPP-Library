#include "../Includes/ressources.h"

using namespace std;

Ressources::Ressources() {
}


Ressources::~Ressources(){

}

string Ressources::nom() const
{
return _nom;
}

void Ressources::setNom(const string &nom)
{
_nom = nom;
}

string Ressources::auteur() const
{
return _auteur;
}

void Ressources::setAuteur(const string &auteur)
{
_auteur = auteur;
}

string Ressources::id() const
{
return _id;
}

void Ressources::setId(const string &id)
{
_id = id;
}

string Ressources::type() const
{
return _type;
}

void Ressources::setType(const string &type)
{
_type = type;
}


void Ressources::show() {

    cout << endl << "Informations sur la ressource : " << _id << endl;
    cout << "Type : " << _type << endl;
    cout << "Titre : " << _nom << endl;
    cout << "Auteur : " << _auteur << endl;

}

void Ressources::list() {
    cout << _id << " \t - \t " << _type << " \t - \t "  << _nom << " \t - \t "  << _auteur << endl;
}
