#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow fenetre;
    //QString titre = "Bibliothèque numérique";
    //fenetre.setWindowTitle(titre);
    fenetre.show();

    return app.exec();
}
