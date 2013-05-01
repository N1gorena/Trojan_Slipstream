#ifndef HEARTS_H
#define HEARTS_H

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
#include"bullet.h"
#include <QHBoxLayout>


/**
A class representing a 3 heart container widge. Unused

@author Nicolas Guangorena
*/

class hearts : public QWidget
{
	public:
	hearts(int amt);
	~hearts();
	//QVBoxLayout* container;
	std::vector<QLabel*> cora;
	void deduct();
	private:
	int amount;
	QPixmap* Heartpic;
	
};

#endif
