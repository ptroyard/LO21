#ifndef DOSSIER_H
#define DOSSIER_H
#include "include.h"

class Dossier{

        QString login;
        QString nom;
        QString prenom;
        QString adresseEtu;
        QString nationalite;
        QString dateNaiss;
        Formation* cursusEtu;
        QString semestre;
        Inscription* uvValidees;
        Inscription* uvEnCours;
        Credit* nbCredits;
        Inscription* inscr;
        friend class DossierM;

    public :
        Dossier(const QString& log, const QString& n, const QString& p, const QString& aetu, const QString& nat, const QString& dn, const QString& s):
            login(log), nom(n), prenom(p), adresseEtu(aetu), nationalite(nat), dateNaiss(dn), semestre(s){}
        ~Dossier(){}
        const QString getLogin() const{return this->login;}
        const QString getNom() const{return this->nom;} // Hypothese : Ne se marie pas � l'utc, qu'un seul nom possible
        const QString getPrenom() const{return this->prenom;}
        const QString getDateNaiss() const{return this->dateNaiss;}
        const QString getNationalite() const{return this->nationalite;}
        const QString getAdresseEtu() const{return this->adresseEtu;}
        const QString getSemestre() const{return this->semestre;}
        const Formation* getCursus() const {return *this->cursusEtu;}
        const Inscription* getUVv() const {return *this->uvValidees;}
        const Inscription* getUVec() const {return *this->uvEnCours;}
        const Credit* getnbCredit() const {return *this->nbCredits;}
        const Inscription getinscription() const {return *this->inscr;}



        void setAdresseEtu(const QString& ae){this->adressEtu=ae;}
        void setSemestre(const QString& s){this->adresseEtu=s;}
        void setResultat(const QString* r){
            /*A completer, tq r[i]!=NULL ... if(r[i]={A,B,C,D,E,} ajoutuvvalidee() ajoutcredits()*/}

        void ajoutInscr(Semestre s, const UV* uv, Note res);
        void ajoutcredit(unsigned int credits, QString categorie);
        bool /*A verifier pour bool*/ complete(const UV& exige, const UV& rejet, const UV& pref);
        /*void enregistreSolution(UV** solution);*/




        //void ajoutInscr(semestre s, const UV* uv, Note res);
        //void ajoutcredit(unsigned int credits, QString categorie);
        //bool /*A verifier pour bool*/ complete(const UV& exige, const UV& rejet, const UV& pref);
        /*void enregistreSolution(UV** solution);*/


};

#endif // DOSSIER_H
