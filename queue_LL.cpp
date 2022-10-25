#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

}*front = NULL,*rear = NULL;  // golobally access

void enqueue(int x){
    Node* t = new Node(x);
    if(t==NULL){                    // heap is Full
        cout<<"Queue is Full"<<endl;
    }
    if(front==NULL){      // first Entry
        front = rear = t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}

int dequeue(){
    int x =-1;
    if(front == NULL){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        Node* p;
        p = front;
        x = p->data;
        front = front->next;
        free(p);
    }
    return x;
}
void display(){
    Node* p = front;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
