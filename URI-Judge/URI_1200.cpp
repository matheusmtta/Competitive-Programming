#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

map <int, char> mp;
vector <char> prnt;

struct node{
	int value;
	struct node *left, *right;
};

struct node *newNode(int x){
	struct node *tmp = new node;
	tmp->value = x;
	tmp->left = tmp->right = nullptr;
	return tmp;
}

struct node* insert(struct node* node, int x){
	if (node == nullptr) return newNode(x);
	if (x < node->value)
		node->left = insert(node->left, x);
	else if (x > node->value)
		node->right = insert(node->right, x);
	return node;
}

bool search(struct node* node, int x){
	if (node == nullptr) return false;
	if (node->value == x) return true;
	if (x < node->value && node->left != nullptr)
		return search(node->left, x);
	else if (x > node->value && node->right != nullptr)
		return search(node->right, x);
	return false;
}

void get_infix(struct node *v){
	if (v != nullptr){
		get_infix(v->left);
		prnt.push_back(mp[v->value]);
		get_infix(v->right);
	}
}

void get_post(struct node *v){
	if (v != nullptr){
		get_post(v->left);
		get_post(v->right);
		prnt.push_back(mp[v->value]);
	}
}

void get_prefix(struct node *v){
	if (v != nullptr){
		prnt.push_back(mp[v->value]);
		get_prefix(v->left);
		get_prefix(v->right);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	struct node *root = nullptr;

	while (cin >> str){
		if (str == "I"){
			char x; cin >> x;
			mp[x-'a'] = x;
			if (root == nullptr) root = insert(root, x-'a');
			insert(root, x-'a');
		}
		else if (str == "P"){
			char x; cin >> x;
			search(root, x-'a') ? cout << x << " existe" << endl : cout << x << " nao existe" << endl;
		}
		else if (str == "INFIXA"){
			get_infix(root);
			for (int i = 0; i < prnt.size(); i++){
				cout << prnt[i];
				if (i != prnt.size()-1) cout << " ";
			}
			prnt.clear();
			cout << endl;
		}
		else if (str == "POSFIXA"){
			get_post(root);
			for (int i = 0; i < prnt.size(); i++){
				cout << prnt[i];
				if (i != prnt.size()-1) cout << " ";
			}
			prnt.clear();
			cout << endl;
		}
		else if (str == "PREFIXA"){
			get_prefix(root);
			for (int i = 0; i < prnt.size(); i++){
				cout << prnt[i];
				if (i != prnt.size()-1) cout << " ";
			}
			prnt.clear();
			cout << endl;
		}
	}

	return 0;
}