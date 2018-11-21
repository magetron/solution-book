#include "stdio.h"
#include "stdlib.h"

void merge (int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int tmp_left[n1];
	int tmp_right[n2];

	for (int i = 0; i < n1; i++) tmp_left[i] = arr[l + i];
	for (int i = 0; i < n2; i++) tmp_right[i] = arr[m + 1 + j];
	
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (tmp_left[i] <= tmp_right[j]) {
			arr[k] = tmp_left[i];
			i++;
		} else {
			arr[k] = tmp_right[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = tmp_left[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = tmp_right[j];
		j++;
		k++;
	}
	return;
}

void mergesort(int arr[], int l, int r) {
	if (l < r) {
		int m = (r + l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
	return;
}

int main () {
	return 0;
}

