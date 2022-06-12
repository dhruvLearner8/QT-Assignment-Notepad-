#include "aboutmedialog.h"
#include "ui_aboutmedialog.h"

AboutMeDialog::AboutMeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMeDialog)
{
    ui->setupUi(this);
}

AboutMeDialog::~AboutMeDialog()
{
    delete ui;
}
