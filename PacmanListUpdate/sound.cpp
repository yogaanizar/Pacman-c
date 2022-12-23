#include "header.h"

void sLoading(){
	PlaySound("assets//Loading.wav",NULL, SND_FILENAME|SND_ASYNC);
}

void sMenu(){
	PlaySound("assets//Menu.wav",NULL, SND_FILENAME|SND_ASYNC);
}

void sOpening(){
	PlaySound("assets//Opening.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void sWin(){
	PlaySound("assets//Win.wav",NULL, SND_FILENAME|SND_ASYNC);
}

void sMakanPelet(void *arg){
	mciSendString("open assets//Makan-Pelet.wav type mpegvideo alias smallpellet",NULL,0,NULL);
	mciSendString("play smallpellet from 0",NULL,0,NULL);
	_endthread();
}

void sPlay(){
	PlaySound("assets//PlaySound.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}


void sMakanHati(void *arg){
	mciSendString("open assets//Makan-Hati.wav type mpegvideo alias largepellet",NULL,0,NULL);
	mciSendString("play Largepellet from 0",NULL,0,NULL);
	_endthread();
}

void sLose(){
	PlaySound("assets//Lose.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void sMati(void *arg){
    mciSendString("open assets//Mati.wav type mpegvideo alias mati",NULL,0,NULL);
	mciSendString("play mati from 0",NULL,0,NULL);
	_endthread();
}
