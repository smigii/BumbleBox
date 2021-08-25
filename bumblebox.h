#ifndef BUMBLEBOX_H
#define BUMBLEBOX_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BumbleBox; }
QT_END_NAMESPACE

class BumbleBox : public QMainWindow
    {
        Q_OBJECT

    public:
        BumbleBox(QWidget *parent = nullptr);
        ~BumbleBox();

    private slots:
        void on_actionNew_Clip_triggered();

        void on_pushButton_clicked();

    private:
        Ui::BumbleBox *ui;
    };
#endif // BUMBLEBOX_H
