#include"header.h"

//==============DEKLARASI================//
int A[BRS][KLM];
int i,k,j,e,temp,temp2, tempGhost1, tempGhost2,barisLoc,kolomLoc,cGhost;
int level;




void *map;
unsigned long size;

typedef struct{
	clock_t second,minute,hours;
} times;

typedef struct{
	char name[10];
	char Player[7];
	int point;
	int health;
	int level;
	times duration;
} sc;
sc scoree;
pacm HS;

//===========================MAIN=====================//
void menu_utama(){
	int x, y, ltemp;
	int p=1;
	scoree.health=3;
	menu:
	menu_awal();
	while(1){
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>155 && x<155+185)&&(y>485 && y<585)){
                cleardevice();
                pilihlevel();
		}else if((x>405 && x<405+185)&&(y>485 && y<585)){
            tampilHighscore();

		}else if((x>655 && x<655+185)&&(y>485 && y<585)){
			while(1){
                p = move_htp(p);
                how(p);
				readimagefile("assets//img//pacman//ack.jpg",150,600,150+150,50+600);
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>150 && x<150+150)&&(y>600 && y<650)){
					goto menu;
				}
			}
		}else if((x>905 && x<905+185)&&(y>485 && y<585)){
			keluar();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>420 && x<520)&&(y>390 && y<440)){
					goto menu;
				}else if((x>740 && x<790)&&(y>390 && y<440)){
					exit(1);
				}

			}
		}
	}
}

void pilihlevel(){
int x, y;
	bool lvmenu = true;
	tingkatan();
	while(lvmenu){
	getmouseclick(WM_LBUTTONDOWN, x, y);
	if((x>155 && x<155+185)&&(y>485 && y<585)){
		if((x>-1)&&(y>-1)){
		lvmenu = false;
		cleardevice();
        scoree.level = 1;
        game(scoree.level);
        }
	}else if((x>405 && x<405+185)&&(y>485 && y<585)){
		if((x>-1)&&(y>-1)){
		lvmenu = false;
		cleardevice();
		scoree.level = 2;
		game(scoree.level);
		}
	}else if((x>655 && x<655+185)&&(y>485 && y<585)){
		if((x>-1)&&(y>-1)){
		lvmenu = false;
		cleardevice();
		scoree.level = 3;
		game(scoree.level);
		}
	}else if((x>905 && x<905+185)&&(y>485 && y<585)){
		return menu_utama();
	}
	}
}

void tampilMaps2(List L){
    address Pacman, P2;

    Pacman = First(L);
    Pacman = Down(Next(Pacman));
    P2 = Pacman;
//scoree.point = 260;
    while(Pacman != Nil)
    {
        pointt(Pacman);
        if(scoree.point == 262){
            num_level();
            saveScore(scoree.point);

		}
        view_level(scoree.level);
        view_health(scoree.health);
        tulisan();
        tempp(Pacman);
        movement(Pacman);
        Pacman = limit(Pacman);
        sensorGhost(L, Pacman);

    }
}

void game(int level){
    cGhost=0;
    List maze;
    address Pacman;
    CreateList(&maze);

    makeMaps(&maze, level);
   // movement(scoree.level,maze, Pacman);
    tampilMaps(maze);
    tampilMaps2(maze);

   // Matrix(&maze);
    //connectNode(&maze);

   // pacman(maze);
    /*
    int lives=3;
    int ltemp;
    sc_lv(scoree.level);
            cleardevice();
            next(scoree.level);
            showMap(level);
            maping();
            sPlay();
            timer_start();
            view_highscore(1);
            pacmanLoc();
            cGhost=0;
            ltemp = scoree.level;
				while(scoree.level==ltemp ){
					view_level(ltemp);
					view_health(scoree.health);
					tulisan();
					if(_kbhit){
					pointt();
					tempp();
					setPacmanLoc();
					movement(scoree.level);
					limit();
					pacmanLoc();
                    sensorGhost();
                    }
					timer_end();
				}
				*/
}








//=====================GHOST=========================//
void pacmanLoc(){
        barisLoc = i;
        kolomLoc = j;
}

void setPacmanLoc(){
    i = barisLoc;
    j = kolomLoc;
}

void setPacmanPos(){
    if(scoree.level == 1){
		i = 15;
		j = 7;
	}
	if(scoree.level == 2){
		i = 3;
		j = 1;
	}
	if(scoree.level == 3){
		i = 1;
		j = 1;
	}
}

