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
    //From example at http://doc.qt.io/qt-5/qttestlib-tutorial3-example.html
    void testGui();
    void testAppForm();


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

//Test for failing testcase

void firstguitest::test_case1()
{
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "jello world");
    QCOMPARE(lineEdit.text(), QString("hello world"));
}

QTEST_MAIN(firstguitest)

#include "tst_firstguitest.moc"
