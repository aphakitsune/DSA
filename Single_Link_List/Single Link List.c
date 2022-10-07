#include <stdio.h>
#include <stdlib.h>

//2.
typedef int ElementType;
typedef struct Node* NodeType;
struct Node {
    ElementType element;
    NodeType next;
};
typedef NodeType Position;
typedef Position List;

//3.
void MakeNullList(List *Header) {
    (*Header)=(NodeType)malloc(sizeof(struct Node));
    (*Header)->next= NULL;
}

//4.
int EmptyList(List L) {
    return (L->next==NULL);
}

//5.
Position First(List L) {
    return L;
}

//6.
Position Next(Position P, List L) {
    return P->next;
}

//7.
ElementType Retrieve(Position P, List L) {
    if (P->next!=NULL)
        return P->next->element;
}

//8.
Position EndList(List L) {
  Position P;
  P=First(L);
    while (P->next!=NULL)
        P=P->next;return P;
}

//9.
void InsertList(ElementType X,Position P, List *L) {
    Position T;
    T=(NodeType)malloc(sizeof(struct Node));
    T->element=X;
    T->next=P->next;
    P->next=T;
}

//10.
void ReadList(List *L) {
    int i,N;
    ElementType X;
    MakeNullList(L);
    printf("So phan tu danh sach N= ");
    scanf("%d",&N);
    for(i=1;i<=N;i++) {
        printf("Phan tu thu %d: ",i);
        scanf("%d",&X);
        InsertList(X,EndList(*L),L);
    }
}

//11.
void PrintList(List L) {
    Position P;
    P = First(L);
    while (P != EndList(L)) {
        printf("%d ",Retrieve(P,L));
        P = Next(P, L);
    }
    printf("\n");
}

//12.
int main() {
  List L;
  ElementType X;
  Position P;
  ReadList(&L);
  printf("Danh sach vua nhap: ");
  PrintList(L);
}
