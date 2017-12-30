#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

/**
 * @brief The About class
 * This is form dialog with about application
 * information.
 */
class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUT_H
