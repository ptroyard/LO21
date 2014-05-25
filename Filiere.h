#ifndef FILIERE_H
#define FILIERE_H
#include "include.h"

class Filiere {

    QString nom;
    QString description;
    QString responsable;
    unsigned int duree; //en semestre
    UV** uvform;// Uvs que propose la formation
    Credit* credits;
    //On gère que 102 crédits donc pas les crédits libres mais gérer la différence entre PCB et filière
    Formation& branche;
    unsigned int nbUv;
    unsigned int nbMaxUv;


    public :
        Filiere(const QString& n, const QString& desc, const QString& resp, const unsigned int dur, Credit* cred, Formation& br, unsigned int nb=0,unsigned int nb2=0):
            nom(n), description(desc), responsable(resp), duree(dur), credits(cred), branche(br), nbUv(nb),nbMaxUv(nb2) {}

        const QString getNom() const{return this->nom;}
        const QString getdesc() const {return this->description;}
        const QString getresp() const {return this->responsable;}
        const unsigned int getduree() const {return this->duree;}


        const unsigned int getnbUv() {return this->nbUv;}
        const unsigned int getMaxnbUv() {return this->nbMaxUv;}


        UV* getuvform() {return *this->uvform;}
        Credit getcred() {return *this->credits;}

        void setNom(const QString& n) {nom=n;}
        void setdesc(const QString& d) {description=d;}
        void setresp(const QString& r) {responsable=r;}
        void setduree(const unsigned int d) {duree=d;}


        void setnbUv(const unsigned int nb1) {nbUv=nb1;}
        void setMaxnbUv(const unsigned int nb2) {nbMaxUv=nb2;}


        void ajoutUV(UV* uv); //on incremente le nombre d'UV de 1
        void supprimerUV(UV* uv);//on décrémente le nombre d'UV de 1
        bool trouveUV(const UV& uv);

        void modifierCredit(const Credit* cred);


};


#endif // FILIERE_H
