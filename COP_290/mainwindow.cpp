#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include "classes.h"
#include <fstream>
#include<QtGui>
#include<QPainter>
#include <QLabel>
#include <QPicture>
#include<math.h>

#define PI 3.14159265

bool drawTheLines;
using namespace std;
two_d_point combiner_top(three_d_point a){
int x=a.x_extractor();
int y=a.y_extractor();
two_d_point c;
c.setx(x);
c.sety(y);
return c;
}

two_d_point combiner_front(three_d_point b){

int x=b.x_extractor();
int z=b.z_extractor();
two_d_point c;
c.setx(x);
c.sety(z);
return c;
}

two_d_point combiner_side(three_d_point c){

int y=c.y_extractor();
int z=c.z_extractor();
two_d_point d;
d.setx(y);
d.sety(z);
return d;
}


two_d_point top_viewmaker(three_d_point arr){
//We did this to just match it with the first assignment
//cout<<"working\n";
return combiner_top(arr);
}
two_d_point front_viewmaker(three_d_point arr){
//We did this to just match it with the first assignment
return combiner_front(arr);
}
two_d_point side_viewmaker(three_d_point arr){
//We did this to just match it with the first assignment
return combiner_side(arr);
}

bool func(two_d_point a,two_d_point b,int j,int k){

    if((a.getx()-b.getx())!=0){

float m=(a.gety()-b.gety())/(a.getx()-b.getx());
float c=a.gety()-m*(a.getx());
if((k-m*j-c)<=5){
    return true;
}
else{
    return false;
}}
else{

    if((j==a.getx())&&(k<=max(a.gety(),b.gety()))&&(k>=min(a.gety(),b.gety()))){
        return true;
    }
    else{
        return false;
    }
}
}

int fInt=12;
int arraysize=30;
int numl;
int view;
int ag[12],bg[12],cg[12],dg[12];
int ago[100],bgo[100],cgo[100],dgo[100];
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this); // On QPainter::paintEvent;
if(view==1)
p.setPen(Qt::red);
else if(view==2)
    p.setPen(Qt::blue);
else if(view==3)
    p.setPen(Qt::green);
if(m_clicked&&(numl==1)){
    int i=0;
    if(view==1){
    while(i<fInt){
    p.drawLine(ag[i]* 100+370,320+bg[i]*100,cg[i]*100+370,dg[i]*100+320);
    i++;
    }}
    else if(view==2){
        while(i<fInt){
        p.drawLine(ag[i]* 100+370+200,320+bg[i]*100,cg[i]*100+370+200,dg[i]*100+320);
        i++;
        }}
    else{
        while(i<fInt){
        p.drawLine(ag[i]* 100+370+400,320+bg[i]*100,cg[i]*100+370+400,dg[i]*100+320);
        i++;
        }}

    p.setPen(Qt::black);
}
else if(m_clicked&&(numl==2)){

    int i=0;

    while(i<575){
    p.drawLine(ago[i]* 100+370,520+bgo[i]*100,cgo[i]*100+370,dgo[i]*100+520);
    i++;

    }
}
else
p.drawRect(0,0,64,64);

p.end();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    m_clicked=false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw(){


    m_clicked=true;
    update();

}


void MainWindow::on_pushButton_2_clicked()
{
    numl=1;



       ifstream myfile;
       string fileLocation;



    if(numl==1){
    myfile.open("/home/savvy/COP_290/Inputfile.txt");
    //makes sure that the file opened properly
    while(myfile.fail())
    {
        cout << "The file at location " << "Inputfile.txt" << " failed to open" << endl;
        cout << "Please enter the location of the file: ";

        myfile.open("/home/savvy/COP_290/Inputfile.txt");
    }

    //extracts data from the file
    myfile >> fInt ;
int a[6];

three_d_point array[fInt][2];


for(int i=0;i<fInt;i++){
for(int j=0;j<6;j++){
myfile >>a[j];
}
three_d_point point1;
three_d_point point2;
point1.setx(a[0]);
point1.sety(a[1]);
point1.setz(a[2]);
point2.setx(a[3]);
point2.sety(a[4]);
point2.setz(a[5]);

array[i][0]=point1;
array[i][1]=point2;
}
view=1;
//cout<<"Which view do you want"<<endl<<"1. Top view"<<endl<<"2. Front view"<<endl<<"3. side view"<<endl<<"enter the number"<<endl;
//cin>>view;


if(view==1){
for(int i=0;i<fInt;i++){
    cout<<endl;
//    ag=0;
//    bg=0;
//    cg=64;
//    dg=64;
ag[i]=top_viewmaker(array[i][0]).getx();
bg[i]=top_viewmaker(array[i][0]).gety();
cg[i]=top_viewmaker(array[i][1]).getx();
dg[i]=top_viewmaker(array[i][1]).gety();
}
draw();
}


    }
}

