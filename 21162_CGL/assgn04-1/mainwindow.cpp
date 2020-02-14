#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string>
#include<iostream>

using namespace std ;

QImage image(450, 450, QImage::Format_RGB888);
int r = 0, g = 0,b = 0 ;
QRgb color = qRgb(r,g,b);


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
    string red1 ;
    int redc = qRgb(r,0,0) ;
    red1 = to_string(redc) ;
    QString red2("red1") ;
    ui->verticalScrollBar->setStyleSheet("color : " + red2) ;
}



void MainWindow::on_verticalScrollBar_2_valueChanged(int value)
{
    g = value ;
    color = qRgb(r,g,b) ;
}

void MainWindow::on_verticalScrollBar_3_valueChanged(int value)
{
    b = value ;
    color = qRgb(r,g,b) ;
}

void MainWindow::on_pushButton_clicked()
{

}
