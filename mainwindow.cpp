#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QTextCodec>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //prise en charge de l'utf8
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));

    //affichage des données
    chargerPrat();
    chargerCab();
    chargerMed();
    chargerVis();
    chargerDep();
    chargerLabo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_action_Quitter_triggered()
{
    this->close();
}

void MainWindow::chargerPrat()
{
    //réinitialisation des widgets
    ui->listWidgetPraticiens->clear();
    ui->comboBoxCabinetPraticien->clear();
    ui->comboBoxTypePraticien->clear();

    //affichage des praticiens
    QSqlQuery affichePrats("select PRA_NOM, PRA_PRENOM from PRATICIEN order by PRA_NOM,PRA_PRENOM");
    while(affichePrats.next())
    {
        ui->listWidgetPraticiens->addItem(affichePrats.value(0).toString()+" "+affichePrats.value(1).toString());
    }

    ui->comboBoxTypePraticien->addItem("Type de Praticien");
    QSqlQuery afficheType("select TYP_LIBELLE from TYPE_PRATICIEN ORDER BY TYP_LIBELLE");
    while(afficheType.next())
    {
        ui->comboBoxTypePraticien->addItem(afficheType.value(0).toString());
    }

    ui->comboBoxCabinetPraticien->addItem("Cabinet");
    QSqlQuery afficheCabCombo("select CAB_LOCAL FROM CABINET ORDER BY CAB_LOCAL");
    while(afficheCabCombo.next())
    {
        ui->comboBoxCabinetPraticien->addItem(afficheCabCombo.value(0).toString());
    }
}

void MainWindow::chargerCab()
{
    //reinitialisation des widgets
    ui->listWidgetCabinet->clear();

    //affichage des cabinets
    QSqlQuery afficheCabs("select CAB_LOCAL from CABINET ORDER BY CAB_LOCAL");
    while(afficheCabs.next())
    {
        ui->listWidgetCabinet->addItem(afficheCabs.value(0).toString());
    }
}

void MainWindow::chargerMed()
{
    //reinitialisation des widgets
    ui->listWidgetMedicaments->clear();
    ui->comboBoxFamilleMedicament->clear();

    //affichage des medicaments
    QSqlQuery afficheMedics("select MED_DEPOTLEGAL, MED_NOMCOMMERCIAL FROM MEDICAMENT ORDER BY MED_DEPOTLEGAL");
    while (afficheMedics.next())
    {
        ui->listWidgetMedicaments->addItem(afficheMedics.value(0).toString()+" , "+afficheMedics.value(1).toString());
    }

    //combo box
    ui->comboBoxFamilleMedicament->addItem("Famille de Médicament");
    QSqlQuery afficheFamille("select FAM_LIBELLE from FAMILLE ORDER BY FAM_LIBELLE");
    while(afficheFamille.next())
    {
        ui->comboBoxFamilleMedicament->addItem(afficheFamille.value(0).toString());
    }
}

void MainWindow::chargerVis()
{
    //reinitialisation des widgets
    ui->listWidgetVisiteurs->clear();
    ui->comboBoxDepartementVisiteur->clear();
    ui->comboBoxSecteurVisiteur->clear();
    ui->comboBoxLaboVisiteur->clear();

    //affichage des visiteurs
    QSqlQuery afficheVisits("select VIS_NOM, VIS_PRENOM FROM VISITEUR ORDER BY VIS_NOM,VIS_PRENOM");
    while (afficheVisits.next())
    {
        ui->listWidgetVisiteurs->addItem(afficheVisits.value(0).toString()+" "+afficheVisits.value(1).toString());
    }

    //combobox departement
    ui->comboBoxDepartementVisiteur->addItem("Departement");
    QSqlQuery afficheDep("select DEP_NOM FROM DEPARTEMENT ORDER BY DEP_NOM;");
    while(afficheDep.next())
    {
        ui->comboBoxDepartementVisiteur->addItem(afficheDep.value(0).toString());
    }

    //combobox labo
    ui->comboBoxLaboVisiteur->addItem("Labo");
    QSqlQuery afficheLabo("select LAB_NOM from LABO ORDER BY LAB_NOM");
    while(afficheLabo.next())
    {
        ui->comboBoxLaboVisiteur->addItem(afficheLabo.value(0).toString());
    }

    //combobox secteur
    ui->comboBoxSecteurVisiteur->addItem("Secteur");
    QSqlQuery afficheSecteur("select SEC_LIBELLE FROM SECTEUR ORDER BY SEC_LIBELLE");
    while(afficheSecteur.next())
    {
        ui->comboBoxSecteurVisiteur->addItem(afficheSecteur.value(0).toString());
    }
}

