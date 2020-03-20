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

vector <int> prnt;

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

struct node* insert(struct node* v, int x){
	if (v == nullptr) return newNode(x);
	if (x < v->value)
		v->left = insert(v->left, x);
	else if (x > v->value)
		v->right = insert(v->right, x);
	return v;
}

bool search(struct node* v, int x){
	if (v == nullptr) return false;
	if (v->value == x) return true;
	if (x < v->value && v->left != nullptr)
		return search(v->left, x);
	else if (x > v->value && v->right != nullptr)
		return search(v->right, x);
	return false;
}

struct node *get_max(struct node *v){
	if (v == nullptr)
		return nullptr;
	else if (v->right == nullptr)
		return v;
	else
		return get_max(v->right);
}

struct node *get_min(struct node *v){
	if (v == nullptr)
		return nullptr;
	else if (v->left == nullptr)
		return v;
	else 
		return get_min(v->left);
}

struct node *del(struct node *v, int x){
	if (v == nullptr) return nullptr;
	if (x < v->value)
		v->left = del(v->left, x);
	else if (x > v->value)
		v->right = del(v->right, x);
	else if (v->left && v->right) {
		struct node *tmp = get_max(v->left);

		v->value = tmp->value;
		v->left = del(v->left, tmp->value);
	}
	else {
		struct node *tmp = v;
		if (v->left == nullptr)
			v = v->right;
		else if (v->right == nullptr)
			v = v->left;

		delete tmp;
	}
	return v;
}

void get_infix(struct node *v){
	if (v != nullptr){
		get_infix(v->left);
		prnt.push_back(v->value);
		get_infix(v->right);
	}
}

void get_post(struct node *v){
	if (v != nullptr){
		get_post(v->left);
		get_post(v->right);
		prnt.push_back(v->value);
	}
}

void get_prefix(struct node *v){
	if (v != nullptr){
		prnt.push_back(v->value);
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
			int x; cin >> x;
			if (root == nullptr) root = insert(root, x);
			insert(root, x);
		}
		else if (str == "P"){
			int x; cin >> x;
			search(root, x) ? cout << x << " existe" << endl : cout << x << " nao existe" << endl;
		}
		else if (str == "R"){
			int x; cin >> x;
			root = del(root, x);
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