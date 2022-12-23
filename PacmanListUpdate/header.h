#ifndef header_H
#define header_H

#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<process.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>

#include"kontrol.h"
#include"menuawal.h"
#include"maps2.h"
#include"enemy_img.h"
#include"sound.h"
#include"score.h"
//#include"matrix.h"
#include"maps_list.h"


#define SIZEMTRX 40
#define BRS 720/SIZEMTRX //18
#define KLM 1280/SIZEMTRX //32
#define img_mtrx 40*j,40*i,40+40*j,40+40*i
#define fullscreen 0,0,getmaxx(),getmaxy()

#define RT 1
#define LT 2
#define UP 3
#define DN 4

#define Up_Lt 1
#define Up 2
#define Up_Rt 3
#define Lt 4
#define Rt 5
#define Dn_Lt 6
#define Dn 7
#define Dn_Rt 8


typedef struct{
	int Score;
	char Player[7];
}pacm;



#endif
