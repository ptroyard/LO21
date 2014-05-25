



class Dossier {
    QString login[8];
    QString nom;
    QString prenom;
    QString adresse;
    QString nationalite;
    QDate datenaissance;
    Formation* cursus; // ACCESSEUR
    QString semestre[5];
    QString* UVvalide; //ou Inscription
    QString* UVencours;
    QString* credit;
    QString** insert; //ou Inscription**
public :
    QString getlogin() const {return login;}
    QString getnom() const {return nom;}
    QString getprenom() const {return prenom;}
    QString getadresse() const {return adresse;}
    QString getnationalite() const {return nationalite;}
    QDate getdatenaissance() const {return datenaissance;}

    void setadresseetu (const QString& adreetu) {adresse=adreetu;}
    QString getsemestre() const {return semestre;}
    void setsemestre (const QString& sem) {semestre=sem;}
    void setresultat (const QString* tabres); //voir UML
    Dossier(){}
    ~Dossier(){}
    Inscription ajoutinscr(semestre s, const UV* uvs, Note res);
    void ajoutequivalence (unsigned int credit, QString Categorie);
    void complete(const UV& exige, const UV& rejet, const UV& pref);
    void enregistre(UV** solution);

};

class DossierManager {
private:
    Dossier** dos;
    unsigned int nbDossier;
    void addItem(Dossier* dossier);
    //bool modification;
    Dossier* trouverDossier(const QString& login) const;
    DossierManager(const DossierManager& dm);
    DossierManager& operator=(const DossierManager& dm);
    DossierManager();
    ~DossierManager();
    //QString file;
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
    static DossierManager& getInstance();
    static void libererInstance();
    void ajouterDossier(const QString& login, const QString& nom, const QString& prenom);
    const Dossier& getDossier(const QString& login) const;
    Dossier& getDossier(const QString& login);
    /*class Iterator {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Iterator(UV** u, unsigned nb):currentUV(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentUV(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw UTProfilerException("error, next on an iterator which is done");
            nbRemain--;
            currentUV++;
        }
        UV& current() const {
            if (isDone())
                throw UTProfilerException("error, indirection on an iterator which is done");
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
            while(nbRemain>0 && (*currentUV)->getCategorie()!=categorie){
                nbRemain--; currentUV++;
            }
        }
    public:
        FilterIterator():nbRemain(0),currentUV(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw UTProfilerException("error, next on an iterator which is done");
            do {
                nbRemain--; currentUV++;
            }while(nbRemain>0 && (*currentUV)->getCategorie()!=categorie);
        }
        UV& current() const {
            if (isDone())
                throw UTProfilerException("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    FilterIterator getFilterIterator(Categorie c) {
        return FilterIterator(uvs,nbUV,c);
    }*/
};

class Formation{
};

#endif
