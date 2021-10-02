#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	char ch;
	Node *left;
	Node *right;
	
	Node(char c)
	{
		ch = c;
		left = 	NULL;
		right = NULL;
	}

};
int main()
{
	Node* n1 = new Node('a');
	Node* n2 = new Node('b');
	Node* n3 = new Node('c');
	Node* n4 = new Node('d');

	pair<int, Node*> p(5,n1 ), p1(4,n2), p3(1,n3), p2(2,n4);

	priority_queue<pair<int, Node*>, vector<pair<int, Node*> >, greater<pair<int, Node*> > > pq;
	priority_queue<pair<int, Node*> > pq1;

	pq.push(p);
	pq.push(p1);
	pq.push(p2);
	pq.push(p3);

	pq1.push(p);
        pq1.push(p1);
        pq1.push(p2);
        pq1.push(p3);

	while(!pq.empty() | !pq.empty())
	{
		pair<int, Node*> it = pq.top();
		pair<int, Node*> it1 = pq1.top();

		pq.pop();
		pq1.pop();

		cout << it.first << " " << (it.second)->ch << endl;
		cout << it1.first << " " << (it1.second)->ch << endl << endl;
	}


	
}
