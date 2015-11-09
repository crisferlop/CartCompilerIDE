#include "ide.h"
#include "ui_ide.h"
#include <iostream>
#include "qdebug.h"
#include "y.tab.c"
#include "qfile.h"
#include <QTextBlock>

IDE::IDE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IDE),onEdit(true),lines(1)
{
    ui->setupUi(this);
    ui->langu->setTextColor(QColor(255,255,255));
    ui->langu->setFontWeight(QFont::Bold);
    connect(&mthread,SIGNAL(updateText()),this,SLOT(on_pushButton_clicked()));
    mthread.start();
}

IDE::~IDE()
{
    delete ui;
}


void IDE::on_pushButton_clicked()
{

    mut.lock();
    //QFile *m = new QFile("temp");
    ui->langu->setEnabled(false);
    //m->remove();
    //m->open(QFile::WriteOnly);
    //m->write(ui->langu->toPlainText().toStdString().c_str());
    //m->close();
    QString T =ui->langu->toPlainText();
    QTextCursor cursor = ui->langu->textCursor();
    ui->langu->setText("");
    ui->errors->setText("");
    qDebug() << T;
    //delete m;
    onEdit = true;
    if (T.compare("") != 0)
    test(T.toStdString().c_str(),this);
    ui->langu->setTextCursor(cursor);
    onEdit = false;
    ui->langu->setEnabled(true);
    mut.unlock();
}

void IDE::on_langu_cursorPositionChanged()
{
    //mut.lock();
    if (!onEdit){
        QTextCursor cursor = ui->langu->textCursor();
        Q_ASSERT(ui->langu);
        cursor.movePosition(QTextCursor::StartOfLine);
        lines = 1;
        while(cursor.positionInBlock()>0) {
            cursor.movePosition(QTextCursor::Up);
            lines++;
        }
        QTextBlock block = cursor.block().previous();

        while(block.isValid()) {
            lines += block.lineCount();
            block = block.previous();
        }
        ui->statusBar->showMessage(QString("Linea ").append( QString::number(lines)));
    }
    //mut.unlock();
}
