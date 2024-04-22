#include "showdata.h"
#include "ui_showdata.h"
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
#include <main2.h>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QStringList>
#include <QString>
#include <QPushButton>
#include <QDebug>
using namespace std;
showdata::showdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showdata)
{
    ui->setupUi(this);

}

showdata::~showdata()
{
    delete ui;
}

// 定义城市类
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
// 希尔排序
void fun1::shellsort(int arr[100][100],int year,int y,int x,string name[300])
{
    for(int gap=x/2;gap>0;gap=gap/2)
    {
        for(int i=0;i<gap;i++)
        {
            for(int j=i+gap;j<x;j+=gap)
            {
                if(arr[j-gap][year]<arr[j][year])
                {
                    int temp=arr[j][year];
                    int ytemp[100];
                    for(int m=0;m<y;m++)
                    {
                        ytemp[m]=arr[j][m];
                    }
                    string stemp=name[j];
                    int k;
                    for(k=j-gap;k>=0;k-=gap)
                    {
                        if(arr[k][year]>temp)
                        {
                            break;
                        }
                        arr[k+gap][year]=arr[k][year];
                        for(int m=0;m<y;m++)
                        {
                            arr[k+gap][m]=arr[k][m];
                        }
                        name[k+gap]=name[k];
                    }
                    arr[k+gap][year]=temp;
                    for(int m=0;m<y;m++)
                    {
                        arr[k+gap][m]=ytemp[m];
                    }
                    name[k+gap]=stemp;
                }
            }
        }
    }
}
// 快速排序
void fun1::quicksort(int arr[100][100],int year,int y,int l,int x,string name[300])
{
    if (l<x)
    {
        int i=l,j=x,temp=arr[l][year];
        int ytemp[100];
        for(int m=0;m<y;m++)
        {
            if(m==year)
                continue;
            ytemp[m]=arr[l][m];
        }
        string stemp=name[l];
        while (i<j)
        {
            while(i<j&&arr[j][year]<=temp)
                j--;
            if(i < j)
            {
                for(int m=0;m<y;m++)
                {
                    if(m==year)
                        continue;
                    arr[i][m]=arr[j][m];
                }
                name[i]=name[j];
                arr[i++][year]=arr[j][year];

            }
            while(i<j&&arr[i][year]>temp)
                i++;
            if(i<j)
            {
                for(int m=0;m<y;m++)
                {
                    if(m==year)
                        continue;
                    arr[j][m]=arr[i][m];
                }
                name[j]=name[i];
                arr[j--][year]=arr[i][year];

            }

        }
        for(int m=0;m<y;m++)
        {
            if(m==year)
                continue;
            arr[i][m]=ytemp[m];
        }
        name[i]=stemp;
        arr[i][year]=temp;
        quicksort(arr,year,y,l,i-1,name);
        quicksort(arr,year,y,i+1,x,name);
    }
}
// 归并排序
void fun1::merge(int arr[100][100],int year,int y,int x,string name[300],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int temp[100];
    int ytemp[100][100];
    string stemp[100];
    while(i<=mid&&j<=high)
    {
        if(arr[i][year]>=arr[j][year])
        {
            for(int m=0;m<y;m++)
            {
                if(m==year)
                    continue;
                ytemp[k][m]=arr[i][m];
            }
            stemp[k]=name[i];
            temp[k++]=arr[i++][year];
        }
        else
        {
            for(int m=0;m<y;m++)
            {
                if(m==year)
                    continue;
                ytemp[k][m]=arr[j][m];
            }
            stemp[k]=name[j];
            temp[k++]=arr[j++][year];
        }
    }
    while(i<=mid)
    {
        for(int m=0;m<y;m++)
        {
            if(m==year)
                continue;
            ytemp[k][m]=arr[i][m];
        }
        stemp[k]=name[i];
        temp[k++]=arr[i++][year];
    }
    while(j<=high)
    {
        for(int m=0;m<y;m++)
        {
            if(m==year)
                continue;
            ytemp[k][m]=arr[j][m];
        }
        stemp[k]=name[j];
        temp[k++]=arr[j++][year];
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        for(int m=0;m<y;m++)
        {
            if(m==year)
                continue;
            arr[i][m]=ytemp[k][m];
        }
        name[i]=stemp[k];
        arr[i][year]=temp[k];
    }
}
void fun1::mergesort(int arr[100][100],int year,int y,int x,string name[300],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid =  low + (high - low)/2;
    mergesort(arr,year,y,x,name,low,mid);
    mergesort(arr,year,y,x,name,mid+1,high);
    merge(arr,year,x,y,name,low,mid,high);
}
// 整理类中的数据
void fun1::builddatabase(ks a[300],int n,int (&arr)[100][100],int &x,int &y,string name[300],int year[300])
{
    name[0]=a[0].name;
    year[0]=a[0].year;
    for(int i=1;i<n;i++)
    {
        int b1=0,b2=0;//判断是否与前面相同
        for(int q=0;q<x;q++)
        {
            if(a[i].name==name[q])
            {
                b1++;
            }
        }
        if(b1==0)
        {
            name[x]=a[i].name;
            x++;
        }
        for(int q=0;q<y;q++)
        {
            if(a[i].year==year[q])
            {
                b2++;
            }
        }
        if(b2==0)
        {
            year[y]=a[i].year;
            y++;
        }
    }
    // 冒泡排序年份
    for(int i=0;i<y-1;i++)
    {
        for(int i=0;i<y-1;i++)
        {
            if(year[i]>year[i+1])
            {
                int temp=year[i];
                year[i]=year[i+1];
                year[i+1]=temp;
            }
        }
    }
    // 初始化
    for(int p=0;p<x;p++)
    {
        for(int q=0;q<y;q++)
        {

            arr[p][q]=0;
        }
    }
    // 再次遍历将数据填入二维数组
    for(int i=0;i<n;i++)
    {
        for(int p=0;p<x;p++)
        {
            for(int q=0;q<y;q++)
            {
                if(a[i].name==name[p]&&a[i].year==year[q])
                {
                    if(arr[p][q]!=0)
                    {
                        QMessageBox::StandardButton result=QMessageBox::critical(NULL, "wrong","重复输入");
                        main2 m1;
                        m1.exec();
                    }
                    arr[p][q]=a[i].num;
                }
            }
        }
    }

}
// 计算年平均率
void fun1::cchange(int arr[100][100],int y,int x,int year[300])
{

    for(int i=0;i<x;i++)
    {
        int a=y;
        int temp1=0,year1=0;
        int temp2=0,year2=0;
        int v=0;
        for(int j=0;j<y;j++)
        {
            if(arr[i][j]==0)
            {
                a--;
            }
            else
            {
                if(temp1==0)
                {
                    temp1=arr[i][j];
                    year1=year[j];
                }
                else
                {
                    if(temp2==0)
                    {
                        temp2=arr[i][j];
                        year2=year[j];
                    }
                    else
                    {
                        v+=(temp2-temp1)/(year2-year1);
                        temp1=0;
                        temp2=0;
                    }
                }
            }
        }
        if(a==1)
        {
            arr[i][y]=-1;
        }
        else
        {
            arr[i][y]=v/(a/2);
        }
    }
}
void showdata::showda()
{
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
    QTableWidget *tableWidget = new QTableWidget(x,y+1);
    tableWidget->setWindowTitle("QTableWidget & Item");
    tableWidget->resize(700, 400); //设置表格
    QStringList header;
    for(int m=0;m<y;m++)
    {
        header<<QString::number(year[m]);
    }
    header<<"年变化量";
    tableWidget->setHorizontalHeaderLabels(header);
    QStringList header2;
    for(int m=0;m<x;m++)
    {
        header2<<QString::fromStdString(name[m]);
    }
    tableWidget->setVerticalHeaderLabels(header2);
    thefun.cchange(arr,y,x,year);
    for(int z=0;z<x;z++)
    {
        for(int c=0;c<y+1;c++)
        {
            tableWidget->setItem(z,c,new QTableWidgetItem(QString::number(arr[z][c])));
        }
    }
//    auto button = new QPushButton(QStringLiteral("排序"), tableWidget);
//    button->setFixedSize(50,25);
//    auto cellWidget = new QWidget(this);
//    auto layout = new QHBoxLayout(cellWidget);
//    layout ->addWidget(button);
//    cellWidget->setLayout(layout);
//    tableWidget->setCellWidget(0, y+1, cellWidget);
//    connect(button, SIGNAL(clicked()), this, SLOT(onTableBtnClicked()));
//    QPushButton*button=new QPushButton("1");
//    QStandardItemModel *tableModel = new QStandardItemModel(this);
//    tableWidget->setModel(tableModel);
//    button->setProperty("status", "normal");
//    connect(button, SIGNAL(clicked()), this, SLOT(onTableBtnClicked()));
//    tableWidget->setCellWidget(0,y+1,button);
//    QPushButton *button = new QPushButton("Start");

//    // set custom property
//    button->setProperty("id", 1); // set custom property
//    button->setProperty("name", QString("hello qt tablview %1").arg(1));
//    button->setProperty("status", "normal");
//    connect(button, SIGNAL(clicked()), this, SLOT(this->onTableBtnClicked()));
//    tableWidget->setCellWidget(1,3,button);



    tableWidget->show();
    s2=new sort1();
    s2->show();


}

