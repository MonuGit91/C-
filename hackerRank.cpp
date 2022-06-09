#include <iostream>
#include <string>
using namespace std;

int starting(string A, int i, string s) {
  	int j = 0; 
  	for(j =  0; j < s.size(); j++) {
     	if(A[i] == s[j]) return j; 
    }
  	return -1;
}
int mat(string A, int i, string s, int p) {
 	int count = 0;
  	while(i < A.size() && p < s.size() && (A[i] == s[p])) {
      	i++;
      	p++;
      	count++;
    }
  	return count;
}
int main() {
  	string A, s;
  	getline(cin, A);
	getline(cin, s);

  	int i, p, m, count = 0;
  	for(i = 0; i < A.size(); i++) {
     	p = starting(A, i, s);  	
      	if(p == -1) continue;	
      	m = mat(A, i, s, p);
      	
      	if(p == 0) {
         	count += (1 + (s.size()-m)); 
        }
      	else {
         	count += (1 + (s.size()+m)); 
        }
		i = i+m;
    }
  	cout << count << endl;
 	return 0;
}
