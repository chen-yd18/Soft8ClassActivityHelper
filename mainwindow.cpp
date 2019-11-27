#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "pushcdkeydialog.h"
#include "signupdialog.h"
#include "bank.h"
#include <stdio.h>
#include <io.h>
#include <qDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    activityType(0)
{
    if(_access("footprint.s8",0)){
        FILE *fp=fopen("footprint.s8","w");
        for(int i=0;i<32768;i++)
            fprintf(fp,"0");
        fclose(fp);
    }
    ui->setupUi(this);
    LoginDialog dialog;
    dialog.exec();
    userID=dialog.userID;
    qDebug()<<userID;
    qDebug()<<(encrypt(320191223));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    PushCDKeyDialog dialog(nullptr, userID);
    dialog.exec();
    if(dialog.ok){
        QMessageBox box(nullptr);
        box.setText("领取成功！你获得了10金币");
        box.exec();
    }
    else{
        QMessageBox box(nullptr);
        box.setText("CDKey无效，是不是一不小心敲错了?");
        box.exec();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(activityType!=0){
        QMessageBox box(nullptr);
        box.setText("已经签过到了哦");
        box.exec();
        return;
    }
     SignupDialog dialog(nullptr);
     dialog.exec();
     activityType=dialog.activityType;
     if(activityType==0){
         QMessageBox box(nullptr);
         box.setText("活动暗号有误，请检查一下");
         box.exec();
     }
     else{
         QMessageBox box(nullptr);
         if(activityType==1)box.setText("集体自习活动 签到成功！");
         else if(activityType==2)box.setText("知识竞答活动 签到成功！");
         else if(activityType==3)box.setText("经验分享讲座 签到成功！");
         else box.setText("其他活动 签到成功！");
         box.exec();
     }
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug()<<queryCoin();
}
