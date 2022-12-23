#include"header.h"

int maps_level(int l, int a, int b){
	if(l==1){
		int B[BRS][KLM] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 6, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 6, 1},
		{1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1},
		{1, 5, 5, 1, 5, 5, 5, 1, 1, 1, 1, 5 ,5, 5, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1, 5, 5, 5, 1, 5, 5, 1},
		{1, 5, 5, 1, 1, 5, 1, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 1, 5, 1, 1, 5, 5, 1},
		{1, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 1},
		{1, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 1},
		{1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 1, 1, 5, 1, 1, 1},
		{1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 5, 1, 1, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 1, 1, 5, 1, 1, 1},
		{1, 5, 5, 5, 1, 1, 5, 5, 5, 5, 5, 5, 1, 6, 5, 5, 5, 5, 6, 1, 5, 5, 5, 5, 5, 5, 1, 1, 5, 5, 5, 1},
		{1, 5, 5, 5, 6, 1, 1, 1, 1, 1, 1, 0, 1, 5, 5, 5, 5, 5, 5, 1, 5, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 1},
		{1, 5, 5, 5, 5, 5, 5, 1, 1, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 2, 2, 6, 5, 5, 5, 5, 5, 1},
		{1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1},
		{1, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 1},
		{1, 6, 5, 5, 5, 5, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 2, 5, 5, 5, 5, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
		return B[a][b];
	}
}

void maps(int matrix, int baris, int kolom){
	if(matrix==0){
		background(baris, kolom);
	}
	if(matrix==1){
		tembok(baris, kolom);
	}
	if(matrix==5){
		pelet(baris, kolom);
	}
	if(matrix==6){
        hati(baris, kolom);
	}
}

void background(int i, int j){
	readimagefile("assets//img//labirin//background.jpg", img_mtrx);
}

void tembok(int i, int j){
	readimagefile("assets//img//labirin//temb.gif", img_mtrx);
}
void pelet(int i, int j){
	readimagefile("assets//img//labirin//pelet.jpg", img_mtrx);
}

void hati(int i, int j){
    readimagefile("assets//img//labirin//hati.jpg",img_mtrx);
}


void samping(int i, int j, int p){
	if(p==1){
		readimagefile("assets//img//char//pRIGHT2.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pRIGHT1.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pRIGHT-0.jpg", img_mtrx);
	}else if(p==2){
		readimagefile("assets//img//char//pLEFT2.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pLEFT1.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pLEFT-0.jpg", img_mtrx);
	}
}

void atas(int i, int j, int p){
	if(p==3){
		readimagefile("assets//img//char//pUP-2.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pUP-1.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pUP-0.jpg", img_mtrx);
	}
}

void bawah(int i, int j, int p){
    if(p==4){
        readimagefile("assets//img//char//pDOWN-2.jpg", img_mtrx);
        delay(10);
		readimagefile("assets//img//char//pDOWN-1.jpg", img_mtrx);
		delay(10);
		readimagefile("assets//img//char//pDOWN-0.jpg", img_mtrx);
    }
}
