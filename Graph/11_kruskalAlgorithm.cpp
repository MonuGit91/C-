#include <iostream>
using namespace std;

class Edge {
public:
	int v1, v2, w;
};

int n, e;
Edge* arr;
Edge* output;

bool compair(Edge e1, Edge e2) {
	return (e1.w < e2.w);
}

void print(Edge *arr, int e) {
	for(int i = 0; i < e; i++) {
        cout << arr[i].v1 << " " << arr[i].v2 << " " << arr[i].w << endl;
    }
}

//for one edge Time complexity of findParent: O(V) 
//for E edges Time complexity: O(EV)
//for complete graph E = V^2
int findParent(int* parent, int v) {
	if(parent[v] == v) {
		return v;
	}
	return findParent(parent, parent[v]);

}

//____________________________________________________________________________________________
//Union find algorithm ie, Union by rank and path compression
//---------------------------------------------------------------
//Time Complexity(findParentByPathCompression): 4alpha
int findParentByPathCompression(int* parent, int man) {
	if(parent[man] == man) {
		return man;
	}
	return parent[man] = findParentByPathCompression(parent, parent[man]);
}

void unionByRank(int* rank, int man1, int man2, int *parent) {
	if(rank[man1] < rank[man2]) {
		parent[man1] = man2;
	}
	else if(rank[man1] > rank[man2]) {
		parent[man2] = man1;
	}
	else {
		parent[man1] = man2;
		rank[man1]++;
	}
}
//----------------------------------------------------------------


void MST(Edge* arr, int &n, int &e) {
	sort(arr, arr+e, compair);//Time Complexity: E(logE)
	//  print(arr, e);

	output = new Edge[n-1];
	int parent[n];
	
	for(int i = 0; i < n; i++) parent[i] = i;
	
	int count = 0; 
	int k = 0;
/*
	int rank[n];
	for(int i = 0; i < n; i++) {
		rank[i] = 0;
	}
*/
	for(int i = 0; i < e && count < n-1; i++) {
		//arr[i], v2, v2
//		int p1 = findParentByPathCompression(parent, arr[i].v1);
//		int p2 = findParentByPathCompression(parent, arr[i].v2);
		int p1 = findParent(parent, arr[i].v1);
		int p2 = findParent(parent, arr[i].v2);

		if(p1 == p2) continue;		
		
//		unionByRank(rank, p1, p2, parent);
		parent[p1] = p2;

		output[k++] = arr[i];
		count++;
	}

}

int main() {
	cin >> n >> e;
	arr = new Edge[e];
	for(int i = 0; i < e; i++) {
		cin >> arr[i].v1 >> arr[i].v2 >> arr[i].w;
	}
//	print(arr, e);
	cout << endl;
    
	MST(arr, n, e);
	print(output, n-1);


	return 0;
}
/*
4 4
0 1 3
0 3 5
1 2 1
2 3 8

1 2 1
0 1 3
0 3 5
*/
