#include"header.h"


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


void sensorGhost(){
    printf("ini sensorGhost\n");
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
    }
}

void sensorPacman(){

	if((i>barisLoc) && (j>kolomLoc)){
		pathGhost(Up_Lt);
	}else
	if((i>barisLoc) && (j == kolomLoc)){
		pathGhost(Up);
	}else
	if((i > barisLoc) && (j < kolomLoc)){
		pathGhost(Up_Rt);
	}else
	if((i == barisLoc) && (j > kolomLoc)){
		pathGhost(Lt);
	}else
	if((i == barisLoc) && (j < kolomLoc)){
		pathGhost(Rt);
	}else
	if((i < barisLoc) && (j > kolomLoc)){
		pathGhost(Dn_Lt);
	}else
	if((i < barisLoc) && (j == kolomLoc)){
		pathGhost(Dn);
	}else
	if((i < barisLoc) && (j < kolomLoc)){
		pathGhost(Dn_Rt);
	}
}

void checkMatrixGhost(int cek){
    if(cek == 0){
        A[i][j]=temp;
        tempMaps(temp, i, j);
    }
    if(cek == 11){
        A[i][j]=temp;
        readimagefile("maze//11.jpg", 40*j-1,40*i,40+40*j-1,40+40*i);
    }
    if(cek ==12){
        A[i][j]=temp;
        readimagefile("maze//12.jpg", 40*j-1,40*i,40+40*j-1,40+40*i);
    }
}


void pathGhost(int loc){

bool kiri, kanan, atas, bawah;
	//Cek Atas
	if((A[i-1][j]==1) || (A[i-1][j]==2) || (A[i-1][j]==6) || (A[i-1][j]==4) || (A[i-1][j]==3)|| (A[i-1][j]==5)){
		atas = false;
	}else{
		atas = true;
	}
	//Cek Bawah
	if((A[i+1][j]==1) || (A[i+1][j]==2) || (A[i+1][j]==6) || (A[i+1][j]==4)|| (A[i+1][j]==5)|| (A[i+1][j]==3)){
		bawah = false;
	}else{
		bawah = true;
	}
	//Cek Kiri
	if((A[i][j-1]==1) || (A[i][j-1]==2) || (A[i][j-1]==6) || (A[i][j-1]==5) || (A[i][j-1]==4) || (A[i][j-1]==3)){
		kiri = false;
	}else{
		kiri = true;
	}
	//Cek Kanan
	if((A[i][j+1]==1)||(A[i][j+1]==2) || (A[i][j+1]==6) || (A[i][j+1]==4) || (A[i][j+1]==5) || (A[i][j+1]==3)){
		kanan = false;
	}else{
		kanan = true;
	}
	moveGhost(atas,bawah,kiri,kanan,loc);

}


