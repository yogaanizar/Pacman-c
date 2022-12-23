
//#ifndef 181511008_H
//#define 181511008_H
#include"matrix.h"

void tampilMaps2(List L);
void movement(address Pacman);
void ceksprite(int sprite, int baris, int kolom, address Pacman);
void tempp(address Pacman);
address move(bool up, bool down, bool left, bool right, address Pacman);
address limit(address Pacman);

void next(int l);
//void movement(int l);
//void limit();
void tempMaps(int temp, int baris, int kolom);
//void move(bool atas, bool bawah, bool kiri, bool kanan);
//void ceksprite(int sprite, int baris, int kolom);
void showMap(int lv);
//void tempp();
void maping();
void menu_utama();
void pointt(address Pacman);
void sc_lv(int l);
void die();
void num_level();
void next_level();
void timers(clock_t dur_h, clock_t dur_m,clock_t dur_s);
void sort_file();
void highscore();
void save(char* name, int l);
void view_highscore(int a);


//input user nama
void saveScore(int score);
void inputnama();

//tampil
void tampilHighscore();
void levelHighscore();

//level
void pilihlevel();
void game(int level);
//#endif



void pacmanLoc();
void setPacmanLoc();
void setPacmanPos();

//ghost baru

void tempGhost(address Ghost);
void sensorGhost(List L, address Pacman);
address sensorPacman(address enemy, address Pacman);
address checkMatrixGhost(int cek, address enemy);
address pathGhost(int loc, address enemy);
address controlGhost(int dir, address enemy);
address moveGhost(bool up, bool down, bool left, bool right, int loc, address enemy);
void setGhostPath();