void MainWindow::on_pushButton_3_clicked()
{
    numl=1;



       ifstream myfile;
       string fileLocation;



    if(numl==1){
    myfile.open("/home/savvy/COP_290/Inputfile.txt");
    //makes sure that the file opened properly
    while(myfile.fail())
    {
        cout << "The file at location " << "Inputfile.txt" << " failed to open" << endl;
        cout << "Please enter the location of the file: ";

        myfile.open("/home/savvy/COP_290/Inputfile.txt");
    }

    //extracts data from the file
    myfile >> fInt ;
int a[6];

three_d_point array[fInt][2];


for(int i=0;i<fInt;i++){
for(int j=0;j<6;j++){
myfile >>a[j];
}
three_d_point point1;
three_d_point point2;
point1.setx(a[0]);
point1.sety(a[1]);
point1.setz(a[2]);
point2.setx(a[3]);
point2.sety(a[4]);
point2.setz(a[5]);

array[i][0]=point1;
array[i][1]=point2;
}
view=2;
//cout<<"Which view do you want"<<endl<<"1. Top view"<<endl<<"2. Front view"<<endl<<"3. side view"<<endl<<"enter the number"<<endl;
//cin>>view;


if(view==2){
for(int i=0;i<fInt;i++){
    cout<<endl;
//    ag=0;
//    bg=0;
//    cg=64;
//    dg=64;
ag[i]=front_viewmaker(array[i][0]).getx();
bg[i]=front_viewmaker(array[i][0]).gety();
cg[i]=front_viewmaker(array[i][1]).getx();
dg[i]=front_viewmaker(array[i][1]).gety();
}
draw();
}

    }}

void MainWindow::on_pushButton_4_clicked()
{

    numl=1;



       ifstream myfile;
       string fileLocation;



    if(numl==1){
    myfile.open("/home/savvy/COP_290/Inputfile.txt");
    //makes sure that the file opened properly
    while(myfile.fail())
    {
        cout << "The file at location " << "Inputfile.txt" << " failed to open" << endl;
        cout << "Please enter the location of the file: ";

        myfile.open("/home/savvy/COP_290/Inputfile.txt");
    }

    //extracts data from the file
    myfile >> fInt ;
int a[6];

three_d_point array[fInt][2];


for(int i=0;i<fInt;i++){
for(int j=0;j<6;j++){
myfile >>a[j];
}
three_d_point point1;
three_d_point point2;
point1.setx(a[0]);
point1.sety(a[1]);
point1.setz(a[2]);
point2.setx(a[3]);
point2.sety(a[4]);
point2.setz(a[5]);

array[i][0]=point1;
array[i][1]=point2;
}
view=3;
//cout<<"Which view do you want"<<endl<<"1. Top view"<<endl<<"2. Front view"<<endl<<"3. side view"<<endl<<"enter the number"<<endl;
//cin>>view;


if(view==3){
for(int i=0;i<fInt;i++){
    cout<<endl;
//    ag=0;
//    bg=0;
//    cg=64;
//    dg=64;
ag[i]=top_viewmaker(array[i][0]).getx();
bg[i]=top_viewmaker(array[i][0]).gety();
cg[i]=top_viewmaker(array[i][1]).getx();
dg[i]=top_viewmaker(array[i][1]).gety();
}
draw();
}


    }
}




















