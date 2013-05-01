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
#include"missile.h"

missile::missile()
{
	x = 0;
	y = 0;
	Missilepic = new QPixmap( "images/missile.jpg");
	setPixmap( Missilepic->scaledToWidth(40));
}
missile::~missile()
{
	delete Missilepic;
}
QGraphicsPixmapItem* missile::getMissile()
{
	return this;
}
