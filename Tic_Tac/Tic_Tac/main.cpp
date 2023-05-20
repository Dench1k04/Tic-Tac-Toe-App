#include "widget.h"
#include "dialog.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

      Dialog welcomeDialog;
      welcomeDialog.setWindowTitle("Tic Tac Toe");
      welcomeDialog.setWindowIcon(QIcon(":/resources/assets/title_ico.png"));
        welcomeDialog.setFixedSize(300, 400);
        welcomeDialog.show();

    return a.exec();
}
