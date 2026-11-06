#include <iostream>
using namespace std;
void Nhap(float *a, int h, int c) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < c; j++) {
			cin >> a[i * c + j];
		}
	}
}
void In(float *a, int h, int c) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < c; j++) { 
			cout << a[i * c + j] << "\t" << endl;
		}
	}
}
int main() {
	float *a;
	int n, m;
	cout << "Nhap so hang, so cot cua ma tran: ";
	cin >> n >> m;
	a = new float[n * m];
	nhap(a, m, n);
	in(a, m, n);
	return 0;
}