void MainWindow::chargerDep()
{
    //reinitialisation des widgets
    ui->listWidgetDepartement->clear();

    //affichage des departements
    QSqlQuery afficheDeps("select DEP_NOM FROM DEPARTEMENT ORDER BY DEP_NOM");
    while (afficheDeps.next())
    {
        ui->listWidgetDepartement->addItem(afficheDeps.value(0).toString());
    }
}

void MainWindow::chargerLabo()
{
    //reinitialisation
    ui->listWidgetLabo->clear();

    //affichage des labos
    QSqlQuery afficheLabos("select LAB_NOM FROM LABO ORDER BY LAB_NOM");
    while(afficheLabos.next())
    {
        ui->listWidgetLabo->addItem(afficheLabos.value(0).toString());
    }
}

void MainWindow::viderChampsPrat()
{
    //On rafraichit tout
    ui->lineEditAdressePraticien->clear();
    ui->lineEditCoefNotPraticien->clear();
    ui->lineEditCoefPresPraticien->clear();
    ui->lineEditCPPraticien->clear();
    ui->lineEditNomPraticien->clear();
    ui->lineEditPrenomPraticien->clear();
    ui->lineEditVillePraticien->clear();
    ui->radioButtonNon->setChecked(false);
    ui->radioButtonOui->setChecked(false);
    ui->comboBoxCabinetPraticien->setCurrentIndex(0);
    ui->comboBoxTypePraticien->setCurrentIndex(0);
    this->pra_nom ="";
    this->pra_prenom="";
}

void MainWindow::viderChampsCab()
{
    ui->lineEditLocalCabinet->clear();
    ui->lineEditTelCabinet->clear();
    ui->lineEditVilleCabinet->clear();
    this->cab_nom="";
}

void MainWindow::viderChampMed()
{
    ui->lineEditCompositionMedicament->clear();
    ui->lineEditDepLegalMedicament->clear();
    ui->lineEditNomCommercialMedicament->clear();
    ui->lineEditPrixEchMed->clear();
    ui->textEditContreIndicMedicament->clear();
    ui->textEditEffetsMedicament->clear();
    ui->comboBoxFamilleMedicament->setCurrentIndex(0);
    this->med_depLeg="";
}

void MainWindow::viderChampVis()
{
    ui->lineEditMatriculeVisisteur->clear();
    ui->lineEditNomVisiteur->clear();
    ui->lineEditPrenomVisiteur->clear();
    ui->lineEditAdresseVisiteur->clear();
    ui->lineEditCPVisiteur->clear();
    ui->lineEditVilleVisiteur->clear();
    ui->lineEditDateEmbaucheVisiteur->clear();
    ui->comboBoxDepartementVisiteur->setCurrentIndex(0);
    ui->comboBoxLaboVisiteur->setCurrentIndex(0);
    ui->comboBoxSecteurVisiteur->setCurrentIndex(0);
    ui->radioButtonDelegueNON->setChecked(false);
    ui->radioButtonDelegueOUI->setChecked(false);
    this->vis_nom="";
    this->vis_prenom="";
}

void MainWindow::viderChampDep()
{
    ui->lineEditCodeDepartement->clear();
    ui->lineEditNomDepartement->clear();
    ui->lineEditChefVenteDepartement->clear();
    this->dep_nom="";
}

void MainWindow::viderChampLabo()
{
    ui->lineEditCodeLabo->clear();
    ui->lineEditNomLabo->clear();
    ui->lineEditChefVenteLabo->clear();
    this->lab_nom="";
}

