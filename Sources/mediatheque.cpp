#include "../Includes/mediatheque.h"
#include "../Includes/library_string2.h"

Mediatheque::Mediatheque() {
}

Mediatheque::~Mediatheque(){

}

string Mediatheque::nomMed() const
{
    return _nomMed;
}

void Mediatheque::setNomMed(const string &nomMed)
{
    _nomMed = nomMed;
}

void Mediatheque::load(string filename) { //Charge la médiathèque correspondante au nom du fichier (filename)

    reset();

    string file = filename + ".txt";
    int nRessources = 0;
    _nomMed = filename;

    string ligne;

    ifstream fichier(file, ios::in);  // on ouvre le fichier en lecture

    if(fichier) {  // si l'ouverture a réussi

        while(getline(fichier, ligne)) { //On récupére chaque ligne

            nRessources++;
            string mot;
            string id;
            string type;
            string nom;
            string auteur;

            for(int i = 0; i < 4; i++) { //On extrait les infos de base de la ligne (id, type, nom et auteur)

                mot = découpageMot(ligne);
                ligne = découpageLigne(ligne);

                switch(i) {
                    case 0 :
                        id = mot;
                    break;

                    case 1 :
                        type = mot;
                    break;

                    case 2 :
                        nom = mot;
                    break;

                    case 3 :
                        auteur = mot;
                    break;
                }
            }

            if (type == "Livre") { //En fonction du type, on récupère les autres infos
                string année;
                string résumé;
                string nPage;

                for(int i = 0; i < 2; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    switch(i) {
                        case 0 :
                            année = mot;
                        break;

                        case 1 :
                            résumé = mot;
                        break;          
                    }
                }

                nPage = ligne;

                Livre *ressource = new Livre(); // On copie les infos dans le type qui va bien
                ressource->setId(id);
                ressource->setNom(nom);
                ressource->setAuteur(auteur);
                ressource->setType(type);

                ressource->setAnnée(année);
                ressource->setRésumé(résumé);
                ressource->setNPage(nPage);
                _baseDonnées.push_back(ressource); //On ajoute la ressource à la base de données

            }

            else if (type == "CD") {
                string durée;
                string nPiste;
                string prod;

                for(int i = 0; i < 2; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    switch(i) {
                        case 0 :
                            durée = mot;
                        break;

                        case 1 :
                            nPiste = mot;
                        break;
                    }
                }

                prod = ligne;

                CD *ressource = new CD(); // creation d'un livre et incorporation des infos
                ressource->setId(id);
                ressource->setNom(nom);
                ressource->setAuteur(auteur);
                ressource->setType(type);

                ressource->setDurée(durée);
                ressource->setNPiste(nPiste);
                ressource->setProd(prod);
                _baseDonnées.push_back(ressource);

            }

            else if (type == "VHS") {

                string durée;
                string prod;

                for(int i = 0; i < 1; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    switch(i) {
                        case 0 :
                            durée = mot;
                        break;
                    }
                }

                prod = ligne;

                VHS *ressource = new VHS();
                ressource->setId(id);
                ressource->setNom(nom);
                ressource->setAuteur(auteur);
                ressource->setType(type);

                ressource->setDurée(durée);
                ressource->setProd(prod);
                _baseDonnées.push_back(ressource);

            }

            else if (type == "DVD") {

                string durée;
                string prod;
                string nPiste;

                for(int i = 0; i < 2; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    switch(i) {
                        case 0 :
                            durée = mot;
                        break;

                        case 1 :
                            prod = mot;
                        break;
                    }
                }

                nPiste = ligne;

                DVD *ressource = new DVD();
                ressource->setId(id);
                ressource->setNom(nom);
                ressource->setAuteur(auteur);
                ressource->setType(type);

                ressource->setDurée(durée);
                ressource->setProd(prod);
                ressource->setNPiste(nPiste);
                _baseDonnées.push_back(ressource);

            }

            else if (type == "Num") {
                string extension;
                string taille;
                string chemin;

                for(int i = 0; i < 2; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    switch(i) {
                        case 0 :
                            extension = mot;
                        break;

                        case 1 :
                            taille = mot;
                        break;
                    }
                }

                chemin = ligne;

                Num *ressource = new Num(); // creation d'un livre et incorporation des infos
                ressource->setId(id);
                ressource->setNom(nom);
                ressource->setAuteur(auteur);
                ressource->setType(type);

                ressource->setExtension(extension);
                ressource->setTaille(taille);
                ressource->setChemin(chemin);
                _baseDonnées.push_back(ressource);

            }

            else if (type == "Revue") {
                string année;
                string résumé;
                string nPage;
                string éditeur;
                unsigned nArticle;

                for(int i = 0; i < 5; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    switch(i) {
                        case 0 :
                            année = mot;
                        break;

                        case 1 :
                            résumé = mot;
                        break;

                        case 2 :
                            nPage = mot;
                        break;

                        case 3 :
                            éditeur = mot;
                        break;

                        case 4 :
                            nArticle = static_cast<unsigned>(stoi(mot));
                        break;
                    }
                }

                Revue *ressource = new Revue();
                ressource->setId(id);
                ressource->setNom(nom);
                ressource->setAuteur(auteur);
                ressource->setType(type);

                ressource->setAnnée(année);
                ressource->setRésumé(résumé);
                ressource->setNPage(nPage);
                ressource->setÉditeur(éditeur);

                for(unsigned i = 0; i< nArticle; i++) {
                    mot = découpageMot(ligne);
                    ligne = découpageLigne(ligne);

                    Article *article = new Article();
                    article->setNomArticle(mot);
                    ressource->addArticle(article);
                }

                _baseDonnées.push_back(ressource);

            }

            else
                cout << "Problème de lecture de la ressource " << nRessources << endl << "Vérifiez la ligne " << nRessources +1 << endl;

        }

        cout << "La médiathèque " << _nomMed << " a bien été chargée." << endl;
        cout << "Nombre de ressources chargées : " << _baseDonnées.size() << endl;

        fichier.close();  // on ferme le fichier`

    }

    else  // sinon
      cerr << "Impossible d'ouvrir le fichier !" << endl;

    if(_baseRecherche.empty()) { //On charge aussi toutes les ressources dans la base de données courante
        for (unsigned i =0; i < static_cast<unsigned>(_baseDonnées.size()); i++) {

            _baseRecherche.push_back((_baseDonnées[i]));
        }
    }

}

