#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include"hearts.h"
#include<QProgressBar>


/** A class representing the main graphical window of the program designed to implement a sidescrolling shooter

@author Nicolas Guangorena
*/
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
/** Constructor */
    explicit MainWindow();
    /** Deconstructor */
    ~MainWindow();
/** function to show the mainwindown graphically */
    void show();
    /** overloaded function to take in key presses for the game */
    void keyPressEvent(QKeyEvent* event);
    /** function to output the score to a highscores list txt file*/
    void score_out();
   
private:
	/** layout to attach to "this" top level widget */
	QVBoxLayout* top_layout;
    
    /** Push button to start game */
    QPushButton* Start_Game;
    /** Push button to quit game */
    QPushButton* Quit;
    //**Push button to pause game */
    QPushButton* Pausebutt;
    /** Top level scene holding everything */
    QGraphicsScene *top_scene;      
    /** top level view to show the scene */
    QGraphicsView *view; 
    /** Master clock */
    QTimer* Master; 
    /** Scoreboard display */
    score* count;
    /** gamewindow where the gameplay occurs */
    GameWindow* game;
    /** health bar */
    QProgressBar* health;
    
    /** total health count */
    int hp;
    /** player jets x position */
    int pjetx;
    /** player jets y position */
    int pjety;
    /** enemy jets x position */
    int ejetx;
    /** enemy jets y position. Archaic */
    int ejety;
    /** archaic */
    int miss1x;
    /** archaic */
    int miss1y;
    /** archaic */
    bool miss1;
    /** total ticks of the clock that have occurred */
    int ticks;
    /** archaic */
    int bulletx;
    /** archaic */
    int bullety;
    /** integer for clouds x coordinate */
    int cloudx;
    /** integer for clouds y coordinate */
    int cloudy;
    /** starting bombs x position */
    int bombx;
    /** starting bombs y position */
    int bomby;
    /** bool indicating whether player is dead or alive */
    bool dead;
    /** integer for how long, or how many clock ticks one has been dead for */
    int deadtime;
    
    /** archaic*/
    bool binflight;
    /** level for later */
    int level;
    /** bool for whether game has begun */
    bool begun;
    /** bool for whether game has been paused */
    bool paused;
   
	
    
   
public slots:
/** Slot to end the program */
    void QuitGame();
    /** Slot to start program */
    void StartGame();
    /** Slot to cheat during program */
    void Pause();
    /** Slot calling functions needed at every tick of the clock */
    void tick_of_the_clock();
   
  
};

#endif // MAINWINDOW_H