void MainWindow::on_listWidgetPraticiens_clicked(QModelIndex index)
{
    //on recup l'item
    QString nomEntier = ui->listWidgetPraticiens->currentItem()->text();
    //on coupe pour avoir le nom et le prénom séparés
    QStringList nomPrenom = nomEntier.split(" ");

    //on s'assure qu'aucun espace ne traîne
    QString nom= nomPrenom[0];
    QString prenom = nomPrenom[1];

    //au cas ou on va modifier le nom, on enregistre les vieux nom et prenom
    this->pra_nom=nom;
    this->pra_prenom=prenom;
    //qDebug()<<pra_nom+" "+pra_prenom;
    //on recup le reste
    QSqlQuery recup("select PRA_CODE, PRA_NOM, PRA_PRENOM, PRA_ADRESSE, PRA_CP,PRA_VILLE,PRA_COEFNOTORIETE,TYP_CODE,PRA_COEFPRESCRIPTION from PRATICIEN WHERE PRA_NOM='"+nom.trimmed()+"' and PRA_PRENOM='"+prenom.trimmed()+"';");
    recup.next();

    //on affiche
    ui->lineEditNomPraticien->setText(recup.value(1).toString());
    ui->lineEditPrenomPraticien->setText(recup.value(2).toString());
    ui->lineEditAdressePraticien->setText(recup.value(3).toString());
    ui->lineEditCPPraticien->setText(recup.value(4).toString());
    ui->lineEditVillePraticien->setText(recup.value(5).toString());
    ui->lineEditCoefNotPraticien->setText(recup.value(6).toString());
    ui->lineEditCoefPresPraticien->setText(recup.value(8).toString());

    //combobox type de medecin
    QSqlQuery recupType("select TYP_LIBELLE FROM TYPE_PRATICIEN WHERE TYP_CODE='"+recup.value(7).toString()+"';");
    recupType.first();

    int indexCombo = ui->comboBoxTypePraticien->findText(recupType.value(0).toString());
    ui->comboBoxTypePraticien->setCurrentIndex(indexCombo);

    //comboBox cabinet
    QSqlQuery recupCab ("select CAB_LOCAL,REMPLACANT from CABINET NATURAL JOIN TRAVAILLE WHERE PRA_CODE="+recup.value(0).toString());
    recupCab.first();

    //s'il a un cabinet
    int indexCab;
    if(recupCab.value(0).toString()!=NULL)
    {
        indexCab = ui->comboBoxCabinetPraticien->findText(recupCab.value(0).toString());
    }
    else
    {
        indexCab = 0;
    }

        ui->comboBoxCabinetPraticien->setCurrentIndex(indexCab);


    //radiobutton
    if(recupCab.value(1).toInt() == 1)
    {
        ui->radioButtonOui->setChecked(true);
    }
    else
    {
        ui->radioButtonNon->setChecked(true);
    }
}

void MainWindow::on_pushButtonAJoutPraticien_clicked()
{
    //on recup tout
    //->line edit
    QString nom = ui->lineEditNomPraticien->text();
    QString prenom = ui->lineEditPrenomPraticien->text();
    QString adresse = ui->lineEditAdressePraticien->text();
    QString CP = ui->lineEditCPPraticien->text();
    QString ville = ui->lineEditVillePraticien->text();
    QString coefNot = ui->lineEditCoefNotPraticien->text();
    QString coefPres = ui->lineEditCoefPresPraticien->text();

    //->comboBox
    //cabinet
    QString cabNom = ui->comboBoxCabinetPraticien->currentText();
    QSqlQuery recupCabId("select CAB_ID FROM CABINET WHERE CAB_LOCAL='"+cabNom+"'");
    recupCabId.first();
    QString cabId = recupCabId.value(0).toString();

    //type
    QString nomType = ui->comboBoxTypePraticien->currentText();
    QSqlQuery recupTypeId("select TYP_CODE FROM TYPE_PRATICIEN WHERE TYP_LIBELLE='"+nomType+"';");
    recupTypeId.first();
    QString typeId = recupTypeId.value(0).toString();

    //radiobutton
    QString rempl;
    if(ui->radioButtonOui->isChecked())
    {
        rempl="1";
    }
    else
    {
        rempl="0";
    }
    qDebug()<<rempl;

    //id du praticien
    QSqlQuery recupNum("select max(PRA_CODE)+1 FROM PRATICIEN;");
    recupNum.first();
    QString num = recupNum.value(0).toString();

    //on fait les requetes (dans le bon ordre du premier coup, si possible)
    //table praticien (+type)
    QSqlQuery insertPraticien("insert into PRATICIEN VALUES ("+num+",'"+nom+"','"+prenom+"','"+adresse+"','"+CP+"','"+ville+"',"+coefNot+",'"+typeId+"',"+coefPres+")");
    insertPraticien.exec();

    //table travaille (cabinet)
    QSqlQuery insertCab("INSERT INTO TRAVAILLE VALUES ("+cabId+","+num+","+rempl+")");
    insertCab.exec();

    //on retablit
    viderChampsPrat();
    chargerPrat();

}


