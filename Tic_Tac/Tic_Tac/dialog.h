#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QSlider>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QChar>
#include "widget.h"


class Dialog: public QWidget
{
public:
    Dialog(QWidget *parent = 0);
private:
    QLabel *title;
    QLabel *boardSizeLabel;
    QSlider *slider;
    QGridLayout *grid;
    QLineEdit *user1Input;
    QLineEdit *user2Input;
    QLabel *user1Label;
    QLabel *user2Label;
    QPushButton *btn;
    Widget *w;

private slots:
    void sliderValueChanged();
    void startGame();
};

#endif // DIALOG_H
