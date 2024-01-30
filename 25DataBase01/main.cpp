#include <QCoreApplication>

#include <QtSql>

/*
 * DB Type
 * MySQL or MariaDB 5.6: QMYSQL
 * Oricle Call Interface Driver: QOCI
 * Open Database Connectivity(ODBC): QODBC
 * PostgreSQL(7.3): QPSQL
 * IBM DB2(7.1): QDB2
 * SQLite Version 3: QSQLITE
 * Borland InterBase: QIBASE
*/

void connectDb()
{
    // 연결 예제
    QSqlDatabase db = QSqlDatabase::addDatabase("QMySQL");

    db.setHostName("host_name"); // IP or DNS Host name
    db.setDatabaseName("database_name"); // Database name
    db.setUserName("userName"); // user name
    db.setPassword("password"); // password
    db.setPort(3000); // port

    bool bOpen = db.open();

    if (bOpen)
    {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS table_name(id INTEGER UNIQUE PRIMARY KEY,\
                    first VARCHAR(30),\
                    second VARCHAR(30))");
    }

}

void connecDbSpecify()
{
    // 두개중 하나 선택하여 쿼리
    QSqlDatabase firstDb;
    QSqlDatabase secondDb;

    firstDb = QSqlDatabase::addDatabase("QMYSQL", "connection_name");
    firstDb.setHostName("host_name"); // IP or DNS Host name
    firstDb.setDatabaseName("database_name"); // Database name
    firstDb.setUserName("userName"); // user name
    firstDb.setPassword("password"); // password
    firstDb.setPort(3000); // port

    // second db blah blah
    secondDb = QSqlDatabase::addDatabase("QMYSQL", "connection_name");
    secondDb.setHostName("host_name"); // IP or DNS Host name
    secondDb.setDatabaseName("database_name"); // Database name
    secondDb.setUserName("userName"); // user name
    secondDb.setPassword("password"); // password
    secondDb.setPort(3001); // port

    QSqlQuery *query = new QSqlQuery(firstDb);

    query->prepare("CREATE TABLE IF NOT EXISTS table_name(id INTEGER UNIQUE PRIMARY KEY,"
                   "first VARCHAR(30),"
                   "second VARCHAR(30))");

    if (query->exec())
        qDebug() << "Create Table";
    else
        qDebug() << "Create Table Fail: " << query->lastQuery();
}

void Database_Handling()
{
    // 데이터베이스 핸들링
    QSqlQuery query;
    query.exec("SELECT first, scond FROM table_name WHERE first == 10");
}

void Access_Result_Set()
{
    // 데이터 Result set 접근
    QSqlQuery query;
    query.exec("SELECT first, scond FROM table_name WHERE first == 10");

    while(query.next())
    {
        QString first = query.value(0).toString();
        QString second = query.value(1).toString();
        qDebug() << "first: " << first << ", second: " << second;
    }
}

void Insert_Query()
{
    // insert 예제
    QSqlQuery query;
    query.exec("INSERT INTO table_name(first, second) VALUES('value1', 100)");
}

void query_placeholder()
{
    // placeholder 방식
    QSqlQuery query;
    query.prepare("INSERT INTO table_name(first, second) VALUES(:first, :second)");

    query.bindValue(":first", "value1");
    query.bindValue(":second", 100);

    query.exec();
}

void query_position_binding()
{
    // position binding 방식
    QSqlQuery query;
    query.prepare("INSERT INTO table_name(first, second) VALUES(?, ?)");

    query.addBindValue("value1");
    query.addBindValue(100);

    query.exec();
}

void example_procedure()
{
    // 프로시저 사용 예제- MariaDB Procedure
    QSqlQuery query;
    query.prepare("create procedure qtestproc(OUT para1 IT, OUT param2 INT)"
                  "BEGIN"
                  "set param1 = 1;"
                  "set param2 = 2;"
                  "END");
    query.exec();
}

void example_out_parameter()
{
    // 프로시저 사용 예제- MariaDB Procedure
    QSqlQuery query;
    query.exec("call qtestproc (@outval1, @outval2)");
    query.exec("select @outval1, @outval2");

    qDebug() << query.value(0) << query.value(1);
}

void example_transaction()
{
    // 트랜잭션, 커밋
    QSqlDatabase::database().transaction();

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.exec("INSERT INTO table_name(first, second) VALUES('value1', 100)");

    QSqlDatabase::database().commit();
}

void example_roll_back()
{
    // 롤백
    QSqlDatabase db = QSqlDatabase::database();

    db.transaction();

    QSqlQuery query(db);
    query.exec("INSERT INTO table_name(first, second) VALUES('value1', 100)");

    db.commit();

    QSqlDatabase::database().commit();
}

void example_hasFeature()
{
    // ...

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    if (db.driver()->hasFeature(QSqlDriver::Transactions))
    {
        // 트랜잭션 지원
    }
    else
    {
        // 트랜잭션 지원 안함
    }
}

void example_BLOB_insert()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS table_name("
               "IMAGE_DATE BLOB)");

    query.prepare("INSERT INTO table_name(IMAGE_DATE) VALUES(?)");


    QByteArray imageData;
    query.bindValue(0, imageData);

    query.exec();
}

void example_BLOB_select()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    query.prepare("SELECT IMAGE_DATA FROM table_name");

    if (query.exec())
    {
        while(query.next())
        {
            QByteArray imageData;
            imageData = query.value(0).toByteArray();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);




    return a.exec();
}
