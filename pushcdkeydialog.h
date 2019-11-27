#ifndef PUSHCDKEYDIALOG_H
#define PUSHCDKEYDIALOG_H

#include <QDialog>

namespace Ui {
class PushCDKeyDialog;
}

class PushCDKeyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PushCDKeyDialog(QWidget *parent = nullptr, long long id=0);
    ~PushCDKeyDialog();
    long long userID;
    bool ok;

private slots:
    void on_pushButton_clicked();

private:
    Ui::PushCDKeyDialog *ui;
};

#endif // PUSHCDKEYDIALOG_H
