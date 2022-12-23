#include"header.h"

void menu_awal(){
    sMenu();
	int x, y;
   	readimagefile("assets//img//pacman//VIEW_PACMAN.jpg",fullscreen);
	x= 155;
   	y= 485;
	readimagefile("assets//img//pacman//play3.jpg",x,y,185+x,110+y);
	x=405;
	readimagefile("assets//img//pacman//high2.jpg",x,y,185+x,110+y);
	x=655;
	readimagefile("assets//img//pacman//info2.jpg",x,y,185+x,110+y);
	x=905;
	readimagefile("assets//img//pacman//exit2.jpg",x,y,185+x,110+y);
}


void menu_awal_1(){
	int x, y;
   	readimagefile("assets//img//pacman-menu-bg.jpg",fullscreen);
}

int move_htp(int p){
	int ax;
	if(kbhit()){
		ax = getch();
		if(ax == 77){
			p++;
			if(p==4){
				p = 1;
			}
		}else if(ax == 75){
			p--;
			if(p==0){
				p = 3;
			}
		}
	}
	return p;
}

void splashscreen(){
	int x, y, a, b, i=400, j=50, k, l;

	a=300;
	b=300;

	sLoading();
	x=((getmaxx()/2)-(a/2));
	y=((getmaxy()/2)-(b/2));
	k=((getmaxx()/2)-(i/2));
	l=((getmaxy()/2)-(j/2));

		readimagefile("assets//img//loading//5.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//6.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//7.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//8.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//9.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//10.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//11.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//12.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//13.jpg", fullscreen);
		delay(250);
		readimagefile("assets//img//loading//14.jpg", fullscreen);
		delay(250);
}

