#include "ressources.h"

#ifndef LIVRE_H
#define LIVRE_H

class Livre : public Ressources{

public :
    Livre();
    ~Livre();

    string année() const;
    void setAnnée(const string &année);

    string résumé() const;
    void setRésumé(const string &résumé);

    string nPage() const;
    void setNPage(const string &nPage);

    virtual void show();

protected :
    string _année;
    string _résumé;
    string _nPage;
};

#endif // LIVRE_H
