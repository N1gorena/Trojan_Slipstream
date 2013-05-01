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
#include"pjet.h"

pjet::pjet()
{
	Pjetpic = new QPixmap( "images/playerjet.png");
	setPixmap( Pjetpic->scaledToHeight(40));
}
pjet::~pjet()
{
	delete Pjetpic;
}
QGraphicsPixmapItem* pjet::getPjet()
{
	return this;
}
