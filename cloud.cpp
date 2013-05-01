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
#include"cloud.h"

cloud::cloud()
{
	Cloudpic = new QPixmap( "images/cloud.png");
	setPixmap( Cloudpic->scaledToHeight(30));
}
cloud::~cloud()
{
	delete Cloudpic;
}
QGraphicsPixmapItem* cloud::getCloud()
{
	return this;
}
