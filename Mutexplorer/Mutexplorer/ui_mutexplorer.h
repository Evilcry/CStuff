/********************************************************************************
** Form generated from reading UI file 'mutexplorer.ui'
**
** Created: Fri 4. Jun 18:45:42 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUTEXPLORER_H
#define UI_MUTEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mutexplorer
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *enumerate;
    QPushButton *save;
    QPushButton *about;
    QPushButton *close;

    void setupUi(QDialog *Mutexplorer)
    {
        if (Mutexplorer->objectName().isEmpty())
            Mutexplorer->setObjectName(QString::fromUtf8("Mutexplorer"));
        Mutexplorer->resize(600, 283);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/MyResources/applications-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Mutexplorer->setWindowIcon(icon);
        layoutWidget = new QWidget(Mutexplorer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 581, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 4);

        enumerate = new QPushButton(layoutWidget);
        enumerate->setObjectName(QString::fromUtf8("enumerate"));

        gridLayout->addWidget(enumerate, 2, 0, 1, 1);

        save = new QPushButton(layoutWidget);
        save->setObjectName(QString::fromUtf8("save"));

        gridLayout->addWidget(save, 2, 1, 1, 1);

        about = new QPushButton(layoutWidget);
        about->setObjectName(QString::fromUtf8("about"));

        gridLayout->addWidget(about, 2, 2, 1, 1);

        close = new QPushButton(layoutWidget);
        close->setObjectName(QString::fromUtf8("close"));

        gridLayout->addWidget(close, 2, 3, 1, 1);


        retranslateUi(Mutexplorer);

        QMetaObject::connectSlotsByName(Mutexplorer);
    } // setupUi

    void retranslateUi(QDialog *Mutexplorer)
    {
        Mutexplorer->setWindowTitle(QApplication::translate("Mutexplorer", "Mutexplorer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Mutexplorer", "Mutex List", 0, QApplication::UnicodeUTF8));
        enumerate->setText(QApplication::translate("Mutexplorer", "Mutex List", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("Mutexplorer", "Dump to File", 0, QApplication::UnicodeUTF8));
        about->setText(QApplication::translate("Mutexplorer", "About", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("Mutexplorer", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mutexplorer: public Ui_Mutexplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUTEXPLORER_H
