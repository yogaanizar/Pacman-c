
#include "header.h"

void ghostMerah(int i, int j){
    readimagefile("enemy//GmerahUP-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GmerahUP-2.jpg", img_mtrx);
    delay(100);
}

void ghostBiru(int i, int j){
    readimagefile("enemy//GbiruUP-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GbiruUP-2.jpg", img_mtrx);
    delay(100);
}

void Gmerah(int i, int j, int p){
    if(p==2){
    readimagefile("enemy//GmerahUP-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GmerahUP-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==3){
    readimagefile("enemy//GmerahDOWN-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GmerahDOWN-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==1){
    readimagefile("enemy//GmerahLEFT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GmerahLEFT-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==0){
    readimagefile("enemy//GmerahRIGHT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GmerahRIGHT-2.jpg", img_mtrx);
    delay(100);
    }
}


void Gbiru(int i, int j, int p){
    if(p==2){
    readimagefile("enemy//GbiruUP-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GbiruUP-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==3){
    readimagefile("enemy//GbiruDOWN-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GbiruDOWN-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==1){
    readimagefile("enemy//GbiruLEFT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GbiruLEFT-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==0){
    readimagefile("enemy//GbiruRIGHT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GbiruRIGHT-2.jpg", img_mtrx);
    delay(100);
    }
}

void Gpink(int i, int j, int p){
    if(p==2){
    readimagefile("enemy//GpinkUP-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GpinkUP-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==3){
    readimagefile("enemy//GpinkDOWN-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GpinkDOWN-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==1){
    readimagefile("enemy//GpinkLEFT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GpinkLEFT-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==0){
    readimagefile("enemy//GpinkDOWN-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GpinkDOWN-2.jpg", img_mtrx);
    delay(100);
    }
}

void Goren(int i, int j, int p){
    if(p==2){
    readimagefile("enemy//GorenUP-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GorenUP-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==3){
    readimagefile("enemy//GorenDOWN-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GorenDOWN-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==1){
    readimagefile("enemy//GorenLEFT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GorenLEFT-2.jpg", img_mtrx);
    delay(100);
    }
    if(p==0){
    readimagefile("enemy//GorenRIGHT-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//GorenRIGHT-2.jpg", img_mtrx);
    delay(100);
    }
}

void GDead(int i, int j){
    readimagefile("enemy//Gdead-1.jpg", img_mtrx);
    delay(100);
    readimagefile("enemy//Gdead-2.jpg", img_mtrx);
    delay(100);
}



