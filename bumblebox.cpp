#include "bumblebox.h"
#include "ui_bumblebox.h"

#include "newclipdialog.h"


BumbleBox::BumbleBox(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BumbleBox)
{
    ui->setupUi(this);
}

BumbleBox::~BumbleBox()
{
    delete ui;
}


void BumbleBox::on_actionNew_Clip_triggered()
{
    NewClipDialog ncd;
    ncd.setModal(true);
    ncd.exec();
}

void BumbleBox::on_pushButton_clicked()
{

}
