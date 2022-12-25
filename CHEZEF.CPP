#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>
int x1,y1,x2,y2,x1old,x2old,ycenter,xcenter;
int xnewcenter,ynewcenter,radius,ballspeedx,ballspeedy;
char sym,pit[20];
int score=0,speed=10;
void ball()
{
	time_t t;
	xcenter=xnewcenter;
	ycenter =ynewcenter;
	xnewcenter=xcenter+ballspeedx;
	ynewcenter=ycenter+ballspeedy;
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(xcenter,ycenter,radius,radius);
	setfillstyle(1,11);
	fillellipse(xnewcenter,ynewcenter,radius,radius);
	setcolor(11);
	if(xnewcenter-radius<0)
		ballspeedx=-ballspeedx;
	if(xnewcenter+radius>640)
		ballspeedx=-ballspeedx;
	if(ynewcenter-radius<0)
		ballspeedy=-ballspeedy;
	if(ynewcenter+radius>340)
	{
		if(xnewcenter>x1 && xnewcenter<x2)
		{
			ballspeedy=-ballspeedy;
			srand((int)time(&t));
			ballspeedx=random(3);
			if(random(3)==1)
				ballspeedx=-ballspeedx;
			score++;
		}
		else
		{
			cleardevice();
			outtextxy(250,150,"GAME OVER !! ");
			outtextxy(180,180,"THANK YOU FOR PLAYING OUR GAME !! ");
			outtextxy(250,210,"Press Q to Exit");
			outtextxy(280,250,": )");

			getch();
		}
		return;
	}
	delay(10);
}
void bat(char sym)
{
	switch(sym)
	{
		case 'z' : 	if(x1>0)
					{
						x1old=x1;
						x2old=x2;
						x1=x1-5;
						x2=x2-5;
						delay(10);
						setfillstyle(1,0);
						bar(x1old,y1,x2old,y2);
						setfillstyle(1,13);
						bar(x1,y1,x2,y2);
					}
					if(x1==0)
					{
						delay(10);
						setfillstyle(1,13);
						bar(x1,y1,x2,y2);
					}
					break;
		case 'x' :	if(x2<640)
					{
						x1old=x1;
						x2old=x2;
						x1=x1+5;
						x2=x2+5;
						delay(10);
						setfillstyle(1,0);
						bar(x1old,y1,x2old,y2);
						setfillstyle(1,13);
						bar(x1,y1,x2,y2);
					}
					if(x2==640)
					{
						delay(10);
						setfillstyle(1,13);
						bar(x1,y1,x2,y2);
					}
					break;
		}
}
void play()
{
	while(inportb(0x60)!=16)
	{
		if(inportb(0x60)==44) bat('z');
		if(inportb(0x60)==45) bat('x');
		ball();
	}
}
void initialize()
{
	time_t t;
	x1=rand();
	x1=320;
	y1=x1+30;
	x2=x1+80;
	y2=y1+40;
	srand((int)time(&t));
	xnewcenter=random(200);
	ynewcenter=random(200);
	ballspeedx=2;
	srand((int)time(&t));
	ballspeedy=random(3);
	if(random(3)==0)
	{
		ballspeedx=-ballspeedx;
		ballspeedy=-ballspeedy;
	}
	radius=20;
	play();
}
void main()
{
	int gd=0,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	outtextxy(90,40,"~~PADMABHUSHAN VASANTDADA PATIL INSTITUTE OF TECHNOLOGY~~");
	outtextxy(90,70,"SECOND YEAR COMPUTER SCIENCE ENGINEERING (2022-2023)");
	outtextxy(150,110,"---Computer Graphics Mini-Project---");
	outtextxy(180,150,"~~ WERLCOME TO THE GAME OF PONG ~~");
	outtextxy(90,160,"Instractions:");
	outtextxy(90,180,"Press Q to Exit");
	outtextxy(90,190,"Press Z, X to move the bar");
	outtextxy(90,210,"Press any key to continue.");
	outtextxy(90,240,"Created By :  Abhiram Suradkar(Roll No : 02)");
	outtextxy(200,260,"Atharva Wader (Roll No : 61)");
	outtextxy(200,280,"Yash Chavan (Roll No : 63)");

	getch();
	cleardevice();
	initialize();
	getch();
}