void sensorGhost(List L, address Pacman){
    address Ghost, P2, enemy, pCur;
    cGhost=0;
    printf("ini sensir Ghost\n");
    Ghost = First(L);
    P2 = Ghost;

    while(Ghost != Nil)
    {
        if( Next(Ghost) != NULL ){
            if(Info(Ghost)== 14){
                enemy=Ghost;
                pCur=enemy;
                ghostMerah(I(enemy), J(enemy));
                if((I(enemy) == I(Pacman)) && (J(enemy) == J(Pacman))){
                        Info(enemy) = temp;
						tempMaps(temp, I(enemy), J(enemy));
						if(scoree.health==1){
                        gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        saveScore(scoree.point);
                        savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        menu_utama();
                        }else{
                        scoree.health--;
                        }
						gameover(I(enemy),J(enemy));
						enemy=pCur; //setGhostPath();
						ghostMerah(I(enemy), J(enemy));
                }else if((I(enemy) != I(Pacman)) && (J(enemy) != J(Pacman))){

                checkMatrixGhost(cGhost,enemy);
                sensorPacman(enemy,Pacman);
                printf("ini cGhost: %d", cGhost);
                tempMaps(cGhost, I(enemy), J(enemy));

                }
            }

            Ghost = Next(Ghost);
        }
        else{
            Ghost = Down(P2);
            P2 = Ghost;
        }

    }
}

/*
    if(Info(Ghost)== 14){
                enemy=Ghost;
                printf("Ketemu! Info enemy : %d", Info(enemy));
                if((I(enemy) == I(Pacman)) && (J(enemy) == J(Pacman))){
                        Info(enemy) = temp;
						tempMaps(temp, I(enemy), J(enemy));
						if(scoree.health==1){
                        gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        saveScore(scoree.point);
                        savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        menu_utama();
                        }else{
                        scoree.health--;
                        }
						gameover(I(enemy),J(enemy));
						enemy=Ghost; //setGhostPath();
						ghostMerah(I(enemy), J(enemy));
                }else if((I(enemy) != I(Pacman)) && (J(enemy) != J(Pacman))){
                checkMatrixGhost(cGhost,enemy);
                enemy = sensorPacman(enemy,Pacman);
                ghostMerah(I(enemy), J(enemy));
                }
        }

*/

   /*
    for(i=0;i<BRS;i++){
        for(j=0;j<KLM;j++){
            if(A[i][j]== 14){
                printf("temp: %d", temp);
                if((i == barisLoc) && (j == kolomLoc)){
						A[i][j]=temp;
						printf("temp: %d", temp);
						tempMaps(temp, i, j);
						if(scoree.health==1){
                        gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        saveScore(scoree.point);
                        savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        menu_utama();
                        }else{
                        scoree.health--;
                        }
						gameover(i,j);
						setGhostPath();
						ghostMerah(i, j);
                }else if((i != barisLoc) && (j != kolomLoc)){
                checkMatrixGhost(cGhost);
                sensorPacman();
                ghostMerah(i, j);
                }
            }
        }
    }*/


void tempGhost(address Ghost){
    printf("ini tempGhost\n");
	tempGhost2 = tempGhost1;
	tempGhost1 = Info(Ghost);
}

address sensorPacman(address enemy, address Pacman){

	if((I(enemy)>I(Pacman)) && (J(enemy)>J(Pacman))){
		enemy = pathGhost(Up_Lt, enemy);
	}else
	if((I(enemy)>I(Pacman)) && (J(enemy) == J(Pacman))){
		enemy = pathGhost(Up, enemy);
	}else
	if((I(enemy) > I(Pacman)) && (J(enemy) < J(Pacman))){
		enemy = pathGhost(Up_Rt, enemy);
	}else
	if((I(enemy) == I(Pacman)) && (J(enemy) > J(Pacman))){
		enemy = pathGhost(Lt, enemy);
	}else
	if((I(enemy) == I(Pacman)) && (J(enemy) < J(Pacman))){
		enemy = pathGhost(Rt, enemy);
	}else
	if((I(enemy) < I(Pacman)) && (J(enemy) > J(Pacman))){
		enemy = pathGhost(Dn_Lt, enemy);
	}else
	if((I(enemy) < I(Pacman)) && (J(enemy) == J(Pacman))){
		enemy = pathGhost(Dn, enemy);
	}else
	if((I(enemy) < I(Pacman)) && (J(enemy) < J(Pacman))){
		enemy = pathGhost(Dn_Rt, enemy);
	}
	return enemy;
}

