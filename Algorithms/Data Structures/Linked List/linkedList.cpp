#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

struct Node {
	Node *next, *previous;
	int data;

	Node(int data = 0) : data(data) {
		next = previous = nullptr;
	};
};

struct List {
	int length = 0;
	Node *head = nullptr, *tail = nullptr;

	List()  {};

	void append(int data){
		Node *tmp = new Node(data);

		if (length == 0) head = tail = tmp; 
		else {
			tmp->previous = tail;
			tail->next = tmp;
			tail = tmp;
		}

		length++;
	}

	void pop_back(){
		if (length == 0) return;
		
		Node *tmp = new Node;
		if (length == 1){
			tmp = head;
			head = tail = nullptr;
		}
		else {
			tmp = tail;
			tail->previous->next = nullptr;
			tail = tail->previous;
		}

		delete tmp;
		length--;
	}

	void clear(){
		Node *tmp, *nxt;
		tmp = head;

		while (tmp != nullptr){
			nxt = tmp->next;
			delete tmp;
			tmp = nxt;
			length--;
		}

		head = nullptr, tail = nullptr;
	}

	void display(){
		Node *tmp = head;

		while (tmp != nullptr){
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		cout << endl;
	}

	int size(){
		return length;
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}
