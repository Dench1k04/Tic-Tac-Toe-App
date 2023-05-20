#include "dialog.h"
#include "gamestate.h"
#include "board.h"
#include <iostream>

using namespace std;

Dialog::Dialog(QWidget *parent) : QWidget(parent)
{

   title = new QLabel("Welcome to our app!", this);
   title->setGeometry(45,30,200,40);
   title->setStyleSheet("font-size: 20px;");
   user1Input = new QLineEdit();
   user2Input = new QLineEdit();
   user1Input->setText("user 1");
   user2Input->setText("user 2");

   user1Label = new QLabel("User 1 name");
   user2Label = new QLabel("User 2 name");

   slider = new QSlider(Qt::Horizontal,this);
   slider->setMaximum(10);
   slider->setMinimum(3);
   slider->setMaximumWidth(200);

   boardSizeLabel = new QLabel(QString::number(slider->minimum()), this);

   btn = new QPushButton("Start");


   connect(slider, &QSlider::valueChanged,this, &Dialog::sliderValueChanged);
   connect(btn, &QPushButton::clicked,this, &Dialog::startGame);

   grid = new QGridLayout (this);

   grid->addWidget(slider, 0,0);
   grid->addWidget(boardSizeLabel, 0, 1);
   grid->addWidget(user1Input, 1,0);
   grid->addWidget(user1Label, 1,1);
   grid->addWidget(user2Input, 2,0);
   grid->addWidget(user2Label, 2,1);
   grid->addWidget(btn, 3,0);

   setLayout(grid);
}


void Dialog::startGame() {
        Dialog::close();
        GameState *state = new GameState(user1Input->text().toStdString(),user2Input->text().toStdString(), slider->value());
        Board *board = new Board(state);

        Widget *w = new Widget(state,board);
        w->setWindowTitle("Tic Tac Toe");
        w->setWindowIcon(QIcon(":/resources/assets/title_ico.png"));
        w->show();
}
void Dialog::sliderValueChanged() {
    boardSizeLabel->setText(QString::number(slider->value()));
}
