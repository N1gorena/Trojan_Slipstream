#ifndef SCORE_H
#define SCORE_H

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
//#include"GUITile.h"
#include<QTextEdit>
#include<QRadioButton>
#include<QListView>
#include<QListWidget>
#include<QLCDNumber>
#include<string>
#include"hearts.h"

/**
A class representing a score keeper and name keeper widget.

@author Nicolas Guangorena
*/
class score : public QWidget
{Q_OBJECT
	public:
	explicit score( );
	
	~score();
	/** QWidget holding the actual scoreboard */
	QWidget* Scoreboard;
	/** function to set the score held in the lcd display
	@param num Number to be set
	*/
	void setScore( int num);
	/* function to return a bool of whether the scoreboard is all prepped
	@return returns true when a name has been entered and set
	*/
	bool Set();
	private:
	/** layout for scoreboard and lcd display and label */
	QVBoxLayout* boardlayout;
	/** label holding name and score moniker */
	QLabel* Points;
	/** LCD display for the score */
	QLCDNumber* Score;
	/** line edit box for inputting name */
	QLineEdit* nombre;
	/** archaic i believe unused but kept to not mess something up */
	hearts* live;
	/** boolean returned by Set() function */
	bool named;
	public slots:
	/** slot called by the line edit to set the name in the label to what was in the line edit box
	This function also hides and removes the line edit box after a user has entered their name.
	 */
	void name();

};








#endif
