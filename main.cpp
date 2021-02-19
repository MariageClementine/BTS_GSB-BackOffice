#include <QtGui/QApplication>
#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //connexion a la base
    QSqlDatabase base=QSqlDatabase::addDatabase("QMYSQL");
    base.setHostName("localhost");
    base.setUserName("GSBVisiteur");
    base.setDatabaseName("GSB_gestionCR");
    if(!base.open())
    {
        qDebug()<<"Le serveur de données est inaccessible.\r\nMerci de contacter votre administrateur et de relancer l'application.";
        return(1);
    }
    else
    {
        DialogConnexion d;
        if(d.exec()==QDialog::Accepted)
        {
            MainWindow w;
            w.show();
            return a.exec();
        }
        else
        {
            return 0;
        }
    }
}
