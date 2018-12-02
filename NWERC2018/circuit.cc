#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define PI 3.141592653589
#define max_n 1005

using namespace std;

struct loc {
	double x;
	double y;
	double a_s;
	double a_e;
};

loc pos[max_n];
int num[max_n];
bool visited[max_n];
int connection[max_n][max_n];
int n;

int number_of_children (int current_node) {
	//printf("current node = %d\n", current_node);
	int count = 0;
	visited[current_node] = true;
	for (int i = 1; i <= connection[current_node][0]; i++) 
		if (!visited[connection[current_node][i]]) {
			int tmp = number_of_children(connection[current_node][i]);
			num[connection[current_node][i]] = tmp;
			//printf("num[%d] = %d\n", connection[current_node][i], tmp);
			count += tmp;
	}
	//printf("count = %d\n", count);
	return count + connection[current_node][0] - 1;
}


void provide_loc (int current_node) {
	//printf("current_node = %d\n", current_node);
	//printf("x = %lf\n", pos[current_node].x);
	//printf("y = %lf\n", pos[current_node].y);
	//printf("start angle = %lf\n", pos[current_node].a_s);
	//printf("end angle = %lf\n", pos[current_node].a_e);
	visited[current_node] = true;
	if (num[current_node] == 0) return;
	else {
		double cur_angle = pos[current_node].a_s;
		double range = pos[current_node].a_e - pos[current_node].a_s;
		double denominator = num[current_node];
		//printf("denominator = %lf\n", denominator);
		for (int i = 1; i <= connection[current_node][0]; i++) if (!visited[connection[current_node][i]]) {
			double angle = range / denominator * (num[connection[current_node][i]] + 1);
			//printf("node_dealing_with = %d\n", connection[current_node][i]);
			pos[connection[current_node][i]].x = pos[current_node].x + cos((cur_angle) / 180 * PI);
			pos[connection[current_node][i]].y = pos[current_node].y + sin((cur_angle) / 180 * PI);
			//printf("position (x,y) = ( %lf , %lf)\n", pos[connection[current_node][i]].x, pos[connection[current_node][i]].y);
			pos[connection[current_node][i]].a_s = cur_angle;
			pos[connection[current_node][i]].a_e = cur_angle + angle;
			provide_loc(connection[current_node][i]);
			cur_angle += angle;
		}
		return;
	}
}

int main () {
	freopen("circuit.in", "r", stdin);
	freopen("circuit.ans", "w", stdout);
	scanf("%d", &n);
	memset(connection, 0, sizeof(connection));
	for (int i = 0; i < n - 1; i++) {
		int tmp_a, tmp_b;
		scanf("%d%d", &tmp_a, &tmp_b);
		//if (tmp_a > tmp_b) swap(tmp_a, tmp_b);
		connection[tmp_a][0]++;
		connection[tmp_a][connection[tmp_a][0]] = tmp_b;
		connection[tmp_b][0]++;
		connection[tmp_b][connection[tmp_b][0]] = tmp_a;
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= connection[i][0]; j++) printf("%d ", connection[i][j]);
	//	printf("\n");
	//}
	memset(visited, false, sizeof(visited));
	num[1] = number_of_children(1) + 1;
	//for (int i = 1; i <= n; i++) printf("%d ", num[i]);
	//printf("\n");
	pos[1].x = 0;
	pos[1].y = 0;
	pos[1].a_s = 0;
	pos[1].a_e = 360;
	memset(visited, false, sizeof(visited));
	/*for (int i = 1; i <= n; i++) {
		visited[i] = true;
		double cur_angle = pos[i].a_s;
		double range = pos[i].a_e - pos[i].a_s;
		double denominator = num[i];
		for (int j = 1; j <= connection[i][0]; j++) if (!visited[connection[i][j]]) {
			double angle = range / denominator * (num[connection[i][j]] + 1);
			pos[connection[i][j]].x = pos[i].x + cos((angle + cur_angle) / 180 * PI);
			pos[connection[i][j]].y = pos[i].y + sin((angle + cur_angle) / 180 * PI);
			pos[connection[i][j]].a_s = cur_angle;
			pos[connection[i][j]].a_e = cur_angle + angle;
			cur_angle += angle;
		}
	}*/
	provide_loc(1);
	for (int i = 1; i <= n; i++) {
		printf("%lf %lf\n", pos[i].x, pos[i].y);
	}
	fclose(stdin);
	fclose(stdout);
}
