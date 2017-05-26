//Look http://doc.qt.io/qt-5/qtest.html#keyClicks
//And here http://code.qt.io/cgit/
//About testing overall http://www.diva-portal.org/smash/get/diva2:858640/FULLTEXT01.pdf
//http://doc.qt.io/qt-5/qtest.html#keyClicks
//Look more https://community.kde.org/Guidelines_and_HOWTOs/UnitTests

#include <QCoreApplication>
#include <QtTest/QtTest>
#include <QtWidgets>
#include <mainwindow.h>  //Class to be tested


class firstguitest : public QObject
{
    Q_OBJECT

public:
    firstguitest();
    ~firstguitest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1(); //Failing test case
    void testGui();
    void testAppForm();
    void testFormButton();
    void internationalization();


};

firstguitest::firstguitest()
{

}

firstguitest::~firstguitest()
{

}

void firstguitest::initTestCase()
{

}

void firstguitest::cleanupTestCase()
{

}

void firstguitest::testGui()
{
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "hello world");
    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void firstguitest::testAppForm()
{
    MainWindow w;
    w.show();
    QCOMPARE(w.GetTestingText(), QString("plugin init"));
}

void firstguitest::testFormButton()
{
    MainWindow w;
    w.show();
    //Obtain QPushButton from mainwindow.
    //Iterate until QPushButton is found;
    QPushButton *pushButton=NULL;
    pushButton=w.findChild<QPushButton*>();
    if(pushButton!=NULL)
    {
        QSignalSpy spy(pushButton, SIGNAL(clicked(bool)));
        if(spy.count() < 1)
        {
            pushButton->click();
            int i = 0;
            while (w.GetTestingText()!="1" && i++ < 10)
            {
                QTest::qWait(250);
            }
            pushButton->click();
        }
    }
    QCOMPARE(w.GetTestingText(), QString("2"));
}


void firstguitest::internationalization()
{
    bool neverhere=true;
    MainWindow w;
    w.show();
    //Obtain combobox from mainwindow.
    //Iterate until QComboBox is found; Note that this doesn't
    //work with multiple QComboBoxes.
    QComboBox *combotest=NULL;
    combotest=w.findChild<QComboBox*>();
    if(combotest!=NULL)
    {
        QSignalSpy spy(combotest, SIGNAL(currentIndexChanged(int)));
        if(spy.count() < 1)
        {
            //Choose Finnish language from combobox.
            combotest->setCurrentIndex(1);
            if(spy.count() == 1)
            {
                QList<QVariant> arguments = spy.takeFirst(); // take the first signal
                if(arguments.at(0).toInt() >= 1)
                {
                    int i = 0;
                    QString ts=QString("plugin init");
                    while (w.GetTestingText()==ts && i++ < 50)
                    {
                        QTest::qWait(250);
                    }
                    neverhere=false;
                }
            }
        }
    }
    QCOMPARE(w.GetTestingText(), QString("pluginin alustus kerrat"));
}

//Test for failing testcase

void firstguitest::test_case1()
{
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "jello world");
    QCOMPARE(lineEdit.text(), QString("hello world"));
}

QTEST_MAIN(firstguitest)

#include "tst_firstguitest.moc"
