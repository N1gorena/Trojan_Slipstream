#ifndef PJET_H
#define PJET_H

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
A class representing a players jet pixmap item

@author Nicolas Guangorena
*/

class pjet : public QGraphicsPixmapItem
{
	public:
	pjet();
	~pjet();
	QGraphicsPixmapItem* getPjet();
	private:
	/** pixmap holding the player jet picture */
	QPixmap* Pjetpic;
	
};








#endif
