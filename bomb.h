#ifndef BOMB_H
#define BOMB_H

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


/**
A class representing a pixmap bomb item

@author Nicolas Guangorena
*/

class bomb : public QGraphicsPixmapItem
{
	public:
	bomb();
	~bomb();
	QGraphicsPixmapItem* getBomb();
	private:
	/** pixmap of bomb picture */
	QPixmap* bombpic;
	
};








#endif
