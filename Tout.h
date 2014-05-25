#ifndef TOUT_H
#define TOUT_H
#include "include.h"



class Semestre {
    Saison saison;
    unsigned int annee;
public:
    Semestre(Saison s, unsigned int a):saison(s),annee(a){ if (annee<1972||annee>2099) throw Exception("annee non valide"); }
    Saison getSaison() const { return saison; }
    unsigned int getAnnee() const { return annee; }
    //pas de set ?!
};

inline QTextStream& operator<<(QTextStream& f, const Semestre& s) { return f<<s.getSaison()<<s.getAnnee()%100; }

class Categorie {
    QString nom;
    //nombre requis par formation
public :
    Categorie (const QString& n): nom(n){}
    const QString& getNom() const {return nom;}
};

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

class UVManager {
private:
    UV** uvs;
    unsigned int nbUV;
    unsigned int nbMaxUV;
    void addItem(UV* uv);
    bool modification;
    UV* trouverUV(const QString& c) const;
    UVManager(const UVManager& um);
    UVManager& operator=(const UVManager& um);
    UVManager();
    ~UVManager();
    QString file;
    /*friend struct Handler;
    struct Handler{
        UVManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;*/

public:

    void load(const QString& f);
    void save(const QString& f);
    static UVManager& getInstance();
    static void libererInstance();
    void ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p);
    const UV& getUV(const QString& code) const;
    UV& getUV(const QString& code);
    class Iterator {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Iterator(UV** u, unsigned nb):currentUV(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentUV(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw Exception("error, next on an iterator which is done");
            nbRemain--;
            currentUV++;
        }
        UV& current() const {
            if (isDone())
                throw Exception("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    Iterator getIterator() {
        return Iterator(uvs,nbUV);
    }

    class iterator {
        UV** current;
        iterator(UV** u):current(u){}
        friend class UVManager;
    public:
        iterator():current(0){};
        UV& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(uvs); }
    iterator end() { return iterator(uvs+nbUV); }

    class FilterIterator {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Categorie categorie;
        FilterIterator(UV** u, unsigned nb, Categorie c):currentUV(u),nbRemain(nb),categorie(c){
            while(nbRemain>0){
                nbRemain--; currentUV++;
            }
        }
    public:
        FilterIterator():nbRemain(0),currentUV(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw Exception("error, next on an iterator which is done");
            do {
                nbRemain--; currentUV++;
            }while(nbRemain>0);
        }
        UV& current() const {
            if (isDone())
                throw Exception("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    FilterIterator getFilterIterator(Categorie c) {
        return FilterIterator(uvs,nbUV,c);
    }
};


class Formation {

    QString nom;
    QString description;
    QString responsable;
    unsigned int duree; //en semestre
    bool filiere; // Formation avec fillieres (branches...) ou non (Hutech, TC)
    UV** uvform;// Uvs que propose la formation
    Credit* credits;
    //On gère que 102 crédits donc pas les crédits libres mais gérer la différence entre PCB et filière
    Filiere* tabfil;
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


        Formation* getTabFil() {return this->tabfil;}
        UV** getuvform() {return *this->uvform;}
        Credit* getcred() {return this->credits;}

        void setNom(const QString& n) {nom=n;}
        void setdesc(const QString& d) {description=d;}
        void setresp(const QString& r) {responsable=r;}
        void setduree(const unsigned int d) {duree=d;}
        void setFiliere(const bool f){filiere=f;}

        void setnbUv(const unsigned int nb1) {nbUv=nb1;}
        void setMaxUv(const unsigned int nb2) {nbMaxUv=nb2;}
        void setnbFi(const unsigned int nb3) {nbFi=nb3;}
        void setMaxFi(const unsigned int nb4) {nbMaxFi=nb4;}


        void ajoutUV(UV* uv); //on incremente le nombre d'UV de 1
        void supprimerUV(UV* uv);//on décrémente le nombre d'UV de 1
        bool trouveUV(const UV& uv);

        void ajoutFiliere(const QString& n, const QString& d="Non renseginée", const QString& re="Non renseigné", const bool& fi, const unsigned int nb1, const unsigned int nb2);
        void supprimerFiliere (const QString& n, const QString& d="Non renseginée", const QString& re="Non renseigné", const bool& fi, const unsigned int nb1, const unsigned int nb2);
        bool trouveFiliere(const Filiere& fil);

        void modifierCredit(const Credit* cred);


};










#endif // TOUT_H
