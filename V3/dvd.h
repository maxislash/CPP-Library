#include "VHS.h"

#ifndef DVD_H
#define DVD_H


class DVD : public VHS {

public:
    DVD();
    ~DVD();

    string nPiste() const;
    void setNPiste(const string &nPiste);

    virtual void show();

protected :
    string _nPiste;
};

#endif // DVD_H
