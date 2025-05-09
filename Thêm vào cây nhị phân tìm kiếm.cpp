/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
insert
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
//###INSERT CODE HERE
Node* T = root;
if(root==NULL) {
    Node* tmp = new Node(data);
        root = tmp;
}
while(T){
if(T->data == data)	return root;

if(T->data	> data)	{
if(T->left==NULL){
Node* tmp = new Node(data);
T->left	= tmp;
}
else T = T->left;
}

else{
if	(T->right == NULL){
Node* tmp = new Node(data);
T->right = tmp;
}
else T = T->right;
}
}
return	root;
    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}
