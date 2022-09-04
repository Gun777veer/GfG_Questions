//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.


void delete_begin(Node* head){     //inserting at the beginning

    head=head->next;
}

void delete_middle(int k, Node* head){
    if(k==0){
        delete_begin(head);
    }
    else{
    struct Node* p=head;
    int count =0;

    while(count!=(k-2)){
        p=p->next;
        count++;
    }
    p->next=p->next->next;
    }

}



Node *removeDuplicates(Node *head)
{
    struct Node* ptr=head;
    struct Node* ptr1=head;

    int count1=0,count2=0;


    while(ptr!=NULL){
        while(ptr1!=NULL){
            if(ptr->data==ptr1->next->data){
                delete_middle(count1, head);
            }
            count2++;
            ptr1=ptr1->next;
        }
        count1++;
        ptr=ptr->next;
    }
 // your code goes here
}