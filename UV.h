#ifndef UV_H
#define UV_H
#include "include.h"


class UV {
    QString code;
    QString titre;
    Credit* credits; //une UV peut rapporter des créditss ds plusieurs catégories
    bool automne;
    bool printemps;
    UV(const UV& u);
    UV& operator=(const UV& u);
    UV(const QString& c, const QString& t, bool a, bool p): code(c),titre(t), automne(a),printemps(p){}
    friend class UVManager;
public:
    QString getCode() const { return code; }
    QString getTitre() const { return titre; }
    Credit* getCredit() const {return credits;}

    bool ouvertureAutomne() const { return automne; }
    bool ouverturePrintemps() const { return printemps; }
    void setCode(const QString& c) { code=c; }
    void setTitre(const QString& t) { titre=t; }
    void setNbCredits(const Credit* cred) {credits=cred;}
    void setOuvertureAutomne(bool b) { automne=b; }
    void setOuverturePrintemps(bool b) { printemps=b; }
};

QTextStream& operator<<(QTextStream& f, const UV& uv);

#endif // UV_H