address checkMatrixGhost(int cek, address enemy){
    if(cek == 0){
        Info(enemy)=temp;
        tempMaps(temp, I(enemy), J(enemy));
    }
    if(cek == 11){
        Info(enemy)=temp;
        //tempMaps(cek, I(enemy), J(enemy));
        readimagefile("maze//11.jpg", 40*J(enemy)-1,40*I(enemy),40+40*J(enemy)-1,40+40*I(enemy));
    }
    if(cek ==12){
        Info(enemy)=temp;
       // tempMaps(cek, I(enemy), J(enemy));
        readimagefile("maze//12.jpg", 40*J(enemy)-1,40*I(enemy),40+40*J(enemy)-1,40+40*I(enemy));
    }
    return enemy;
}

address pathGhost(int loc, address enemy){

bool kiri, kanan, atas, bawah;
	//Cek Atas
	if((Info(Upp(enemy))==1) || (Info(Upp(enemy))==2) || (Info(Upp(enemy))==6) || (Info(Upp(enemy))==4) || (Info(Upp(enemy))==3)|| (Info(Upp(enemy))==5)){
		atas = false;
	}else{
		atas = true;
	}
	//Cek Bawah
	if((Info(Down(enemy))==1) || (Info(Down(enemy))==2) || (Info(Down(enemy))==6) || (Info(Down(enemy))==4)|| (Info(Down(enemy))==5)|| (Info(Down(enemy))==3)){
		bawah = false;
	}else{
		bawah = true;
	}
	//Cek Kiri
	if((Info(Prev(enemy))==1) || (Info(Prev(enemy))==2) || (Info(Prev(enemy))==6) || (Info(Prev(enemy))==5) || (Info(Prev(enemy))==4) || (Info(Prev(enemy))==3)){
		kiri = false;
	}else{
		kiri = true;
	}
	//Cek Kanan
	if((Info(Next(enemy))==1)||(Info(Next(enemy))==2) || (Info(Next(enemy))==6) || (Info(Next(enemy))==4) || (Info(Next(enemy))==5) || (Info(Next(enemy))==3)){
		kanan = false;
	}else{
		kanan = true;
	}
	enemy = moveGhost(atas,bawah,kiri,kanan,loc, enemy);
    return enemy;
}

