#include "sort1.h"
#include "ui_sort1.h"
#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <iostream>
#include <fstream>
#include <cstring>
#include <QMessageBox>
#include <cstdlib>
#include <time.h>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QStringList>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <main2.h>
using namespace std;

sort1::sort1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sort1)
{
    ui->setupUi(this);
}

sort1::~sort1()
{
    delete ui;
}

class ks
{
public:
    string name;//城市名称
    int year;//年份
    int num;//在校人数
};
class fun1
{
public:
    void shellsort(int arr[100][100],int year,int y,int x,string name[300]);
    void quicksort(int arr[100][100],int year,int y,int l,int x,string name[300]);
    void merge(int arr[100][100],int year,int y,int x,string name[300],int low,int mid,int high);
    void mergesort(int arr[100][100],int year,int y,int x,string name[300],int low,int high);
    void builddatabase(ks a[300],int n,int (&arr)[100][100],int &x,int &y,string name[300],int year[300]);
    void mainks();
    void cchange(int arr[100][100],int y,int x,int year[300]);
};

void sort1::on_pushButton_clicked()
{
    if(ui->textEdit_2->document()->isEmpty())
    {
        QMessageBox::StandardButton result=QMessageBox::critical(ui->pushButton, "wrong","输入为空");
        close();
        sort1 so1;
        so1.exec();
    }
    int sorty=ui->textEdit_2->toPlainText().toInt();
    close();
    string s[300];//储存文本数据
    ks a[300];//类储存文本数据
    fun1 thefun;
    fstream f("imformation.txt");
    string line;
    int i=0;//组数
    while(getline(f,line))
    {
        s[i]=line;
        i++;
    }
    // 将数据存入类中
    for(int j=0;j<i;j++)
    {
        int blackplace1,blackplace2;
        blackplace1 = s[j].find_first_of(' ');
        blackplace2 = s[j].find_last_of(' ');
        a[j].name=s[j].substr(0,blackplace1);
        a[j].year=std::stoi(s[j].substr(blackplace1,blackplace2));
        if(blackplace2==s[j].length()-1)
        {
            a[j].num=0;
        }
        else
        {
            a[j].num=std::stoi(s[j].substr(blackplace2,s[j].length()-1));
        }
    }
    int arr[100][100];
    int x=1;//不同的城市
    int y=1;//不同的年份
    string name[300];
    int year[300];
    thefun.builddatabase(a,i,arr,x,y,name,year);
    int boy=0,truey=0;
    for(int m=0;m<y;m++)
    {
        if(sorty==year[m])
        {
            truey=m;
            boy++;
        }
    }
    if(boy==0)
    {
        QMessageBox::StandardButton result=QMessageBox::critical(ui->pushButton, "wrong","没有这个年份");
        close();
        sort1 so2;
        so2.exec();
    }
    srand((unsigned)time(NULL));
    int ran1=(rand() % 3)+ 1;
    if(ran1==1)
    {
        thefun.shellsort(arr,truey,y,x,name);
    }
    else if(ran1==2)
    {
        thefun.quicksort(arr,truey,y,0,x-1,name);
    }
    else
    {
        thefun.mergesort(arr,truey,y,x,name,0,x-1);
    }
    thefun.cchange(arr,y,x,year);
    QTableWidget *tableWidget = new QTableWidget(x,y+1);
    tableWidget->setWindowTitle("QTableWidget & Item");
    tableWidget->resize(700, 400); //设置表格
    QStringList header;
    for(int m=0;m<y;m++)
    {
        header<<QString::number(year[m]);
    }
    header<<"年变化量";
    header<<QString::fromStdString("tool");
    tableWidget->setHorizontalHeaderLabels(header);
    QStringList header2;
    for(int m=0;m<x;m++)
    {
        header2<<QString::fromStdString(name[m]);
    }
    tableWidget->setVerticalHeaderLabels(header2);
    for(int z=0;z<x;z++)
    {
        for(int c=0;c<y+1;c++)
        {
            tableWidget->setItem(z,c,new QTableWidgetItem(QString::number(arr[z][c])));
        }
    }

    tableWidget->show();
    s2=new sort1();
    s2->show();
}


void sort1::on_pushButton_2_clicked()
{
    close();
    string s[300];//储存文本数据
    ks a[300];//类储存文本数据
    fun1 thefun;
    fstream f("imformation.txt");
    string line;
    int i=0;//组数
    while(getline(f,line))
    {
        s[i]=line;
        i++;
    }
    // 将数据存入类中
    for(int j=0;j<i;j++)
    {
        int blackplace1,blackplace2;
        blackplace1 = s[j].find_first_of(' ');
        blackplace2 = s[j].find_last_of(' ');
        a[j].name=s[j].substr(0,blackplace1);
        a[j].year=std::stoi(s[j].substr(blackplace1,blackplace2));
        if(blackplace2==s[j].length()-1)
        {
            a[j].num=0;
        }
        else
        {
            a[j].num=std::stoi(s[j].substr(blackplace2,s[j].length()-1));
        }
    }
    int arr[100][100];
    int x=1;//不同的城市
    int y=1;//不同的年份
    string name[300];
    int year[300];
    thefun.builddatabase(a,i,arr,x,y,name,year);
    thefun.cchange(arr,y,x,year);
    thefun.shellsort(arr,y,y,x,name);
    QTableWidget *tableWidget = new QTableWidget(x,y+1);
    tableWidget->setWindowTitle("QTableWidget & Item");
    tableWidget->resize(700, 400); //设置表格
    QStringList header;
    for(int m=0;m<y;m++)
    {
        header<<QString::number(year[m]);
    }
    header<<"年变化量";
    header<<QString::fromStdString("tool");
    tableWidget->setHorizontalHeaderLabels(header);
    QStringList header2;
    for(int m=0;m<x;m++)
    {
        header2<<QString::fromStdString(name[m]);
    }
    tableWidget->setVerticalHeaderLabels(header2);
    for(int z=0;z<x;z++)
    {
        for(int c=0;c<y+1;c++)
        {
            tableWidget->setItem(z,c,new QTableWidgetItem(QString::number(arr[z][c])));
        }
    }

    tableWidget->show();
    s2=new sort1();
    s2->show();
}

