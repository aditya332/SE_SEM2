#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
using namespace std;

QImage image(500, 350, QImage::Format_RGB888);
QRgb color = qRgb(255,255,255);
int xs,ys,xe,ye;
int wxs,wys,wxe,wye;
bool lin = false,cli = false;
int crdi[100][4] ,crdi2[100][4], ind = 0 , ind2 = 0;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *eve){
    if(lin){
        if(eve->button()==Qt::LeftButton){
            xs = eve->pos().x();
            ys = eve->pos().y();
            xs -= 50;
            ys -= 50;
            crdi[ind][0] = xs;
            crdi[ind][1] = ys;
        }
    }
    if(cli){
        if(eve->button()==Qt::LeftButton){
            wxs = eve->pos().x();
            wys = eve->pos().y();
            wxs -= 50;
            wys -= 50;
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if(lin){
        if (event->button() == Qt::LeftButton){
            xe = event->pos().x();
            ye = event->pos().y();
            xe -= 50;
            ye -= 50;
            crdi[ind][2] = xe;
            crdi[ind][3] = ye;
            ind++;
            dda(xs-10,ys-10,xe-10,ye-10);
        }
    }
    if(cli){
        if(event->button()==Qt::LeftButton){
            wxe = event->pos().x();
            wye = event->pos().y();
            wxe -= 50;
            wye -= 50;
            dda(wxs-10,wys-10,wxe-10,wys-10);
            dda(wxs-10,wys-10,wxs-10,wye-10);
            dda(wxs-10,wye-10,wxe-10,wye-10);
            dda(wxe-10,wys-10,wxe-10,wye-10);
        }
    }
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

int MainWindow::compute(int x11,int y11){
    int code = INSIDE;
    if (x11 < wxs)
        code |= LEFT;
    else if (x11 > wxe)
        code |= RIGHT;
    if (y11 < wys)
        code |= BOTTOM;
    else if (y11 > wye)
        code |= TOP;
    return code;
}

void MainWindow::clipping(int xs1,int ys1,int xe2,int ye2){
    int code1 = compute(xs1, ys1);
    int code2 = compute(xe2, ye2);
    while(true){
        if ((code1 == 0) && (code2 == 0))
            break;
        else if (code1 & code2)
            break;
        else
        {
            int code_out;
            int x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            if (code_out & TOP)
            {
                x = xs1 + (xe2 - xs1) * (wye - ys1) / (ye2 - ys1);
                y = wye;
            }
            else if (code_out & BOTTOM)
            {
                x = xs1 + (xe2 - xs1) * (wys - ys1) / (ye2 - ys1);
                y = wys;
            }
            else if (code_out & RIGHT)
            {
                y = ys1 + (ye2 - ys1) * (wxe - xs1) / (xe2 - xs1);
                x = wxe;
            }
            else if (code_out & LEFT)
            {
                y = ys1 + (ye2 - ys1) * (wxs - xs1) / (xe2 - xs1);
                x = wxs;
            }
            if (code_out == code1)
            {
                xs1 = x;
                ys1 = y;
                code1 = compute(xs1, ys1);
            }
            else
            {
                xe2 = x;
                ye2 = y;
                code2 = compute(xe2, ye2);
            }
        }
    }
    crdi2[ind2][0] = xs1 ;
    crdi2[ind2][1] = ys1 ;
    crdi2[ind2][2] = xe2 ;
    crdi2[ind2][3] = ye2 ;
    ind2++;
}

void MainWindow::on_pushButton_clicked()
{
    lin = true;
    cli = false;
}

void MainWindow::on_pushButton_2_clicked()
{
    lin = false;
    cli = true;
}

void MainWindow::on_pushButton_3_clicked()
{
    lin = false;
    cli = false;
    for(int i = 0;i<ind;i++){
        crdi[i][0] = 0;
        crdi[i][1] = 0;
        crdi[i][2] = 0;
        crdi[i][3] = 0;
    }
    image.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    for(int i = 0;i<ind;i++){
        clipping(crdi[i][0],crdi[i][1],crdi[i][2],crdi[i][3]);
    }
    image.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
    dda(wxs-10,wys-10,wxe-10,wys-10);
    dda(wxs-10,wys-10,wxs-10,wye-10);
    dda(wxs-10,wye-10,wxe-10,wye-10);
    dda(wxe-10,wys-10,wxe-10,wye-10);
    for(int i = 0;i<ind;i++){
        dda(crdi2[i][0]-10,crdi2[i][1]-10,crdi2[i][2]-10,crdi2[i][3]-10);
    }
    lin = false;
    cli = false;
}
