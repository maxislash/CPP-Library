#include <iostream>

#ifndef LIBRARY_STRING2_H
#define LIBRARY_STRING2_H

using namespace std;

string découpageLigne(string ligne) { //Découpe la ligne en deux morceaux en fonction du premier séparateur  *=*
    unsigned pos = static_cast<unsigned>(ligne.find(" *=* "));
    unsigned tailleLigne = static_cast<unsigned>(ligne.size());
    string newLigne = ligne.substr(pos+5,tailleLigne-(pos+5));
    return newLigne;
}

string découpageMot(string ligne) { //Découpe le mot d'une ligne avnt le premier séparateur *=*
    unsigned pos = static_cast<unsigned>(ligne.find(" *=* "));
    string mot = ligne.substr(0,pos);
    return mot;
}

bool rechercheString(string chaine, string compare) { //Recherche dans "chaine", le string "compare" sans tenir compte de la casse

    unsigned taille = static_cast<unsigned>(chaine.size());
    string newChaine;
    char c;

    for (unsigned i =0; i < taille; i++) {
        c = static_cast<char>(toupper(chaine[i]));
        newChaine.push_back(c);
    }

    taille = static_cast<unsigned>(compare.size());
    string newCompare;

    for (unsigned i =0; i < taille; i++) {
        c = static_cast<char>(toupper(compare[i]));
        newCompare.push_back(c);
    }

    if(newChaine.find(newCompare) != string::npos)
        return true;
    else
        return false;
}

#endif // LIBRARY_STRING2_H
