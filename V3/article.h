#include <iostream>

#ifndef ARTICLE_H
#define ARTICLE_H

using namespace std;

class Article { //Classe Article qui sont contenus dans une revue

public:
    Article();
    virtual ~Article();

    string nomArticle() const;
    void setNomArticle(const string &nomArticle);

    virtual void show();

protected :
    string _nomArticle;
    //string _auteurArticle;

};

#endif // ARTICLE_H
