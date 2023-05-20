#ifndef BOARD_H
#define BOARD_H
#include "gamestate.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Board: public QWidget
{

public:
    Board(GameState *state, QWidget *parent = 0);
    QList<QList<QPushButton*>> btnList;
    QGridLayout *grid;
private:
    GameState *state;
    QVBoxLayout *users;
    QLabel *user1Label;
    QLabel *user2Label;

private slots:
    void btnClick();

};

#endif // BOARD_H
