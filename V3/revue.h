#include "livre.h"
#include "article.h"
#include <vector>

#ifndef REVUE_H
#define REVUE_H


class Revue : public Livre {

public:
    Revue();
    ~Revue();

    virtual string éditeur() const;
    void setÉditeur(const string &éditeur);

    virtual void show();

    void addArticle(Article* article);
    int getNArticle();
    string getNomArticleI(int i);

protected :
    string _éditeur;
    vector <Article *> _tableauArticle;
    string _nArticle;

};

#endif // REVUE_H
