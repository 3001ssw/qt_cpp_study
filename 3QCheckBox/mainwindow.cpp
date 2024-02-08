#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCheckBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pbtnGroup = new QButtonGroup(this);

    const int iCount = 3;
    int iX = 10, iY = 10, iCX = 100, iCY = 30, iGap = 10;
    QString str[iCount] = {"check&1", "check&2", "check&3"};
    for (int iIndex = 0 ; iIndex < iCount ; iIndex++)
    {
        QCheckBox *pCheckBox = new QCheckBox(str[iIndex], this);
        pCheckBox->setGeometry(iX, iY, iCX, iCY);

        m_pbtnGroup->addButton(pCheckBox);
        m_pbtnGroup->setId(pCheckBox, iIndex);
        iY += iCY + iGap;

        connect(pCheckBox, SIGNAL(clicked()), this, SLOT(checkbox_clicked()));
    }

    m_pbtnGroup->setExclusive(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkbox_clicked()
{
    int iID = m_pbtnGroup->checkedId();
    qDebug() << "checkbox clicked!! button id: " << iID;
}
