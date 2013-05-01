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
#include"bullet.h"

bullet::bullet()
{
	 x = 0;
	Bulletpic = new QPixmap( "images/bullet.png");
	setPixmap( Bulletpic->scaledToHeight(10));
}
bullet::~bullet()
{
	delete Bulletpic;
}
QGraphicsPixmapItem* bullet::getBullet()
{
	return this;
}
