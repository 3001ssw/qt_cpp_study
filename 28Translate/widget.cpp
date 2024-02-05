#include "widget.h"
#include "ui_widget.h"

/*
1. 프로젝트에 TRANSLATION 추가
2. tr() 함수를 소스에서 호출
3. .ts 파일 생성(lupdate)
4. Qt Linguist 실행
5. .qm 파일 생성(lrelease)
6. 소스코드에 qm 파일 추가


1. .pro에 TRANSLATIONS = korean.ts 추가
2. tr("hello")
3. .ts 파일 생성
3-1. tools -> external -> linguist -> update translation(lupdate) 실행
3-2. prompt> lupdate -verbose translation_example.pro
4. linguist 실행(qt 설치폴더에 linguist 있음). ts파일 불러오기
5. .qm 파일 생성
5-1. tools -> external -> linguist -> release translation(lrelease) 실행
5-2. lrelease translate_example.pro
6. qm 파일 추가
QTranslator translator;
translator.load(":/Translator/korean.qm");
QApplication::installTransllator(&translator);


*/

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton2->setText(tr("hello"));
}

Widget::~Widget()
{
    delete ui;
}

