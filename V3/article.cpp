#include "../Includes/Article.h"

using namespace std;

Article::Article(){

}

Article::~Article(){

}

string Article::nomArticle() const
{
    return _nomArticle;
}

void Article::setNomArticle(const string &nomArticle)
{
    _nomArticle = nomArticle;
}

//string Article::auteurArticle() const
//{
//    return _auteurArticle;
//}

//void Article::setAuteurArticle(const string &auteurArticle)
//{
//    _auteurArticle = auteurArticle;
//}

void Article::show() {

    cout << "Titre de l'article : " << _nomArticle << endl;
     //cout << "Auteur de l'article : " << _auteurArticle << endl;

}
