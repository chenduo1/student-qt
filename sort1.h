#ifndef SORT1_H
#define SORT1_H
#include <QDialog>

namespace Ui {
class sort1;
}

class sort1 : public QDialog
{
    Q_OBJECT

public:
    explicit sort1(QWidget *parent = nullptr);
    ~sort1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sort1 *ui;
//    sort1*so1;
//    sort1*so2;
    sort1*s2;
};
class main2;
#endif // SORT1_H
