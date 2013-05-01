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
#include"ejet.h"

ejet::ejet(int pos)
{	
	y = pos;
	//missiles = 2;
	//missile1 = new missile;
	bullets = new bullet;
	Bulletpic = new QPixmap( "images/bullet.png");
	//QSize temp(60,20);
	bullets->setPixmap( Bulletpic->scaledToWidth(50));
	Ejetpic = new QPixmap( "images/ejet.png");
	setPixmap( Ejetpic->scaledToHeight(40));
}
ejet::~ejet()
{
	delete Ejetpic;
	delete Bulletpic;
}
QGraphicsPixmapItem* ejet::getEjet()
{
	return this;
}
/*missile* ejet::Launch1()
{
	//QPointF launchpos = this->scenePos();
	return missile1;
	
		
}*/
bullet* ejet::fire()
{
	
	
	return bullets;
}


