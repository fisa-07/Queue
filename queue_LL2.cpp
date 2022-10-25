#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    public:
    Node(){}   // unparamatersied constuctor for declearing obj in main
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    void enqueue(int x);
    int dequeue();
    void display();
}*front = NULL,*rear = NULL;  // golobally access

void Node::enqueue(int x){
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

int Node :: dequeue(){
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

void Node :: display(){
    Node* p = front;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    Node q;
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(-1);
    q.display();
    return 0;
}