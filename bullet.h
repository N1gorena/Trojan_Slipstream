#ifndef BULLET_H
#define BULLET_H

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
A class representing a pixmap bullet item

@author Nicolas Guangorena
*/

class bullet : public QGraphicsPixmapItem
{
	public:
	/** x coordinate position of bullet */
	int x;
	bullet();
	~bullet();
	QGraphicsPixmapItem* getBullet();
	private:
	/** pixmap holding bullet pic */
	QPixmap* Bulletpic;
	
};








#endif