address moveGhost(bool up, bool down, bool left, bool right, int loc, address enemy){
	if(loc == Up_Lt){
		if(up && !left){
			enemy=controlGhost(UP, enemy);
			Info(Upp(enemy))=14;
			i--;
		}else
		if(up && left){
			enemy=controlGhost(UP, enemy);
			Info(Upp(enemy))=14;
			i--;
		}else
		if(!up && left){
			enemy=controlGhost(LT, enemy);
			Info(Prev(enemy))=14;
			j--;
		}else

		if(!up && !left){
			if(down){
				enemy=controlGhost(DN,enemy);
				Info(Down(enemy))=14;
				i++;
			}else if(right){
				enemy=controlGhost(RT, enemy);
				Info(Next(enemy))=14;
				j++;
			}
		}
	}
	if(loc == Up){
		if(up){
			enemy=controlGhost(UP, enemy);
			Info(Upp(enemy))=14;
			i--;
		}else
		if(!up){
			if(right){
				enemy=controlGhost(RT, enemy);
				Info(Next(enemy))=14;
				j++;
			}else if(down){
				enemy=controlGhost(DN, enemy);
				Info(Down(enemy))=14;
				i++;
			}else if(left){
				enemy=controlGhost(LT, enemy);
				Info(Prev(enemy))=14;
				j--;
			}
		}
	}
	if(loc == Up_Rt){
		if(up && !right){
			enemy=controlGhost(UP, enemy);
			Info(Upp(enemy))=14;
			i--;
		}else
		if(up && right){
			enemy=controlGhost(RT, enemy);
			Info(Next(enemy))=14;
			j++;
		}else
		if(!up && right){
			enemy=controlGhost(RT, enemy);
			Info(Next(enemy))=14;
			j++;
		}else
		if(!up && !right){
			if(left){
				enemy=controlGhost(LT, enemy);
				Info(Prev(enemy))=14;
				j--;
			}else if(down){
				enemy=controlGhost(DN, enemy);
				Info(Down(enemy))=14;
				i++;
			}
		}
	}
	if(loc == Lt){
		if(left){
			enemy=controlGhost(LT, enemy);
			Info(Prev(enemy))=14;
			j--;
		}else
		if(!left){
			if(right){
				enemy=controlGhost(RT, enemy);
				Info(Next(enemy))=14;
				j++;
			}else if(down){
				enemy=controlGhost(DN, enemy);
				Info(Down(enemy))=14;
				i++;
			}else if(up){
				enemy=controlGhost(UP, enemy);
				Info(Upp(enemy))=14;
				i--;
			}
		}
	}
	if(loc == Rt){
		if(right){
			enemy=controlGhost(RT, enemy);
			Info(Next(enemy))=14;
			j++;
		}else
		if(!right){
			if(left){
				enemy=controlGhost(LT, enemy);
				Info(Prev(enemy))=14;
				j--;
			}else if(down){
				enemy=controlGhost(DN, enemy);
				Info(Down(enemy))=14;

				i++;
			}else if(up){
				enemy=controlGhost(UP, enemy);
				Info(Upp(enemy))=14;
				i--;
			}
		}
	}
	if(loc == Dn_Lt){
		if(down && left){
			enemy=controlGhost(DN, enemy);
			Info(Down(enemy))=14;
			i++;
		}else
		if(down && !left){
			enemy=controlGhost(DN, enemy);
			Info(Down(enemy))=14;
			i++;
		}else
		if(!down && left){
			enemy=controlGhost(LT, enemy);
		Info(Prev(enemy))=14;
			j--;
		}else
		if(!down && !left){
			if(right){
				enemy=controlGhost(RT, enemy);
				Info(Next(enemy))=14;
				j++;
			}else if(up){
				enemy=controlGhost(UP, enemy);
				Info(Upp(enemy))=14;
				i--;
			}
		}
	}
	if(loc == Dn){
		if(down){
			enemy=controlGhost(DN, enemy);
            Info(Down(enemy))=14;
			i++;
		}else
		if(!down){
			if(left){
				enemy=controlGhost(LT, enemy);
				Info(Prev(enemy))=14;
				j--;
			}else if(right){
				enemy=controlGhost(RT, enemy);
				Info(Next(enemy))=14;
				j++;
			}else if(up){
				enemy=controlGhost(UP, enemy);
				Info(Upp(enemy))=14;
				i--;
			}
		}
	}
	if(loc == Dn_Rt){
		if(down && right){
			enemy=controlGhost(DN, enemy);
			Info(Down(enemy))=14;
			i++;
		}else
		if(down && !right){
			enemy=controlGhost(DN, enemy);
			Info(Down(enemy))=14;
			i++;
		}else
		if(!down && right){
			enemy=controlGhost(RT, enemy);
			Info(Next(enemy))=14;
			j++;
		}else
		if(!down && !right){
			if(left){
				enemy=controlGhost(LT, enemy);
				Info(Prev(enemy))=14;
				j--;
			}else if(up){
				enemy=controlGhost(UP, enemy);
				Info(Upp(enemy))=14;
				i--;
			}
		}
	}
	return enemy;

}

address controlGhost(int dir, address enemy){

if(dir==UP){
		if(Info(Upp(enemy))==0){
			cGhost = 0;
		}else
		if(Info(Upp(enemy))==11){
			cGhost = 11;
		}else
		if(Info(Upp(enemy))==12){
			cGhost = 12;
        }
	}
	if(dir==DN){
		if(Info(Down(enemy))==0){
			cGhost = 0;
		}else
		if(Info(Down(enemy))==11){
			cGhost = 11;
		}else
		if(Info(Down(enemy))==12){
			cGhost = 12;
		}
	}
	if(dir==LT){
		if(Info(Prev(enemy))==0){
			cGhost = 0;
		}else
		if(Info(Prev(enemy))==11){
			cGhost = 11;
		}else
		if(Info(Prev(enemy))==12){
			cGhost = 12;
		}
	}
	if(dir==RT){
		if(Info(Next(enemy))==0){
			cGhost = 0;
		}else
		if(Info(Next(enemy))==11){
			cGhost = 11;
		}else
		if(Info(Next(enemy))==12){
			cGhost = 12;
		}
	}
	return enemy;
}

