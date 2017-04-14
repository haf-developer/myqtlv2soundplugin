#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <soundlv2lib.h>
#include <QTranslator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString GetTestingText();

protected:
    QTranslator *translator;
    // Overrided event handlers
    // Misc. protected functions
    // virtual void changeEvent(QEvent *); //From QWidget
    void changeEvent(QEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    int buttontest=2;
};

#endif // MAINWINDOW_H
