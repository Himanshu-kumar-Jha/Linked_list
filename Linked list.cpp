#include <iostream>
using namespace std;
//print a linked list
class list; //forward decleration
class Node{
    int data;
    public:
    Node *next;
    friend class list;
    int getdata(){
        return data;
    }
    Node(int d):data(d),next(NULL){}
    //to delete a node we use node destructor
    ~Node(){
        if(next!=NULL){
            delete next;
        }
        cout<<"deleating node with data "<<data<<endl;
    }
};




class list{
    Node *head;
    Node *tail;
    public:
    // initilation of a new linked list
    //both head and tail are null
    Node*begin(){
        return head;
    }
    list():head(NULL),tail(NULL){}; //list constructor
    void push_front(int data){
        if(head==NULL){
            Node*n=new Node(data);
            head=tail=n;
        }
        else{
            Node *n=new Node(data);
            n->next=head;
            head=n;
        }
    }
    
    
    void push_back(int data){
        if(head==NULL){
            Node*n=new Node(data);
            head=tail=n;
        }
        else{
            Node *n=new Node(data);
            tail->next=n;
            tail=n;
        }}
    void insert(int data, int pos){
        if(pos==0) push_front(data);
        else{
            Node *temp=head;
            for(int jump=1;jump<=pos-1;jump++){
                temp=temp->next;
            }
            Node*n=new Node(data);
            n->next=temp->next;
            temp->next=n;
        }
    }
    int search(int key){
        Node*temp=head;
        int pos=0;
        while(temp!=NULL){
            if(temp->data==key){
                return pos;
            }
            pos++;
            temp=temp->next;
        }
        return -1;
    }
    //recursive search
    int helper_search(Node *start,int key){
        if(start==NULL){
            return -1;
        }
        if(start->data==key){
            return 0;
        }
        // remaining part of linked list
        int subidx=helper_search(start->next,key);
        if(subidx==-1) {
            return -1;
        }
        return subidx+1;
    }
    int recursive_search(int key){
        int pos=helper_search(head,key);
        return pos;
    }
    void pop_front(){
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    //destructor for list
    ~list(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
};
int main() {
    list l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(5);
    l.push_back(0);
    l.insert(7,2);
    l.pop_front();
    // to print a linked list
    Node*head=l.begin();
    while(head!=NULL){
        cout<<head->getdata()<<"->";
        head=head->next;
    }
    cout<<endl;
    cout<<l.search(1)<<endl;
    cout<<l.recursive_search(1)<<endl;

    return 0;
}