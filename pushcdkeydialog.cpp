#include "pushcdkeydialog.h"
#include "ui_pushcdkeydialog.h"
#include "encrypt.h"
#include "bank.h"
#include <QDebug>

PushCDKeyDialog::PushCDKeyDialog(QWidget *parent, long long id) :
    QDialog(parent),
    ui(new Ui::PushCDKeyDialog),
    userID(id),ok(false)
{
    ui->setupUi(this);
}

PushCDKeyDialog::~PushCDKeyDialog()
{
    delete ui;
}

void PushCDKeyDialog::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text();
    long long key=0;
    for(int i=0;i<str.size();i++){
        if(str[i].unicode()<'0'||str[i].unicode()>'9'){
            hide();
            return;
        }
        key=key*10+str[i].unicode()-'0';
    }
    key^=userID;
    qDebug()<<"key="<<key;
    for(int i=2019;i<=2022;i++)
        for(int j=1;j<=12;j++)
            for(int k=1;k<=31;k++)
            if(decrypt(key,i*10000+j*100+k,i*10000+j*100+k)!=-1){
                if(queryRecord(SHARE,0,i,j,k)){
                    hide();return;
                }
                addRecord(SHARE,0,i,j,k);
                ok=true;break;
            }
    hide();
}
