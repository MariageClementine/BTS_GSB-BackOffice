/*!
  *\file mainwindow.cpp
  *\brief Gestion de la base de données GSB
  *\author Mariage Clementine
  *\version 1.0
  *\date 14/11/12
  *\bug Aucun
  *\warning Certains champs ne peuvent être supprimés en raison des contraintes d'intégrité référentielle.\n
  * L'onglet département a été désactivé en raison de l'inutilité qu'il y aurait à le gérer.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

namespace Ui {
    class MainWindow;
}
/*!
  *\class MainWindow
  *\brief Prend en charge la gestion de la base de données GSB
  *\details Hérite de QMainWindow\n
  * Affiche et gère les données des tables PRATICIEN, CABINET, MEDECIN, VISITEUR et LABO.\n
  * Permet: consultations, ajouts, modifications et suppressions.
  */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /*!
      *\fn MainWindow(QWidget *parent = 0)
      *\brief Constructeur de la MainWindow
      *\details Charge la prise en compte de l'utf-8,\n
      * Fait appel aux fonctions void chargerPrat(), void chargerCab(),\n
      *chargerMed(), chargerVis(), chargerDep(), chargerLabo().
      *\return Ne retourne rien.
      */
    MainWindow(QWidget *parent = 0);
    /*!
      *\fn ~MainWindow()
      *\brief Destructeur de la MainWindow
      *\return Ne retourne rien.
      */
    ~MainWindow();
    /*!
      *\fn void chargerPrat()
      *\brief Récupère les informations sur les praticiens et les affiche dans un QListWidget
      *\details Vide préalablement toute combobox et QListWidget associées.\n
      * Récupère également les libellés dans les tables TYPE_PRATICIEN et CABINET (via TRAVAILLE) et les affiche dans des combobox.
      *\return Ne retourne rien
      */
    void chargerPrat();
    /*!
      *\fn void chargerCab()
      *\brief Récupère les informations sur les cabinets et les affiche dans un QListWidget
      *\details Vide préalablement toute combobox et QListWidget associées.
      *\return Ne retourne rien
      */
    void chargerCab();
    /*!
      *\fn void chargerMed()
      *\brief Récupère les informations sur les médicaments et les affiche dans un QListWidget
      *\details Vide préalablement toute combobox et QListWidget associées.\n
      * Récupère également les libellés dans la table FAMILLE et les affiche dans une combobox.
      *\return Ne retourne rien
      */
    void chargerMed();
    /*!
      *\fn void chargerVis()
      *\brief Récupère les informations sur les visiteurs et les affiche dans un QListWidget
      *\details Vide préalablement toute combobox et QListWidget associées.\n
      * Récupère également les libellés dans les tables DEPARTEMENT,LABO et SECTEUR et les affiche dans des combobox.
      *\return Ne retourne rien
      */
    void chargerVis();
    /*!
      *\fn void chargerDep()
      *\brief Récupère les informations sur les departements et les affiche dans un QListWidget
      *\details Vide préalablement toute combobox et QListWidget associées.
      *\return Ne retourne rien
      */
    void chargerDep();
    /*!
      *\fn void chargerLabo()
      *\brief Récupère les informations sur les laboratoires et les affiche dans un QListWidget
      *\details Vide préalablement toute combobox et QListWidget associées.
      *\return Ne retourne rien
      */
    void chargerLabo();
    /*!
      *\fn void viderChampsPrat()
      *\brief Réinitialise l'onglet
      *\details Applique la fonction clear() à tous les lineEdit de l'onglet,\n
      * remet le currentIndex de comboBoxCabinetPraticien et comboBoxTypePraticien à 0,\n
      * unchecke les radioButtonOui et radioButtonNon,\n
      * vide les chaînes pra_nom et pra_prenom.
      *\return Ne retourne rien
      */
    void viderChampsPrat();
    /*!
      *\fn void viderChampsCab()
      *\brief Réinitialise l'onglet
      *\details Applique la fonction clear() à tous les lineEdit de l'onglet,\n
      * vide la chaîne cab_nom.
      *\return Ne retourne rien
      */
    void viderChampsCab();
    /*!
      *\fn void viderChampMed()
      *\brief Réinitialise l'onglet
      *\details Applique la fonction clear() à tous les lineEdit de l'onglet,\n
      * remet le currentIndex de la comboBoxFamilleMedicament à 0,\n
      * vide la chaîne med_depLeg.
      *\return Ne retourne rien
      */
    void viderChampMed();
    /*!
      *\fn void viderChampVis()
      *\brief Réinitialise l'onglet
      *\details Applique la fonction clear() à tous les lineEdit de l'onglet,\n
      * remet le currentIndex de comboBoxSecteurVisiteur, comboBoxLaboVisiteur et comboBoxDepartementVisiteur à 0,\n
      * unchecke les radioButtonDelegueOUI et radioButtonDelegueNON,\n
      * vide les chaînes vis_nom et vis_prenom.
      *\return Ne retourne rien
      */
    void viderChampVis();
    /*!
      *\fn void viderChampDep()
      *\brief Réinitialise l'onglet
      *\details Applique la fonction clear() à tous les lineEdit de l'onglet,\n
      * vide la chaîne dep_nom.\n
      *-->Fonction obsolète      
      *\return Ne retourne rien
      */
    void viderChampDep();
    /*!
      *\fn void viderChampLabo()
      *\brief Réinitialise l'onglet
      *\details Applique la fonction clear() à tous les lineEdit de l'onglet,\n
      * vide la chaîne lab_nom.
      *\return Ne retourne rien
      */
    void viderChampLabo();
    /*!
      *\property QString pra_nom
      *\brief Conserve le nom d'un praticien sur lequel on a cliqué, en vue d'une évetuelle modification.
      *\details Complète la variable QString pra_prenom.
      */
    QString pra_nom;
    /*!
      *\property QString pra_prenom
      *\brief Conserve le prenom d'un praticien sur lequel on a cliqué, en vue d'une évetuelle modification.
      *\details Complète la variable QString pra_nom.
     */
    QString pra_prenom;
    /*!
      *\property QString cab_nom
      *\brief Conserve le nom d'un cabinet sur lequel on a cliqué en vue d'une évetuelle modification.
      */
    QString cab_nom;
    /*!
      *\property QString med_depLeg
      *\brief Conserve le dépot légal d'un médicament sur lequel on a cliqué, en vue d'une évetuelle modification.
      */
    QString med_depLeg;
    /*!
      *\property QString vis_nom
      *\brief Conserve le nom d'un visiteur sur lequel on a cliqué, en vue d'une évetuelle modification.
      *\details Complète la variable QString vis_prenom.
      */
    QString vis_nom;
    /*!
      *\property QString vis_prenom
      *\brief Conserve le prenom d'un visiteur sur lequel on a cliqué, en vue d'une évetuelle modification.
      *\details Complète la variable QString vis_nom.
      */
    QString vis_prenom;
    /*!
      *\property QString dep_nom
      *\brief Conserve le nom d'un département sur lequel on a cliqué, en vue d'une évetuelle modification.
      *\details Variable obsolète.
      */
    QString dep_nom;
    /*!
      *\property QString lab_nom
      *\brief Conserve le nom d'un laboratoire sur lequel on a cliqué, en vue d'une évetuelle modification.
      */
    QString lab_nom;



protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;


private slots:
    /*!
      *\fn void on_pushButtonSupprLabo_clicked()
      *\brief Supprime un laboratoire de la base de données
      *\details Récupère le nom du laboratoire contenu dans la QString lab_nom et l'insère dans une requête DELETE.\n
      *Ne fonctionne que s'il n'est rattaché à aucun visiteur.\n
      *\Appelle les fonctions viderChampLabo(), chargerLabo() et chargerVis().
      *\return Ne retourne rien.
      */
    void on_pushButtonSupprLabo_clicked();
    /*!
      *\fn void on_pushButtonModifierLabo_clicked()
      *\brief Modifie les données d'un laboratoire sélectionné
      *\details Récupère le nom du laboratoire contenu dans la QString lab_nom, les données contenues dans les lineEdit et les insère dans une requête UPDATE.\n
      *\Appelle les fonctions viderChampLabo(), chargerLabo() et chargerVis().
      *\return Ne retourne rien.
      */
    void on_pushButtonModifierLabo_clicked();
    /*!
      *\fn void on_pushButtonAjoutLabo_clicked()
      *\brief Ajoute une ligne de données à la table LABORATOIRE.
      *\details Récupère les données dans les lineEdit et les insère dans une requête INSERT.\n
      *\Appelle les fonctions viderChampLabo(), chargerLabo() et chargerVis().
      *\return Ne retourne rien.
      */
    void on_pushButtonAjoutLabo_clicked();
    /*!
      *\fn  void on_listWidgetLabo_clicked(QModelIndex index)
      *\brief Affiche les infos sur le laboratoire cliqué dans les lineEdit
      *\details Récupère le nom du labo et l'enregistre dans la QString lab_nom.\n
      *Fait une requête SELECT sur ce nom et affiche.
      *\param QModelIndex index = l'index de l'item cliqué. Variable inutile dans la fonction.
      *\return Ne retourne rien.
      */
    void on_listWidgetLabo_clicked(QModelIndex index);
    /*!
      *\fn void on_pushButtonSupprDepartement_clicked()
      *\brief Supprime un département de la base de données
      *\details Récupère le nom du département contenu dans la QString dep_nom et l'insère dans une requête DELETE.\n
      *Ne fonctionne que s'il n'est rattaché à aucun visiteur.\n
      *\Appelle les fonctions viderChampDep(), chargerDep() et chargerVis().\n
      *--> Fonction obsolète.
      *\return Ne retourne rien.
      */
    void on_pushButtonSupprDepartement_clicked();
    /*!
      *\fn void on_pushButtonModifierDepartement_clicked()
      *\brief Modifie les données d'un département sélectionné
      *\details Récupère le nom du département contenu dans la QString dep_nom, les données contenues dans les lineEdit et les insère dans une requête UPDATE.\n
      *\Appelle les fonctions viderChampDep(), chargerDep() et chargerVis().\n
      *-->Fonction obsolète
      *\return Ne retourne rien.
      */
    void on_pushButtonModifierDepartement_clicked();
    /*!
      *\fn void on_pushButtonAjoutDepartement_clicked()
      *\brief Ajoute une ligne de données à la table DEPARTEMENT.
      *\details Récupère les données dans les lineEdit et les insère dans une requête INSERT.\n
      *\Appelle les fonctions viderChampDep(), chargerDep() et chargerVis().\n
      * -->fonction obsolète
      *\return Ne retourne rien.
      */
    void on_pushButtonAjoutDepartement_clicked();
    /*!
      *\fn  void on_listWidgetDepartement_clicked(QModelIndex index)
      *\brief Affiche les infos sur le département cliqué dans les lineEdit
      *\details Récupère le nom du département et l'enregistre dans la QString dep_nom.\n
      *Fait une requête SELECT sur ce nom et affiche.
      *\param QModelIndex index = l'index de l'item cliqué. Variable inutile dans la fonction.
      *\return Ne retourne rien.
      */
    void on_listWidgetDepartement_clicked(QModelIndex index);
    /*!
      *\fn void on_pushButtonSupprVisiteur_clicked()
      *\brief Supprime un visiteur de la base de données
      *\details Récupère les nom et prenoms du visiteur contenus dans les QString vis_nom et vis_prenom et les insère dans une requête DELETE.\n
      *\Supprime aussi ses attaches à DEPARTEMENT, LABO, et SECTEUR.\n
      *\Appelle les fonctions viderChampVis() et chargerVis().
      *\return Ne retourne rien.
      */
    void on_pushButtonSupprVisiteur_clicked();
    /*!
      *\fn void on_pushButtonModifierVisiteur_clicked()
      *\brief Modifie les données d'un visiteur sélectionné
      *\details Récupère les nom et prenom du visiteur contenus dans les QString vis_nom et vis_prenom, les données contenues dans les lineEdit et les insère dans une requête UPDATE.\n
      *Modifie également les Secteurs, Labos et Départements lui correspondant.\n
      *\Appelle les fonctions viderChampVis() et chargerVis().
      *\return Ne retourne rien.
      */
    void on_pushButtonModifierVisiteur_clicked();
    /*!
      *\fn void on_pushButtonAjoutVisiteur_clicked()
      *\brief Ajoute une ligne de données à la table VISITEUR.
      *\details Récupère les données dans les lineEdit et les insère dans une requête INSERT.\n
      *Récupère également le code des Departement, Secteur et Labo associés et les ajoute à la requête.\n
      *\Appelle les fonctions viderChampVis() et chargerVis().
      *\return Ne retourne rien.
      */
    void on_pushButtonAjoutVisiteur_clicked();
    /*!
      *\fn  void on_listWidgetVisiteurs_clicked(QModelIndex index)
      *\brief Affiche les infos sur le visiteur cliqué dans les lineEdit
      *\details Récupère le nom et le prénom du visiteur et les enregistre dans les QString vis_nom et vis_prenom.\n
      *Fait une requête SELECT sur ces nom et prénom et affiche.\n
      *Récupère également le libellé des secteur, département et laboratoire associés, et les affiche dans les combobox.\n
      *Checke le radioButtonDelegueOUI si le champ DELEGUE prend la valeur 1, checke le radioButtonDelegueNON sinon.
      *\param QModelIndex index = l'index de l'item cliqué. Variable inutile dans la fonction.
      *\return Ne retourne rien.
      */
    void on_listWidgetVisiteurs_clicked(QModelIndex index);
    /*!
      *\fn void on_pushButtonSupprMedicament_clicked()
      *\brief Supprime un médicament de la base de données
      *\details Récupère le dépôt légal du médicament contenu dans la QString med_depLeg et l'insère dans une requête DELETE.\n
      *\Supprime aussi ses attaches à FAMILLE.\n
      *\Appelle les fonctions viderChampMed() et chargerMed().
      *\return Ne retourne rien.
      */
    void on_pushButtonSupprMedicament_clicked();
    /*!
      *\fn void on_pushButtonModifierMedicament_clicked()
      *\brief Modifie les données d'un médicament sélectionné
      *\details Récupère le dépôt légal du médicament contenu dans la QString med_depLeg, les données contenues dans les lineEdit et les insère dans une requête UPDATE.\n
      *Modifie également la famille lui correspondant.\n
      *\Appelle les fonctions viderChampMed() et chargerMed().
      *\return Ne retourne rien.
      */
    void on_pushButtonModifierMedicament_clicked();
    /*!
      *\fn void on_pushButtonAjoutMedicament_clicked()
      *\brief Ajoute une ligne de données à la table MEDICAMENT.
      *\details Récupère les données dans les lineEdit et les insère dans une requête INSERT.\n
      *Récupère également le code de la famille de médicaments associée et l'ajoute à la requête.\n
      *\Appelle les fonctions viderChampMed() et chargerMed().
      *\return Ne retourne rien.
      */
    void on_pushButtonAjoutMedicament_clicked();
    /*!
      *\fn  void on_listWidgetMedicaments_clicked(QModelIndex index)
      *\brief Affiche les infos sur le médicament cliqué dans les lineEdit
      *\details Récupère le dépôt légal du médicament et l'enregistre dans la QString med_depLeg.\n
      *Fait une requête SELECT sur ce dépôt légal et affiche.\n
      *Récupère également la famille de médicaments associée, et l'affiche dans la combobox.\n
      *\param QModelIndex index = l'index de l'item cliqué. Variable inutile dans la fonction.
      *\return Ne retourne rien.
      */
    void on_listWidgetMedicaments_clicked(QModelIndex index);
    /*!
      *\fn void on_pushButtonSupprCabinet_clicked()
      *\brief Supprime un cabinet de la base de données
      *\details Récupère le nom du cabinet contenu dans la QString cab_nom et l'insère dans une requête DELETE.\n
      * Ne fonctionne que s'il n'est rattaché à aucun praticien.\n
      *\Appelle les fonctions viderChampsCab(), chargerCab() et chargerPrat().
      *\return Ne retourne rien.
      */
    void on_pushButtonSupprCabinet_clicked();
    /*!
      *\fn void on_pushButtonModifierCabinet_clicked()
      *\brief Modifie les données d'un cabinet sélectionné
      *\details Récupère le nom du cabinet contenu dans la QString cab_nom, les données contenues dans les lineEdit et les insère dans une requête UPDATE.\n
      *\Appelle les fonctions viderChampsCab(), chargerCab() et chargerPrat().
      *\return Ne retourne rien.
      */
    void on_pushButtonModifierCabinet_clicked();
    /*!
      *\fn void on_pushButtonAjoutCabinet_clicked()
      *\brief Ajoute une ligne de données à la table CABINET.
      *\details Récupère les données dans les lineEdit et les insère dans une requête INSERT.\n
      *\Appelle les fonctions viderChampsCab(), chargerCab() et chargerPrat().
      *\return Ne retourne rien.
      */
    void on_pushButtonAjoutCabinet_clicked();
    /*!
      *\fn  void on_listWidgetCabinet_clicked(QModelIndex index)
      *\brief Affiche les infos sur le cabinet cliqué dans les lineEdit
      *\details Récupère le nom du cabinet et l'enregistre dans la QString cab_nom.\n
      *Fait une requête SELECT sur ce nom et affiche.\n
      *\param QModelIndex index = l'index de l'item cliqué. Variable inutile dans la fonction.
      *\return Ne retourne rien.
      */
    void on_listWidgetCabinet_clicked(QModelIndex index);
    /*!
      *\fn void on_pushButtonSupprPraticien_clicked()
      *\brief Supprime un praticien de la base de données
      *\details Récupère les nom et prenom du praticien contenus dans les QString pra_nom et pra_prenom et les insère dans une requête DELETE.\n
      *\Supprime aussi ses attaches à TYPE_PRATICIEN et TRAVAILLE.\n
      *\Appelle les fonctions viderChampsPrat() et chargerPrat().
      *\return Ne retourne rien.
      */
    void on_pushButtonSupprPraticien_clicked();
    /*!
      *\fn void on_pushButtonModifierPraticien_clicked()
      *\brief Modifie les données d'un praticien sélectionné
      *\details Récupère les nom et prenom du praticien contenus dans les QString pra_nom et pra_prenom, les données contenues dans les lineEdit et les insère dans une requête UPDATE.\n
      *Modifie également le type et le cabinet correspondants.\n
      *\Appelle les fonctions viderChampsPrat() et chargerPrat().
      *\return Ne retourne rien.
      */
    void on_pushButtonModifierPraticien_clicked();
    /*!
      *\fn void on_pushButtonAJoutPraticien_clicked()
      *\brief Ajoute une ligne de données à la table PRATICIEN.
      *\details Crée un nouvel identifiant (le dernier +1)\n
      *Récupère les données dans les lineEdit et les insère dans une requête INSERT.\n
      *Récupère également le type de praticien associé et les ajoute à la requête.\n
      *Récupère également le code du cabinet et l'insère dans une requête INSERT destinée à la table TRAVAILLE.\n
      *\Appelle les fonctions viderChampsPrat() et chargerPrat().
      *\return Ne retourne rien.
      */
    void on_pushButtonAJoutPraticien_clicked();
    /*!
      *\fn  void on_listWidgetPraticiens_clicked(QModelIndex index)
      *\brief Affiche les infos sur le praticien cliqué dans les lineEdit
      *\details Récupère le nom et le prénom du praticien et les enregistre dans les QString pra_nom et pra_prenom.\n
      *Fait une requête SELECT sur ces nom et prénom et affiche.\n
      *Récupère également le libellé des cabinet et type de praticien associés, et les affiche dans les combobox.\n
      *Checke le radioButtonOui si le champ REMPLACANT prend la valeur 1, checke le radioButtonNon sinon.
      *\param QModelIndex index = l'index de l'item cliqué. Variable inutile dans la fonction.
      *\return Ne retourne rien.
      */
    void on_listWidgetPraticiens_clicked(QModelIndex index);
    /*!
      *\fn void on_action_Quitter_triggered()
      *\brief  Quitte l'application
      *\return 0
      */
    void on_action_Quitter_triggered();

};

#endif // MAINWINDOW_H
