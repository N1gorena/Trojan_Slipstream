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
#include<QKeyEvent>
#include<QProgressBar>
int maxhp = 3;
int velx =  2;
int vely = 3;
int centerx = -375;
int centery = 120;

MainWindow::MainWindow()  {
	pjetx = -750;
	pjety = 0;
	ejetx = -10;
	ejety = 300;
	ticks = 501;
	miss1x= 0;
    	miss1y = 0;
    	miss1 = 0;
    	bulletx = 0;
    	bullety = 0;
    	cloudx = 0;
   	cloudy = 0;
  	bombx = 0;
  	bomby = 0;
  	
    //We need a scene and a view to do graphics in QT
    top_scene = new QGraphicsScene();
    view = new QGraphicsView( top_scene );
	//view->setSceneRect( 0,0,800,800);
	//top_level = new QWidget;
	

	top_layout = new QVBoxLayout;
	
	//
	QWidget* buttons = new QWidget;
	Start_Game = new QPushButton(tr("Start Game"));
	//Start_Game->resize(100,30);
	connect(Start_Game , SIGNAL(clicked()) , this , SLOT(StartGame()));
	
	Quit = new QPushButton(tr("Quit"));
	//Quit->resize(100,30);
	connect( Quit , SIGNAL(clicked()) , this , SLOT(QuitGame()));
	
	Pausebutt = new QPushButton(tr("pause"));
	//Pausebutt->resize(100,30);
	connect(Pausebutt, SIGNAL(clicked()) , this , SLOT(Pause()));
	
	QHBoxLayout* horbuttlay = new QHBoxLayout;
	
	
	horbuttlay->addWidget(Start_Game);
	//horbuttlay->addWidget( name );
	horbuttlay->addWidget(Quit);
	horbuttlay->addWidget(Pausebutt);
	
	count = new score();
	
	horbuttlay->addWidget( count->Scoreboard );
	//heart\/
		health = new QProgressBar;
		hp = maxhp;
		health->setMaximum(hp);
		health->setMinimum(0);
		health->setValue(hp);
		horbuttlay->addWidget( health );
		
	
	
	//heart^
	horbuttlay->setSizeConstraint( QLayout::SetFixedSize ); 
	buttons->setLayout(horbuttlay);
	//
	
	
	top_layout->addWidget(buttons);
	
	
	
	
	
	
	//
	game = new GameWindow;
	top_layout->addWidget( game->getView() );
	
	//top_level->
	setLayout( top_layout );
	//top_level->
	//setFixedSize(800,900);
	//top_level->
	//setGeometry(0,0,800,800);
	top_scene->addWidget( this );
	view->setFixedSize(800,530);
	
	
	//IN PROGRESS
	/*
	game->makeBomb();
	game->makePjet();
	game->makeEjet();
	game->makeCloud();
	game->makeCloud();
	game->moveCloud(-300, 200);
	cloudx = -300;
	cloudy = 200;
	game->moveEnemy(ejetx,ejety);
	game->LaunchMissile();
	miss1x = ejetx; miss1y = ejety;
	game->moveJet(-750,0);
	game->moveJet(-5,0);
	game->moveJet(-750,0);
	*/
	//
	
	//Start_Game->hide();
	//namedone=0;
	
	 	Master = new QTimer(this);
		Master->setInterval(33);
    		connect(Master, SIGNAL(timeout()), this, SLOT(tick_of_the_clock()));
	
	
	
	
	
	

dead = 0;
deadtime = 0;


binflight = false;



begun = false;







    level = 0;
	activateWindow();
	setFocus();
 setFocusPolicy(Qt::StrongFocus); 
 paused = 0;
   	
}



void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
  //  timer->start();
  //  newboxtime->start();

    //This is how we get our view displayed.
    view->show();
  
    
}

MainWindow::~MainWindow()
{
    //add all stuff later still
    delete Master;
    delete Start_Game;
    delete Quit;
    delete Pausebutt;
    delete count;
   //delete top_scene;
    delete view;  
    delete top_layout;
   // delete top_level;
   delete game;
  
 
    
    
   
  
   
   
}

void MainWindow::StartGame()
{
	
	  //Start_Game->hide();
	if( !begun && count->Set())
	{
	ticks = 501;
	hp = maxhp;
	health->setValue(hp);
	pjetx = -750;
	pjety = 0; 
	grabKeyboard();
	Master->start();
	level = 1;
	  begun = true;
	  game->makeBomb();
	game->makePjet();
	game->makeEjet(300);
	game->makeCloud();
	game->moveCloud(-300, 200);
	cloudx = -300;
	cloudy = 200;
	game->moveEnemy();
	game->LaunchMissile();
	miss1x = ejetx; miss1y = ejety;
	game->moveJet(-750,0);
	}
	else if( begun)
	{
		hp = maxhp;
		level = 1;
		velx = rand()%6;
		vely = 3;
		pjetx = -750;
		pjety = 0;
		ejetx = -10;
		ejety = 300;
		ticks = 501;
		game->reset();
		 game->makeBomb();
		game->makePjet();
		game->makeEjet(300);
		game->makeCloud();
		game->moveCloud(-300, 200);
		cloudx = -300;
		cloudy = 200;
		game->moveEnemy();
		game->LaunchMissile();
		miss1x = ejetx; miss1y = ejety;
		game->moveJet(-750,0);
	}
	/*if( !namedone)
	{
		count->setName( name->text() );
		name->hide();
		namedone = 1;
	} */  
} 

void MainWindow::Pause()
{
	if( Master->isActive() )
	{
	paused = true;
	Master->stop();
	}
	else if( begun && paused )
	{
	paused = false;
	Master->start();
	}
}

