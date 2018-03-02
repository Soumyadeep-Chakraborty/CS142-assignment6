//Binary-search on Linkedlists

#include <iostream>

using namespace std;

//declaring a class node that specifies the components of a node 

class node

{

public:

int data;

node *next;

node *prev;

//class constructor for class node

node() { 

    data = 0;

    next = NULL;

    prev = NULL;

}

};

//declaring a class linkedlist that specifies the componenets of a LL and declares some elementary functions of LL

class linked_list

{

public:

node *head, *tail;

//class constructor for LL

linked_list() 

{

head = NULL;

tail = NULL;

}

void insert(int data);//functions in linked list

};

//function to insert nodes into a linked list

void linked_list::insert (int data){

node *tmp = new node;

tmp->data = data;

tmp->next = NULL;

tmp->prev = NULL;

if(head == NULL)

{

head = tmp;

tail = tmp;

}

else

{

tail->next = tmp;

tmp->prev = tail;

tail = tail->next;

}

}

//function to count the number of nodes in a linked-list

int countItems (node* temp,node* temp2){

    int c=0;

    while(temp != temp2->next){

        temp = temp->next;

        c++;

    }

    return c;

}

//declaring a function binary search that takes the head of LL, tail of LL and the key as argument and returns the position of the key

int bsearch(node* h,node* t,int k){

    node*curr=h; //declaring curr as a pointer to a node that initially points to the head

    int c=countItems(h,t); //c is the total number of elements the LL contains
	
	//loop to locate the middle element of the LL and store the address in the pointer curr
	
    for(int i=1;i<(c/2);i++){

        curr=curr->next;

    }

    if(curr->data==k){

        return countItems(h,curr); //if the data of the middle element is the key, it returns the position of the element by calling function countitems

    }

    else if(curr->data>k){

        if(curr->data!=curr->prev->data+1){

            cout<<"error";

        }

        return bsearch(h,curr->prev,k); //recursive calling to bsearch function if curr->data is greater than the key

    }

    else if(curr->data<k){

        if(curr->data!=curr->prev->data+1){

            cout<<"error";

        }

        return bsearch(curr->next,t,k); ////recursive calling to bsearch function if curr->data is lesser than the key

    }

    else{
		cout<<"ERROR!!-Element not found";
        return -1;

    }

}

//declaring a class bubblesort that sort the elements in a linked list in an ascending order

class bubblesort{

    public:
	
	//sort function taking nodes of linked lists as argument
	
   void sort(node *h){

	for(node*i = h;i!=NULL;){

    for(node*j = h;j->next!=NULL;){

    if((j->data) > j->next->data){

    int t = j->next->data;

    j->next->data = j->data;

    j->data = t;

    }j=j->next;

    }i=i->next;

    }return;

   }

};

int main(){

    int key;
    
    int x,d;

    cout<<"Enter size of linked list : ";

    cin>>x;
    
	//declaring an class component ll1 belonging to class linked list
	
    linked_list ll1;
    
	//calling the bubble sort function
	
    bubblesort c;
    
    	cout<<" Enter the elements of linked list : ";
	
	for(int i=0;i<x;i++){
		cout<<"node["<<i<<"]->data : ";
		cin>>d;
		ll1.insert(d);
		cout<<"\n";
	}

    c.sort(ll1.head);

    cout<<"Enter the element whose position you want to find : ";

    cin>>key;

    int ans=bsearch(ll1.head,ll1.tail,key);

    cout<<"The element is in position : "<<ans;

    return 0;

}
