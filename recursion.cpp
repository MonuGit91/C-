#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
Node* helpFactorial(int n, Node* tail) {
    if(n == 1) {
        tail = new Node(1);
        return tail;
    }
    
    tail = helpFactorial(n-1, tail);

    Node* temp = tail; 
    Node* pre = NULL;
    int carry = 0;
    while(temp) {
        int data = temp->data * n + carry;
       
        temp->data = data % 10;
        carry = data/10;

        pre = temp;
        temp = temp->next;
    }
    while(carry) {
        pre->next = new Node(carry%10);
        carry /= 10;
        pre = pre->next;
    }
    return tail;
}
void printFactorial(Node* tail) {
    if(tail == NULL) return;
    
    printFactorial(tail->next);

    cout << tail->data;
}

void factorialLargeNo(int n) {
    Node* tail = helpFactorial(n, NULL);
    printFactorial(tail);
}

int factorial(int n) {
    if(n == 0) return 1;
    return n*factorial(n-1);
}

int summation(int n) {
    if(n == 0) return 0;
    return n+summation(n-1);
}
int pow(int x, int n) {
    if(n == 0) return 1;
    return x*pow(x, n-1);
}
int countDigits(int n) {
    if(n == 0) return 0;
    return 1 + countDigits(n/10);
}
void print1ToN(int n) {
    if(n == 0) return;
    print1ToN(n-1);
    cout << n << " ";
}

bool arrSortedOrNot(int arr[], int n) {
    if(n == 1) return true;
    
    if(arr[n-1] < arr[n-2]) return false;

    return arrSortedOrNot(arr, n-1);

}

int nthFibonachiiHelper(int n, int arr[]) {
    if(n == 0 || n == 1) {
        arr[n] = n;
        return n;
    }
    
    if(arr[n] != -1) {
        return arr[n];
    }

    return arr[n] = nthFibonachiiHelper(n-1, arr) + nthFibonachiiHelper(n-2, arr);
}
int nthFibonachii() {
    int n = 20;
    int arr[n+1];
    for(int i = 0; i <= n; i++) arr[i] = -1;
    return nthFibonachiiHelper(n, arr);
}
int main() {
    cout << "factorial: " << (factorial(10)) << endl;
    cout << "factorial of large no: ", factorialLargeNo(10);
    cout << "\nsummation: " << (summation(5)) << endl;
    cout << "power of n: " << pow(2, 3) << endl;
    cout << "countDidits: " << countDigits(10) << endl;
    cout << "print 1 to n: ", print1ToN(5);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "\narrSortedOrNot: " << arrSortedOrNot(arr, 10) << endl;

    
    cout << "Fibonachii: " <<  nthFibonachii();

    return 0;
}