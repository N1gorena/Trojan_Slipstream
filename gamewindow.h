#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

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
#include<QBrush>
#include"bomb.h"
#include"pjet.h"
#include"ejet.h"
#include"cloud.h"
#include"missile.h"


/** A class representing the games graphical window of the program designed to implement a sidescrolling shooter

@author Nicolas Guangorena
*/
class GameWindow : public QWidget {
    Q_OBJECT
    
public:
/** Constructor */
    explicit GameWindow();
    /** Deconstructor */
    ~GameWindow();
/** function to show the gamewindow graphically */
    void show();
    /** function to get the view the game is in
    @return GraphicsView pointer
    */
    QGraphicsView* getView();
    /** function to reset the game to initial state */
    void reset();
    /** function to make a new bomb and put it in the scene */
    void makeBomb();
      /** function to make a new player jet and put it in the scene */
    void makePjet();
      /** function to make a new enemy jet and put it in the scene
      @param where Integer for y coordinate to place it at
       */
    void makeEjet(int where);
      /** function to make a new cloud and put it in the scene */
    void makeCloud();
      /** function to move enemies and update in the scene */
    void moveEnemy();
    /** function to launch a missile for every enemy present in scene */
    void LaunchMissile();
    /** function to move missiles based on an int indicating player y position 
    @param tly the y coordinate of the object tracked by the missiles
    */
    void miss1( int tly);
    /** function to move player jet
    @param tlx x coordinate to move to
    @param tly y coordinate to move to
    */
    void moveJet(int tlx, int tly);
    /** function to fire bullets based on enemy positions*/
    void enemyfire();
    /** function to move all fired bullets */
    bool bulletmove();
    /** archaic function to remove bullets */
    void bulletbegone();
    /** function to move cloud 
    @param tlx x coordinate to move to
    @param tly y coordinate to move to
    */
    void moveCloud(int tlx, int tly);
    /** function to place bomb 
    @param tlx x coordinate to place at
    @param tly y coordinate to place at
    @param b bomb number
    */
    void moveBomb(int tlx, int tly, int b);
    /** function detecting collisions with player character 
    @return boolean indicating hit(1) or miss(0)
    */
    bool collision();
    /** the graphics view displaying the scene */
   QGraphicsView *view; 
private:
	
	/** Top Level widget housing the rest of the widgets */
	QWidget* top_level;
	/** Top Level scene housing the items */
    	QGraphicsScene *top_scene;      
    	/**background brush */
    	QBrush* background;
    	/** bomb pointer */
    	bomb* bomba;
    	/** player jet */
    	pjet* myjet;
    	/** Enemy jet */
    	ejet* enemy;
    	/** cloud */
    	cloud* dick;
    	/** missile */
    	missile* rocket;
	/** vector for bombs */
	std::vector<bomb*> bombs;
	/** vector for clouds */
	std::vector<cloud*> clouds;
	/** vector for enemy fighters */
	std::vector<ejet*> efighter;
	/** vector for bullets */
	std::vector<bullet*> bullets;
	/** vector for missiles */
	std::vector<missile*> missiles;
    
   
public slots:

  
};

#endif