void Mediatheque::show(string id) { //On montre toutes les infos d'une ressource
    unsigned i = 0;
    while( i < static_cast<unsigned>(_baseDonnées.size())  && _baseDonnées[i]->id() != id) { //On recherche la ressource avec l'id correspondante
        i++;
    }

    if (_baseDonnées[i]->id() == id) { //Dès qu'on l'a trouvé, on affiche ses infos
        _baseDonnées[i]->show();
    }

    else if (i == (static_cast<unsigned>(_baseDonnées.size()))) {
        cout << "La ressource " << id << " n'est pas dans la médiathèque." << endl;
    }
}

void Mediatheque::bye() { //On ferme l'appli en nettoyant les vector créés

    _baseDonnées.clear();
    _baseRecherche.clear();

    cout << "Au revoir" << endl;
    exit(1);
}

void Mediatheque::reset() { //On nettoie seulement les vector créés

    _baseDonnées.clear();
    _baseRecherche.clear();

    cout << "Toutes les ressources ont été supprimées de la médiathèque " << _nomMed << endl;
}

void Mediatheque::deleteId(string id) { //On supprime une ressource en fonction de son id

    unsigned i = 0;
    while( i < static_cast<unsigned>(_baseDonnées.size()) && _baseDonnées[i]->id() != id) { //Recherche de la ressource
        i++;
    }

    if (_baseDonnées[i]->id() == id) { //Si on l'a trouve, on l'efface et on fait de même dansla base de recherche
        _baseDonnées.erase(_baseDonnées.begin()+i);

        while( i < static_cast<unsigned>(_baseRecherche.size()) && _baseRecherche[i]->id() != id) {
            i++;
        }

        if (_baseRecherche[i]->id() == id) {
            _baseRecherche.erase(_baseRecherche.begin()+i);
        }

        clear();
        cout << "La ressource " << id << " a bien été effacée de la médiathèque" << endl;
    }


    else if (i == static_cast<unsigned>(_baseDonnées.size())) { //Sinon, on l'indique à l'utilisateur
        cout << "La ressource " << id << " n'est pas dans la médiathèque." << endl;
    }

}

