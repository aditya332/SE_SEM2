#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include <QImage>

int main(int argc, char *argv[])
{
    /*QApplication app(argc, argv);
    MainWindow window;
    window.resize(1000, 650); //resize draws window with width and height
    window.setWindowTitle("First example");  //add title on window
    window.show();  //shows the window*/

    QApplication a(argc, argv);
    MainWindow w;
    /*QImage image(300, 300, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0); //set color of pixel as green
    image.setPixel(50,50,value); //draws pixel with value
    image.setPixel(150,150,qRgb(255,255,255)); //draws pixel in white color at x,y
    //position.
    QLabel l;
    //shows pixel on screen
    l.setPixmap(QPixmap::fromImage(image));
    l.show();*/

    QImage image(700, 700, QImage::Format_RGB888);
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
    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();
    return a.exec();
}
