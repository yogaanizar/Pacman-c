//#ifndef matrix_H
//#define matrix_H
#include"header.h"

#define Nil NULL
#define Info(P)  (P)->Info
#define I(P)     (P)->I
#define J(P)     (P)->J
#define Next(P)  (P)->Next
#define Prev(P)  (P)->Prev
#define Upp(P)   (P)->Upp
#define Down(P)  (P)->Down
#define First(L) (L).First


typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype Info;
	 infotype I;
	 infotype J;
	 address Next;
	 address Prev;
	 address Down;
	 address Upp;
	 } ElmtList;

typedef struct List {
	  address First;
}List;


int ListEmpty (List L);
void CreateList (List * L);
address Alokasi (infotype X, infotype i, infotype j);
void InsVLast (List * L, infotype X, infotype i, infotype j);
void InsertLast (List * L, address P);
void PrintInfo (List L);

//#endif

