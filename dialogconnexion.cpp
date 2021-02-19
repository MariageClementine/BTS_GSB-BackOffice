#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QTextCodec>
#include <QSqlQuery>
#include <QDebug>



DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
    //prise en compte de l'utf8 pour les chaines en dur dans le code
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    //masquer le mot de passe
    ui->lineEditMdp->setEchoMode(QLineEdit::Password);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

void DialogConnexion::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DialogConnexion::on_pushButtonCo_clicked()
{


    //on récup les données
    QString log =ui->lineEditLog->text();
    QString mdp =ui->lineEditMdp->text();
    QString req="select count(*) from ADMIN WHERE AD_NOM='"+log+"' and DATE_EMBAUCHE='"+mdp+"'";
    //qDebug()<<req;
    QSqlQuery connexion(req);
    connexion.first();
    if(connexion.value(0).toInt()==1)
    {
        accept();
    }
    else
    {
        ui->labelInfo->setText("Erreur de connexion");
        ui->lineEditLog->clear();
        ui->lineEditMdp->clear();
    }


}


void DialogConnexion::on_pushButtonDeco_clicked()
{
    reject();
}
