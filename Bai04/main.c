#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char HoTen[30];
	int MaSV;
	float diem1, diem2, diem3;
}SV;

typedef struct tagNode {
	SV infor;
	struct tagNode *link;
}Node;

typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}LList;

void initList(LList *L) {
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

Node* getNode(SV sv) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) return NULL;
    p->infor = sv;
    p->link = NULL;
    return p;
}

void addTail(LList *L, SV sv) {
    Node *p = getNode(sv);
    if (p == NULL) return;

    if (L->pHead == NULL) {
        L->pHead = L->pTail = p;
    } else {
        L->pTail->link = p;
        L->pTail = p;
    }
    L->spt++;
}

void Nhap(LList *L, int n) {
	for (int i = 0; i < n; i++) {
		SV sv;
		scanf("%s%d%f%f%f",sv.HoTen, &sv.MaSV, &sv.diem1, &sv.diem2, &sv.diem3);
		addTail(L, sv);
	}
}

void In(LList L) {
	Node *p = L.pHead;
	printf("%s %d %.2f %.2f %.2f\n", p->infor.HoTen, p->infor.MaSV, p->infor.diem1, p->infor.diem2, p->infor.diem3);
    p = p->link;
}

int main(){
	LList L;
    initList(&L);
    int n;
    scanf("%d", &n);
    Nhap(&L, n);
    In(L);
    return 0;
}
