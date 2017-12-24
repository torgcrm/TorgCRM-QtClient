#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class About;
}

/**
 * @brief The About class
 * This is form dialog with about application
 * information.
 */
class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
