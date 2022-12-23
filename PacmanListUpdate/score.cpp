#include"header.h"
//FUNSTION UNTUK MENGHITUNG POIN DARI MAKANAN

clock_t ts, te, dur_s,dur_m,dur_h;


int score(int matrix, int brs, int klm, int p){
	if (matrix==11){
		p=p+1;
        _beginthread(sMakanPelet,0,NULL);
	}else if (matrix==12){
        p=p+10;
        _beginthread(sMakanHati,0,NULL);
	}
	return p;
}

int health(int matrix, int brs, int klm, int h){
    if (matrix==12){
        h=h+1;
	}
	return h;
}

void view_score(int p){
    setcolor(WHITE);
	char msg[3];
	settextstyle(1, 0, 3); //font ketebalan warna
	sprintf(msg, "score: %d", p);
	outtextxy(1080,80,msg);
}

void view_health(int h){
    setcolor(WHITE);
	char msg[3];
	settextstyle(1, 0, 3); //font ketebalan warna
	sprintf(msg, "health: %d", h);
	outtextxy(1080,120,msg);
}

void finish(int p, int l){
	if(l == 1){
		if(p == 262){
			next_level();
		}
	}else if(l == 2){
		if(p == 288){
			next_level();
		}
	}else if(l == 3){
		if(p == 268){
			next_level();
		}
	}
}

void view_level(int l){
	char msg[128];
	settextstyle(1, 0, 3);
	sprintf(msg, "level: %d", l);
	outtextxy(1080,60,msg);
}

void tulisan(){
	char msg1[128], msg2[128], msg3[128];
	setcolor(WHITE);
	settextstyle(1, 0, 2);
	sprintf(msg1, "Ayo!!!");
	outtextxy(1115,250,msg1);
	sprintf(msg2, "Bermain");
	outtextxy(1105,300,msg2);
	settextstyle(1, 0, 3);
	setcolor(YELLOW);
	sprintf(msg3, "PACMAN");
	outtextxy(1080,350,msg3);
	delay(50);
}

void winner_view(int l){
	cleardevice();
	readimagefile("img//img//win//WINVIEW_PACMAN.jpg", fullscreen);
	sWin();
	delay(2000);

}

void view_leaderboard(){
	int x,y;

	readimagefile("assets//img//leaderboard//LEADERBOARD_PACMAN.jpg",fullscreen);

	x=250;
	y=200;
	readimagefile("assets//img//leaderboard//NAMA_PACMAN.jpg",x,y,400+x,450+y);

	x=650;
	y=200;
	readimagefile("assets//img//leaderboard//SCORE_PACMAN.jpg",x,y,400+x,450+y);

	readimagefile("assets//img//pacman//ack.jpg",80,640,80+70,50+640);
}

void gameover(int i, int j){
//	_beginthread(gameover_sound,0,NULL);
	readimagefile("pacman-die//1.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//2.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//3.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//4.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//5.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//6.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//7.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//8.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//9.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//10.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//11.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//12.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//13.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//14.jpg", img_mtrx);
	delay(200);
	readimagefile("pacman-die//16.jpg", img_mtrx);
	delay(200);
	readimagefile("maze//0.jpg", img_mtrx);

}

void gameover_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s){
    cleardevice();
	readimagefile("img//img//gameover//GAMEOVER_PACMAN.jpg", 0,0,1280,720);
	sLose();
	delay(5000);
}

void savescore_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s){
	int x,y,j,k;
	cleardevice();
	readimagefile("img//img//view//VIEW_PACMAN.jpg", 0,0,1280,720);
	view_save_score();
	char nama [7];
	strcpy(nama,"PACMAN"); settextstyle(2, 0, 8); outtextxy(600, 150 ,nama);
	int ax, z=0;
		view2_score(p);
		view2_time(dur_h,dur_m,dur_s);
		delay(2000);
}

void view2_score(int p){
	char msg[13];
	settextstyle(2, 0, 8);
	sprintf(msg, "score \n %d", p);
	outtextxy(600,280,msg);
}

void view2_time(clock_t dur_h, clock_t dur_m,clock_t dur_s){
	char msg[20];
	settextstyle(2, 0, 8);
	sprintf(msg, "Time %d:%d:%d", dur_h,dur_m,dur_s);
	outtextxy(600,310,msg);
}

