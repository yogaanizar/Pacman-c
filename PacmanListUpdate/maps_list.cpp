#include "header.h"


void makeMaps(List *L, int level){

    List L2;
    address P1, P2, bawah, P3, P4;
    int elemen;


    int i = 0, j = 0;

    for(i=0;i<18;i++){
        CreateList(&L2);
		for(j=0;j<32;j++)
		{
            elemen = maps_level(level, i, j);
			P1 = Alokasi(elemen ,i ,j );
			if (i==0)
			{
				InsertLast(&(*L), P1);
				P2 = First(*L);
			}
			else
			{
				InsertLast(&L2, P1);
				Down(bawah) = P1;
				Upp(P1)=bawah;
				if(Next(P1)==NULL){
                    P3=First(L2);
                    while(P3!=NULL && Next(P3)!=P1){
                        P3=Next(P3);
                    }
				}
                Prev(P1)=P3;
				bawah = Next(bawah);
			}
		}
		if(i > 0)
		{
			P2 = Down(P2);
		}
		bawah = P2;


    }


    PrintInfo (*L);

}


void tampilMaps(List L){
    address P, P2;

    // Cek dari kiri ke kanan (atas ke bawah)
    P = First(L);
    P2 = P;

    while(P != Nil)
    {
        maps(Info(P), I(P), J(P));
        if( Next(P) != NULL )
            P = Next(P);
        else{
            P = Down(P2);
            P2 = P;
        }
    }
}



