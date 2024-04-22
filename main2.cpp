#include "main2.h"
#include "ui_main2.h"
#include<QMessageBox>
#include <iostream>
#include<fstream>
#include<showdata.h>
using namespace std;

main2::main2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main2)
{
    ui->setupUi(this);
}

main2::~main2()
{
    delete ui;
}



void main2::on_pushButton_clicked()
{
    // 创建并打开一个文本文件
      ofstream MyFile("imformation.txt");
      // 写入文件
      if(ui->textEdit->document()->isEmpty())
      {
          QMessageBox::StandardButton result=QMessageBox::critical(ui->pushButton, "wrong","输入为空");
          close();
          main2 m1;
          m1.exec();
      }
      MyFile << ui->textEdit->toPlainText().toStdString();
      // 关闭文件
      MyFile.close();
      close();

      myshow = new showdata(this);
      myshow->showda();


}


