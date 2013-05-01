#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include"score.h"
#include<QTextEdit>
#include<QRadioButton>
#include<QListView>
#include<QListWidget>
#include"gamewindow.h"
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>

bomb::bomb()
{
	bombpic = new QPixmap( "images/mine.png");
	setPixmap( bombpic->scaledToHeight(30));
}
bomb::~bomb()
{
	delete bombpic;
}
QGraphicsPixmapItem* bomb::getBomb()
{
	return this;
}
