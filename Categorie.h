#ifndef CATEGORIE_H
#define CATEGORIE_H
#include "include.h"



class Categorie {
    QString nom;
    //nombre requis par formation
public :
    Categorie (const QString& n): nom(n){}
    const QString& getNom() const {return nom;}
};

#endif // CATEGORIE_H