void setGhostPath(){

    if(scoree.level == 1){
		i = 8;
		j = 13;
		A[i][j] = 14;
	}
	if(scoree.level == 2){
		i = 9;
		j = 10;
		A[i][j] = 14;
	}
	if(scoree.level == 3){
		i = 13;
		j = 8;
		A[i][j] = 14;
	}
}




//======================PACMAN===============================//

void movement(address Pacman){
    printf("ini movement\n");

        Info(Pacman)=13;
        while(Info(Pacman)==13){
            if(Info(Pacman)==13){
            ceksprite(k, I(Pacman), J(Pacman), Pacman);
            Info(Pacman)=temp;
            e=getch();
            }
        }
	tempMaps(temp, I(Pacman), J(Pacman));
    }


void ceksprite(int sprite, int baris, int kolom, address P){
    printf("ini ceksprite\n");
    address AT, BW, KN, KR;
   // AT=Upp(P);
   if(Upp(P)==NULL){
    printf("NULL\n");
   }
	if(sprite==0){
		if(temp == 0 || temp2 ==1  ){
			atas(baris,kolom,3);
			printf("info: %d", Info(P));

			if(Info(Upp(P)) == 14 || Info(Down(P)) == 14 || Info(Next(P)) == 14 || Info(Prev(P)) == 14){
                gameover(baris, kolom);
                    if(scoree.health==1){
                        gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        saveScore(scoree.point);
                        savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        menu_utama();
                    }else{
                    scoree.health--;
                    P=Next(P);
                    }

			}

		}

	}
	if(sprite==1){
		if(temp == 0 || temp2 ==0){
			samping(baris,kolom,1);
			if(Info(Upp(P)) == 14 || Info(Down(P)) == 14 || Info(Next(P)) == 14 || Info(Prev(P)) == 14){
                gameover(baris, kolom);
                if(scoree.health==1){
                        gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        saveScore(scoree.point);
                        savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        menu_utama();
                    }else{
                    scoree.health--;
                    P=Next(P);
                    }
			}
        }
	}
	if(sprite==2){
		if(temp == 0 || temp2 ==0){
            samping(baris,kolom,2);
            if(Info(Upp(P)) == 14 || Info(Down(P)) == 14 || Info(Next(P)) == 14 || Info(Prev(P)) == 14){
                gameover(baris, kolom);
                if(scoree.health==1){
                        gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        saveScore(scoree.point);
                        savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                        menu_utama();
                    }else{
                    scoree.health--;
                    P=Next(P);
                    }
			}
		}
	}
	if(sprite==3){
            bawah(baris, kolom,4);
            if(Info(Upp(P)) == 14 || Info(Down(P)) == 14 || Info(Next(P)) == 14 || Info(Prev(P)) == 14){
                gameover(baris, kolom);
                if(scoree.health==1){
                    gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                    saveScore(scoree.point);
                    savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                    menu_utama();
                    }else{
                    scoree.health--;
                    P=Next(P);
                    }
			}
	}
	printf("done checksprite\n");
}

void tempp(address P){
    printf("ini temp\n");
	temp2 = temp;
	temp = Info(P);
	if(temp ==11||temp==12  ){
		temp = 0;
	}
}

address limit(address P){
printf("ini limit\n");
	bool kiri, kanan, atas, bawah;
	if(Info(Upp(P))==1 || Info(Upp(P))== 2 || Info(Upp(P))== 3 || Info(Upp(P))== 4 || Info(Upp(P))== 5 || Info(Upp(P))== 6 || Info(Upp(P))== 14) {
            atas = false;
	}else{
        atas = true;
	}

	if(Info(Down(P))==1 || Info(Down(P))==2 || Info(Down(P))==3 || Info(Down(P))==4 || Info(Down(P))==5 || Info(Down(P))==6 || Info(Down(P))== 14){
            bawah = false;
	}else{
        bawah = true;
	}
	if(Info(Prev(P))==1 || Info(Prev(P))==2 || Info(Prev(P))==3 || Info(Prev(P))==4 ||  Info(Prev(P))==5 ||  Info(Prev(P))==6 || Info(Prev(P))== 14) {
            kiri = false;
	}else{
	    kiri=true;
	}

	if(Info(Next(P))==1 || Info(Next(P))==2 || Info(Next(P))==3 || Info(Next(P))==4 || Info(Next(P))==5 || Info(Next(P))==6 || Info(Next(P))== 14){
        kanan =false;
	}else{
	kanan = true;
	}
	//First(Pacman)=P;
	P = move(atas,bawah,kiri,kanan,P);
	return P;
}