void moveGhost(bool up, bool down, bool left, bool right, int loc){
	if(loc == Up_Lt){
		if(up && !left){
			controlGhost(UP);
			A[i-1][j]=14;
			i--;
		}else
		if(up && left){
			controlGhost(UP);
			A[i-1][j]=14;
			i--;
		}else
		if(!up && left){
			controlGhost(LT);
			A[i][j-1]=14;
			j--;
		}else

		if(!up && !left){
			if(down){
				controlGhost(DN);
				A[i+1][j]=14;
				i++;
			}else if(right){
				controlGhost(RT);
				A[i][j+1]=14;
				j++;
			}
		}
	}
	if(loc == Up){
		if(up){
			controlGhost(UP);
			A[i-1][j]=14;
			i--;
		}else
		if(!up){
			if(right){
				controlGhost(RT);
				A[i][j+1]=14;
				j++;
			}else if(down){
				controlGhost(DN);
				A[i+1][j]=14;
				i++;
			}else if(left){
				controlGhost(LT);
				A[i][j-1]=14;
				j--;
			}
		}
	}
	if(loc == Up_Rt){
		if(up && !right){
			controlGhost(UP);
			A[i-1][j]=14;
			i--;
		}else
		if(up && right){
			controlGhost(RT);
			A[i][j+1]=14;
			j++;
		}else
		if(!up && right){
			controlGhost(RT);
			A[i][j+1]=14;
			j++;
		}else
		if(!up && !right){
			if(left){
				controlGhost(LT);
				A[i][j-1]=14;
				j--;
			}else if(down){
				controlGhost(DN);
				A[i+1][j]=14;
				i++;
			}
		}
	}
	if(loc == Lt){
		if(left){
			controlGhost(LT);
			A[i][j-1]=14;
			j--;
		}else
		if(!left){
			if(right){
				controlGhost(RT);
				A[i][j+1]=14;
				j++;
			}else if(down){
				controlGhost(DN);
				A[i+1][j]=14;
				i++;
			}else if(up){
				controlGhost(UP);
				A[i-1][j]=14;
				i--;
			}
		}
	}
	if(loc == Rt){
		if(right){
			controlGhost(RT);
			A[i][j+1]=14;
			j++;
		}else
		if(!right){
			if(left){
				controlGhost(LT);
				A[i][j-1]=14;
				j--;
			}else if(down){
				controlGhost(DN);
				A[i+1][j]=14;

				i++;
			}else if(up){
				controlGhost(UP);
				A[i-1][j]=14;
				i--;
			}
		}
	}
	if(loc == Dn_Lt){
		if(down && left){
			controlGhost(DN);
			A[i+1][j]=14;
			i++;
		}else
		if(down && !left){
			controlGhost(DN);
			A[i+1][j]=14;
			i++;
		}else
		if(!down && left){
			controlGhost(LT);
			A[i][j-1]=14;
			j--;
		}else
		if(!down && !left){
			if(right){
				controlGhost(RT);
				A[i][j+1]=14;
				j++;
			}else if(up){
				controlGhost(UP);
				A[i-1][j]=14;
				i--;
			}
		}
	}
	if(loc == Dn){
		if(down){
			controlGhost(DN);
			A[i+1][j]=14;
			i++;
		}else
		if(!down){
			if(left){
				controlGhost(LT);
				A[i][j-1]=14;
				j--;
			}else if(right){
				controlGhost(RT);
				A[i][j+1]=14;
				j++;
			}else if(up){
				controlGhost(UP);
				A[i-1][j]=14;
				i--;
			}
		}
	}
	if(loc == Dn_Rt){
		if(down && right){
			controlGhost(DN);
			A[i+1][j]=14;
			i++;
		}else
		if(down && !right){
			controlGhost(DN);
			A[i+1][j]=14;
			i++;
		}else
		if(!down && right){
			controlGhost(RT);
			A[i][j+1]=14;
			j++;
		}else
		if(!down && !right){
			if(left){
				controlGhost(LT);
				A[i][j-1]=14;
				j--;
			}else if(up){
				controlGhost(UP);
				A[i-1][j]=14;
				i--;
			}
		}
	}
}


void controlGhost(int dir){
if(dir==UP){
		if(A[i-1][j]==0){
			cGhost = 0;
		}else
		if(A[i-1][j]==11){
			cGhost = 11;
		}else
		if(A[i-1][j]==12){
			cGhost = 12;
        }
	}
	if(dir==DN){
		if(A[i+1][j]==0){
			cGhost = 0;
		}else
		if(A[i+1][j]==11){
			cGhost = 11;
		}else
		if(A[i+1][j]==12){
			cGhost = 12;
		}
	}
	if(dir==LT){
		if(A[i][j-1]==0){
			cGhost = 0;
		}else
		if(A[i][j-1]==11){
			cGhost = 11;
		}else
		if(A[i][j-1]==12){
			cGhost = 12;
		}
	}
	if(dir==RT){
		if(A[i][j+1]==0){
			cGhost = 0;
		}else
		if(A[i][j+1]==11){
			cGhost = 11;
		}else
		if(A[i][j+1]==12){
			cGhost = 12;
		}
	}
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


