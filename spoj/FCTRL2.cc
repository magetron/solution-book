#include <bits/stdc++.h>
#define MAX_RESULT_LENGTH 160
#define MAX_N_LENGTH 3

using namespace std;

void factorial (int n) {
	short int *result = new short int[MAX_RESULT_LENGTH];
	for (int i = 0; i < MAX_RESULT_LENGTH; i++) result[i] = 0;	
	int result_length = 1;
	result[0] = 1;
	for (int i = 2; i <= n; i++) {
		short int *i_arr = new short int[MAX_N_LENGTH];
		i_arr[0] = i % 10;
		i_arr[1] = i / 10 % 10;
		i_arr[2] = i / 100;
		
		short int *new_result = new short int[MAX_RESULT_LENGTH];
		for (int j = 0; j < MAX_RESULT_LENGTH; j++) new_result[j] = 0;

		for (int j = 0; j < MAX_N_LENGTH; j++) if (i_arr[j] > 0) {
			short int *tmp_result = new short int[MAX_RESULT_LENGTH];
			for (int k = 0; k < MAX_RESULT_LENGTH; k++) tmp_result[k] = 0;
			int tmp_result_length = result_length + j;
			for (int k = 0; k < result_length; k++) {
				tmp_result[k + j] += result[k] * i_arr[j];
				if (tmp_result[k + j] >= 10) {
					tmp_result[k + j + 1] = tmp_result[k + j] / 10;
					tmp_result[k + j] %= 10;
				}
			}	
			if (tmp_result[tmp_result_length] > 0) tmp_result_length++;
			for (int k = 0; k < tmp_result_length; k++) {
				new_result[k] += tmp_result[k];
				if (new_result[k] >= 10) {
					new_result[k + 1] += 1;
					new_result[k] -= 10;
				}	
			}
			if (new_result[tmp_result_length] > 0) result_length = tmp_result_length + 1;
			else result_length = tmp_result_length;
			delete [] tmp_result;
		}

		for (int j = 0; j < result_length; j++) result[j] = new_result[j];

		delete [] new_result;
		delete [] i_arr;
	}
	if (result[result_length - 1] == 0) result_length--;
	for (int i = result_length - 1; i >= 0; i--) cout << result[i];
	cout << endl;
	delete [] result;
}

int main () {
	// freopen("FCTRL2.in", "r", stdin);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		factorial(n);
	}
	// fclose(stdin);
}	

