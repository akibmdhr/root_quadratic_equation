#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QIntValidator"
#include "QMessageBox"

double diskri;
int CoeA;
int CoeB;
int CoeC;
QString valueA;
QString valueB;
QString valueC;
double X1;
double X2;
QString diskriminant;
QString firstRoot;
QString secondRoot;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->letxtA->setValidator(new QIntValidator);
    ui->letxtB->setValidator(new QIntValidator);
    ui->letxtC->setValidator(new QIntValidator);

}

void MainWindow::clearAllTextField(){
    ui->letxtA->clear();
    ui->letxtB->clear();
    ui->letxtC->clear();

    diskri= 0.0;
    CoeA= 0;
    CoeB= 0;
    CoeC= 0;
    X1 = 0.0;
    X2 = 0.0;

}

bool MainWindow::validateAllTextField(){
    valueA = ui->letxtA->text();
    valueB = ui->letxtB->text();
    valueC = ui->letxtC->text();

    CoeA = valueA.toInt();
    CoeB = valueB.toInt();
    CoeC = valueC.toInt();

    if(CoeA != 0 && CoeB != 0 && CoeC != 0)
    {
        return true;
    }else{
        return false;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(validateAllTextField()){
        CoeA = ui->letxtA->text().toInt();
        CoeB = ui->letxtB->text().toInt();
        CoeC = ui->letxtC->text().toInt();

        diskri = (CoeB * CoeB) - (4 * CoeA * CoeC );

        if(diskri > 0)
        {
            X1 = (-CoeB + sqrt(diskri))/ 2* CoeA;
            X2 = (-CoeB - sqrt(diskri))/ 2* CoeA;

            ui->leDis->setText(QString::number(diskri));
            ui->leX1->setText(QString::number(X1));
            ui->leX2->setText(QString::number(X2));




        }else{
            QMessageBox::about(this, "Error","negative discriminant cannot equate to root of Equation of X1 and X2");
        }
        diskriminant = QString::number(diskri);
         firstRoot = QString::number(X1);
          secondRoot = QString::number(X2);

          QString historyEqu = "AX² +BX +C = 0";

          if(CoeA != 1)
          {
               historyEqu.replace("A", QString::number(CoeA));
          }
          else{
               historyEqu.replace("A","");
          }
          if(CoeB < 1 || CoeB < 0 )
          {
              historyEqu.replace("+B", QString::number(CoeB));
          }
          else if(CoeB == 1){
              historyEqu.replace("B","");
          }
          else{
              historyEqu.replace("B", QString::number(CoeB));
               //historyEqu.replace("B","");
          }
          if(CoeC < 0)
          {
             historyEqu.replace("+C", QString::number(CoeC));
          }
          else {
               historyEqu.replace("C", QString::number(CoeC));
          }




           ui->teHistory->append(historyEqu + "     Discriminant = " + diskriminant +"        root1 = " + firstRoot + "      root2 = " + secondRoot);

           clearAllTextField();





    }


}

