#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* left;
struct node* right;
};

struct node* insert(struct node*, int);
struct node* NewNode(int); 
struct node* build123();
void printTree(struct node*); 
void testBuild123();
int size(struct node*);
void testSize();
int maxDepth(struct node*);
void testMaxDepth(); 
int minValue(struct node*);
void testMinValue(); 
void printTree(struct node*);
void testPrintTree(); 
void printPostOrder(struct node*);
void testPrintPostOrder();
int hasPathSum(struct node*, int);
void testHasPathSum(); 
void printPaths(struct node*); 
void testPrintPaths();
void printPathsRecur(struct node*, int *,int);
 
int main() {

//testBuild123();
//testSize();
//testMaxDepth();
//testMinValue();
//testPrintTree();
//testPrintPostOrder();
//testHasPathSum();
testPrintPaths();
return 0;

}


/*
Give a binary search tree and a number, inserts a new node
with the given number in the correct place in the tree.
Returns the new root pointer which the caller should
then use (the standard trick to avoid using reference
parameters).
*/
struct node* insert(struct node* newnode, int data) {
// 1. If the tree is empty, return a new, single node
if (newnode == NULL) {
return(NewNode(data));
}
else {
// 2. Otherwise, recur down the tree
if (data <= newnode->data) newnode->left = insert(newnode->left, data);
else newnode->right = insert(newnode->right, data);
return(newnode); // return the (unchanged) node pointer
}
}

/*
Helper function that allocates a new node
with the given data and NULL left and right
pointers.
*/
struct node* NewNode(int data) {
struct node* newnode =(struct node*) malloc(sizeof(struct node));
// "new" is like "malloc"
newnode->data = data;
newnode->left = NULL;
newnode->right = NULL;
return(newnode);
}

/*Build a simple binary search tree with 2 as the root node.*/
struct node* build123() {

//Calling NewNode 3 times and with 3 pointers.
/*struct node* rootNode = NewNode(2);
struct node* leftNode = NewNode(1);
struct node* rightNode = NewNode(3);
rootNode->left = leftNode;
rootNode->right = rightNode;*/

//Calling NewNode 3 times and with 1 pointers.
/*struct node* rootNode = NewNode(2);
rootNode->left = NewNode(1);
rootNode->right = NewNode(3);*/

//Calling insert 3 times by passing root pointer.
struct node* rootNode = insert(NULL,2);
rootNode = insert(rootNode,1);
rootNode = insert(rootNode,3);
return rootNode;
}

/*Test function for build123()*/
void testBuild123() {
struct node* root = build123();
printf("Root node is %d \n",root->data);
printf("Left node is %d \n",(root->left)->data);
printf("Right node is %d \n",(root->right)->data);
}

/*Recursively count the number of nodes in a tree */
int size(struct node* newnode) {
int count = 0;
if(newnode != NULL)
{
  count++;
  if(newnode->left != NULL)
    count += size(newnode->left);
  if(newnode->right != NULL)
    count += size(newnode->right);
  return count;
}
}
 
/*Test function for testing size()*/
void testSize() {
struct node* rootNode = insert(NULL,2);
rootNode = insert(rootNode,1);
rootNode = insert(rootNode,3);
rootNode = insert(rootNode,5);
rootNode = insert(rootNode,4);
rootNode = insert(rootNode,8);
rootNode = insert(rootNode,9);
printf("Size of binary tree is %d \n",size(rootNode));
} 

/*Recursively find the maximum depth of a binary tree.*/
int maxDepth(struct node* n) {
int ldepth=0,rdepth=0;
if(n != NULL) {
  if(n->left != NULL)
    ldepth +=  maxDepth(n->left);
  if(n->right != NULL)
    rdepth += maxDepth(n->right);
  if(ldepth >= rdepth)
    return ++ldepth;
  else if(rdepth > ldepth)
    return ++rdepth;
}
}

/*Test function for testing maxDepth()*/
void testMaxDepth() {
struct node* rootNode = insert(NULL,2);
rootNode = insert(rootNode,1);
rootNode = insert(rootNode,3);
rootNode = insert(rootNode,5);
rootNode = insert(rootNode,4);
rootNode = insert(rootNode,8);
rootNode = insert(rootNode,9);
int depth = maxDepth(rootNode);
printf("Max Depth of binary tree is %d \n",depth);

}