void MainWindow::on_pushButtonModifierPraticien_clicked()
{
    //on recup tout
    //->line edit
    QString nom = ui->lineEditNomPraticien->text();
    QString prenom = ui->lineEditPrenomPraticien->text();
    QString adresse = ui->lineEditAdressePraticien->text();
    QString CP = ui->lineEditCPPraticien->text();
    QString ville = ui->lineEditVillePraticien->text();
    QString coefNot = ui->lineEditCoefNotPraticien->text();
    QString coefPres = ui->lineEditCoefPresPraticien->text();

    //->comboBox
    //cabinet
    QString cabNom = ui->comboBoxCabinetPraticien->currentText();
    QSqlQuery recupCabId("select CAB_ID FROM CABINET WHERE CAB_LOCAL='"+cabNom+"'");
    recupCabId.first();
    QString cabId = recupCabId.value(0).toString();

    //type
    QString nomType = ui->comboBoxTypePraticien->currentText();
    QSqlQuery recupTypeId("select TYP_CODE FROM TYPE_PRATICIEN WHERE TYP_LIBELLE='"+nomType+"';");
    recupTypeId.first();
    QString typeId = recupTypeId.value(0).toString();

    //radiobutton
    //marche pas, a voir
    QString rempl;
    if(ui->radioButtonOui->isChecked())
    {
        rempl="1";
    }
    else
    {
        rempl="0";
    }

    //l'id du praticien
    QSqlQuery recupIdPrat("select PRA_CODE FROM PRATICIEN WHERE PRA_NOM='"+this->pra_nom+"' AND PRA_PRENOM='"+this->pra_prenom+"';");
    recupIdPrat.first();
    QString idPrat = recupIdPrat.value(0).toString();

    //on modifie
    //praticien (+type)
    QSqlQuery reqPrat("update PRATICIEN set PRA_NOM='"+nom+"', PRA_PRENOM='"+prenom+"', PRA_ADRESSE='"+adresse+"', PRA_CP='"+CP+"', PRA_VILLE='"+ville+"', PRA_COEFNOTORIETE="+coefNot+", TYP_CODE='"+typeId+"', PRA_COEFPRESCRIPTION="+coefPres+" where PRA_CODE="+idPrat+";");
    reqPrat.exec();

    //son cabinet (travaille)
    QSqlQuery modifCab("update TRAVAILLE set CAB_ID="+cabId+", REMPLACANT="+rempl+" where PRA_CODE="+idPrat+";");
    modifCab.exec();

    //on vide tout
    //on charge
    chargerPrat();
    viderChampsPrat();
}

void MainWindow::on_pushButtonSupprPraticien_clicked()
{
    //on recup l'id du praticien
    QSqlQuery recupIdPrat("select PRA_CODE FROM PRATICIEN WHERE PRA_NOM='"+this->pra_nom+"' AND PRA_PRENOM='"+this->pra_prenom+"';");
    recupIdPrat.first();
    QString idPrat = recupIdPrat.value(0).toString();

    //on supprime
    QSqlQuery supprCab("delete from TRAVAILLE where PRA_CODE="+idPrat);
    supprCab.exec();
    QSqlQuery supprPrat("delete from PRATICIEN where PRA_CODE="+idPrat);
    supprCab.exec();

    //on reinitialise
    chargerPrat();
    viderChampsPrat();
}

void MainWindow::on_listWidgetCabinet_clicked(QModelIndex index)
{
    //on recup
    QString nom = ui->listWidgetCabinet->currentItem()->text();
    QString debug = "select CAB_TEL, CAB_VILLE WHERE CAB_LOCAL='"+nom+"'; ";
    QSqlQuery recup("select CAB_TEL, CAB_VILLE from CABINET WHERE CAB_LOCAL='"+nom+"'; ");
    recup.next();
    //en vue d'une modif, on retient le nom de base
    this->cab_nom=nom;

    //on affiche
    ui->lineEditLocalCabinet->setText(nom);
    ui->lineEditTelCabinet->setText(recup.value(0).toString());
    ui->lineEditVilleCabinet->setText(recup.value(1).toString());
}

void MainWindow::on_pushButtonAjoutCabinet_clicked()
{
    //on récup les données
    //lineEdit
    QString nom=ui->lineEditLocalCabinet->text();
    QString tel = ui->lineEditTelCabinet->text();
    QString ville = ui->lineEditVilleCabinet->text();

    //id
    QSqlQuery recupId("select max(CAB_ID)+1 from CABINET;");
    recupId.first();
    QString id=recupId.value(0).toString();

    //on ajoute
    QSqlQuery ajout("insert into CABINET VALUES ("+id+", '"+nom+"', '"+tel+"', '"+ville+"');");
    ajout.exec();

    //on actualise
    chargerCab();
    viderChampsCab();
    //on met aussi a jour la combo de l'onglet praticien
    chargerPrat();
}

