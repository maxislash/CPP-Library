#include "../Includes/DVD.h"

using namespace std;

DVD::DVD() : VHS(){

}


DVD::~DVD(){

}

string DVD::nPiste() const
{
    return _nPiste;
}

void DVD::setNPiste(const string &nPiste)
{
    _nPiste = nPiste;
}

void DVD::show() {

    VHS::show();
    cout << "Nombre de piste : " << _nPiste << endl;

}