int minValue(struct node* n) {
int min=0,temp=0;
if(n->left != NULL) {
  min = (n->left)->data;
  temp = minValue(n->left);
  if(min >= temp)
    min = temp;
  return min;
}
else
  return n->data;
}

/*Test function for testing minValue()*/
void testMinValue() {
struct node* rootNode = insert(NULL,3);
rootNode = insert(rootNode,2);
rootNode = insert(rootNode,1);
rootNode = insert(rootNode,5);
rootNode = insert(rootNode,4);
rootNode = insert(rootNode,8);
rootNode = insert(rootNode,9);
int min = minValue(rootNode);
printf("Min Value the binary search tree is %d \n",min);
}

/*Print the binary search tree in ascending order. */
void printTree(struct node* n) {
  
if(n->left != NULL) {
  printTree(n->left);
}
printf("%d ",n->data);

if(n->right != NULL) {
  printTree(n->right);
  //printf("%d ",(n)->data);
}

}

/*Test printTree() */
void testPrintTree() {
struct node* rootNode = insert(NULL,4);
rootNode = insert(rootNode,3);
rootNode = insert(rootNode,2);
rootNode = insert(rootNode,1);
rootNode = insert(rootNode,6);
rootNode = insert(rootNode,5);
rootNode = insert(rootNode,7);
printTree(rootNode);
}

/*Print the nodes of a binary search tree according to a postorder bottom-up traversal.
    4
   / \
  2   5
 / \
1   3 The output of the function should be 1,3,2,5,4.
   
 */
void printPostOrder(struct node* n) {

if(n->left != NULL) {
  printPostOrder(n->left);
}

if(n->right != NULL) {
  printPostOrder(n->right);
}
printf("%d ",n->data);

}

/*Test function for printPostOrder()*/
void testPrintPostOrder() {
struct node* rootNode = insert(NULL,4);
rootNode = insert(rootNode,2);
rootNode = insert(rootNode,5);
rootNode = insert(rootNode,3);
rootNode = insert(rootNode,1);
printPostOrder(rootNode);
}

int hasPathSum(struct node* n, int sum) {

int stemp=0;
if(n != NULL) {
  sum = sum - n->data;
  if(n->left != NULL || n->right != NULL) {
    if(n->right == NULL) {
     if(hasPathSum(n->left,sum) == 1) 
       return 1;
     }
    else if(n->left == NULL) {
     if(hasPathSum(n->right,sum) == 1)
      return 1;
    }
    else {
      if(hasPathSum(n->left,sum) == 1)
        return 1;
      if(hasPathSum(n->right,sum) == 1)
        return 1;

    }

  }  
if(sum == 0)
  return 1;  
else return -1;
    
}    

}

void testHasPathSum() {

struct node* rootNode = insert(NULL,5);
rootNode = insert(rootNode,4);
rootNode = insert(rootNode,8);
rootNode = insert(rootNode,3);
rootNode = insert(rootNode,7);
rootNode = insert(rootNode,9);
if(hasPathSum(rootNode,32) == 1)
  printf("Works \n");
else
  printf("you suckk..!! \n");

}

void printPaths(struct node* n) {
int *path = (int *)malloc(sizeof(int) * maxDepth(n));
printPathsRecur(n,path,0);

}

void printPathsRecur(struct node* n, int *path,int pathLen) {

if(n != NULL) {
  path[pathLen++] = n->data;
  if(n->left != NULL || n->right != NULL) {
     if(n->right == NULL) {
       printPathsRecur(n->left,path,pathLen);
     } 
     else if(n->left == NULL) {
       printPathsRecur(n->right,path,pathLen);
     }
     else {
       printPathsRecur(n->left,path,pathLen);
       printPathsRecur(n->right,path,pathLen);

     } 

  }
  else {
    for(int i=0;i<pathLen;i++)
      printf("%d ",path[i]);
       
    printf("\n-----------------------\n");
  }
}

}

void testPrintPaths() {

struct node* rootNode = insert(NULL,5);
rootNode = insert(rootNode,4);
rootNode = insert(rootNode,8);
rootNode = insert(rootNode,3);
rootNode = insert(rootNode,7);
rootNode = insert(rootNode,9);
rootNode = insert(rootNode,2);
rootNode = insert(rootNode,1);
printPaths(rootNode);

}
