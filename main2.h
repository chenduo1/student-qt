#ifndef MAIN2_H
#define MAIN2_H

#include <QDialog>
#include <showdata.h>
namespace Ui {
class main2;
}

class main2 : public QDialog
{
    Q_OBJECT

public:
    explicit main2(QWidget *parent = nullptr);
    ~main2();

private slots:

    void on_pushButton_clicked();

private:
    Ui::main2 *ui;
    showdata *myshow;
};

#endif // MAIN2_H
