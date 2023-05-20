#include "board.h"
#include "gamestate.h"
#include <iostream>

using namespace std;

Board::Board(GameState *state, QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout (this);
    this->state = state;
    int size = state->getBoardSize();
        for(int i = 0; i < size; i++) {
            QList<QPushButton*> subList;
            for(int j = 0; j < size; j++) {
                QPushButton *btn = new QPushButton( this);
                btn->setFixedSize(80, 100);
                btn->setAccessibleDescription(QString::number(i)+QString::number(j));
                btn->setStyleSheet("background-color: #22558f;");

                connect(btn, &QPushButton::clicked,this, &Board::btnClick);

                subList.append(btn);
                grid->addWidget(btn, i,j);
            }
            btnList.append(subList);
        }
        grid->setColumnStretch(0|1|2| 3,25);

        user1Label = new QLabel(QString::fromStdString(state->getPlayersList()[0]->name), this);
        user1Label->setGeometry(width() - 100, 50, 100, 100);
        user1Label->setStyleSheet("font-size: 15px");
        user2Label = new QLabel(QString::fromStdString(state->getPlayersList()[1]->name), this);
        user2Label->setGeometry(width() - 100, 200, 100, 100);
}

void Board::btnClick() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString i(QChar(button->accessibleDescription()[0]));
    QString j(QChar(button->accessibleDescription()[1]));

    button->setIcon(state->getPlayersList()[state->getCurrentUserIndex()]->img);
    button->setIconSize(QSize(50,50));
    button->setDisabled(true);

    state->updateGameState(i.toInt(), j.toInt(), state->getCurrentUserIndex());
    state->updateCurrentUser();

}