address move(bool up, bool down, bool left, bool right, address P){
printf("ini move\n");

	switch(getch())
	{
		case KEY_UP	:
			if(up){
                k=0;
				P=Upp(P);
			}
			break;
		case KEY_RIGHT:
			if(right){
                k = 1;
				P=Next(P);
			}
			break;
		case KEY_DOWN	:
			if(down){
                k=3;
				P=Down(P);
			}
			break;
		case KEY_LEFT	:
			if(left){
                k = 2;
				P=Prev(P);
			}
			break;
	}
	return P;
}


void next(int l){
	int a,b;
	for(a=0;a<BRS;a++){
		for(b=0;b<KLM;b++){
			A[a][b]=maps_level(l, a, b);
		}
	}
}

void showMap(int lv){
	for(i=0;i<BRS;i++){
		for(j=0;j<KLM;j++){
			maps(A[i][j],i,j);
		}
	}
	for(i=0;i<BRS;i++){
		for(j=0;j<KLM;j++){
			pellet(A[i][j],i,j);
		}
	}
	size = imagesize(fullscreen);
	map = malloc(size);
	getimage(fullscreen,map);
	if(lv == 1){
		i=15;
		j=7;
	}
	else if (lv == 2){
		i=3;
		j=1;
	}
	else{
		i=1;
		j=1;
	}
}

