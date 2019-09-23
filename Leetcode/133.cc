#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();


class Solution {
public:
    Node* cloneGraph(Node* node) {
    	vector<bool> visited(101, false);
		map<int, Node*> dict;
		queue<Node*> q;
		q.push(node);
		visited[node -> val] = true;
		while (!q.empty()) {
			Node *cur = q.front();
			dict[cur -> val] = new Node(cur -> val, vector<Node*>());
			q.pop();
			for (Node* n : cur -> neighbors) if (!visited[n -> val]) {
				q.push(n);
				visited[n -> val] = true;
			}
		}
		visited = vector<bool>(101, false);
		q.push(node);
		visited[node -> val] = true;
		while (!q.empty()) {
			Node *cur = q.front();
			//cout << cur -> val << endl;
			for (Node* n : cur -> neighbors) dict[cur -> val] -> neighbors.push_back(dict[n -> val]);
			q.pop();
			for (Node* n : cur -> neighbors) if (!visited[n -> val]) {
				q.push(n);
				visited[n -> val] = true;
			}
		}
		return dict[node -> val];
	}
};

int main () {
	Solution s;
	Node* n1 = new Node(1, vector<Node *>());
	Node* n2 = new Node(2, vector<Node *>());
	Node* n3 = new Node(3, vector<Node *>());
	Node* n4 = new Node(4, vector<Node *>());
	n1 -> neighbors = vector<Node *>{n2, n4};
	n2 -> neighbors = vector<Node *>{n1, n3};
	n3 -> neighbors = vector<Node *>{n2, n4};
	n4 -> neighbors = vector<Node *>{n1, n3};
	Node* nn1 = s.cloneGraph(n1);
	cout << nn1 -> val << nn1 -> neighbors.size() << " " << nn1 -> neighbors[0] -> val << " " << nn1 -> neighbors[1] -> val << endl;
	cout << nn1 -> neighbors[0] -> val << nn1 -> neighbors.size() << " " << nn1 -> neighbors[0] -> neighbors[0] -> val << " " << nn1 -> neighbors[0] -> neighbors[1] -> val << endl;
	Node* nn4 = nn1 -> neighbors[1];
	cout << nn4 -> val << nn4 -> neighbors.size() << " "<< nn4 -> neighbors[0] -> val << " " << nn4 -> neighbors[1] -> val << endl;
	Node* nn3 = nn1 -> neighbors[0] -> neighbors[1];
	cout << nn3 -> val << nn3 -> neighbors.size() << " " << nn3 -> neighbors[0] -> val << " " << nn3 -> neighbors[1] -> val << endl;
	return 0;
}


