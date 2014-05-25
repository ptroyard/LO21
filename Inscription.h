#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include "include.h"



enum Note { A, B, C, D, E, F, FX, RES, ABS, /* en cours */ EC  };
enum Saison { Automne, Printemps };
//inline QTextStream& operator<<(QTextStream& f, const Saison& s) { if (s==Automne) f<<"A"; else f<<"P"; return f;}



class Inscription {
    const UV* uv;
    Semestre semestre;
    Note* resultat;
    //COmment concordent UV avec résultat ?
public:
    Inscription(const UV& u, const Semestre& s, Note* res=EC):uv(&u),semestre(s),resultat(res){}
    const UV& getUV() const { return *uv; }
    Semestre getSemestre() const { return semestre; }
    Note* getResultat() const { return resultat; }
    void setResultat(Note* newres) { resultat=newres; }
};

#endif // INSCRIPTION_H
