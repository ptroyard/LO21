#include "include.h"


/*CategorieM::CategorieM():categ(0),nbCategorie(0),nbMaxCategorie(0),file(""),modification(false){}


void CategorieM::load(const QString& f){
    if (file!=f) this->~CategorieM();
    file=f;

    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw Exception("Erreur oCategorieerture fichier Categorie");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named Categories, we'll go to the next.
            if(xml.name() == "Categorie") continue;
            // If it's named Categorie, we'll dig the information from there.
            if(xml.name() == "cat") {
                QString nom;

                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named Categorie.


                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "Categorie")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        if(xml.name() == "nom") {
                            xml.readNext(); code=xml.text().toString();
                        }

                    }
                    // ...and next...
                    xml.readNext();
                }
                ajouterCategorie(nom);

            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw Exception("Erreur lecteur fichier Categorie, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}



void CategorieM::save(const QString& f){
    file=f;
    QFile newfile( file);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw Exception(QString("erreur oCategorieerture fichier xml"));
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);

     stream.writeTextElement("nom",Categories[i]->getNom());

     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();

}

CategorieM::~CategorieM(){
    if (file!="") save(file);
    for(unsigned int i=0; i<nbCategorie; i++) delete Categories[i];
    delete[] Categories;
}


void CategorieM::ajouterCategorie(const QString& n){
    if (trouverCategorie(c)) {
        throw Exception(QString("erreur, d�ja existante"));
    }else{
        Categorie* newCategorie=new Categorie(n);

        modification=true;
    }
}

Categorie* CategorieM::trouverCategorie(const QString& c)const{
    for(unsigned int i=0; i<nbCategorie; i++)
        if (c==Categories[i]->getNom()) return Categories[i];
    return 0;
}

Categorie& CategorieM::getCategorie(const QString& nom){
    Categorie* Categorie=trouverCategorie(nom);
    if (!Categorie) throw Exception("erreur, CategorieM, Categorie inexistante",__FILE__,__LINE__);
    return *Categorie;
}


const Categorie& CategorieM::getCategorie(const QString& nom)const{
    return const_cast<CategorieM*>(this)->getNom(nom);

}

CategorieM::Handler CategorieM::handler=Handler();

CategorieM& CategorieM::getInstance(){
    if (!handler.instance) handler.instance = new CategorieM; /* instance cr��e une seule fois lors de la premi�re utilisation
    return *handler.instance;
}

void CategorieM::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}*/



