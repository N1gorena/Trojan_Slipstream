#ifndef CLOUD_H
#define CLOUD_H

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
A class representing a pixmap cloud item

@author Nicolas Guangorena
*/

class cloud : public QGraphicsPixmapItem
{
	public:
	cloud();
	~cloud();
	QGraphicsPixmapItem* getCloud();
	private:
	/* Pixmap item holding cloud picture */
	QPixmap* Cloudpic;
	
};








#endif
