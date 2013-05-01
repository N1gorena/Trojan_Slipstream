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
#include <QHBoxLayout>
#include"score.h"
#include<QTextEdit>
#include<QRadioButton>
#include<QListView>
#include<QListWidget>
#include"gamewindow.h"
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include"hearts.h"

hearts::hearts(int amt)
{	
	amount = amt;
	//container = new QVBoxLayout;
	Heartpic = new QPixmap( "heart.png");
	for(int x = 0 ; x < amt ; x++)
	{
		QLabel* temp = new QLabel(this);
		temp->setPixmap( Heartpic->scaledToHeight(10) );
		cora.push_back(temp);
		//container->addWidget( temp );
	}
	
	
	
	//setLayout(container);
}
hearts::~hearts()
{
	delete Heartpic;
	//int temp = cora.size();
	/*for(int x = 0 ; x < temp ; x++)
	{
		delete cora[x];
	} */
	
}
void hearts::deduct()
{
	amount--;
	if( amount >=0)
	{
		cora[amount]->hide();
	}
	
}