void MainWindow::on_pushButtonModifierCabinet_clicked()
{
    //on recup
    QString nom = ui->lineEditLocalCabinet->text();
    QString tel = ui->lineEditTelCabinet->text();
    QString ville = ui->lineEditVilleCabinet->text();

    //on modifie
    QSqlQuery modif("update CABINET set CAB_LOCAL='"+nom+"', CAB_TEL='"+tel+"', CAB_VILLE='"+ville+"' WHERE CAB_LOCAL='"+this->cab_nom+"';");
    modif.exec();

    //on actualise
    chargerCab();
    viderChampsCab();
    //on met aussi a jour la combo de l'onglet praticien
    chargerPrat();
}

void MainWindow::on_pushButtonSupprCabinet_clicked()
{
    //on suppr
    QSqlQuery suppr("delete from CABINET WHERE CAB_LOCAL='"+this->cab_nom+"';");
    suppr.exec();

    //on actualise
    chargerCab();
    viderChampsCab();
    //on met aussi a jour la combo de l'onglet praticien
    chargerPrat();
}

void MainWindow::on_listWidgetMedicaments_clicked(QModelIndex index)
{
    //on recup l'item
    QString nomEntier = ui->listWidgetMedicaments->currentItem()->text();
    //on coupe pour avoir le nom et le prénom séparés
    QStringList nomSplit = nomEntier.split(" , ");

    //on s'assure qu'aucun espace ne traîne
    QString depLeg= nomSplit[0];
    QString nomCom = nomSplit[1];

    //au cas ou on va modifier:
    this->med_depLeg=depLeg;

    //on recup le reste
    QSqlQuery recup("select FAM_CODE, MED_COMPOSITION, MED_EFFETS, MED_CONTREINDIC, MED_PRIXECHANTILLON FROM MEDICAMENT WHERE MED_DEPOTLEGAL='"+depLeg+"';");
    recup.next();

    QString famId = recup.value(0).toString();
    QSqlQuery recupFam("select FAM_LIBELLE FROM FAMILLE WHERE FAM_CODE ='"+famId+"';");
    recupFam.first();

    //on affiche
    ui->lineEditDepLegalMedicament->setText(depLeg);
    ui->lineEditNomCommercialMedicament->setText(nomCom);
    ui->lineEditCompositionMedicament->setText(recup.value(1).toString());
    ui->textEditEffetsMedicament->setText(recup.value(2).toString());
    ui->textEditContreIndicMedicament->setText(recup.value(3).toString());
    ui->lineEditPrixEchMed->setText(recup.value(4).toString());

    //la combo
    int indexCombo = ui->comboBoxFamilleMedicament->findText(recupFam.value(0).toString());
    ui->comboBoxFamilleMedicament->setCurrentIndex(indexCombo);
}

void MainWindow::on_pushButtonAjoutMedicament_clicked()
{
    //on récup les données
    //combo
    QString nomFam = ui->comboBoxFamilleMedicament->currentText();
    QSqlQuery recupFam("select FAM_CODE FROM FAMILLE WHERE FAM_LIBELLE='"+nomFam+"';");
    recupFam.first();
    QString famId = recupFam.value(0).toString();

    //le reste
    QString compo = ui->lineEditCompositionMedicament->text();
    QString depLeg = ui->lineEditDepLegalMedicament->text();
    QString nomCom = ui->lineEditNomCommercialMedicament->text();
    QString prixEch= ui->lineEditPrixEchMed->text();
    QString contreIndic = ui->textEditContreIndicMedicament->toPlainText();
    QString effets = ui->textEditEffetsMedicament->toPlainText();

    //on ajoute
    QSqlQuery ajout("insert into MEDICAMENT VALUES('"+depLeg+"','"+nomCom+"','"+famId+"','"+compo+"','"+effets+"','"+contreIndic+"',"+prixEch+");");
    ajout.exec();

    //on rafraichit
    chargerMed();
    viderChampMed();
  }

void MainWindow::on_pushButtonModifierMedicament_clicked()
{
    //on récup les données
    //combo
    QString nomFam = ui->comboBoxFamilleMedicament->currentText();
    QSqlQuery recupFam("select FAM_CODE FROM FAMILLE WHERE FAM_LIBELLE='"+nomFam+"';");
    recupFam.first();
    QString famId = recupFam.value(0).toString();

    //le reste
    QString compo = ui->lineEditCompositionMedicament->text();
    QString depLeg = ui->lineEditDepLegalMedicament->text();
    QString nomCom = ui->lineEditNomCommercialMedicament->text();
    QString prixEch= ui->lineEditPrixEchMed->text();
    QString contreIndic = ui->textEditContreIndicMedicament->toPlainText();
    QString effets = ui->textEditEffetsMedicament->toPlainText();

    //on modifie
    QSqlQuery modif("update MEDICAMENT SET MED_DEPOTLEGAL='"+depLeg+"', MED_NOMCOMMERCIAL='"+nomCom+"', FAM_CODE='"+famId+"', MED_COMPOSITION='"+compo+"', MED_EFFETS='"+effets+"', MED_CONTREINDIC='"+contreIndic+"', MED_PRIXECHANTILLON="+prixEch+" where MED_DEPOTLEGAL='"+this->med_depLeg+"';");
    modif.exec();

    //on rafraichit
    chargerMed();
    viderChampMed();
}

