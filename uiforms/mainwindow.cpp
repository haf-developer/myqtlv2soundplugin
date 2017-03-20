#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //TODO
    //Using QLibrary to load the shared library
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::GetTestingText()
{
    return ui->lineEdit_2->text();
}

void MainWindow::on_pushButton_clicked()
{
    //Something to show that button was clicked.
    ui->lineEdit->setText("Pushed");
    int myproblem = 100;

    Soundlv2lib& mysound=Soundlv2lib::Instance();
    myproblem = mysound.Init();

    QString problemtext=QString::number(myproblem);
    ui->lineEdit_2->setText(problemtext);
}
