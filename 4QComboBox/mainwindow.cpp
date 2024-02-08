#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/icons/icon_c.ico"), ("1"));
    ui->comboBox->addItem(QIcon(":/icons/icon_d.ico"), ("2"));
    ui->comboBox->addItem(QIcon(":/icons/icon_f.ico"), ("3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::select_combobox()
{

}
