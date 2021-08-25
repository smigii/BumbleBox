#ifndef NEWCLIPDIALOG_H
#define NEWCLIPDIALOG_H

#include <memory>

#include <QDialog>

class QFile;
class QMediaPlayer;

namespace Ui {
class NewClipDialog;
}

class NewClipDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit NewClipDialog(QWidget *parent = nullptr);
        ~NewClipDialog();

    private slots:
        void on_pushButton_FileChooser_clicked();

        void on_pushButton_Play_clicked();

        void on_pushButton_SkipStart_clicked();

        void on_pushButton_Stop_clicked();

        void on_pushButton_SkipEnd_clicked();

    private:
        Ui::NewClipDialog *ui;

        std::unique_ptr<QFile> file;

        std::unique_ptr<QMediaPlayer> player;

    };

#endif // NEWCLIPDIALOG_H
