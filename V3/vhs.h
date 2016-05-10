#include "ressources.h"

#ifndef VHS_H
#define VHS_H


class VHS : public Ressources {

public:
    VHS();
    ~VHS();

    virtual string prod() const;
    void setProd(const string &prod);

    string durée() const;
    void setDurée(const string &durée);

    virtual void show();

protected :
    string _durée;
    string _prod;

};

#endif // VHS_H
