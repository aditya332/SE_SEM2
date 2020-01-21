#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage image(450, 450, QImage::Format_RGB888);
QRgb value = qRgb(0,255,0);
float x1,y1,x2,y2;
int w;

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
    x1 = s1.toFloat();
    QString s2 = ui->plainTextEdit_2->toPlainText();
    y1 = s2.toFloat();
    QString s3 = ui->plainTextEdit_3->toPlainText();
    x2 = s3.toFloat();
    QString s4 = ui->plainTextEdit_4->toPlainText();
    y2 = s4.toFloat();
    QString s5 = ui->plainTextEdit_5->toPlainText();
    w = s5.toInt();
    //ui->plainTextEdit->clear();
    //ui->plainTextEdit_2->clear();
    //ui->plainTextEdit_3->clear();
    //ui->plainTextEdit_4->clear();
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
}
void MainWindow::on_pushButton_clicked()
{
    input();
    dda(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    input();
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
    for(int i = 0;i<c/3;i++){
        image.setPixel(x1+xi,y1+yi,value);
        x1 += xi*3;
        y1 += yi*3;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    input();
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
        if((i%7)!=0 && (i+1)%7!=0 && (i+2)%7!=0)
            image.setPixel(x1+xi,y1+yi,value);
        x1 += xi;
        y1 += yi;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    input();
    int c;

    float y11 = y1,y22 = y2,y111 = y1,y222 = y2;
    for(int i =0;i<w/2;i++){
        dda(x1,y11++,x2,y22++);
        dda(x1,y111--,x2,y222--);
    }
     ui->label->setPixmap(QPixmap::fromImage(image));
     ui->label->show();
}
