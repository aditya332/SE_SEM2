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

void MainWindow::on_pushButton_clicked()
{
    QImage image(500, 500, QImage::Format_RGB888);
        QRgb value;
        value=qRgb(0,255,0);
        //draws a line using setPixel() function
        for(int x=50;x<250;++x){
        image.setPixel(x,100,value);
        image.setPixel(200+x,50+x,value);
        image.setPixel(500-x,250+x,value);
        image.setPixel(250,50+x,value);
        image.setPixel(250,150+x,value);
        image.setPixel(250,250+x,value);
        }
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->label->show();
}
