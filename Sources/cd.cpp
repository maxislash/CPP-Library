#include "../Includes/cd.h"

using namespace std;

CD::CD() : Ressources(){
    
}


CD::~CD(){

}


string CD::prod() const
{
    return _prod;
}

void CD::setProd(const string &prod)
{
    _prod = prod;
}

string CD::durée() const
{
    return _durée;
}

void CD::setDurée(const string &durée)
{
    _durée = durée;
}

string CD::nPiste() const
{
    return _nPiste;
}

void CD::setNPiste(const string &nPiste)
{
    _nPiste = nPiste;
}

void CD::show() {

    Ressources::show();
    cout << "Durée du CD : " << _durée << endl;
    cout << "Nombre de piste : " << _nPiste << endl;
    cout << "Maison de production : " << _prod << endl;

}
