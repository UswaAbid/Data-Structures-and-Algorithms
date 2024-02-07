
#include<iostream>
using namespace std;

struct Node{
	
	int data;
	Node *left, *right;
	Node(int val){
		
		data = val;
		left = NULL;
		right = NULL;	
	}
};

 Node* insertBST(Node *root, int val)
 {
 	if(root == NULL){
 		return new Node(val);
	 }
 	
 	if(val < root->data){
 		root->left = insertBST(root->left , val);
	 }
	 
	 else{
	 	root->right = insertBST(root->right , val);
	 }
	 return root; 
 }

 void inorder(Node *root){
 	if(root == NULL){
 		return;
	 }
	 inorder(root->left);
	 cout << root->data << " ";
	 inorder(root->right);
 }
 
  Node* inorderSucc(Node* root){
  	Node* ptr = root;
  	while(ptr && ptr->left != NULL){
  		ptr = ptr->left;
	  }
	  return ptr;
  }
 
 Node* searchInBST(Node* root, int key){
 	
 	if(root == NULL){
 		return NULL; 
	 }
	 
 	if(root->data == key){
 		return root;
	 }
	 
	if(root->data > key){
 		return searchInBST(root->left , key);
	 }
	 
	 	return searchInBST(root->right , key);
 }
   
  Node* deleteInBST(Node* root, int key){
  //case 1 and 2
  
  if(key < root->data){
  	root->left = deleteInBST(root->left, key);
  }
  
   else if(key > root->data){
  	root->right = deleteInBST(root->right, key);
  }
  
   else{
   	if(root->left == NULL){
   		Node* temp = root->right;
   		delete(root);
   		return temp;
	   }
	   else if(root->right == NULL){
	   	Node* temp = root->left;
   		delete(root);
   		return temp;
	   }
	
	//case 3
	Node* temp = inorderSucc(root->right);
	root->data = temp->data;
	root->right = deleteInBST(root->right, temp->data);
   }
   return root;
 }
  
  
int main()
{
	Node *root = NULL;
	root = insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	insertBST(root,7);

    //print inorder
    cout << "\n\n__INSERTION__:";
    cout << "\n The tree build after insertion:  ";
    inorder(root);
    cout<< endl;
    
    int key;
     cout << "\n__SEARCHING__:";
    cout << "\n Enter the element to search in a tree: ";
    cin >> key;
    if(searchInBST(root, key) == NULL){
    	cout << " key doesnot exist";
	}else {
		cout << " key exists"; 
	}
	 cout << "\n\n__DELETION__:";
    cout << "\n Enter the element to delete in a tree: ";
    cin >> key;
    root = deleteInBST(root, key);
    
    cout << " The tree after deletion:  ";
    inorder(root);
    cout<< endl;
    
	return 0;
}
