#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>


void makecar(int x, int y)
 {
  setcolor(15);
  //line(x+1,y+45,x+10,y);
  rectangle(x+0,y,x+45,y+100);//base
   rectangle(x+5,y+25,x+40,y+65);//hood

  rectangle(x+5,y,x+15,y+5);//lights
  //floodfill((x+x+6)/2,(y+y+5)/2,15);

  rectangle(x+30,y,x+40,y+5);//lights
 // floodfill((x+x+31)/2,(y+y+5)/2,15);
 // setfillstyle(SOLID_FILL,10);

 line(x+1,y+15,x+5,y+24);
 line(x+44,y+15,x+40,y+24);
 line(x+5,y+65,x+1,y+70);
 line(x+40,y+65,x+44,y+70);
  floodfill((x+x+50)/2,(y+y+100)/2,15);
  setfillstyle(SOLID_FILL,4);
  }

void clear(int x,int y)
 {
 setcolor(8);
 rectangle(x+0,y,x+45,y+100);//base
 rectangle(x+5,y+25,x+40,y+65);//hood

 rectangle(x+5,y,x+15,y+5);//lights
// floodfill((x+x+6)/2,(y+y+5)/2,15);
 //setfillstyle(SOLID_FILL,10);

 rectangle(x+30,y,x+40,y+5);//lights
 //floodfill((x+x+31)/2,(y+y+5)/2,15);

 line(x+1,y+15,x+5,y+24);
 line(x+44,y+15,x+40,y+24);
 line(x+5,y+65,x+1,y+70);
 line(x+40,y+65,x+44,y+70);
 setfillstyle(SOLID_FILL,8);
 floodfill((x+x+50)/2,(y+y+100)/2,8);
 setcolor(15);
 }


void main()
 {
  int driver,mode;
  driver = DETECT;
  initgraph(&driver,&mode,"C://TURBOC3//BGI");
  int x=300,y=350,ch,life=3,score=0;
  char choice;
  for(int m=1;m<25;m++)
	for(int n=1;n<80;n++) {
	       //	gotoxy(n,m);
	       //	cout<<" ";
		}
  setcolor(WHITE);
  rectangle(249,0,401,getmaxy());
  setfillstyle(SOLID_FILL,8);
  floodfill(325,getmaxy()/2,WHITE);
  for(int level=1;(level<=5)&&(life>0);level++)
  {
	if(level==1){

	  }
	 else {
	     gotoxy(5,5);
	     cout<<"You Won.";
	     delay(2000);
	     exit(0);
	     }
  for(int i=0;(i<10)&&(life>0);i++)
   {
	setcolor(RED);
	rectangle(420,125,600,175);
	gotoxy(55,10);
	cout<<"Level = "<<level;
	rectangle(420,250,600,300);
	gotoxy(55,18);
	cout<<"Lives = "<<life;
	rectangle(420,350,600,400);
	gotoxy(55,24);
	cout<<"Score = "<<score;
	int accident=0;
	int y1=1,x1=250+((rand()%3)*50);
	int y2=1,x2=250+((rand()%3)*50);
	score += 10;
	while(y1<getmaxy()-1)
	{
		clear(x1,y1);
		clear(x2,y2);
		y1++;
		y2++;
		makecar(x1,y1);
		makecar(x2,y2);
		makecar(x,y);
		delay(3-level);
		if(kbhit())
		{
			makecar(x,y);
			ch=getch();
			switch(ch) {
			case 27: exit(0);
			break;
			case 75:clear(x,y);
				if(x>250)
				x=x-50;
				makecar(x,y);
			break;
			case 77:clear(x,y);
				if(x<350)
				x=x+50;
				makecar(x,y);
			break;
			}

		}

 //accident
if((x==x1)||(x==x2))
if((((y-y1)<100)&&((y-y1)>0)) || (((y-y2)<100)&&((y-y2)>0)))
accident=1;
 }
	  if(accident==1)
	  {
	    life =life-1;
	    score -= 10;
	    if(life==0) {
	     gotoxy(5,5);
	     cout<<"GAME OVER ";
	     break;
	     }
	    gotoxy(5,5);
	    cout<<"You have lost 1 life";
	    delay(1000);
	    gotoxy(5,5);
	    cout<<"                         ";
	    }
  }
  }
 getch();
 }