void MainWindow::on_pushButton_clicked()
{
    numl=2;

       ifstream myfile;
       string fileLocation;
       myfile.open("/home/savvy/COP_290/a.txt");

           //makes sure that the file opened properly
           while(myfile.fail())
           {
               cout << "The file at location " << "a.txt" << " failed to open" << endl;
               cout << "Please enter the location of the file: ";

               myfile.open("/home/savvy/COP_290/a.txt");
           }

           //extracts data from the file
           myfile >> fInt ;

           two_d_point top_view[fInt][2];
           two_d_point front_view[fInt][2];
           two_d_point side_view[fInt][2];
           for (int i = 0; i < fInt; ++i)
           {
               int a,b;
               myfile >> a ;
               myfile >> b ;
               top_view[i][0].setx(a);
               top_view[i][0].sety(b);
               myfile >> a ;
               myfile >> b ;
               top_view[i][1].setx(a);
               top_view[i][1].sety(b);
               /* code */
           }
           for (int i = 0; i < fInt; ++i)
           {
               int a,b;
               myfile >> a ;
               myfile >> b ;
               front_view[i][0].setx(a);
               front_view[i][0].sety(b);
               myfile >> a ;
               myfile >> b ;
               front_view[i][1].setx(a);
               front_view[i][1].sety(b);
               /* code */
           }
           for (int i = 0; i < fInt; ++i)
           {
               int a,b;
               myfile >> a ;
               myfile >> b ;
               side_view[i][0].setx(a);
               side_view[i][0].sety(b);
               myfile >> a ;
               myfile >> b ;
               side_view[i][1].setx(a);
               side_view[i][1].sety(b);
               /* code */
           }
           //Inputs taken

           //This is the array[][] which is 0 first and only 1 if the point is in the view


           int top_array[arraysize][arraysize];
           for (int i = 0; i < arraysize; ++i)
            {
               for (int j = 0; j < arraysize; ++j)
               {
                   top_array[i][j]=0;
                   /* code */
               }
               /* code */
            }
           //using a function that has y=mx + c and passing m and c as
           //parameters and then using that to check whether the given point fits the equation or not and then using that to just change the top_array
            for (int i = 0; i < fInt; ++i)
            {
               for (int j = 0; j <arraysize; ++j)
               {
                   for (int k = 0; k < arraysize; ++k)
                   {
                       if (func(top_view[i][0],top_view[i][1],j,k))
                       {

                           top_array[j][k]=1;
                           cout<<"1\n";
                           /* code */
                       }
                       /* code */
                   }
                   /* code */
               }
               /* code */
            }
            //for front view
            int front_array[arraysize][arraysize];
           for (int i = 0; i < arraysize; ++i)
            {
               for (int j = 0; j < arraysize; ++j)
               {
                   front_array[i][j]=0;
                   /* code */
               }
               /* code */
            }
           //using a function that has y=mx + c and passing m and c as
           //parameters and then using that to check whether the given point fits the equation or not and then using that to just change the front_array
            for (int i = 0; i < fInt; ++i)
            {
               for (int j = 0; j <arraysize; ++j)
               {
                   for (int k = 0; k < arraysize; ++k)
                   {
                       if (func(front_view[i][0],front_view[i][1],j,k))
                       {
                           front_array[j][k]=1;
                           /* code */
                       }
                       /* code */
                   }
                   /* code */
               }
               /* code */
            }




            //for side view
            int side_array[arraysize][arraysize];
           for (int i = 0; i < arraysize; ++i)
            {
               for (int j = 0; j < arraysize; ++j)
               {
                   side_array[i][j]=0;
                   /* code */
               }
               /* code */
            }
           //using a function that has y=mx + c and passing m and c as
           //parameters and then using that to check whether the given point fits the equation or not and then using that to just change the side_array
            for (int i = 0; i < fInt; ++i)
            {
               for (int j = 0; j <arraysize; ++j)
               {
                   for (int k = 0; k < arraysize; ++k)
                   {
                       if (func(side_view[i][0],side_view[i][1],j,k))
                       {
                           side_array[j][k]=1;
                           /* code */
                       }
                       /* code */
                   }
                   /* code */
               }
               /* code */
            }
            int three_d_answer[arraysize][arraysize][arraysize];
            int abd=0;
            for (int i = 0; i < arraysize; ++i)
            {

               for (int j = 0; j < arraysize; ++j)
               {
                   for (int k = 0; k < arraysize; ++k)
                   {
                       three_d_answer[i][j][k]=0;



                       if ((top_array[i][j]==1)&&(front_array[i][k]==1)&&(side_array[j][k]==1))
                       {

                           three_d_answer[i][j][k]=1;
                           float x=i*cos((PI)/6)-k*cos((PI)/6);
                           float y=j-x*sin((PI)/6)-k*sin((PI)/6);
                           ago[abd]=x;
                           bgo[abd]=y;
                           cout<<x<<","<<y<<endl;
                           cgo[abd]=ago[abd]+10;
                           dgo[abd]=bgo[abd++]+10;
                           /* code */

                       }
                       /* code */
                   }
                   /* code */
               }
               /* code */
            }

            draw();

}