void showdata::on_pushButton_clicked()
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
    srand((unsigned)time(NULL));
    int ran1=(rand() % 3)+ 1;
    if(ran1=1)
    {
        for(int m=0;m<y;m++)
        {
            thefun.shellsort(arr,m,y,x,name);
        }
    }
    else if(ran1=2)
    {
        for(int m=0;m<y;m++)
        {
            thefun.quicksort(arr,m,y,0,x-1,name);
        }
    }
    else
    {
        for(int m=0;m<y;m++)
        {
            thefun.mergesort(arr,m,y,x,name,0,x-1);
        }

    }
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
    thefun.cchange(arr,y,x,year);
    for(int z=0;z<x;z++)
    {
        for(int c=0;c<y+1;c++)
        {
            tableWidget->setItem(z,c,new QTableWidgetItem(QString::number(arr[z][c])));
        }
    }
//    auto button = new QPushButton(QStringLiteral("排序"), tableWidget);
//    button->setFixedSize(50,25);
//    auto cellWidget = new QWidget(this);
//    auto layout = new QHBoxLayout(cellWidget);
//    layout ->addWidget(button);
//    cellWidget->setLayout(layout);
//    tableWidget->setCellWidget(0, y+1, cellWidget);
//    connect(button, SIGNAL(clicked()), this, SLOT(onTableBtnClicked()));

//    QPushButton*button=new QPushButton("1");
//    QStandardItemModel *tableModel = new QStandardItemModel(this);
//    tableWidget->setModel(tableModel);
//    button->setProperty("status", "normal");
//    connect(button, SIGNAL(clicked()), this, SLOT(onTableBtnClicked()));
//    tableWidget->setCellWidget(0,y+1,button);

    tableWidget->show();


}

