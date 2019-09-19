#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
		Node* ret = root;
		while (root -> left) {
			Node* left_root = root;
			Node* child = root -> left;
			while (root -> next) {
				child -> next = root -> right;
				child -> next -> next = root -> next -> left;
				child = root -> next -> left;
				root = root -> next;
			}
			child -> next = root -> right;
			root = left_root -> left;
		}
		return ret;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	return 0;
}