void tempMaps(int temp, int baris, int kolom){
	if(temp==0){
		readimagefile("maze//0.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==1){
		readimagefile("maze//1.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==2){
		readimagefile("maze//2.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==3){
		readimagefile("maze//3.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==4){
		readimagefile("maze//4.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==5){
		readimagefile("maze//5.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==6){
		readimagefile("maze//6.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==7){
		readimagefile("maze//7.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==8){
		readimagefile("maze//8.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==9){
		readimagefile("maze//9.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==10){
		readimagefile("maze//10.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==11){
        printf("ini harusnya ada\n");
		readimagefile("maze//11.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==12){
		readimagefile("maze//12.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
}

void pointt(address Pacman){
	scoree.point=score(Info(Pacman),0,0,scoree.point);
	scoree.health=health(Info(Pacman),0,0,scoree.health);
	view_score(scoree.point);
}

void maping(){
    sOpening();
	for(i=0;i<BRS;i++){
		for(j=0;j<KLM;j++){
			maps(A[i][j],i,j);
		}
	}
	setPacmanPos();
}

void sc_lv(int l){
	if(l==1){
		readimagefile("assets//img//game//startt.jpg",fullscreen);
		delay(1300);
	}else{
		readimagefile("assets//img//game//nextlevel.jpg",fullscreen);
		delay(1300);
	}
}

void num_level(){
		scoree.level++;
		int x,y;
		if(scoree.level >= 2){
			winner_view(scoree.point);
			saveScore(scoree.point);
			savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
		}
		delay(1000);
}

void timers(clock_t dur_h, clock_t dur_m,clock_t dur_s){
	scoree.duration.hours=dur_h;
	scoree.duration.minute=dur_m;
	scoree.duration.second=dur_s;
}

void next_level(){
A[15][25]=18;
outgame(15,25);
if((i==14  &&  j==25)||(i==15  &&  j==24)){
    char msg[128];
	setcolor(LIGHTBLUE);
	settextstyle(1, 0, 2);
	sprintf(msg, "NEXT LEVEL");
	outtextxy(1080,500,msg);
	num_level();
	}
}

void save(char* name, int l){
	FILE *fp;
    sc p;
	strcpy(p.name,name);
	p.point=l;
    p.duration.hours = scoree.duration.hours;
    p.duration.minute = scoree.duration.minute;
    p.duration.second = scoree.duration.second;

	if((fp=fopen("user.txt", "ab+")) == NULL){
		printf("File tidak dapat dibuka!\n");
	}else{
		fwrite(&p, sizeof(p), 1, fp);

	}
	fclose(fp);
}

void view_highscore(int a){
    FILE *pt;
    if(scoree.level==1){
    	pt= fopen("assets\\level1score.txt", "r");
	}
	if(scoree.level==2){
    	pt = fopen("assets\\level2score.txt", "r");
	}
	if(scoree.level==3){
    	pt = fopen("assets\\level3score.txt", "r");
	}
    char view[15];
    char view2[15];
    int n=1;
    int x,y,status = true;


    //sort_file();

    while(fread(&HS,sizeof(HS), 1, pt)==1){
    if(a==1){
    setcolor(WHITE);
	char msg[3];
	settextstyle(1, 0, 2); //font ketebalan warna
	sprintf(msg, "highscore: %d", HS.Score);
	outtextxy(1080,20,msg);
            }
        }
    if(a==2){
            while(fread(&HS, sizeof(HS),1,pt)==1){
                settextstyle(10,0,4);
                setcolor(WHITE);
                sprintf(view,"%d", HS.Score);
                outtextxy(850,350,view);
                sprintf(view2,"%s", HS.Player);
                outtextxy(400,350,view2);
            }
        }

    fclose(pt);
}

void sort_file(){
	pacm dt,temp;

	int i,x;
	int f_struct;
	int f_file;

	FILE *fp;
    if(scoree.level==1){
    	fp= fopen("assets\\level1score.txt", "r");
	}
	if(scoree.level==2){
    	fp = fopen("assets\\level2score.txt", "r");
	}
	if(scoree.level==3){
    	fp = fopen("assets\\level3score.txt", "r");
	}

	f_struct = sizeof(sc);
	fseek(fp, 0, SEEK_END);
	f_file = ftell(fp);

	rewind(fp);
	for(i=0;i< f_file; i += f_struct){
		for(x=0;x< f_file - f_struct; x += f_struct){
			fread(&dt, f_struct, 1, fp);
			fread(&temp, f_struct, 1, fp);
			if(dt.Score>temp.Score){
				fseek(fp, -(f_struct*2) , SEEK_CUR);
				fwrite(&temp, f_struct, 1, fp);
				fwrite(&dt, f_struct, 1, fp);
				fseek(fp, -f_struct , SEEK_CUR);
			}
			else{
				fseek(fp, -f_struct , SEEK_CUR);
			}
		}
		rewind(fp);
	}
	fclose(fp);
}

void die(){
    int lv;
	if(A[i+1][j]==14 || A[i-1][j]==14 || A[i][j+1]==14 || A[i][j-1]==14){
        _beginthread(sMati,0,NULL);
		gameover(i,j);

        if(scoree.health==1){
                gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                saveScore(scoree.point);
                savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
                menu_utama();
		}else{
		scoree.health--;
		}

        i++;
	}
}





//======================ENDGAME========================//
void saveScore(int score) {
	int name = 0;
	int right = 0;
	int x,y;
	inputnama();
	while(name<7){
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>53 && x<53+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//A.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'a';
			right += 80;
			name++;
		}
		if((x>118 && x<118+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//B.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'b';
			right += 80;
			name++;
		}
		if((x>183 && x<183+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//C.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'c';
			right += 80;
			name++;
		}
		if((x>248 && x<248+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//D.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'd';
			right += 80;
			name++;
		}
		if((x>313 && x<313+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//E.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'e';
			right += 80;
			name++;
		}
		if((x>378 && x<378+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//F.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'f';
			right += 80;
			name++;
		}
		if((x>443 && x<443+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//G.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'g';
			right += 80;
			name++;
		}
		if((x>508 && x<508+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//H.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'h';
			right += 80;
			name++;
		}
		if((x>573 && x<573+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//I.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'i';
			right += 80;
			name++;
		}
		if((x>638 && x<638+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//J.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'j';
			right += 80;
			name++;
		}
		if((x>703 && x<703+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//K.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'k';
			right += 80;
			name++;
		}
		if((x>768 && x<768+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//L.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'l';
			right += 80;
			name++;
		}
		if((x>833 && x<833+65)&&(y>374 && y<374+80)){
			readimagefile ("abjad//M.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'm';
			right += 80;
			name++;
		}
		if((x>53 && x<53+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//N.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'n';
			right += 80;
			name++;
		}
		if((x>118 && x<118+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//O.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'o';
			right += 80;
			name++;
		}
		if((x>183 && x<183+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//P.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'p';
			right += 80;
			name++;
		}
		if((x>248 && x<248+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//Q.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'q';
			right += 80;
			name++;
		}
		if((x>313 && x<313+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//R.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'r';
			right += 80;
			name++;
		}
		if((x>378 && x<378+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//S.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 's';
			right += 80;
			name++;
		}
		if((x>443 && x<443+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//T.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 't';
			right += 80;
			name++;
		}
		if((x>508 && x<508+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//U.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'u';
			right += 80;
			name++;
		}
		if((x>573 && x<573+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//V.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'v';
			right += 80;
			name++;
		}
		if((x>638 && x<638+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//W.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'w';
			right += 80;
			name++;
		}
		if((x>703 && x<703+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//X.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'x';
			right += 80;
			name++;
		}
		if((x>768 && x<768+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//Y.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'y';
			right += 80;
			name++;
		}
		if((x>833 && x<833+65)&&(y>454 && y<474+80)){
			readimagefile ("abjad//Z.jpg", 248+right, 239, 313+right, 319);
			HS.Player[name] = 'z';
			right += 80;
			name++;
		}
		if((x>375 && x<581)&&(y>591 && y<633+80)){
			name = 7;
		}
	}

    if(scoree.level==1){
    	FILE *nilai1;
    	nilai1 = fopen("assets\\level1score.txt", "ab+");
    	HS.Score = score;
   		fwrite(&HS,sizeof(HS),1,nilai1);
		fclose(nilai1);

	}
	if(scoree.level==2){
    	FILE *nilai2;
    	nilai2 = fopen("assets\\level2score.txt", "ab+");
    	HS.Score = score;
   		fwrite(&HS,sizeof(HS),1,nilai2);
		fclose(nilai2);
	}
	if(scoree.level==3){
    	FILE *nilai3;
    	nilai3 = fopen("assets\\level3score.txt", "ab+");
    	HS.Score = score;
   		fwrite(&HS,sizeof(HS),1,nilai3);
		fclose(nilai3);
	}
}

void tampilHighscore(){

	int x, y;
	tingkatan();
	while(1){
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>155 && x<155+185)&&(y>485 && y<585)){
			cleardevice();
			scoree.level=1;
			levelHighscore();
		}
        if((x>405 && x<405+185)&&(y>485 && y<585)){
			cleardevice();
			scoree.level=2;
			levelHighscore();
		}
		if((x>655 && x<655+185)&&(y>485 && y<585)){
			cleardevice();
			scoree.level=3;
			levelHighscore();
		}
		if((x>905 && x<905+185)&&(y>485 && y<585)){
            return menu_utama();
        }
        }
}

void levelHighscore(){
    int x,y;
    char buffer[100];
    char buffer1[100];
    char buffer2[100];
    int j = 300;
    view_leaderboard();
	if(scoree.level==1){
		FILE *nilai1;
		nilai1 = fopen("assets\\level1score.txt", "r");
		settextstyle(2, 0, 8);
		//sort_file();
		while(fread(&HS, sizeof(HS), 1, nilai1)) {
			sprintf(buffer,"%s\n", HS.Player);
			sprintf(buffer1,"%d\n", HS.Score);
			outtextxy(450,j,buffer);
			outtextxy(750,j,buffer1);
			j = j+30;
		}fclose(nilai1);
	}
	if(scoree.level==2){
		FILE *nilai2;
		nilai2 = fopen("assets\\level2score.txt", "r");
		settextstyle(2, 0, 8);
		//sort_file();
		while(fread(&HS, sizeof(HS), 1, nilai2)) {
			sprintf(buffer,"%s\n", HS.Player);
			sprintf(buffer1,"%d\n", HS.Score);
			outtextxy(450,j,buffer);
			outtextxy(750,j,buffer1);
			j = j+30;
		}fclose(nilai2);
	}
	if(scoree.level==3){
		FILE *nilai3;
		nilai3 = fopen("assets\\level3score.txt", "r");
		settextstyle(2, 0, 8);
		//sort_file();
		while(fread(&HS, sizeof(HS), 1, nilai3)) {
			sprintf(buffer,"%s\n", HS.Player);
			sprintf(buffer1,"%d\n", HS.Score);
			outtextxy(450,j,buffer);
			outtextxy(750,j,buffer1);
			j = j+30;
		}fclose(nilai3);
	}
}