void Mediatheque::save(string filename) { //Sauvegarde de la base de données dans un fichier texte

    string file = filename + ".txt";
    string séparateur = " *=* ";
    string type;

    ofstream fichier(file, ios::out | ios::trunc);  // on ouvre le fichier en écriture

    if(fichier) {  // si l'ouverture a réussi

        for (unsigned i =0; i < static_cast<unsigned>(_baseDonnées.size()); i++) {//On parcourt touts les cases de la base de données

            type = _baseDonnées[i]->type();
            //On écrit les infos de bases
            fichier << _baseDonnées[i]->id() << séparateur << type << séparateur << _baseDonnées[i]->nom() << séparateur << _baseDonnées[i]->auteur() << séparateur;
            //En fonction du type, on écrit les infos qui manquent
            if (type == "Livre") {
                Livre *cp = new Livre();
                cp = dynamic_cast<Livre*>(_baseDonnées[i]) ;
                fichier << cp->année() << séparateur << cp->résumé() << séparateur << cp->nPage();
            }

            else if (type == "CD") {
                CD *cp = new CD();
                cp = dynamic_cast<CD*>(_baseDonnées[i]) ;
                fichier << cp->durée() << séparateur << cp->nPiste() << séparateur << cp->prod();
            }

            else if (type == "VHS") {
                VHS *cp = new VHS();
                cp = dynamic_cast<VHS*>(_baseDonnées[i]) ;
                fichier << cp->durée() << séparateur << cp->prod();
            }

            else if (type == "DVD") {
                DVD *cp = new DVD();
                cp = dynamic_cast<DVD*>(_baseDonnées[i]) ;
                fichier << cp->durée() << séparateur << cp->prod() << séparateur << cp->nPiste();
            }

            else if (type == "Num") {
                Num *cp = new Num();
                cp = dynamic_cast<Num*>(_baseDonnées[i]) ;
                fichier << cp->type() << séparateur << cp->taille() << séparateur << cp->chemin();
            }

            else if (type == "Revue") {
                Revue *cp = new Revue();
                cp = dynamic_cast<Revue*>(_baseDonnées[i]) ;
                fichier << cp->année() << séparateur << cp->résumé() << séparateur << cp->nPage() << séparateur <<cp->éditeur() << séparateur << cp->getNArticle();
                for (int i = 0; i< cp->getNArticle() ; i++) {
                    fichier << séparateur << cp->getNomArticleI(i);
                }

            }

            fichier << endl;
        }

        fichier.close();

        cout << "La médiathèque " << _nomMed << " actuellement chargée, a bien été sauvegardée dans le fichier " << file << endl;
    }

    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}