void MainWindow::QuitGame()
{
	//top_level->close();
	game->view->close();
	view->close();
}


void MainWindow::tick_of_the_clock()
{
	
	if( velx > 0 && ticks%200==0)
		{
			velx+=((velx%4)+1);
		}
		else if(velx < 0 && ticks%200==0)
		{ velx-=((velx%4)+1); }
	if( dead && deadtime < 50 )
	{
		deadtime++;
	}
	else if( dead && deadtime >= 50 )
	{
		dead = false;
		deadtime = 0;
	}
	if( game->collision() && !dead )
	{
		if( hp>0)
		{
			hp--;
			health->setValue(hp);
		}
		pjetx = -750;
		pjety = 0;
		game->moveJet(pjetx,pjety);
		dead = true;
		velx = 2;
		vely = 3;
	}
	ticks++;
	if( ticks%750 == 0 )
	{
		int temp = rand()%4;
		
		if(temp ==1)
		{
		int temp = -(rand()%750);
		game->makeBomb();
		game->moveBomb(temp, centery,level );
		level++;
		}
		else if( temp ==2)
		{
			int temp = (rand()%50) + centerx;
			int temp1 = (rand()%50) + centery;
			game->makeBomb();
			game->moveBomb(temp, temp1,level );
			level++;
		}
		else if(temp == 3)
		{
			int temp = -(rand()%750);
			int temp1 = (rand()%300);
			game->makeBomb();
			game->moveBomb(temp , temp1  ,level );
			level++;
		}
		else if( temp == 0)
		{
			int temp = -(rand()%750);
			int temp1 = -(rand()%60);
			game->makeBomb();
			game->moveBomb(temp,temp1,level );
			level++;
		}
		
	}
	//player
	/*
	game->moveJet(pjetx,pjety);
	if(pjetx < -5)
	{
	pjetx++;
	}
	else
	{
	pjetx = -750;
	}
	*/
	//enemy bullet
	/*if(ticks == 560 )
	{
	game->enemyfire();
	bulletx = ejetx;
	bullety = ejety;
	
	}*/binflight = true;
	if(ticks%(500/level) == 0  )
	{
		
		game->enemyfire();
		
		
			
				
		
	}
	binflight = game->bulletmove();
	if(ticks%(650/level) == 0  )
	{
	game->LaunchMissile();
	}
	//enemy
	if( ticks%750 == 0)
	{
		int temp = rand()%300;
		game->makeEjet(ticks%temp);
	}
	game->moveEnemy();
	//enemy missile
	game->miss1(pjety);
	
	//bomb
	game->moveBomb(-400, 100, 0 );
	count->setScore(ticks - 500);
	//cloud
	if( cloudx < 0 && cloudx > -750 && cloudy >-60 && cloudy < 300)
	{
	cloudx+=velx;
	cloudy-=vely;
	game->moveCloud(cloudx, cloudy);
	}
	else if( cloudx >= 0 && ticks%3==0 )
	{
		
		velx = -velx;
		
		cloudx+=velx;
		cloudy-= vely;
		game->moveCloud(cloudx, cloudy);	
	}
	else if(cloudy <= -60 && ticks%3==0)
	{
		vely = -vely;
		/*if( vely < 0)
		{
			vely--;}
		else
		{vely++;}*/
		cloudx+=velx;
		cloudy-= vely;
		game->moveCloud(cloudx, cloudy);		
	}
	else if( cloudx <=-750 && ticks%3==0) 
	{
		
		velx = -velx;
		
		
		cloudx+=velx;
		cloudy-=vely;
		game->moveCloud(cloudx, cloudy);
	}
	else if(cloudy >= 300 && ticks%3==0)
	{
		vely = -vely;
		/*if( vely < 0)
		{
			vely--;}
		else
		{vely++;}*/
		cloudx+=velx;
		cloudy-=vely;
		game->moveCloud(cloudx, cloudy);
	}
	if( hp == 0)
	{
		Master->stop();
		paused = false;
		begun = false;
		game->reset();
		dead = false;
		deadtime = 0;
		ticks = 501;
		
	}
}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
	//QKeyEvent temp(QEvent::KeyPress,0x01000013); 
	if(begun)
	{
		if( event->key() == 0x57 && pjety > -60 )
		{ 
			
			if( !paused )
			{
			pjety -= 7; 
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x44 && pjetx < -5 )
		{
			if(!paused)
			{
			pjetx += 7; 
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x53 && pjety < 290)
		{
			if(!paused)
			{
			pjety += 7; 
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x41 && pjetx > -750)
		{
			if(!paused)
			{
			pjetx -= 7; 
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x5a && pjetx > -750 && pjety < 290)
		{
			if(!paused)
			{
			pjetx -= 7; 
			pjety += 7; 
			
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x43 && pjetx < -5 && pjety < 290)
		{
			if(!paused)
			{
			pjetx += 7; 
			pjety += 7; 
			
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x51 && pjetx > -750 && pjety > -60)
		{
			if(!paused)
			{
			pjetx -= 7; 
			pjety -= 7; 
			
			game->moveJet(pjetx,pjety);
			}
		}
		else if( event->key() == 0x45 && pjetx < -5 && pjety > -60)
		{
			if(!paused)
			{
			pjetx += 7; 
			pjety -= 7; 
			
			game->moveJet(pjetx,pjety);
			}
		}
	}
}
/*void MainWindow::Named()
{
	namedone = 1;
	count->setName(name->text() );
	//Start_Game->show();
	name->hide();
}*/
