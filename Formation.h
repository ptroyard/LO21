#ifndef FORMATION_H
#define FORMATION_H
#include "include.h"



class Formation {

    QString nom;
    QString description;
    QString responsable;
    unsigned int duree; //en semestre
    bool filiere; // Formation avec fillieres (branches...) ou non (Hutech, TC)
    //UV** uvform;// Uvs que propose la formation
    //Credit* credits;
    //On gère que 102 crédits donc pas les crédits libres mais gérer la différence entre PCB et filière
    //Filiere* tabfil;
    unsigned int nbUv;
    unsigned int nbMaxUv;
    unsigned int nbFi;
    unsigned int nbMaxFi;


    public :
        Formation(const QString& n, const QString& desc, QString& resp, const unsigned int dur, const bool& fil=0, const Credit* cred, unsigned int nb=0,unsigned int nb2=0, unsigned int nb3=0,unsigned int nb4=0):
           nom(n), description(desc), responsable(resp),  duree(dur), filiere(fil), credits(cred), nbUv(nb),nbMaxUv(nb2), nbFi(nb3), nbMaxFi(nb4) {}

        const QString getNom() const{return this->nom;}
        const QString getdesc() const {return this->description;}
        const QString getresp() const {return this->responsable;}
        const unsigned int getduree() const {return this->duree;}
        const bool getFiliere(){return this->filiere;}

        const unsigned int getnbUv() {return this->nbUv;}
        const unsigned int getMaxUv() {return this->nbMaxUv;}
        const unsigned int getnbFi() {return this->nbFi;}
        const unsigned int getMaxFi() {return this->nbMaxFi;}


        //Formation* getTabFil() {return this->tabfil;}
       // UV** getuvform() {return *this->uvform;}
       // Credit* getcred() {return this->credits;}

        void setNom(const QString& n) {nom=n;}
        void setdesc(const QString& d) {description=d;}
        void setresp(const QString& r) {responsable=r;}
        void setduree(const unsigned int d) {duree=d;}
        void setFiliere(const bool f){filiere=f;}

        void setnbUv(const unsigned int nb1) {nbUv=nb1;}
        void setMaxUv(const unsigned int nb2) {nbMaxUv=nb2;}
        void setnbFi(const unsigned int nb3) {nbFi=nb3;}
        void setMaxFi(const unsigned int nb4) {nbMaxFi=nb4;}


        /*void ajoutUV(UV* uv); //on incremente le nombre d'UV de 1
        void supprimerUV(UV* uv);//on décrémente le nombre d'UV de 1
        bool trouveUV(const UV& uv);

        void ajoutFiliere(const QString& n, const QString& d="Non renseginée", const QString& re="Non renseigné", const bool& fi, const unsigned int nb1, const unsigned int nb2);
        void supprimerFiliere (const QString& n, const QString& d="Non renseginée", const QString& re="Non renseigné", const bool& fi, const unsigned int nb1, const unsigned int nb2);
        bool trouveFiliere(const Filiere& fil);

        void modifierCredit(const Credit* cred);*/


};

#endif // FORMATION_H
