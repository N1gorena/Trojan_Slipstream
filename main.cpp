#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QPushButton>
/** @mainpage CSCI102 pa5
@section purpose Purpose/overview
The purpose of this PA was to make a Qt sidescroller game
@section requirement Requirements
the requirements were listed in the Git repo describing the PA Gameplay and Grading.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();

    return a.exec();
}