void view_save_score(){
	int x,y;

	x=450;
	y=100;
	readimagefile("assets//img//inGame//untuk.jpg",x,y,400+x,100+y);

	x=450;
	y=280;
	readimagefile("assets//img//inGame//untuk.jpg",x,y,400+x,100+y);

	x=580;
	y=550;
	readimagefile("assets//img//savescore//SAVE_PACMAN.png",x,y,150+x,50+y);
}



void timer_start()
{
	ts=clock();
}

void timer_end()
{
		te=clock();

		dur_s=(double)(te-ts)/CLOCKS_PER_SEC;

		if(dur_s>=60){
			ts=clock();
			dur_m+=1;
			if(dur_m>=60){
				dur_h+=1;
			}
		}

		timers(dur_h,dur_m,dur_s);
		view_time(dur_s, dur_m);
}

void view_time(clock_t p, clock_t l)
{
	char msg[6];
	settextstyle(1, 0, 1);
	sprintf(msg, "Time: %.2d:%.2d", l, p);
	outtextxy(500,0,msg);
}


void inputnama(){
    int x,y;
    readimagefile("abjad//inputnama.jpg",fullscreen);
    x= 53;
   	y= 374;
	readimagefile("abjad//A.jpg",x,y,65+x,110+y);
	x= 118;
	readimagefile("abjad//B.jpg",x,y,65+x,110+y);
	x= 183;
	readimagefile("abjad//C.jpg",x,y,65+x,110+y);
	x= 248;
	readimagefile("abjad//D.jpg",x,y,65+x,110+y);
	x= 313;
	readimagefile("abjad//E.jpg",x,y,65+x,110+y);
	x= 378;
	readimagefile("abjad//F.jpg",x,y,65+x,110+y);
	x= 443;
	readimagefile("abjad//G.jpg",x,y,65+x,110+y);
	x= 508;
	readimagefile("abjad//H.jpg",x,y,65+x,110+y);
	x= 573;
	readimagefile("abjad//I.jpg",x,y,65+x,110+y);
	x= 638;
	readimagefile("abjad//J.jpg",x,y,65+x,110+y);
	x= 703;
	readimagefile("abjad//K.jpg",x,y,65+x,110+y);
	x= 768;
	readimagefile("abjad//L.jpg",x,y,65+x,110+y);
	x= 833;
	readimagefile("abjad//M.jpg",x,y,65+x,110+y);
	x= 53;
	y= 484;
	readimagefile("abjad//N.jpg",x,y,65+x,110+y);
	x= 118;
	readimagefile("abjad//O.jpg",x,y,65+x,110+y);
	x= 183;
	readimagefile("abjad//P.jpg",x,y,65+x,110+y);
	x= 248;
	readimagefile("abjad//Q.jpg",x,y,65+x,110+y);
	x= 313;
	readimagefile("abjad//R.jpg",x,y,65+x,110+y);
	x= 378;
	readimagefile("abjad//S.jpg",x,y,65+x,110+y);
	x= 443;
	readimagefile("abjad//T.jpg",x,y,65+x,110+y);
	x= 508;
	readimagefile("abjad//U.jpg",x,y,65+x,110+y);
	x= 573;
	readimagefile("abjad//V.jpg",x,y,65+x,110+y);
	x= 638;
	readimagefile("abjad//W.jpg",x,y,65+x,110+y);
	x= 703;
	readimagefile("abjad//X.jpg",x,y,65+x,110+y);
	x= 768;
	readimagefile("abjad//Y.jpg",x,y,65+x,110+y);
	x= 833;
	readimagefile("abjad//Z.jpg",x,y,65+x,110+y);
}

void tingkatan(){
sMenu();
	int x, y;
   	readimagefile("assets//img//pacman//VIEW_PACMAN.jpg",fullscreen);
	x= 155;
   	y= 485;
	readimagefile("assets//img//pacman//easy.jpg",x,y,185+x,110+y);
	x=405;
	readimagefile("assets//img//pacman//normal.jpg",x,y,185+x,110+y);
	x=655;
	readimagefile("assets//img//pacman//hard.jpg",x,y,185+x,110+y);
	x=905;
	readimagefile("assets//img//pacman//back.jpg",x,y,185+x,110+y);
}
