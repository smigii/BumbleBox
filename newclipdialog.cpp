#include "newclipdialog.h"
#include "ui_newclipdialog.h"

#include <iostream>

#include <QFile>
#include <QFileDialog>
#include <QMediaPlayer>

#define PLAY    "Play"
#define PAUSE   "Pause"
#define STOP    "STOP"
#define SKIPS   "|<<"
#define SKIPE   ">>|"

NewClipDialog::NewClipDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::NewClipDialog)
{
    ui->setupUi(this);
    ui->pushButton_Play->setText(PLAY);
    ui->pushButton_Stop->setText(STOP);
    ui->pushButton_SkipStart->setText(SKIPS);
    ui->pushButton_SkipEnd->setText(SKIPE);

    playing = false;
    player = std::unique_ptr<QMediaPlayer>(new QMediaPlayer(this));
    player->setNotifyInterval(1);

    nodeTimeChecked = false;
    ui->checkBox_NodeTime->setChecked(false);

    connect(player.get(), &QMediaPlayer::positionChanged, this, &NewClipDialog::on_positionChanged);
    connect(player.get(), &QMediaPlayer::durationChanged, this, &NewClipDialog::on_durationChanged);
}

NewClipDialog::~NewClipDialog()
{
    delete ui;
}

void NewClipDialog::on_pushButton_FileChooser_clicked()
{
    QString fname = QFileDialog::getOpenFileName(this,
    tr("Open an Audio File."),
    tr("/home/smigii/.bumblebox"));

    file = std::unique_ptr<QFile>(new QFile(fname));

    player->setMedia(QUrl::fromLocalFile(fname));

    QFileInfo qfi(file->fileName());
    ui->label_FileName->setText(qfi.fileName());
    ui->label_FileName->setToolTip(file->fileName());
}

void NewClipDialog::on_pushButton_Play_clicked()
{
    if(!player->media().isNull()){

        if(!playing){
            player->play();
            ui->pushButton_Play->setText(PAUSE);
        } else {
            player->pause();
            ui->pushButton_Play->setText(PLAY);
        }

        playing = !playing;
    }

}

void NewClipDialog::on_pushButton_SkipStart_clicked()
{
    if(!player->media().isNull())
        player->setPosition(0);
}

void NewClipDialog::on_pushButton_Stop_clicked()
{
    if(!player->media().isNull()){
        player->stop();
        ui->pushButton_Play->setText(PLAY);
        playing = false;
    }
}

void NewClipDialog::on_pushButton_SkipEnd_clicked()
{
    if(!player->media().isNull()){
        qint64 end = player->duration();
        playing = false;
        player->setPosition(end);
        ui->pushButton_Play->setText(PLAY);
    }
}

void NewClipDialog::on_positionChanged(qint64 pos)
{
    ui->horizontalSlider_Progress->setValue(pos);

    int s = (pos / 1000) % 60;
    int m = (pos / 60000) % 60;
    int h = (pos / 3600000);
    int ms = pos % 1000;
    QTime time(h, m, s, ms);

    ui->timeEdit_Time->setTime(time);

}

void NewClipDialog::on_durationChanged(qint64 pos)
{
    ui->horizontalSlider_Progress->setMaximum(pos);
}
