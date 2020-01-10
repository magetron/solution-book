#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << hex << left << showbase << nouppercase << setw(0) << (long long)A << endl;
        cout << dec << right << setfill ('_') << setw (15) << showpos << fixed << setprecision(2) << B << endl;
        cout << scientific << left << noshowpos << uppercase << setprecision(9) << C << endl;
	}
	return 0;

}
