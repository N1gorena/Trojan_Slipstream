#include "mainwindow.h"
#include<QLabel>
#include<QPicture>
#include<iostream>
#include<QTextEdit>
#include<QFormLayout>
#include<QLineEdit>
#include<QListView>
#include<QRadioButton>
#include<QLabel>
#include<QVBoxLayout>
//#include"boardwidget.h"
#include <QString>
#include<QListWidget>
#include<QStringListModel>
#include<QStringList>
#include<QPixmap>
#include<QBrush>
#include"gamewindow.h"


GameWindow::GameWindow()
{
	top_level = new QWidget;
	top_scene = new QGraphicsScene;
	QPixmap image("images/background.jpg");
	background = new QBrush(image);
	top_scene->setBackgroundBrush( *background );
	view = new QGraphicsView(top_scene); 
	view->setFixedSize(800,400);
	view->setMaximumSize(800,400);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	level = 0;
	


}
GameWindow::~GameWindow()
{
	delete top_level;
	delete background;
	delete view;
	
	
}
void GameWindow::levelUp( bool reset)
{	if(reset)
	{
		QPixmap image("images/background.jpg");
		background = new QBrush(image);
		top_scene->setBackgroundBrush( *background );
		level = 0;
	}
	else
	{
		level++;
		if(level == 1)
		{
			QPixmap image("images/grayback.jpg");
			background = new QBrush(image);
			top_scene->setBackgroundBrush( *background );
		
		}
		else if(level == 2)
		{
			QPixmap image("images/redback.jpg");
			background = new QBrush(image);
			top_scene->setBackgroundBrush( *background );
		}
		else if(level == 3)
		{
			QPixmap image("images/background.jpg");
			background = new QBrush(image);
			top_scene->setBackgroundBrush( *background );
		}
	
		if( level == 3)
		{
			level = 0;
		}
	}
}
void GameWindow::show()
{
	view->show();
}
QGraphicsView* GameWindow::getView()
{
	return view;
}
void GameWindow::makeBomb()
{
	bomba = new bomb;
	top_scene->addItem( bomba );
	bombs.push_back(bomba);
	bomba = NULL;
}
void GameWindow::makePjet()
{
	if( myjet == NULL)
	{
		myjet = new pjet;
	}
	top_scene->addItem( myjet );
}
void GameWindow::makeEjet(int where)
{
	
	enemy = new ejet(where);
	top_scene->addItem( enemy);
	efighter.push_back( enemy );
	where+= 100;
	enemy->setPos(-10,where);
	enemy = NULL;
}
void GameWindow::makeCloud()
{
	dick = new cloud;
	top_scene->addItem(dick);
	clouds.push_back(dick);
	//dick = NULL;
}
void GameWindow::moveEnemy()
{
	
	for(unsigned int x = 0 ; x < efighter.size() ; x++)
	{
	  int g = efighter[x]->y;
	  g-= 1;
	  efighter[x]->y = g;
	  
		  if( g > -60)
		  {
		  
	   	 efighter[x]->setPos(-10,g);
	   	 }
	   	 else
	   	 {
	   		efighter[x]->setPos(-10,300);
	   		efighter[x]->y = 300;
	   	 }
   	 }
}
void GameWindow::LaunchMissile()
{
	for( unsigned int z = 0 ; z < efighter.size() ; z++)
	{
		
		QPointF temp = efighter[z]->scenePos();
		rocket = new missile;
		rocket->x = -10;
		rocket->y = temp.y();
		
		top_scene->addItem(rocket );
		
		missiles.push_back( rocket );
		rocket->setPos( temp );
		
		
		
		
	}
	
	
	
}
void GameWindow::moveJet(int tlx, int tly)
{
	
   	 myjet->setPos( tlx, tly);
}
 void GameWindow::miss1( int tly)
 {
 	
 	for(unsigned int x = 0 ; x< missiles.size() ; x++)
 	{
 	if(missiles[x]->x <= -760)
 	{}
 	else{
	 	missiles[x]->x -= 6;
	 	if( tly > missiles[x]->y)
	 	{
	 		missiles[x]->y += 1;
	 	}
	 	else if( tly < missiles[x]->y)
	 	{
	 		missiles[x]->y -= 1;
	 	}
	 	
	 	int temp1 = missiles[x]->x;
	 	
	 	int temp2 = missiles[x]->y;
	 	missiles[x]->setPos(temp1,temp2);
	 	if(missiles[x]->x <= -750)
	 	{
	 		//top_scene->removeItem( missiles[x] );
	 		missiles[x]->hide();
	 	}
 	}
 	}  
 }
