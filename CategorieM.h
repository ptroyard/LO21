#ifndef CATEGORIEM_H
#define CATEGORIEM_H
#include "include.h"


/*class CategorieM {
private:
    Categorie** Categories;
    unsigned int nbCategorie;
    unsigned int nbMaxCategorie;
    void addItem(Categorie* Categorie);
    bool modification;
    Categorie* trouverCategorie(const QString& cat) const;
    CategorieM(const CategorieM& cm);
    CategorieM& operator=(const CategorieM& cm);
    CategorieM();
    ~CategorieM();
    QString file;
    friend struct Handler;
    struct Handler{
        CategorieM* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;

public:

    void load(const QString& f);
    void save(const QString& f);
    static CategorieM& getInstance();
    static void libererInstance();
    void ajouterCategorie(const QString& n);
    const Categorie& getCategorie(const QString& nom) const;
    Categorie& getCategorie(const QString& nom);
    class Iterator {
        friend class CategorieM;
        Categorie** currentCategorie;
        unsigned int nbRemain;
        Iterator(Categorie** u, unsigned nb):currentCategorie(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentCategorie(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw Exception("error, next on an iterator which is done");
            nbRemain--;
            currentCategorie++;
        }
        Categorie& current() const {
            if (isDone())
                throw Exception("error, indirection on an iterator which is done");
            return **currentCategorie;
        }
    };
    Iterator getIterator() {
        return Iterator(Categories,nbCategorie);
    }

    class iterator {
        Categorie** current;
        iterator(Categorie** u):current(u){}
        friend class CategorieM;
    public:
        iterator():current(0){};
        Categorie& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(Categories); }
    iterator end() { return iterator(Categories+nbCategorie); }

    class FilterIterator {
        friend class CategorieM;
        Categorie** currentCategorie;
        unsigned int nbRemain;
        Categorie categorie;
        FilterIterator(Categorie** c):currentCategorie(u),nbRemain(nb),categorie(c){
            while(nbRemain>0 && (*currentCategorie)->getCategorie()!=categorie){
                nbRemain--; currentCategorie++;
            }
        }
    public:
        FilterIterator():nbRemain(0),currentCategorie(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw Exception("error, next on an iterator which is done");
            do {
                nbRemain--; currentCategorie++;
            }while(nbRemain>0 && (*currentCategorie)->getCategorie()!=categorie);
        }
        Categorie& current() const {
            if (isDone())
                throw Exception("error, indirection on an iterator which is done");
            return **currentCategorie;
        }
    };
    FilterIterator getFilterIterator(Categorie c) {
        return FilterIterator(Categories,nbCategorie,c);
    }
};


};*/

#endif // CATEGORIEM_H
