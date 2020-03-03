#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void dda(int x1, int y1, int x2, int y2);
    void all_disable() ;
    void Draw() ;
    void mult(int st[3][3]) ;
    void scaling() ;
    void mousePressEvent(QMouseEvent *ev) ;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_textEdit_3_textChanged();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int cordi[20][3];
    int x1,y1,x2,y2,vertices;
    bool start;
};

#endif // MAINWINDOW_H
