#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

using namespace std ;

QImage image(400, 400, QImage::Format_RGB888) ;
QRgb color = qRgb(255,255,255) ;
int initialx, initialy;
int restart = 0;
int stx,sty,angle ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vertices = 0 ;
    start = true ;
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
    dda(200,0,200,400) ;
    dda(0,200,400,200) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::all_disable(){
    ui->label_2->setEnabled(false);
    ui->label_4->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->label_5->setEnabled(false);
    ui->label_6->setEnabled(false);
    ui->textEdit->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    ui->textEdit_3->setEnabled(false);
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start==true){
        if(ev->button()==Qt::LeftButton){
          int p = ev->pos().x();
          int q = ev->pos().y();
          p -= 50 ;
          q -= 50 ;
          a[vertices]=p;
          bb[vertices]=q;
          if(restart == 0){
              restart = 1;
              initialx = p;
              initialy = q;
          }
        }

      if(ev->button()==Qt::RightButton){
          dda(a[vertices-1],bb[vertices-1],a[0],bb[0]);
           start=false;
      }
      else{
          if(vertices>0)
              dda(a[vertices],bb[vertices],a[vertices-1],bb[vertices-1]);
      }
     vertices++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::dda(int x1, int y1, int x2, int y2){
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++){
        image.setPixel(x,y,color);
        x=x+xinc;
        y=y+yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_clicked()
{
    all_disable() ;
    ui->label_2->setEnabled(true);
    ui->label_4->setEnabled(true);
    ui->textEdit->setEnabled(true);
    ui->textEdit_2->setEnabled(true);
    //QLabel l1;
}

void MainWindow::on_pushButton_2_clicked()
{
    all_disable();
    ui->label_3->setEnabled(true);
    ui->label_5->setEnabled(true);
    ui->textEdit->setEnabled(true);
    ui->textEdit_2->setEnabled(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    all_disable();
    ui->label_6->setEnabled(true);
    ui->textEdit_3->setEnabled(true);
}

void MainWindow::on_textEdit_textChanged()
{
    QString str = ui->textEdit->toPlainText() ;
    stx = str.toInt() ;
}

void MainWindow::on_textEdit_2_textChanged()
{
    QString str = ui->textEdit_2->toPlainText() ;
    sty = str.toInt() ;
}

void MainWindow::on_textEdit_3_textChanged()
{
    QString str = ui->textEdit_3->toPlainText() ;
    angle = str.toInt() ;
}
