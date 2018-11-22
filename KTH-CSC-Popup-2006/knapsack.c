#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_item_count 2005
#define max_weight_count 2005

typedef struct {
	int value;
	int weight;
} item;

int max_value[max_item_count][max_weight_count];

void do_work (double capacity, int n) {
	//printf("cap = %lf n = %d\n", capacity, n);
	memset(max_value, 0, sizeof(max_value));
	int cp = (int) capacity;
	item items[n];
	memset(items, 0, sizeof(items));
	for (int i = 0; i < n; i++) scanf("%d %d", &items[i].value, &items[i].weight);
	//for (int i = 0; i < n; i++) printf("val = %d weight = %d\n", items[i].value, items[i].weight);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j <= cp; j++) 
			if (i > 0) {
				max_value[i][j] = max_value[i - 1][j];
				if (j >= items[i].weight) {
					int tmp = max_value[i - 1][j - items[i].weight] + items[i].value;
					max_value[i][j] = ( tmp > max_value[i][j]) ? tmp : max_value[i][j];
				} else {
					if (j >= items[0].weight) max_value[0][j] = items[0].value;
				}
			}
	//printf("%d\n", max_value[n - 1][cp]);
	
	
	int i = n - 1;
	int j = cp;
	int ans = 0;
	int ansarr[max_item_count];
	memset(ansarr, 0, sizeof(ansarr));
	while (i > 0) {
		//printf("i = %d j = %d\n", i, j);
		if (max_value[i][j] == max_value[i - 1][j - items[i].weight] + items[i].value) {
			ansarr[ans] = i;
			ans ++;
			j -= items[i].weight;
		}
		i --;
	}
	if (max_value[0][j] == items[0].value) {
		ansarr[ans] = i;
		ans ++;
	}
	printf("%d\n", ans);
	for (int i = ans - 1; i >= 0; i--) printf("%d ", ansarr[i]);
	//printf("DOES QUIT!");
	printf("\n");
}

int main () {
	freopen("knapsack.in", "r", stdin);
	//freopen("knapsack.ans", "w", stdout);
	double c;
	int n;
	while (scanf("%lf %d", &c, &n) != EOF) do_work(c, n);
	fclose(stdin);
	//fclose(stdout);
}

	

