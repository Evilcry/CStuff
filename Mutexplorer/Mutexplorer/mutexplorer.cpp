#include "mutexplorer.h"
#include "ui_mutexplorer.h"
#include "mutexsupport.h"

#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>

#include <windows.h>

Mutexplorer::Mutexplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mutexplorer)
{
    ui->setupUi(this);
}

Mutexplorer::~Mutexplorer()
{
    delete ui;
}

void Mutexplorer::Startup()
{
    Mutexplorer::Mutexscanner(L"\\");
}

void Mutexplorer::Mutexscanner(WCHAR *pszDir)
{
    HANDLE hObj;
    ULONG ntStatus;
    OBJECT_ATTRIBUTES ObjectAttributes;
    POBJDIR_INFORMATION DirObjInformation;
    UNICODE_STRING UName;
    char szData[1024*2];
    char szBuf[1024*2];
    ULONG dw;
    char szIdentBuf[100];
    ULONG index;
    static int iLevel = 0;

    // set indent of current level

    memset(szIdentBuf, ' ', iLevel * 3);
    szIdentBuf[iLevel * 3] = 0;

    RtlInitUnicodeString(&UName, pszDir);

    InitializeObjectAttributes (
            &ObjectAttributes,
            &UName,
            OBJ_CASE_INSENSITIVE,
            NULL,
            NULL );

    ntStatus = NtOpenDirectoryObject(
            &hObj,
            STANDARD_RIGHTS_READ |
            DIRECTORY_QUERY,
            &ObjectAttributes);

    if(ntStatus == 0)
    {
        index = 0; // start index

        do
        {
            memset(szData, 0, sizeof(szData));
            DirObjInformation = (POBJDIR_INFORMATION)&szData;
            ntStatus = NtQueryDirectoryObject(
                    hObj,
                    DirObjInformation,
                    sizeof(szData),
                    TRUE,
                    FALSE,
                    &index,
                    &dw);

            if(ntStatus == 0)
            {
                szBuf[0] = 0;

                if (wcscmp(DirObjInformation->ObjectTypeName.Buffer,L"Mutant") == 0)
                {
                    QString mutexName = QString::fromWCharArray(DirObjInformation->ObjectName.Buffer);
                    ui->listWidget->addItem(mutexName);
                }

                if(wcscmp(DirObjInformation->ObjectTypeName.Buffer,
                          L"Directory") == 0)
                {

                    iLevel++;

                    if(wcslen(pszDir) &&
                       pszDir[wcslen(pszDir) - 1] == (WCHAR)'\\')
                    {
                        swprintf((WCHAR*)szBuf, L"%s%wZ", pszDir,
                                 &DirObjInformation->ObjectName);
                    }
                    else
                    {
                        swprintf((WCHAR*)szBuf, L"%s\\%wZ", pszDir,
                                 &DirObjInformation->ObjectName);
                    }

                    Mutexscanner((WCHAR*)szBuf);

                    iLevel--;
                }
            }
            else if(ntStatus == 0)
                printf("NtQueryDirectoryObject = 0x%lX (%S)\n", ntStatus,
                       pszDir);
        }
        while(ntStatus == 0);

        CloseHandle(hObj);
    }
    else
        printf("NtOpenDirectoryObject = 0x%lX (%S)\n", ntStatus,
               pszDir);

}

void Mutexplorer::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Mutexplorer::on_close_clicked()
{
    Mutexplorer::close();
}

void Mutexplorer::on_about_clicked()
{
    QMessageBox::about(this,"About Mutexplorer", "Mutexplorer by Giuseppe 'Evilcry' Bonfa "
                      "<a href='http://www.evilcodecave.blogspot.com'>Evilcodecave</a>");

}

void Mutexplorer::on_save_clicked()
{
    if ( ui->listWidget->count() == 0 )
    {
        QMessageBox msgBox;
        msgBox.setText("Before dumping into file you have to List Mutexes");
        msgBox.exec();
    }
    else
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Mutex File Dump"), QDir::currentPath(), tr("Text (*.txt)"));

        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                 return;

        file.write("+------------------------------------------------------+\n");

        for (int i = 0; i < ui->listWidget->count();i++)
        {
            file.write(ui->listWidget->item(i)->text().toUtf8() + "\n");
        }

        file.write("+------------------------------------------------------+\n");
        file.close();
    }

}

void Mutexplorer::on_enumerate_clicked()
{
    Mutexplorer::Startup();
}
