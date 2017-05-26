#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibraryInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    translator = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::GetTestingText()
{
    return ui->lineEdit_2->text();
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        {
            QString translated = MainWindow::tr("Plugin init times");
            ui->lineEdit_2->setText(translated);
            QString translated2 = QCoreApplication::translate("MainWindow","Plugin init times",
                "Disamb removing");
            ui->lineEdit_2->setText(translated2);

        } else
    {
        QWidget::changeEvent(event);
    }
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

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    bool loadres = false;
    /* For location of QM files there is a problem
     * https://bugreports.qt.io/browse/QTBUG-48416
     *
     */
    QString translatspath = QCoreApplication::applicationDirPath();

    //Remove old transtalor
    if(translator != NULL)
    {
        qApp->removeTranslator(translator);
        delete translator;
    }
    translator = new QTranslator();

    switch (index) {
    case 0:
        loadres = translator->load("testsoundlib_en", translatspath);
        break;
    case 1:
    {
        loadres = translator->load("testsoundlib_fi.qm", translatspath);
        break;
    }
    case 2:
        loadres = translator->load("testsoundlib_se", translatspath);
        break;
    default:
        break;
    }


    if((qApp != 0) && loadres)
    {
        qApp->installTranslator(translator);
    }
}
