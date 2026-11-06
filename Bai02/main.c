#include <stdio.h>
#include <stdlib.h>

void Nhap(float *a, int h, int c) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < c; j++) {
			scanf("%f", a + i * c + j);
		}
	}
}
void In(float *a, int h, int c) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < c; j++) { 
			printf("%.2f ", *(a + i * c + j));
		}
	}
}
int main() {
	int h, c;
	scanf("%d%d", &h, &c);
	float *a = (float*)malloc(n*sizeof(float));
	if (a == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }
	Nhap(a, h, c);
	In(a, h, c);
	free(a);
	return 0;
}
