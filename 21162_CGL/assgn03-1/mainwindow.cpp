#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

using namespace std ;

QImage image(400, 400, QImage::Format_RGB888) ;
QRgb color = qRgb(255,255,255) ;
int initialx, initialy;
int restart = 0;
int stx = 0,sty = 0,angle = 0 ;
int scale[3][3] ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vertices = 0 ;
    start = true ;
    for(int i = 0 ; i<20 ; i++)
        cordi[i][2] = 1 ;
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
          cordi[vertices][0]=p;
          cordi[vertices][1]=q;
          if(restart == 0){
              restart = 1;
              initialx = p;
              initialy = q;
          }
        }

      if(ev->button()==Qt::RightButton){
          dda(cordi[vertices-1][0],cordi[vertices-1][1],cordi[0][0],cordi[0][1]);
           start=false;
      }
      else{
          if(vertices>0)
              dda(cordi[vertices][0],cordi[vertices][1],cordi[vertices-1][0],cordi[vertices-1][1]);
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

void MainWindow::mult(int st[][3]){
    int temp[vertices-1][3] ;
    for (int i = 0; i < vertices-1; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    temp[i][j] += (st[i][k] * cordi[k][j]);

    for(int i = 0; i<vertices-1; i++){
        cordi[i][0] = temp[i][0] ;
        cordi[i][1] = temp[i][1] ;
    }
}

void MainWindow::Draw(){
    for(int i=0;i<vertices-1;i++){
        x1=cordi[i][0];
        y1=cordi[i][1];
        x2=cordi[i+1][0];
        y2=cordi[i+1][1];
        dda(x1,y1,x2,y2);
    }
    dda(initialx, initialy ,cordi[vertices-1][0],cordi[vertices-1][1]);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::scaling(){
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            scale[i][j] = 0 ;
        }
    }

    //on_textEdit_textChanged();
    //on_textEdit_2_textChanged();
    scale[0][0] = stx ;
    scale[1][1] = sty ;
    scale[2][2] = 1 ;

    mult(scale) ;
    Draw() ;
}

void MainWindow::on_pushButton_4_clicked()
{
    scaling();
}
