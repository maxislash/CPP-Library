#include "../Includes/Revue.h"

using namespace std;


Revue::Revue() : Livre(){

}

Revue::~Revue(){

}

string Revue::éditeur() const
{
    return _éditeur;
}

void Revue::setÉditeur(const string &éditeur)
{
    _éditeur = éditeur;
}


void Revue::show() {

    Livre::show();
    cout << "Editeur : " << _éditeur << endl;
    cout << "Nombre d'article : " << _tableauArticle.size() << endl;

}

void Revue::addArticle(Article* article) {
    _tableauArticle.push_back(article);
}

int Revue::getNArticle() {
    return static_cast<int>(_tableauArticle.size());
}

string Revue::getNomArticleI(int i) {
    return _tableauArticle[i]->nomArticle();
}
