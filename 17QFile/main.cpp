#include <QCoreApplication>
#include <QDir>
#include <QFile>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QDir
    // get path(return 'QDir' Type)
    qDebug() << QDir::current(); // 현재 디렉토리 경로를 반환합니다.
    qDebug() << QDir::home(); // 사용자의 홈 디렉토리 경로를 반환합니다.
    qDebug() << QDir::temp(); // 시스템의 임시 디렉토리 경로를 반환합니다.
    qDebug() << QDir::root(); // 현재 디렉토리 경로의 최상위 경로를 반환 합니다.
    // get path(return 'QString' Type)
    qDebug() << QDir::currentPath(); // 현재 디렉토리 경로를 반환합니다.
    qDebug() << QDir::homePath(); // 사용자의 홈 디렉토리 경로를 반환합니다.
    qDebug() << QDir::tempPath(); // 시스템의 임시 디렉토리 경로를 반환합니다.
    qDebug() << QDir::rootPath(); // 현재 디렉토리 경로의 최상위 경로를 반환 합니다.

//    QDir dir(QDir::currentPath());
     QDir dir(QDir::homePath());
    // QDir dir(QDir::tempPath());
    // QDir dir(QDir::rootPath());

    qDebug() << "dir.mkdir(): " << dir.mkdir("test"); // 디렉토리 생성
    qDebug() << "dir.rename(): " << dir.rename("test", "New"); // 디렉토리 이름 변경
    qDebug() << "dir.exists(): " << dir.exists("New"); // 디렉토리 존재 유무 확인
    qDebug() << "dir.rmdir(): " << dir.rmdir("New"); // 디렉토리 삭제
    qDebug() << "dir.path(): " << dir.path(); // 현재 경로 얻기
    qDebug() << "dir.dirName(): " << dir.dirName(); // 폴더 이름 얻기
    qDebug() << "dir.entryList(): " << dir.entryList(); // 파일&폴더 리스트 얻기
    qDebug() << "dir.isEmpty(): " << dir.isEmpty(); // 파일&폴더 존재 유무 확인



    // QFile
    QFile fileWrite("file.dat");
    // 존재 유무 확인
    if (fileWrite.exists()) //
        qDebug() << "Exist";
    else
        qDebug() << "Not exist";

    // 존재하면 열기
    if (fileWrite.open(QIODevice::ExistingOnly | QIODevice::ReadWrite)) //
    {
        qDebug() << "Exist";
        fileWrite.close();
    }
    else
        qDebug() << "Not exist";

    // 만들면서 열기. 기존 존재하는 파일 있으면 Fail
    if (fileWrite.open(QIODevice::NewOnly | QIODevice::ReadWrite))
    {
        qDebug() << "New file";
        fileWrite.close();
    }
    else
        qDebug() << "New File Fail";

    // 파일을 무조건 새로 만들기.
    if (fileWrite.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        qDebug() << "Truncate file";

        bool bCopy = fileWrite.copy("copy_file.dat"); // 복사 파일 만들기
        qDebug() << "Copy file: " << bCopy;

        bool bRename = fileWrite.rename("new_file.dat"); // 파일 이름 변경
        qDebug() << "Rename file: " << bRename << ", file name: " << fileWrite.fileName();

        bool bDelete = fileWrite.remove("new_file.dat"); // 파일 삭제
        qDebug() << "Delete file: " << bDelete;

        fileWrite.close();
    }
    else
        qDebug() << "Truncate File Fail";

    // write
    QFile file("file.txt");
    if (file.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text))
    {
        //QTextStream out(&file);
        //out << "The magic number is: " << 49 << "\n";

        QByteArray arr;
        arr.append("The magic number is ");
        arr.append("49");
        file.write(arr);

        file.close();
    }
    else
        qDebug() << "Text File Open Fail";

    // read
    if (file.open(QIODevice::Truncate | QIODevice::ReadOnly | QIODevice::Text))
    {
        //QTextStream in(&file);
        //while (!in.atEnd())
        //{
        //    QString line = in.readLine();
        //    qDebug() << "read line: " << line;
        //}

        while (!file.atEnd())
        {
            QByteArray line = file.readLine();
            qDebug() << "read line: " << line;
        }
    }
    else
        qDebug() << "Text File Open Fail";


    return a.exec();
}
