#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <QWidget>
#include <QtWidgets>
#include <QGridLayout>
#include <QMessageBox>

using namespace std;

struct user
{
    string name;
    QIcon img;
};

class GameState: public QWidget
{
    Q_OBJECT
public:
    GameState(string,string,int,QWidget *parent = 0);

    int getBoardSize(){return boardSize;}
    int getCurrentUserIndex(){return currentUserIndex;}
    QList<QList<int>> getState(){return state;}
    QList<user*> getPlayersList(){return playersList;}

    void checkForWinner(int,int,int);
    void showGameState();
    void updateGameState(int, int, int);
    void updateCurrentUser();

private:
    int currentUserIndex = 0;
    int boardSize = 0;
    QWidget parent;
    QList<QList<int>> state;
    QList<user*> playersList;
    void showWinner(string);
    void restartGame();

signals:
    void gameOver();

};

#endif // GAMESTATE_H
