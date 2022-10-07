#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int employeeNumber;
	char name[64];
	int age;
} ElementType;

typedef struct Node* NodeType;

struct Node{
	ElementType element;
	NodeType next;
};

typedef NodeType Position;
typedef Position List;
//
//
//
void MakeNullList(List *header){
	(*header) = (NodeType) malloc (sizeof(struct Node));
	(*header) -> next = NULL;
}

int EmptyList(List L){
	return (L -> next == NULL);
}

Position First(List L){
	return L;
}

ElementType Retrieve(Position p, List L){
	if(p -> next != NULL)
		return p -> next ->element;
}

void WriteList(List *L){
	int i,N;
	ElementType x;
	MakeNullList(L);
	printf("Number of elements in list N:"); scanf("%d",&N);
	for(i=1; i<=N ;i++){
		printf("Elememt %d: ",i); scanf("%d",&x);
		InsertList(x,Endlist(*L),L);
	}
}

Position EndList(List L){
	Position p;
	p = First(L);
	while(p -> next != NULL)
		p = p -> next;
	return p;
}

int Next(Position p, List L){
	return p -> next;
}

void InsertList(ElementType x, Position p, List *L){
	Position t;
	t = (NodeType) malloc (sizeof(struct Node));
	t -> element = x;
	t -> next = p -> next;
	p -> next = t;
}

void PrintList(List L){
	Position p;
	 p = First(L);
	 while(p != EndList(L)){
		 printf("%d ", Retrieve(p,L));
		 p = Next(p,L);
	 }
	 printf("\n");
}

void Sort(List *L){
	Position p,q, smallest;
	p = First(*L);
	
	while(p -> next != NULL){
		smallest = p;
		q = Next(p, *L);
		while(q -> next != NULL){
			if(q -> next -> element.age < smallest -> next -> element.age)
				smallest = q;
			q = Next(q,*L);
		}
		ElementType x;
		x = p -> next -> element;
		p -> next -> element = smallest -> next -> element;
		smallest -> next -> element = x;
		p = Next(p, *L);
	}
}
//
//
//
int main(){
	ElementType x;
	Position p;
	List L;
	int choice=1;
	
	while(choice != 0){
		printf("1: Write content to list\n");
		printf("2: Show list you just type in\n");
		printf("3: Sort content in the list\n");
		printf("4: Insert an element to list\n");
		printf("0: STOP the Program!!\n");
		printf("Your choice: "); scanf("%d",&choice);
		
		switch(choice){
			case(1):
				WriteList(&L);
				break;
			case(2):
				PrintList(L);
				break;
			case(3):
				Sort(&L);
				break;
			case(4):
				//InsertList(,3,&L);
				break;
			default:
				printf("Thank you!!");
				break;
		}
		printf("\n\n");
	}
	return 0;
}
