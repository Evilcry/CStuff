#ifndef MUTEXPLORER_H
#define MUTEXPLORER_H

#include <QDialog>

#include <windows.h>

namespace Ui {
    class Mutexplorer;
}

class Mutexplorer : public QDialog {
    Q_OBJECT
public:
    Mutexplorer(QWidget *parent = 0);
    ~Mutexplorer();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Mutexplorer *ui;
    void Startup(void);
    void Mutexscanner(WCHAR *psxDir);

private slots:
    void on_enumerate_clicked();
    void on_save_clicked();
    void on_about_clicked();
    void on_close_clicked();
};

#endif // MUTEXPLORER_H
