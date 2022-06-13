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

int findParent(int* parent, int v) {
	if(parent[v] == v) {
		return v;
	}
	return findParent(parent, parent[v]);

}

void MST() {
	output = new Edge[n-1];
	int parent[n];
	for(int i = 0; i < n; i++) parent[i] = i;
	int count = 0; 
	int k = 0;

	while(count < n-1) {
		for(int i = 0; i < e; i++) {
			//arr[i], v2, v2;
			int p1 = findParent(parent, arr[i].v1);
			int p2 = findParent(parent, arr[i].v2);

			if(p1 == p2) continue;
			parent[p1] = p2;
			output[k++] = arr[i];
			count++;
		}
	}

}

int main()
{
	cin >> n >> e;
	arr = new Edge[e];
	for(int i = 0; i < e; i++) {
		cin >> arr[i].v1 >> arr[i].v2 >> arr[i].w;
	}
//	print(arr, e);
	
	sort(arr, arr+e, compair);
	cout << endl;
//	print(arr, e);
    
	MST();
	print(output, n-1);


	return 0;
}
