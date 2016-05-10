#include "../Includes/livre.h"

using namespace std;

Livre::Livre() : Ressources() {

}

Livre::~Livre(){

}

string Livre::année() const
{
    return _année;
}

void Livre::setAnnée(const string &année)
{
    _année = année;
}

string Livre::résumé() const
{
    return _résumé;
}

void Livre::setRésumé(const string &résumé)
{
    _résumé = résumé;
}

string Livre::nPage() const
{
    return _nPage;
}

void Livre::setNPage(const string &nPage)
{
    _nPage = nPage;
}

void Livre::show() {

    Ressources::show();
    cout << "Année de parution : " << _année << endl;
    cout << "Résumé : " << _résumé << endl;
    cout << "Nombre de page : " << _nPage << endl;

}
