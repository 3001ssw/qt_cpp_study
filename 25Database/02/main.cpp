#include <QCoreApplication>

#include <QtSql>

// Database Model Class

void example_qsqlquerymodel()
{
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM table_name");

    for (int i = 0 ; i < model.rowCount() ; i++)
    {
        int first = model.record(i).value("first").toInt();
        QString second = model.record(i).value("second").toString();
    }
}

void example_qsqltablemodel_01()
{
    QSqlTableModel model;
    model.setTable("table_name");
    model.setFilter("100 < first"); // 조건절
    model.setSort(0, Qt::DescendingOrder); // 0번째를 기준으로 내림차순

    for (int i = 0 ; i < model.rowCount() ; i++)
    {
        int first = model.record(i).value("first").toInt();
        QString second = model.record(i).value("second").toString();
    }
}

void example_qsqltablemodel_02()
{
    QSqlTableModel model;
    model.setTable("table_name");

    for (int i = 0 ; i < model.rowCount() ; i++)
    {
        QSqlRecord record = model.record(i);
        int first = record.value("first").toInt();
        first += 10;
        record.setValue("first", first);
        model.setRecord(i, record);
    }

    model.submitAll();
}

void example_qsqltablemodel_03()
{
    QSqlTableModel model;
    model.setTable("table_name");

    model.setData(model.index(0, 0), 200);

    model.submitAll();
}

void example_qsqltablemodel_delete_data()
{
    QSqlTableModel model;
    model.setTable("table_name");

    model.removeRows(0, 10); // 0 ~ 10

    model.submitAll();
}

void example_qsqlrelationaltablemodel()
{
    QSqlTableModel model;
    model.setTable("table_name");
    model.setFilter("100 < first"); // 조건절
    model.setSort(0, Qt::DescendingOrder); // 0번째를 기준으로 내림차순

    for (int i = 0 ; i < model.rowCount() ; i++)
    {
        int first = model.record(i).value("first").toInt();
        QString second = model.record(i).value("second").toString();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlQueryModel queryModel;
    QSqlTableModel tableModel;
    QSqlRelationalTableModel relTableModel;


    return a.exec();
}
