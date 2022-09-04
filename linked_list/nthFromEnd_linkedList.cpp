//{ Driver Code Starts
// C program to find n'th Node in linked list
//https://www.geeksforgeeks.org/data-structures/linked-list/?ref=shm
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
    int length(Node* head){
        int count=0;
        Node* ptr =head;
        
        while(ptr){
            count++;
            ptr=ptr->next;
        }
        
        return count;
    }

int getNthFromLast(Node *head, int n)
{
    if(n>length(head)){
        return -1;
    }
    else{
         struct Node* ptr=head;
  
  int i=length(head)-n;
  
  while(i--){
      ptr=ptr->next;
  }
  
  return ptr->data;
    }
}

