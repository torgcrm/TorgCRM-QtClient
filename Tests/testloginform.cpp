#include <QtTest>

class TestLoginForm: public QObject
{
    Q_OBJECT
private slots:
    void testLoginForm();
};

void TestLoginForm::testLoginForm()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(TestLoginForm)
#include "testloginform.moc"
