#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutmedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(filename);  // object for reading and writing file
    currentFile=filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning","cannot open file "+file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);  //reading text
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning","cannot open file "+file.errorString());
        return;
    }
    currentFile=filename;
    setWindowTitle(filename);
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}



void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}



void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    ui->textEdit->textCursor().mergeCharFormat(format);

}


void MainWindow::on_actionUnbold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(QFont::Light);
    ui->textEdit->textCursor().mergeCharFormat(format);
}


void MainWindow::on_actionResume_triggered()
{
    AboutMeDialog abt;
    abt.setModal(true);
    abt.exec();
}


void MainWindow::on_actionIncrease_Font_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(32);
    ui->textEdit->setTextCursor( cursor );
}


void MainWindow::on_actionDecrease_Font_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(16);
    ui->textEdit->setTextCursor( cursor );
}
