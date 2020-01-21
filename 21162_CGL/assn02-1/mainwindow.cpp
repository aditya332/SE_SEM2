#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>

QImage image(400, 400, QImage::Format_RGB888);
QRgb value = qRgb(0,255,0);
int r1 ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input(){
    QString s1 = ui->plainTextEdit->toPlainText();
    r1 = s1.toInt();
}

void MainWindow::bresenham(){
    input() ;
    int x = 0 , y = r1 ;
    int p = (3 - (2*r1)) ;
    display(200,200,x,y) ;
    while(y >= x){
        x++ ;
        if(p > 0){
            y-- ;
            p = p +(4*(x-y)) + 10 ;
        }
        else
            p = p + (4*x) + 6 ;
        display(200,200,x,y) ;
    }
}

void MainWindow::display(int xc,int yc,int x2,int y2){
    image.setPixel(xc+x2,yc+y2,value) ;
    image.setPixel(xc+x2,yc-y2,value) ;
    image.setPixel(xc-x2,yc+y2,value) ;
    image.setPixel(xc-x2,yc-y2,value) ;
    image.setPixel(xc+y2,yc+x2,value) ;
    image.setPixel(xc+y2,yc-x2,value) ;
    image.setPixel(xc-y2,yc+x2,value) ;
    image.setPixel(xc-y2,yc-x2,value) ;
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::dda(){
      float xc1,xc2,yc1,yc2,eps,sx,sy;
      int val,i;
      xc1=r1/2;
      yc1=0;
      sx=xc1;
      sy=yc1;
      i=0;
      do{
          val=pow(2,i);
          i++;
          }while(val<r1/2);
      eps = 1/pow(2,i-1);
      do{
          xc2 = xc1 + yc1*eps;
          yc2 = yc1 - eps*xc2;
          image.setPixel(200+xc2,200-yc2,value);
          xc1=xc2;
          yc1=yc2;
         }while((yc1-sy)<eps || (sx-xc1)>eps);
      ui->label->setPixmap(QPixmap::fromImage(image));
      ui->label->show();
}

void MainWindow::dda(int x10,int y10,int x20,int y20){
    float dx,dy,c;
    dx = x20 - x10;
    dy = y20 - y10;
    float xi,yi;
    if(abs(dx)>abs(dy))
        c = abs(dx);
    else
        c = abs(dy);
    xi = dx/c;
    yi = dy/c;
    for(int i = 0;i<c;i++){
        image.setPixel(x10+xi,y10+yi,value);
        x10 += xi;
        y10 += yi;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_clicked()
{
    bresenham() ;
    dda() ;
    dda(200,200-r1,200-(0.866*r1),(0.5*r1)+200) ;
}
