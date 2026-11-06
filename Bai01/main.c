#include <stdio.h>
#include <stdlib.h>

void Nhap(float *a, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%f", a + i);
	}
}
void In(float *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f ", *(a + i));
	}
}
int main() {
	int n;
	scanf("%d", &n);
	float *a = (float*)malloc(n*sizeof(float));
	Nhap(a, n);
	In(a, n);
	free(a);
	return 0;
}
