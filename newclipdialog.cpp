#include "newclipdialog.h"
#include "ui_newclipdialog.h"

#include <iostream>

#include <QFile>
#include <QFileDialog>
#include <QMediaPlayer>

NewClipDialog::NewClipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewClipDialog)
{
    ui->setupUi(this);

    player = std::unique_ptr<QMediaPlayer>(new QMediaPlayer(this));
}

NewClipDialog::~NewClipDialog()
{
    delete ui;
}

void NewClipDialog::on_pushButton_FileChooser_clicked()
{
    QString fname = QFileDialog::getOpenFileName(this, tr("Open an Audio File."));

    file = std::unique_ptr<QFile>(new QFile(fname));

    player->setMedia(QUrl::fromLocalFile(fname));

    QFileInfo qfi(file->fileName());
    ui->label_FileName->setText(qfi.fileName());
    ui->label_FileName->setToolTip(file->fileName());
}

void NewClipDialog::on_pushButton_Play_clicked()
{
    static bool play = true;
    if(!player->media().isNull()){

        if(play){
            player->play();
            ui->pushButton_Play->setText("Pause");
        } else {
            player->pause();
            ui->pushButton_Play->setText("Play");
        }
    }

    play = !play;
}

void NewClipDialog::on_pushButton_SkipStart_clicked()
{

}

void NewClipDialog::on_pushButton_Stop_clicked()
{

}

void NewClipDialog::on_pushButton_SkipEnd_clicked()
{

}
