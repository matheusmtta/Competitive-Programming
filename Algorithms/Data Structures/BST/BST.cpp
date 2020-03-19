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

void get_infix(struct node *v){
	if (v != nullptr){
		get_infix(v->left);
		cout << " " << v->value;
		get_infix(v->right);
	}
}

void get_post(struct node *v){
	if (v != nullptr){
		get_post(v->left);
		get_post(v->right);
		cout << " " << v->value;
	}
}

void get_prefix(struct node *v){
	if (v != nullptr){
		cout << " " << v->value;
		get_prefix(v->left);
		get_prefix(v->right);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	struct node *root = nullptr;

	int x; cin >> x;

	root = insert(root, x);

	for (int i = 1; i < n; i++){
		int x; cin >> x;
		insert(root, x);
	}

	cout << "Pre.:";
	get_prefix(root);
	cout << endl;

	cout << "In..:";
	get_infix(root);
	cout << endl;

	cout << "Post:";
	get_post(root);
	cout << endl;
	cout << endl;
	
	return 0;
}