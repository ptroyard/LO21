#include "include.h"


bool trouveUV(const UV& uv) {
    for (unsigned int i=0; i<this.getnbUv; i++){
        if (uvform[i].getcode==uv) return 1;}
    return 0;
}


bool ajoutUV(UV* uv){
    if (trouveUV(uv)==1){
        //throw Exception "UV déjà intégrée à la formation";
        cout<<"\nUV déjà intégrée à la formation\n";
        return false;}

    if(nbMaxUV==nbUv){
        UV** tab2 = new UV*[nbMaxUv+10];
        for(unsigned int i=0; i<nbUv; i++)
            tab2[i]=uvform[i];
        UV** temp=uvform;
        uvform=tab2;
        delete[] temp;
        nbMaxUv+=10;
        }
    nbUv++;
    uvform[nbUv]=uv;
    return true;
}

bool supprimerUV(UV* uv){
    if (trouveUV(uv)==0){
        //throw Exception "UV non existante dans la formation";
        cout<<"\nUV non existante dans la formation\n";
        return false;}

    UV** tab2 = new UV*[nbMaxUv];
    for(unsigned int i=0; i<nbUv; i++)
        if (uvform[i]!=uv)
            tab2[i]=uvform[i];
    UV** temp=uvform;
    uvform=tab2;
    delete[] temp;
    nbUv--;
    return true;
}


bool trouveFiliere(const Filiere& fil){
    for (unsigned int i=0; i<this.getTabFil; i++){
        if (tabfil[i].getnom==fil) return 1;}
    return 0;
}

bool ajoutFiliere(const QString& n, const QString& d="Non renseginée", const QString& re="Non renseigné", const bool& fi, const unsigned int nb1, const unsigned int nb2){
    Filiere& filiereajout=Filiere (n, d, re, fil, nb1, nb2);
    if (trouveFiliere(filiereajout)==1){
        //throw Exception "UV déjà intégrée à la formation";
        cout<<"\nUV déjà intégrée à la formation\n";
        return false;}
    if(nbMaxFi==nbFi){
        Filiere** tab2 = new UV*[nbMaxFi+1];
        for(unsigned int i=0; i<nbFi; i++)
            tab2[i]=uvform[i];
        Filiere** temp=tabfil;
        tabfil=tab2;
        delete[] temp;
        nbMaxFi+=1;
        }
    nbFi++;
    tabfil[nbFi]=filiereajout;
    return true;
}



bool supprimerFiliere(const Filiere& Fil){
     if (trouveFiliere(Fil)==0){
        //throw Exception "UV non intégrée à la formation";
        cout<<"\nUV non intégrée à la formation\n";
        return false;}

     Filiere** tab2 = new Filiere*[nbMaxFi];
     for(unsigned int i=0; i<nbFi; i++)
         if (tabfil[i]!=Fil)
             tab2[i]=tabfil[i];
     Filiere** temp=tabfil;
     tabfil=tab2;
     delete[] temp;
     nbFi--;
     return true;
}

void modifierCredit(const Credits* cred){

}