void Mediatheque::add(string type) {//On ajoute une ressource dans la base de données

    string id = to_string((stoi((_baseDonnées.back())->id()))+1); //On trouve une id non prise en regardant la dernière case

    string ligne;
    string nom;
    string auteur;
    //On récupère les infos de base
    cout << "Quel est le nom de la ressource ?" << endl;
    getline(cin,nom);
    cout << "Qui est l'auteur de la ressource ?" << endl;
    getline(cin,auteur);

    if (type == "Livre") { //On récupère les infos complémentaires en fonction du type
        Livre *ressource = new Livre();
        ressource->setId(id);
        ressource->setType(type);
        ressource->setNom(nom);
        ressource->setAuteur(auteur);

        string année;
        string résumé;
        string nPage;

        cout << "Quelle est l'année de parution du livre ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,année);
        cout << "Veuillez donner un résumé du livre (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,résumé);
        cout << "Quel est le nombre de page du livre ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,nPage);

        ressource->setAnnée(année);
        ressource->setRésumé(résumé);
        ressource->setNPage(nPage);

        _baseDonnées.push_back(ressource);
    }

    else if (type == "CD") {
        CD *ressource = new CD();
        ressource->setId(id);
        ressource->setType(type);
        ressource->setNom(nom);
        ressource->setAuteur(auteur);

        string durée;
        string nPiste;
        string prod;

        cout << "Quelle est la durée du CD ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,durée);
        cout << "Combien de piste il y a t-il sur le CD ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,nPiste);
        cout << "Quelle est le nom de la maison de production du CD? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,prod);

        ressource->setDurée(durée);
        ressource->setNPiste(nPiste);
        ressource->setProd(prod);

        _baseDonnées.push_back(ressource);
    }

    else if (type == "VHS") {
        VHS *ressource = new VHS();
        ressource->setId(id);
        ressource->setType(type);
        ressource->setNom(nom);
        ressource->setAuteur(auteur);

        string durée;
        string prod;

        cout << "Quelle est la durée de la VHS ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,durée);
        cout << "Quelle est le nom de la maison de production de la VHS? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,prod);

        ressource->setDurée(durée);
        ressource->setProd(prod);

        _baseDonnées.push_back(ressource);
    }

    else if (type == "DVD") {
        DVD *ressource = new DVD();
        ressource->setId(id);

        ressource->setType(type);
        ressource->setNom(nom);
        ressource->setAuteur(auteur);

        string durée;
        string prod;
        string nPiste;

        cout << "Quelle est la durée du DVD ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,durée);
        cout << "Quelle est le nom de la maison de production du DVD? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,prod);
        cout << "Combien de piste il y a t-il sur le DVD ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,nPiste);

        ressource->setDurée(durée);
        ressource->setProd(prod);
        ressource->setNPiste(nPiste);

        _baseDonnées.push_back(ressource);
    }

    else if (type == "Num") {
        Num *ressource = new Num();
        ressource->setId(id);

        ressource->setType(type);
        ressource->setNom(nom);
        ressource->setAuteur(auteur);

        string extension;
        string taille;
        string chemin;

        cout << "Quel est le type de la ressource numérique ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,extension);
        cout << "Quelle est la taille de la ressource numérique (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,taille);
        cout << "Quel est le chemin de la ressource numérique ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,chemin);

        ressource->setExtension(extension);
        ressource->setTaille(taille);
        ressource->setChemin(chemin);

        _baseDonnées.push_back(ressource);
    }

    else if (type == "Revue") {
        Revue *ressource = new Revue();

        ressource->setId(id);

        ressource->setType(type);
        ressource->setNom(nom);
        ressource->setAuteur(auteur);

        string année;
        string résumé;
        string nPage;

        cout << "Quelle est l'année de parution de la revue ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,année);
        cout << "Veuillez donner un résumé de la revue (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,résumé);
        cout << "Quel est le nombre de page de la revue ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,nPage);

        ressource->setAnnée(année);
        ressource->setRésumé(résumé);
        ressource->setNPage(nPage);

        string éditeur;
        string nArticle;

        cout << "Quel est le nom de l'éditeur de la revue (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,éditeur);
        cout << "Quel est le nombre d' article de la revue ? (si vous ne savez pas, veuillez inscrire : N/A)" << endl;
        getline(cin,nArticle);

        ressource->setÉditeur(éditeur);
        string nomArticle;
        for(int i = 0; i < stoi(nArticle); i++) {
            cout << "Quel est le nom de de l'article " << i+1 << " ? (si vous ne savez pas, veuillez inscrire : N/A)" <<endl;
            getline(cin, nomArticle);
            Article* article = new Article();
            article->setNomArticle((nomArticle));
            ressource->addArticle(article);
        }

        _baseDonnées.push_back(ressource);
    }

    clear(); //On ajoute cette ressource dans la base de recherche en la réinitialisant
    cout << "La ressource " << nom << " avec l'id : " << id << " a bien été ajoutée à la médiathèque " << _nomMed << endl;

}

