#ifndef SHOWDATA_H
#define SHOWDATA_H

#include <QDialog>
#include <sort1.h>
#include <QMessageBox>
namespace Ui {
class showdata;
}

class showdata : public QDialog
{
    Q_OBJECT

public:
    explicit showdata(QWidget *parent = nullptr);
    ~showdata();
    void showda();


private slots:
    void on_pushButton_clicked();


private:
    Ui::showdata *ui;
    showdata *s1;
    sort1 *s2;

};

#endif // SHOWDATA_H
