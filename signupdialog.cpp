#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "encrypt.h"
#include "bank.h"

SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::on_pushButton_clicked()
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
    for(int t=1;t<=9;t++)
        for(int y=2019;y<=2022;y++)
            for(int m=1;m<=12;m++)
                for(int k=1;k<=31;k++)
                if(decrypt(key, t*100000000+y*10000+m*100+k,
                           t*100000000+y*10000+m*100+k)!=-1){
                    if(queryRecord(ACTIVITY,t,y,m,k)){
                        hide();return;
                    }
                    addRecord(ACTIVITY,t,y,m,k);
                    activityType=t;
                    break;
                }
    hide();
}