void Mediatheque::search(string info) { //On recherche une info dans la base de recherche

    vector <Ressources*> baseRechercheTmp; //On créé une base de Recherche temporaire où on va mettre les résultats positifs de la recherche

    for (unsigned i =0; i < static_cast<unsigned>(_baseRecherche.size()); i++) { //On parcourt toutes les cases de la base de Recherche

        string nom = _baseRecherche[i]->nom();
        string auteur = _baseRecherche[i]->auteur();
        string type = _baseRecherche[i]->type();
        string id = _baseRecherche[i]->id();

        if (type == "Livre") {//On vérifie s'il y a un match avec une des infos, si oui, on ajoute la ressource à la base de recherche temporaire
            Livre *cp = new Livre();
            cp = dynamic_cast<Livre*>(_baseRecherche[i]);
            string année = cp->année();
            string résumé = cp->résumé();
            string nPage = cp->nPage();

            if(rechercheString(nom,info) || rechercheString(auteur, info) || rechercheString(type, info) || rechercheString(année,info) || rechercheString(résumé, info) || rechercheString(nPage, info)) {
                baseRechercheTmp.push_back(_baseRecherche[i]);
            }
        }

        else if (type == "CD") {
            CD *cp = new CD();
            cp = dynamic_cast<CD*>(_baseRecherche[i]);
            string durée = cp->durée();

            string nPiste = cp->nPiste();
            string prod = cp->prod();

            if(rechercheString(nom,info) || rechercheString(auteur, info) || rechercheString(type, info) || rechercheString(durée,info) || rechercheString(nPiste, info) || rechercheString(prod, info)) {
                baseRechercheTmp.push_back(_baseRecherche[i]);
            }
        }

        else if (type == "VHS") {

            VHS *cp = new VHS();
            cp = dynamic_cast<VHS*>(_baseRecherche[i]);
            string durée = cp->durée();
            string prod = cp->prod();

            if(rechercheString(nom,info) || rechercheString(auteur, info) || rechercheString(type, info) || rechercheString(durée,info) || rechercheString(prod, info)) {
                baseRechercheTmp.push_back(_baseRecherche[i]);
            }
        }

        else if (type == "DVD") {
            DVD *cp = new DVD();
            cp = dynamic_cast<DVD*>(_baseRecherche[i]);
            string durée = cp->durée();
            string nPiste = cp->nPiste();
            string prod = cp->prod();

            if(rechercheString(nom,info) || rechercheString(auteur, info) || rechercheString(type, info) || rechercheString(durée,info) || rechercheString(nPiste, info) || rechercheString(prod, info)) {
                baseRechercheTmp.push_back(_baseRecherche[i]);
            }

        }

        else if (type == "Num") {
            Num *cp = new Num();
            cp = dynamic_cast<Num*>(_baseRecherche[i]);
            string extension = cp->extension();
            string taille = cp->taille();
            string chemin = cp->chemin();

            if(rechercheString(nom,info) || rechercheString(auteur, info) || rechercheString(type, info) || rechercheString(extension,info) || rechercheString(taille, info) || rechercheString(chemin, info)) {
               baseRechercheTmp.push_back(_baseRecherche[i]);
            }
        }

        else if (type == "Revue") {
            Revue *cp = new Revue();
            cp =dynamic_cast<Revue*>(_baseRecherche[i]);
            string année = cp->année();
            string résumé = cp->résumé();
            string nPage = cp->nPage();
            string éditeur = cp->éditeur();

            if(rechercheString(nom,info) || rechercheString(auteur, info) || rechercheString(type, info) || rechercheString(année,info) || rechercheString(résumé, info) || rechercheString(nPage, info) || rechercheString(éditeur, info)) {
               baseRechercheTmp.push_back(_baseRecherche[i]);
            }

            else {
                for(int j = 0; j < cp->getNArticle(); j++) {
                    if(rechercheString(cp->getNomArticleI(j),info)) {
                        baseRechercheTmp.push_back(_baseRecherche[i]);
                        break;
                    }
                }
            }
        }

    }


    cout << "Recherche effectuée" << endl;

    _baseRecherche.clear();  //On efface alors la base de recherche et on recopie la base de recherche temporaire dans la base de recherche

    for(unsigned i = 0 ; i < baseRechercheTmp.size(); i++) {
        _baseRecherche.push_back(baseRechercheTmp[i]);
    }

    baseRechercheTmp.clear(); //On efface la base de recherche temporaire

    unsigned nRésultat = static_cast<unsigned>(_baseRecherche.size());
    if (nRésultat > 0) {//On indique le nombre de résultats à l'utilisateur
        cout << "Résultats trouvés : " << nRésultat << ". Veuillez inscrire la commande LIST pour les afficher" << endl;
    }
    else
        cout << "Pas de résultat" << endl;
}

void Mediatheque::clear() { //On réinitialise la base de recherche avec la base de données

    _baseRecherche.clear();

    for (unsigned i =0; i < static_cast<unsigned>(_baseDonnées.size()); i++) {

        _baseRecherche.push_back((_baseDonnées[i]));
    }


    cout << "La base de recherche a été réinitialisée" << endl;
}

void Mediatheque::list() { //On affiche les infos de base des ressources de la base de recherche

    if(_baseDonnées.size() == _baseRecherche.size())
        cout << "La médiathèque contient : " << _baseRecherche.size() << " ressources." << endl;

    else
        cout << "La recherche précédente a donné : " << _baseRecherche.size() << " résultat(s)" << endl;

    cout << "Voici la liste :" << endl;
    cout << "ID \t - \t Type \t - \t Nom \t - \t Auteur" << endl;

    for (unsigned  i =0; i < static_cast<unsigned>(_baseRecherche.size()); i++) {
        _baseRecherche[i]->list();
    }
}
