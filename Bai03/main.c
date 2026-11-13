#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char HoTen[30];
	int MaSV;
	float diem1, diem2, diem3;
} SV;

void Nhap(SV *a, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%s", (a + i)->HoTen);
		scanf("%d%f%f%f", &(a + i)->MaSV, &(a + i)->diem1, &(a + i)->diem2, &(a + i)->diem3);
	}
}

void In(SV *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d %.2f %.2f %.2f\n", (a + i)->HoTen, (a + i)->MaSV, (a + i)->diem1, (a + i)->diem2, (a + i)->diem3);
	}
}

int main() {
	int n;
	(scanf("%d", &n);
	SV *a = (SV*)malloc(n * sizeof(SV)); // Cap phat bo nho cho bien con tro a
	Nhap(a, n);
	In(a, n);
	free(a);
	return 0;
}
