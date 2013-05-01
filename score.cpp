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
#include"score.h"
#include <QString>
#include<QListWidget>
#include<QStringListModel>
#include<QStringList>

score::score()
{
	Scoreboard = new QWidget;
	boardlayout = new QVBoxLayout;
	Points = new QLabel;
	Score = new QLCDNumber;
	
	
	Points->setText(tr("Score"));
	Score->setDigitCount(6);
	Score->setSegmentStyle(QLCDNumber::Outline);
	QPalette pail = Score->palette();
	pail.setColor(QPalette::Normal, QPalette::Foreground , Qt::red);
	pail.setColor(QPalette::Normal, QPalette::Background , Qt::black);
	pail.setColor(QPalette::Normal, QPalette::Light , Qt::black);
	pail.setColor(QPalette::Normal, QPalette::Dark , Qt::blue);
	Score->setPalette( pail );
	
	
	Score->display(000000);
	boardlayout->addWidget( Points );
	boardlayout->addWidget( Score );
	nombre =  new QLineEdit("NAME then PLAY" );
	//lives = life;
	//live = new hearts(lives);
	//boardlayout->addWidget( live );
	boardlayout->addWidget( nombre );
	boardlayout->setSizeConstraint(QLayout::SetFixedSize);
	
	connect( nombre , SIGNAL(returnPressed()) , this , SLOT(name()));
	Scoreboard->setLayout( boardlayout );

named = 0;
	

}

score::~score()
{
	delete Score;
	delete Points;
	delete boardlayout;
	delete Scoreboard;
	//delete nombre;
	
}
/*void score::die()
{
	//live->deduct();
}*/
void score::name()
{
	QString name = nombre->text() + " Score:";
	Points->setText( name);
	nombre->hide();
	boardlayout->removeWidget( nombre );
	named = 1;
	
}
void score::setScore(int num)
{
	Score->display(num);
}
bool score::Set()
{
	return named;
}
