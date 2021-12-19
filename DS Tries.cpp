#include <iostream>
#include <string>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child = root->children[index];
        if (child== NULL) {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }
	bool search(TrieNode* root, string str)
    {
        if(str.size() == 0){
            return root->isTerminal;
        }   
        
        int index = str[0] - 'a';
        TrieNode* child = root->children[index];
        
        if(child == NULL) return false; 
        
        return search(child, str.substr(1));
    }
    bool searchWord(string word) {
        // Write your code here
        return search(this->root, word);
    }
    
    void pop(TrieNode *root, string str)
    {
        if(str.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int child_index = str[0] - 'a';
        TrieNode *child = root->children[child_index];
        if(!child)
        {
            //cout << "child not exist\n";
            return;
        }
        pop(child, &str[1]);
        if(child->isTerminal != true)
        {
            for(int i = 0; i < 26; i++)
            {
                if(child->children[i] != NULL) return;
            }
            delete child;
            root->children[child_index] = NULL;
        }
        
    }

    void pop(string str)
    {
        pop(this->root, str);
    }


    bool check(TrieNode* root, string str)
    {
	int i; 
	for(i = 0; i < str.size(); i++)
	{
		int ci = str[i] - 'a';
		
		TrieNode* ch = root->children[ci];
		if(ch != NULL)
		{
			root = ch;
			continue;
		}
		else break;
	}
	if(i == str.size()) return true;
	return false;
    }

    bool helpSearch(TrieNode *root, string str)
    {
	if(root == NULL) return false;
	
	bool ans = check(root, str);
	if(ans == true) return true;

	for(int ci = 0; ci < 26; ci++)
	{
		TrieNode* ch = root->children[ci];
		if(ch != NULL)
		{
			ans = helpSearch(ch, str);
			if(ans == true) return true;
		}
	}
	return false;
    }
    bool search(string str)
    {
	return helpSearch(this->root, str);
    }
};
int main() {
	Trie t;
/*	t.insertWord("abcdef");

	cout << t.search("abcdef") << endl;

 	t.pop("abcdef");
 	cout << t.search("abcdef") << endl;*/

	for(int i = 0; i < 4; i++)
	{
		cout << "Enter string: ";
		string  str;
		getline(cin, str);
		t.insertWord(str);
	}
	/*
	for(int i = 0; i < 5; i++)
	{
		cout << "Enter serch: ";
		string st;
        	getline(cin, st);
		if(t.searchWord(st)==1) cout << "True\n"; 
		else cout << "False\n";
	}*/
	
	for(int i = 0; i < 3; i++)
	{
		cout << "ser : ";
		string st;
		getline(cin, st);
		if(t.search(st) == true) cout << "True\n";
		else cout << "False\n"; 
	}

}


