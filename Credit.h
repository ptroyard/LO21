#ifndef CREDIT_H
#define CREDIT_H
#include "include.h"

class Credit {
    Categorie categorie;
    unsigned int nombre;
public :
    Credit(Categorie cat, unsigned int nb) : categorie(cat), nombre(nb){}
    ~Credit(){}
    const Categorie& getcat()const {return categorie;}
    unsigned int getnombre()const {return nombre;}
    void setcat (const Categorie& cat) {categorie=cat;}
    void setnombre (const unsigned int& nb) {nombre=nb;}
};

#endif // CREDIT_H
