#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./mydb.db");

    // db open
    if (!db.open())
        qDebug() << "db open error: " << db.lastError();

    // create table
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS table_student"
                  "(student_no INTEGER UNIQUE PRIMARY KEY, student_name VARCHAR(30), student_department VARCHAR(30))");

    if (!query.exec())
        qDebug() << "create table error: " << query.lastError();

    // insert
    query.prepare("INSERT INTO table_student"
                  "(student_no, student_name, student_department)"
                  "VALUES(1, '홍길동', '컴퓨터공학과')");
    if (!query.exec())
        qDebug() << "Insert Error: " << query.lastError();

    query.prepare("INSERT INTO table_student"
                  "(student_no, student_name, student_department)"
                  "VALUES(2, '김철수', '정보통신공학과')");
    if (!query.exec())
        qDebug() << "Insert Error: " << query.lastError();

    query.prepare("INSERT INTO table_student"
                  "(student_no, student_name, student_department)"
                  "VALUES(3, '박수민', '영어영문학과')");
    if (!query.exec())
        qDebug() << "Insert Error: " << query.lastError();

    query.prepare("INSERT INTO table_student"
                  "(student_no, student_name, student_department)"
                  "VALUES(4, '이은재', '중어중문학과')");
    if (!query.exec())
        qDebug() << "Insert Error: " << query.lastError();

    // table model
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("table_student");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "학번");
    model->setHeaderData(1, Qt::Horizontal, "이름");
    model->setHeaderData(2, Qt::Horizontal, "학과");

    ui->tableView->setModel(model);

    connect(ui->pbtQuery, &QPushButton::clicked, this, &Widget::slot_pbtQuery);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_pbtQuery()
{
    ui->textEdit->clear();

    QSqlQuery query;
    query.prepare("SELECT student_no, student_name FROM table_student");

    if (!query.exec())
        qDebug() << "select error: " << query.lastError();
    else
    {
        QSqlRecord record = query.record();
        int cols = record.count();

        QString strCol;
        for (int iCol = 0 ; iCol < cols ; iCol++)
        {
            strCol = QString("컬럼: %1, 컬럼명: %2").arg(iCol).arg(record.fieldName(iCol));
            ui->textEdit->append(strCol);
        }

        QString strRow;
        for (int iRow = 0 ; query.next() ; iRow++)
        {
            for (int iCol = 0 ; iCol < cols ; iCol++)
            {
                strRow = QString("행: %1, 컬럼명: %2, 데이터: %3").arg(iRow).arg(record.fieldName(iCol)).arg(query.value(iCol).toString());

                ui->textEdit->append(strRow);
            }
        }
    }
}

