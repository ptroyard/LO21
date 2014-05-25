#ifndef FORMATIONM_H
#define FORMATIONM_H
#include "include.h"


/*class FormationM{
private:
    Formation** Forma;
    unsigned int nbForma;
    unsigned int nbMaxForma;
    void addItemF (Formation* for);
    bool modification;
    FormationM(const FormationM& fm);
    FormationM& operator=(const FormationM& fm);
    FormationM();
    ~FormationM();
    QString file;
    friend struct Handler;
    struct Handler{
        FormationM* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;

public:
    void SupprForma(QString);
    int existForma(QString);
    //Formation& creatForma();
    Formation* trouverForma(QString& c);
    void loadF(const QString& f);
    void saveF(const QString& f);
    static FormationM& getInstance();
    static void libererInstance();
    void AjouterForma(Formation*);
    Formation& getForma(QString&);
    class Iterator {
        friend class FormationM;
        Formation** currentForma;
        unsigned int nbRemain;
        Iterator(Formation** u, unsigned nb):currentForma(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentForma(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw Exception("error, next on an iterator which is done");
            nbRemain--;
            currentForma++;
        }
        Formation& current() const {
            if (isDone())
                throw Exception("error, indirection on an iterator which is done");
            return **currentForma;
        }
    };
    Iterator getIterator() {
        return Iterator(Forma,nbForma);
    }

    class iterator {
        Formation** current;
        iterator(Cursus** u):current(u){}
        friend class FormationM;
    public:
        iterator():current(0){};
        Formation& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(Forma); }
    iterator end() { return iterator(Forma+nbForma); }
};*/



#endif // FORMATIONM_H