void MainWindow::on_pushButtonSupprMedicament_clicked()
{
    //on suppr
    QSqlQuery suppr("delete from MEDICAMENT WHERE MED_DEPOTLEGAL='"+this->med_depLeg+"';");
    suppr.exec();

    //on rafraichit
    chargerMed();
    viderChampMed();
}

void MainWindow::on_listWidgetVisiteurs_clicked(QModelIndex index)
{
    //on recup les données
    //l'item
    QString nomEntier = ui->listWidgetVisiteurs->currentItem()->text();
    //on coupe pour avoir le nom et le prénom séparés
    QStringList nomPrenom = nomEntier.split(" ");

    //on s'assure qu'aucun espace ne traîne
    QString nom= nomPrenom[0];
    QString prenom = nomPrenom[1];

    //au cas ou on va modifier le nom, on enregistre les vieux nom et prenom
    this->vis_nom=nom;
    this->vis_prenom=prenom;

    //on recup le reste
    QString chaineReq="select VIS_MATRICULE,VIS_NOM,VIS_PRENOM,VIS_ADRESSE,VIS_CP,VIS_VILLE,VIS_DATEEMBAUCHE,SEC_CODE,LAB_CODE,DEP_CODE,DELEGUE from VISITEUR where VIS_NOM='"+nom+"' and VIS_PRENOM='"+prenom+"';";
    QSqlQuery req(chaineReq);
    req.first();

    //on les affiche
    ui->lineEditMatriculeVisisteur->setText(req.value(0).toString());
    ui->lineEditNomVisiteur->setText(req.value(1).toString());
    ui->lineEditPrenomVisiteur->setText(req.value(2).toString());
    ui->lineEditAdresseVisiteur->setText(req.value(3).toString());
    ui->lineEditCPVisiteur->setText(req.value(4).toString());
    ui->lineEditVilleVisiteur->setText(req.value(5).toString());
    ui->lineEditDateEmbaucheVisiteur->setText(req.value(6).toString());

    //radio box
    if(req.value(10).toInt()==1)
    {
        ui->radioButtonDelegueOUI->setChecked(true);
    }
    else
    {
        ui->radioButtonDelegueNON->setChecked(true);
    }

    //combo secteur

    QSqlQuery secteur("select SEC_LIBELLE from SECTEUR where SEC_CODE='"+req.value(7).toString()+"';");
    secteur.first();

    //s'il a un secteur
    int indexSecteur;
    if(secteur.value(0).toString()!=NULL)
    {
        indexSecteur = ui->comboBoxSecteurVisiteur->findText(secteur.value(0).toString());
    }
    else
    {
        indexSecteur=0;
    }
    ui->comboBoxSecteurVisiteur->setCurrentIndex(indexSecteur);

    //combo labo
    QSqlQuery labo("select LAB_NOM FROM LABO WHERE LAB_CODE='"+req.value(8).toString()+"';");
    labo.first();

    //si il a un labo
    int indexLabo ;
    if(labo.value(0).toString()!=NULL)
    {
        indexLabo= ui->comboBoxLaboVisiteur->findText(labo.value(0).toString());
    }
    else
    {
        indexLabo=0;
    }
    ui->comboBoxLaboVisiteur->setCurrentIndex(indexLabo);

    //combo dep
    QSqlQuery dep("select DEP_NOM from DEPARTEMENT WHERE DEP_CODE='"+req.value(9).toString()+"';");
    dep.first();

    //s'il a un dep
    int indexDep;
    if(dep.value(0).toString()!=NULL)
    {
        indexDep= ui->comboBoxDepartementVisiteur->findText(dep.value(0).toString());
    }
    else
    {
        indexDep=0;
    }
    ui->comboBoxDepartementVisiteur->setCurrentIndex(indexDep);
}

