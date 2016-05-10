#include "../Includes/VHS.h"

using namespace std;


VHS::VHS() : Ressources(){

}


VHS::~VHS(){

}



string VHS::prod() const
{
    return _prod;
}

void VHS::setProd(const string &prod)
{
    _prod = prod;
}

string VHS::durée() const
{
    return _durée;
}

void VHS::setDurée(const string &durée)
{
    _durée = durée;
}

void VHS::show() {

    Ressources::show();
    cout << "Durée de la VHS : " << _durée << endl;
    cout << "Maison de production : " << _prod << endl;

}
