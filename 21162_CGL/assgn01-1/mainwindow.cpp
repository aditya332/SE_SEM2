#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage image(450, 450, QImage::Format_RGB888);
QRgb value = qRgb(0,255,0);

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

//Bresenham's Square
void MainWindow::Bresenham(int x1,int y1,int x2,int y2){
    int dx,dy,p;
    dx = x2-x1 ;
    dy = y2 - y1 ;
    if(abs(dx)>abs(dy))
        {
            p=2*dy-dx;
            while(x1<=x2)
            {
                 image.setPixel(x1,y1,value);
                x1++;
                if(p<0)
                {
                    p=p+2*dy;
                }
                else
                {
                    p=p+2*dy-2*dx;
                    y1++;
                }
            }
        }
        else if(abs(dx)<abs(dy))
        {
            p=2*dx-dy;
            while(y1<=y2)
            {
                 image.setPixel(x1,y1,value);
                y1++;
                if(p<0)
                {
                    p=p+2*dx;
                }
                else
                {
                    p=p+2*dx-2*dy;
                    x1++;
                }
            }
        }
        else
        {
            while(x1<=x2)
            {
                image.setPixel(x1,y1,value);
                x1++;
                y1++;
            }
    }


    /*while(x <= x2){
        image.setPixel(x,y,value);
        x++;
        if(p < 0)
                p += (2*dy) ;
        else{
             p += (2*dy) - dx ;
             y++;
        }
    }*/
}

void MainWindow::on_pushButton_clicked()
{
    Bresenham(25,25,425,25);
    Bresenham(425,25,425,425);
    Bresenham(25,425,425,425);
    Bresenham(25,25,25,425);
    Bresenham(125,125,325,125);
    Bresenham(325,125,325,325);
    Bresenham(125,325,325,325);
    Bresenham(125,125,125,325);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::dda(int x1,int y1,int x2,int y2){
    float dx,dy,c;
    dx = x2 - x1;
    dy = y2 - y1;
    float xi,yi;
    if(abs(dx)>abs(dy))
        c = abs(dx);
    else
        c = abs(dy);
    xi = dx/c;
    yi = dy/c;
    for(int i = 0;i<c;i++){
        image.setPixel(x1+xi,y1+yi,value);
        x1 += xi;
        y1 += yi;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    dda(225,25,25,225);
    dda(225,25,425,225);
    dda(425,225,225,425);
    dda(225,425,25,225);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