void MainWindow::on_pushButtonAjoutVisiteur_clicked()
{
    QString matricule = ui->lineEditMatriculeVisisteur->text();
    QString nom = ui->lineEditNomVisiteur->text();
    QString prenom = ui->lineEditPrenomVisiteur->text();
    QString adresse = ui->lineEditAdresseVisiteur->text();
    QString CP = ui->lineEditCPVisiteur->text();
    QString ville = ui->lineEditVilleVisiteur->text();
    QString dateEmb = ui->lineEditDateEmbaucheVisiteur->text();

    //le secteur
    QString nomSec=ui->comboBoxSecteurVisiteur->currentText();
    QSqlQuery recupSec("select SEC_CODE FROM SECTEUR WHERE SEC_LIBELLE='"+nomSec+"';");
    recupSec.first();
    QString idSec=recupSec.value(0).toString();

    //le labo
    QString nomLab=ui->comboBoxLaboVisiteur->currentText();
    QSqlQuery recupLab("select LAB_CODE FROM LABO WHERE LAB_NOM='"+nomLab+"';");
    recupLab.first();
    QString idLab = recupLab.value(0).toString();

    //le dep
    QString nomDep = ui->comboBoxDepartementVisiteur->currentText();
    QSqlQuery recupDep("select DEP_CODE FROM DEPARTEMENT WHERE DEP_NOM='"+nomDep+"';");
    recupDep.first();
    QString idDep = recupDep.value(0).toString();

    //le delegue
    QString delegue;
    if(ui->radioButtonDelegueNON->isChecked())
    {
        delegue="0";
    }
    else
    {
        delegue="1";
    }

    //on ajoute
    QString chaineAjoute="insert into VISITEUR VALUES('"+matricule+"','"+nom+"','"+prenom+"','"+adresse+"','"+CP+"','"+ville+"','"+dateEmb+"','"+idSec+"','"+idLab+"','"+idDep+"',"+delegue+")";
    QSqlQuery ajout(chaineAjoute);
    ajout.exec();

    //on rafraichit
    chargerVis();
    viderChampVis();
}

void MainWindow::on_pushButtonModifierVisiteur_clicked()
{
    //on recup les nouvelles données
    QString matricule = ui->lineEditMatriculeVisisteur->text();
    QString nom = ui->lineEditNomVisiteur->text();
    QString prenom = ui->lineEditPrenomVisiteur->text();
    QString adresse = ui->lineEditAdresseVisiteur->text();
    QString CP = ui->lineEditCPVisiteur->text();
    QString ville = ui->lineEditVilleVisiteur->text();
    QString dateEmb = ui->lineEditDateEmbaucheVisiteur->text();

    //le secteur
    QString nomSec=ui->comboBoxSecteurVisiteur->currentText();
    QSqlQuery recupSec("select SEC_CODE FROM SECTEUR WHERE SEC_LIBELLE='"+nomSec+"';");
    recupSec.first();
    QString idSec=recupSec.value(0).toString();

    //le labo
    QString nomLab=ui->comboBoxLaboVisiteur->currentText();
    QSqlQuery recupLab("select LAB_CODE FROM LABO WHERE LAB_NOM='"+nomLab+"';");
    recupLab.first();
    QString idLab = recupLab.value(0).toString();

    //le dep
    QString nomDep = ui->comboBoxDepartementVisiteur->currentText();
    QSqlQuery recupDep("select DEP_CODE FROM DEPARTEMENT WHERE DEP_NOM='"+nomDep+"';");
    recupDep.first();
    QString idDep = recupDep.value(0).toString();

    //le delegue
    QString delegue;
    if(ui->radioButtonDelegueNON->isChecked())
    {
        delegue="0";
    }
    else
    {
        delegue="1";
    }

    //on modifie
    QString chaineModif("update VISITEUR SET VIS_MATRICULE='"+matricule+"',VIS_NOM='"+nom+"',VIS_PRENOM='"+prenom+"',VIS_ADRESSE='"+adresse+"',VIS_CP='"+CP+"',VIS_VILLE='"+ville+"',VIS_DATEEMBAUCHE='"+dateEmb+"',SEC_CODE='"+idSec+"',LAB_CODE='"+idLab+"',DEP_CODE='"+idDep+"',DELEGUE="+delegue+" where VIS_NOM='"+this->vis_nom+"' AND VIS_PRENOM='"+this->vis_prenom+"';");
    QSqlQuery modif(chaineModif);
    modif.exec();

    //on rafraichit
    chargerVis();
    viderChampVis();
}

void MainWindow::on_pushButtonSupprVisiteur_clicked()
{
    //on suppr
    QSqlQuery suppr("delete from VISITEUR WHERE VIS_NOM='"+this->vis_nom+"' AND VIS_PRENOM='"+this->vis_prenom+"';");
    suppr.exec();

    //on rafraichit
    chargerVis();
    viderChampVis();
}