void GameWindow::enemyfire()
{
	for( unsigned int z = 0 ; z < efighter.size() ; z++)
	{
		
		QPointF temp = efighter[z]->scenePos();
		bullet* star = new bullet;
		top_scene->addItem( star );
		
		
		star->setPos( temp );
		bullets.push_back( star );
		
		
		
	}
}
bool GameWindow::bulletmove()
{
	bool return1 = 0;
	for( unsigned int z = 0 ; z < bullets.size() ; z++)
	{
		int y = bullets[z]->x;
		y-=5;
		bullets[z]->x = y;
		
		
		if( y > -750 )
		{
			return1 = true;
			bullets[z]->setX( y );
			
		}
		else
		{
			bullets[z]->hide();
		}
	}
	return return1;
}  
void GameWindow::bulletbegone()
{
	//top_scene->removeItem(efighter[0]->fire());
	(efighter[0]->fire())->hide();
}
void GameWindow::moveCloud( int tlx, int tly )
{
	for( unsigned int x = 0 ; x < clouds.size() ; x++ )
	{
	tlx += (x*50);
	tly -= (x*50);
	clouds[x]->setPos(tlx,tly);
	}
}
void GameWindow::moveBomb(int tlx, int tly, int b)
{
	bombs[b]->setPos(tlx,tly);
}
void GameWindow::reset()
{
	QList<QGraphicsItem*> temp = top_scene->items();
	for( int x = 0 ; x < temp.size() ; x++ )
	{
		top_scene->removeItem( temp[x] );
	}
		/*for( unsigned int x = 0 ; x < clouds.size() ; x++ )
		{
			top_scene->removeItem( clouds[x] );
		}
		for( unsigned int x = 0 ; x < efighter.size() ; x++ )
		{
			top_scene->removeItem( efighter[x] );
		}
		for( unsigned int x = 0 ; x < bombs.size() ; x++ )
		{
			top_scene->removeItem( bombs[x] );
		}
		for( unsigned int x = 0 ; x < bullets.size() ; x++ )
		{
			top_scene->removeItem( bullets[x] );
		}
		for( unsigned int x = 0 ; x < missiles.size() ; x++ )
		{
			top_scene->removeItem( missiles[x] );
		}*/
	//top_scene->removeItem( myjet );
	clouds.clear();
	efighter.clear();
	bombs.clear();
	bullets.clear();
	missiles.clear();
}
bool GameWindow::collision()
{
	bool nope = 0;
	bool remove = 1;
	QList<QGraphicsItem*> temp = top_scene->collidingItems(myjet, Qt::IntersectsItemShape);
	if(temp.size() > 0 )
	{
		for( int x = 0 ; x < temp.size() ; x++ )
		{
			for(unsigned int y= 0 ; y < efighter.size() ; y++)
			{
				if( temp[x] == efighter[y] )
				{
					remove = 0 ;
				}
			}
			for(unsigned int y= 0 ; y < clouds.size() ; y++)
			{
				if( temp[x] == clouds[y] )
				{
					remove = 0 ;
				}
			}
			if( remove)
			{
			top_scene->removeItem( temp[x] );	
			}
		}	
		
		nope = true;
	}
	return nope;
	
}
