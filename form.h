#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include "QTime"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    //void abc();
    ~Form();

private slots:
    void on_pushButton_clicked();
    void timer_timeout();
    void movelabel();
    void keyPressEvent(QKeyEvent *event);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Form *ui;
    QTime t;
    int n;
};

#endif // FORM_H
