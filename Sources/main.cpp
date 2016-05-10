#include "../Includes/ressources.h"
#include "../Includes/livre.h"
#include "../Includes/utilisateur.h"
#include "../Includes/mediatheque.h"
#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"

int main() {
    // Utilisateur* user = new Utilisateur();
    // string nomUtilisateur;
    // string réponse;
    // string motPasse;
    // string action;
    // Mediatheque *currentMed = new Mediatheque();

    // cout << endl << "Bienvenue dans la bibliothèque de Babel" << endl << endl << "Quel est votre nom ?" << endl;
    // getline(cin,nomUtilisateur);
    // user->setNomUtilisateur(nomUtilisateur);
    // cout << endl << "Bonjour " << user->nomUtilisateur() << ", êtes-vous administrateur ?" <<endl;
    // getline(cin,réponse);
    // if(réponse == "oui" || réponse == "yes") {
    //     cout << "Veuillez entrer le mot de passe" << endl;
    //     getline(cin,motPasse);
    //     if(motPasse == user->motPasseAdmin()) {
    //         user->setEstAdmin(true);
    //         cout << "Vous êtes bien l'administrateur, vous avez accès à toutes les fonctions";
    //     }
    //     else
    //         cout << "Vous n'êtes pas administrateur, vous pouvez seulement consulter la médiathèque et effectuer des recherches" << endl;
    // }
    // else
    //     cout << "Vous n'êtes pas administrateur, vous pouvez seulement consulter la médiathèque et effectuer des recherches" << endl;


    // while(true) {
    //     cout << endl << "Quelle action souhaitez-vous effectuer ?" << endl;
    //     getline(cin, action);
    //     user->reconnaissanceAction(action, currentMed);
    // }
    
    QApplication app(argc, argv);

    MainWindow fenetre;
    fenetre.show();

    return app.exec();


}


