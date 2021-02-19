/*!
  * \file dialogconnexion.cpp
  * \brief Classe de connexion
  * \author Mariage Clementine
  * \version 1.0
  * \date 14/11/12
  * \bug aucun
*/
#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
    class DialogConnexion;
}
/*!
  *\class DialogConnexion
  *\brief Cette classe permet l'ouverture d'une fenêtre de connexion
  *\details Hérite de QDialog\n
  *Cette classe permet : \n
  *-l'ouverture d'une fenêtre de connexion,\n
  *-la vérification de la bonne connexion de l'utilisateur,\n
  *-l'ouverture de la MainWindow le cas échéant\n
  */
class DialogConnexion : public QDialog {
    Q_OBJECT
public:
    /*!
      *\fn DialogConnexion(QWidget *parent = 0)
      *\brief Constructeur de la fenêtre de dialogue
      *\details Hérite de QDialog\n
      *Charge la prise en compte de l'utf-8\n
      *Encode le champ de mot de passe
      *\return Ne retourne rien.
      */
    DialogConnexion(QWidget *parent = 0);
        /*!
          \fn ~DialogConnexion()
          \brief Destructeur de la fenêtre de dialogue
          \return Ne retourne rien.
          */
    ~DialogConnexion();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogConnexion *ui;


private slots:
    /*!
      *\fn void on_pushButtonDeco_clicked()
      *\brief Déconnecte l'utilisateur
      *\details Annule la procédure de connexion et ferme l'application en retournant 0.
      *\return Ne retourne rien.
      */
    void on_pushButtonDeco_clicked();
    /*!
      *\fn void on_pushButtonCo_clicked()
      *\brief Lance la procédure de connexion
      *\details Récupère les données saisies et les compare à celles contenues dans la base de données.
      *Si les données saisies sont bien retrouvées dans la base de données, envoie le signal de connexion au main.
      *\return Lance la procédure accept() au main.
      */
    void on_pushButtonCo_clicked();

};

#endif // DIALOGCONNEXION_H
