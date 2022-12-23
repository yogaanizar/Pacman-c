#include"header.h"

List L;

int ListEmpty (List L){
	 return (First(L) == Nil);
}

void CreateList (List * L){
	 First(*L) = Nil;
}

address Alokasi (infotype X, infotype i, infotype j){
    address Node;
	 Node = (address) malloc (sizeof (ElmtList));
	 if (Node!= Nil){
        Info(Node) = X;
        I(Node) = i;
        J(Node) = j;
        Next(Node) = Nil;
        Prev(Node) = Nil;
        Upp(Node) = Nil;
        Down(Node) = Nil;
	 }
    return (Node);
}

void InsVLast (List * L, infotype X, infotype i, infotype j){
address P;

	P = Alokasi (X, i, j);
	if (P != Nil){
        InsertLast (&(*L), P);
    }else{
}
}


void InsertLast (List * L, address P){
address Last;
	if (First(*L) != Nil){
		 Last = First(*L);
		 while (Next(Last) != Nil){
            Last = Next(Last);
         }
		 Next(Last) = P;
	}else{
        First(*L) = P;
    }
}

void PrintInfo (List L){

	// pointer to move right
	address rPtr;

	// pointer to move down
	address dPtr = First(L);

	// loop till node->down is not NULL
	while (dPtr) {

		rPtr = dPtr;

		// loop till node->right is not NULL
		while (rPtr) {
			printf(" %d ", Info(rPtr) );
			rPtr = Next(rPtr);
		}

		printf("\n");
		dPtr = Down(dPtr);
	}
}


