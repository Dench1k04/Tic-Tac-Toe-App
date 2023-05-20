#include "widget.h"
#include <QIcon>
#include <QString>
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent): QWidget(parent)
{
}

Widget::Widget(GameState *state, Board *board, QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(100 * state->getBoardSize() + 300, 100* state->getBoardSize() + 50);
    connect(state, &GameState::gameOver, this, &Widget::close);

//    users = new QVBoxLayout(this);

    setLayout(board->grid);
}

//Widget::closeGame() {

//}

Widget::~Widget()
{

}


