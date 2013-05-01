#ifndef MISSILE_H
#define MISSILE_H

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
A class representing a missile pixmap item

@author Nicolas Guangorena
*/


class missile : public QGraphicsPixmapItem
{
	public:
	int x;
	int y;
	missile();
	~missile();
	QGraphicsPixmapItem* getMissile();
	private:
	/** pixmap holding the missile picture */
	QPixmap* Missilepic;
	
};








#endif
