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
                left =  NULL;
                right = NULL;
        }

};

void normal_priority_queue()
{
        int a = 5, b = 3, c = 8;
        priority_queue<int, vector<int>, greater<int> > pq;
        priority_queue<int> pq1;

        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        pq1.push(a);
        pq1.push(b);
        pq1.push(c);

        while(!pq.empty() | !pq.empty())
        {
                int it = pq.top();
                int it1 = pq1.top();

                pq.pop();
                pq1.pop();

                cout << it <<  ", ";
                cout << it1 << endl;
        }
}

void pair_type_priority_queue()
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
int main()
{
        normal_priority_queue();
        pair_type_priority_queue();
}

