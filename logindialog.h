#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "encrypt.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    long long userID;

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
