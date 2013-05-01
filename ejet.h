#ifndef EJET_H
#define EJET_H

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


/**
A class representing an enemy fighter pixmap item

@author Nicolas Guangorena
*/

class ejet : public QGraphicsPixmapItem
{
	public:
	/** constructor
	@param pos the y position the jet is to be created at.
	*/
	ejet(int pos);
	~ejet();
	QGraphicsPixmapItem* getEjet();
	/** archaic function kept so nothing screws up*/
	bullet* fire();
	/** y position of ejet */
	int y;
	private:
	/** archaic pointer to ejet bullets */
	bullet* bullets;
	/** Pixmap pointer item of the enemy jet */
	QPixmap* Ejetpic;
	/** archaic */
	QPixmap* Bulletpic;
	
};








#endif
