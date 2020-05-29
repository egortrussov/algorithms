#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

int size = 0;

Node* getFreeNode(int value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

int insert(Node **head, int value) {
    Node *tmp = NULL;
    Node *ins = NULL;
    
    int depth = 1;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        size++;
        return depth;
    }
     
    tmp = *head;
    while (tmp) {
    	depth++;
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                size++;
                return depth;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                size++;
                return depth;
            }
        } else {
            return 0;
        }
    }
}

void printTree(Node *root, int level) {
    if (root) {
        cout << root->data << endl;
        printTree(root->left, level + 1);
        printTree(root->right, level + 1);
    }
}

void printLeaves (Node *root) {
    if (root) {
        printLeaves(root->left);
        if (!root->left && !root->right)
            cout << root->data << endl;
        printLeaves(root->right);
    }
}

vector <int> pars;

void printParents (Node *root) {
    if (root) {
    	if (root->left && root->right)
            pars.push_back(root->data);
        printParents(root->left);
        printParents(root->right);
    }
}

vector <int> branches;

void printBranches (Node *root) {
    if (root) {
    	if (root->left && !root->right || !root->left && root->right)
            branches.push_back(root->data);
        printBranches(root->left);
        printBranches(root->right);
    }
}

int main() {
	Node *root = NULL;
	int ans = 0;
	vector <int> v;
	for (;;) {
		int tm;
		cin >> tm;
		int prevSize = size;
		if (tm == 0) 
			break;
		int tempDepth = max(ans, insert(&root, tm));
		if (size > prevSize)
			v.push_back(tm);
	}
	printBranches(root);
	sort(branches.begin(), branches.end());
	for (int i = 0; i < branches.size(); i++) 
		cout << branches[i] << endl;
	
	
	return 0;
}
