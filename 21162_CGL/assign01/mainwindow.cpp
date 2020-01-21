#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_2_clicked()
{
    QImage image(450, 450, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);
    QString s;
    float x1,x2,y1,y2;
    s = ui->textEdit->toPlainText();
    x1 = s.toFloat();
    s = ui->textEdit_2->toPlainText();
    y1 = s.toFloat();
    s = ui->textEdit_3->toPlainText();
    x2 = s.toFloat();
    s = ui->textEdit_4->toPlainText();
    y2 = s.toFloat();

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
        //image.setPixel(x,100,value);
        image.setPixel(x1+xi,y1+yi,value);
        x1 += xi;
        y1 += yi;
    }
    ui->Image->setPixmap(QPixmap::fromImage(image));
    ui->Image->show();
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->Image->clear();
}