void MainWindow::on_listWidgetDepartement_clicked(QModelIndex index)
{
    //on recup les données
    QString nom = ui->listWidgetDepartement->currentItem()->text();
    QString chaineReq="select DEP_CODE,DEP_CHEFVENTE FROM DEPARTEMENT WHERE DEP_NOM='"+nom+"';";
    QSqlQuery req(chaineReq);
    req.first();

    //on affiche
    ui->lineEditCodeDepartement->setText(req.value(0).toString());
    ui->lineEditNomDepartement->setText(nom);
    ui->lineEditChefVenteDepartement->setText(req.value(1).toString());

    //on enregistre le code en vue d'une eventuelle modif
    this->dep_nom=nom;
}

void MainWindow::on_pushButtonAjoutDepartement_clicked()
{
    //on recup les données
    QString nom = ui->lineEditNomDepartement->text();
    QString code= ui->lineEditCodeDepartement->text();
    QString chef = ui->lineEditChefVenteDepartement->text();

    //on ajoute
    QString chaineAjout="insert into DEPARTEMENT VALUES('"+code+"','"+nom+"','"+chef+"');";
    QSqlQuery ajout(chaineAjout);
    ajout.exec();

    //on rafraichit
    chargerDep();
    viderChampDep();
    //on met aussi a jour la combo de l'onglet visiteur
    chargerVis();
}

void MainWindow::on_pushButtonModifierDepartement_clicked()
{
    //on recup les données
    QString nom = ui->lineEditNomDepartement->text();
    QString chef = ui->lineEditChefVenteDepartement->text();


    //on modifie
    QSqlQuery modif("update DEPARTEMENT SET DEP_NOM='"+nom+"',DEP_CHEFVENTE='"+chef+"' WHERE DEP_NOM='"+this->dep_nom+"';");
    modif.exec();

    //on rafraichit
    chargerDep();
    viderChampDep();
    //on met aussi a jour la combo de l'onglet visiteur
    chargerVis();
}

void MainWindow::on_pushButtonSupprDepartement_clicked()
{
    //on suppr
    QString chaineSuppr="delete from DEPARTEMENT WHERE DEP_NOM='"+this->dep_nom+"';";
    QSqlQuery suppr(chaineSuppr);
    suppr.exec();

    //on rafraichit
    chargerDep();
    viderChampDep();
    //on met aussi a jour la combo de l'onglet visiteur
    chargerVis();
}

void MainWindow::on_listWidgetLabo_clicked(QModelIndex index)
{
    //on recup les données
    QString nom = ui->listWidgetLabo->currentItem()->text();
    //on enregistre en vue d'une eventuelle modif
    this->lab_nom=nom;

    //le reste
    QSqlQuery recupLabo("select LAB_CODE, LAB_CHEFVENTE FROM LABO WHERE LAB_NOM='"+nom+"';");
    recupLabo.first();

    //on affiche
    ui->lineEditCodeLabo->setText(recupLabo.value(0).toString());
    ui->lineEditNomLabo->setText(nom);
    ui->lineEditChefVenteLabo->setText(recupLabo.value(1).toString());
}

void MainWindow::on_pushButtonAjoutLabo_clicked()
{
    //on recup les données
    QString  nom = ui->lineEditNomLabo->text();
    QString code = ui->lineEditCodeLabo->text();
    QString chef = ui->lineEditChefVenteLabo->text();

    //on ajoute
    QSqlQuery ajout ("insert into LABO values ('"+code+"','"+nom+"','"+chef+"')");
    ajout.exec();

    //on rafraichit
   chargerLabo();
   viderChampLabo();
   //on met aussi a jour la combo de l'onglet visiteur
   chargerVis();

}

void MainWindow::on_pushButtonModifierLabo_clicked()
{
    //on recup les données
    QString  nom = ui->lineEditNomLabo->text();
    QString code = ui->lineEditCodeLabo->text();
    QString chef = ui->lineEditChefVenteLabo->text();

    //on modifie
    QString chaineModif = "update LABO set LAB_CODE='"+code+"', LAB_NOM='"+nom+"', LAB_CHEFVENTE='"+chef+"' WHERE LAB_NOM='"+this->lab_nom+"';";
    QSqlQuery modif(chaineModif);
    modif.exec();

    //on rafraichit
    chargerLabo();
    viderChampLabo();
    //on met aussi a jour la combo de l'onglet visiteur
    chargerVis();
}

void MainWindow::on_pushButtonSupprLabo_clicked()
{
    //on suppr
    QSqlQuery suppr("delete from LABO where LAB_NOM='"+this->lab_nom+"';");
    suppr.exec();

    //on rafraichit
    chargerLabo();
    viderChampLabo();
    //on met aussi a jour la combo de l'onglet visiteur
    chargerVis();
}
