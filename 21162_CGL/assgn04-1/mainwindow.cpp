#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include<string>
#include<iostream>

using namespace std ;

QImage image(450, 450, QImage::Format_RGB888);
QImage pallete(100,25, QImage::Format_RGB888) ;
int r = 100, g = 100,b = 100 ;
QRgb color = qRgb(r,g,b);
int initialx, initialy;
int restart = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pallete.fill(color);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label_5->setPixmap(QPixmap::fromImage(pallete));
    vertices=0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start==true){
          int p = ev->pos().x();
          int q = ev->pos().y();
          a[vertices]=p-25;
          bb[vertices]=q+25;
          if(restart == 0){
              restart = 1;
              initialx = p-25;
              initialy = q+25;
          }

          if(ev->button()==Qt::RightButton){
              dda(a[vertices],bb[vertices],a[0],bb[0]);
               start=false;
          }
          else{
              if(vertices>0){
                  dda(a[vertices],bb[vertices],a[vertices-1],bb[vertices-1]);
              }
          }
     vertices++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::Draw(){
    for(int i=0;i<vertices-1;i++){
        x1=a[i];
        y1=bb[i];
        x2=a[i+1];
        y2=bb[i+1];
        dda(x1,y1,x2,y2);
    }
    dda(initialx, initialy ,a[vertices-1],bb[vertices-1]);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::dda(int x1, int y1, int x2, int y2){
    float dx,dy ;
    float xi,yi ;
    float len ;
    dx=(x2-x1) ;
    dy=(y2-y1) ;
    if(abs(dx) >= abs(dy))
         len = abs(dx) ;
    else
         len = abs(dy) ;

    xi=float( dx/len) ;
    yi=float(dy/len) ;
    float x,y ;
    x=x1 ;
    y=y1 ;
    int i=0 ;
    while(i<len){
        image.setPixel(x,y,color) ;
        x= x + xi ;
        y= y + yi ;
        i++ ;
    }
}

void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    r = value ;
    color = qRgb(r,g,b) ;
    /*string red1 ;
    int redc = qRgb(r,0,0) ;
    red1 = to_string(redc) ;
    QString red2("red1") ;
    ui->verticalScrollBar->setStyleSheet("color : " + red2) ;*/
    pallete.fill(color);
    ui->label_5->setPixmap(QPixmap::fromImage(pallete));
    ui->label_5->show();
    Draw() ;
}

void MainWindow::on_verticalScrollBar_2_valueChanged(int value)
{
    g = value ;
    color = qRgb(r,g,b) ;
    pallete.fill(color);
    ui->label_5->setPixmap(QPixmap::fromImage(pallete));
    ui->label_5->show();
    Draw() ;
}

void MainWindow::on_verticalScrollBar_3_valueChanged(int value)
{
    b = value ;
    color = qRgb(r,g,b) ;
    pallete.fill(color);
    ui->label_5->setPixmap(QPixmap::fromImage(pallete));
    ui->label_5->show();
    Draw() ;
}
/*
void MainWindow::on_pushButton_clicked()
{
    dda(initialx, initialy ,a[vertices-1],bb[vertices-1]);
    vertices=0;
    start=true;
    restart = 0;
}

void MainWindow::on_pushButton_2_clicked(){
    vertices=0;
    start=true;
    restart = 0;
}
*/
void MainWindow::on_pushButton_3_clicked()
{
    vertices=0;
    start=true;
    restart = 0;
    image.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
