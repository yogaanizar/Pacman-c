#include<time.h>
#include<graphics.h>


int score(int mat, int brs, int klm, int p);
void view_score(int p);
void view_health(int h);
void finish(int p, int l);
void view_level(int l);
void winner_view(int l);
void view_leaderboard();
void gameover(int i, int j);
void savescore_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s);
void gameover_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s);
void view2_score(int p);
void view2_time(clock_t dur_h, clock_t dur_m,clock_t dur_s);
void view_save_score();
void next_level();
void tulisan();
int health(int matrix, int brs, int klm, int h);
void tingkatan();


void timer_start();
void timer_end();
void view_time(clock_t p, clock_t l);
