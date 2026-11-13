#include <stdio.h>
#include <stdlib.h>
// Khai bao cau truc du lieu SV
typedef struct{
	char hoTen[30];
	int ma;
	float d1, d2, d3;
}SV;

// Khai bao node cua DSLK don
typedef struct tagNode{
	SV infor;
	struct tagNode *link; // link: con tro tro den nut tiep theo
}Node;

// Khai bao cau truc quan ly DSLK don
typedef struct{
	Node *pHead; // pHead: con tro den nut dau tien
	Node *pTail; // pTail: con tro den nut cuoi cung
	int spt; // spt: so phan tu trong danh sach
}LList;

// Khoi tao ra mot danh sach rong
void initList(LList *L) {
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

// Kiem tra danh sach rong
int emptyList(LList L) {
	return (L.spt == 0);
}

// Them X vao dau danh sach
void insertHead(LList *L, SV x) {
	Node *pp;
	pp = (Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if (emptyList(*L)) {
		L->pHead = pp;
		L->pTail = pp;
	}
	else {
		pp->link = L->pHead;
		L->pHead = pp;
	}
	L->spt++;
}

// Chen X vao cuoi danh sach
void insertTail(LList *L, SV x) {
	Node *pp;
	pp = (Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if (emptyList(*L)) {
		L->pHead = pp;
		L->pTail = pp;
	}
	else {
		L->pTail->link = pp;
		L->pTail = pp;
	}
	L->spt++;
}

// Chen X vao sau phan tu q trong danh sach
void insertAfter(LList *L, Node *q, SV x) {
	Node *pp;
	if (NULL == q) return;
	else {
		pp = (Node*) malloc(sizeof(Node));
		pp->infor = x;
		pp->link = q->link;
		q->link == pp;
		if (q == (L->pTail)) {
			L->pTail = pp;
		}
		L->spt++;
	}
}

// Chen tang
void chenTang(LList *L, SV x) {
	Node *pp = L->pHead;
	Node *q;
	while (pp != NULL && (pp->infor.ma < x.ma)) {
		q = pp;
		pp = pp->link;
	}
	if (pp == L->pHead) {
		insertHead(L, x);
	}
	else {
		insertAfter(L, q, x);
	}
}

// Tim kiem theo ten
Node *TimKiem(LList L, char ten[30]) {
	Node *pp = L.pHead;
	while (pp != NULL && !strstr(pp->infor.hoTen, ten)) {
		pp = pp->link;
	}
	return pp;
}

// Tim kiem theo id
Node *TimKiem(LList L, int id) {
	Node *pp = L.pHead;
	while (pp != NULL && (pp->infor.ma != id)) {
		pp = pp->link;
	}
	return pp;
}

// Tach danh sach thanh nhieu danh sach
void Tach(LList L, LList *L1, LList *L2) {
	initList(L1);
	initList(L2);
	Node *pp = L.pHead;
	while (pp != NULL) {
		if (pp->infor.d1 < ? || d2 || d3) {
			insertHead(L1, pp->infor);
		}
		else {
			insertHead(L2, pp->infor);
		}
		pp = pp->link;
	}
}

// Ghep nhieu danh thanh mot danh sach 
void Ghep(LList L1, LList L2, LList *L) {
	initList(L);
	Node *p1 = L1.pHead;
	Node *p2 = L2.pHead;
	if (L1.spt < L2.spt) {
		while (p1 != NULL) {
			insertHead(L, p1->infor);
			insertHead(L, p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		}
		while (p2 != NULL) {
			insertHead(L, p2->infor);
			p2 = p2->link;
		}
	}
	else {
		// them
	}
}

// Xoa phan tu o dau danh sach 
void delHead(LList *L) {
	Node *pp;
	if (emptyList(*L)) return;
	else {
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if (L->pHead == NULL) {
			L->pTail = NULL;
		}
	}
}

// Xoa phan tu o sau phan tu q trong danh sach
void delAfter(LList *L, Node *q) {
	Node *pp;
	if (NULL == q) return;
	else {
		pp = q->link;
		if (q->link == L->pTail) {
			L->pTail = q;
		}
	}
}

// Xoa phan tu co khoa K trong danh sach - Xoa theo ten
void delTen(LList *L, char ten[30]) {
	Node *pp = L->pHead;
	Node *q;
	while (pp != NULL && !strstr(pp->infor.hoTen, ten)) {
		q = pp;
		pp = pp->link;
	}
	if (NULL == pp) return;
	else {
		if (pp == L->pHead) {
			delHead(L);
		}
		else {
			delAfter(L, q);
		}
	}
}

// Xoa phan tu co khoa K trong danh sach - Xoa theo ID
void delMa(LList *L, int id) {
	Node *pp = L->pHead;
	Node *q;
	while (pp != NULL && (pp->infor.ma != id)) {
		q = pp;
		pp = pp->link;
	}
	if (NULL == pp) return;
	else {
		if (pp == L->pHead) {
			delHead(L);
		}
		else {
			delAfter(L, q);
		}
	}
}
void Nhap(SV *x) {
	printf("Nhap ma sinh vien: ");
	scanf("%d", &(x->ma));
	if ((x->ma) > 0) {
		printf("Nhap ho va ten sinh vien: ");
		scanf("%s", (x->hoTen));
		printf("Nhap diem mon thu nhat: ");
		scanf("%f", &(x->d1));
		printf("Nhap diem mon thu hai: ");
		scanf("%f", &(x->d2));
		printf("Nhap diem mon thu ba: ");
		scanf("%f", &(x->d3));
	}
}

void In(SV x) {
	printf("Ho va ten: %s, Ma sinh vien: %d, Diem mon 1: %.2f, Diem mon 2: %.2f, Diem mon 3: %.2f\n", x.hoTen, x.ma, x.d1, x.d2, x.d3);
}

// Duyet toan bo va in danh sach ra
void processList(LList L) {
	Node *pp = L.pHead;
	while (pp != NULL) {
		In (pp->infor);
		pp = pp->link;
	}
}

int main(){
	LList L;
	int kt = 0;
	SV x;
	initList(&L); // Tao ra mot danh sach rong
	do {
		printf("Chuong trinh lam viec voi mot danh sach lien ket don sinh vien\n");
		printf("1: Them nut vao dau danh sach.\n");
		printf("2: Them nut vao cuoi danh sach.\n");
		printf("3: Them nut vao sau mot nut khac trong danh sach.\n");
		printf("9: Duyet danh sach.\n");
		printf("0: Thoat\n");
		printf("Moi ban chon: ");
		int chon;
		scanf("%d", &chon);
		switch (chon) {
			case 1: 
				printf("Nhap so thong tin sinh vien can them\n");
				Nhap(&x);
				if (x.ma > 0) {
					insertHead(&L, x);
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 9:
				processList(L);
				break;
			case 0:
				printf("BYE BYE");
				kt = 1;
		}
	}
	while (kt == 0);
}
