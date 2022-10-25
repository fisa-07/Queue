#include<iostream>
using namespace std;
struct Queue{    // Sturcture Queue 
    int size;
    int front;
    int rare;
    int* Q;
};
// Here we take Queue call by Reference
void enqueue(struct Queue* q,int x){  // Use to insert elsement in Queue using rare pointer
    if((q->rare+1)%q->size==q->front)  // condition for Full
    cout<<"Queue is Full"<<endl;
    else{

        q->rare = (q->rare+1)%q->size;
        q->Q[q->rare] = x;
    }
}
int dequeue(struct Queue* q){ // Use to remove elements from first
    int x = -1;
    if(q->front==q->rare)  // Condition for empty
    cout<<"Queue is Empty"<<endl;
    else{
        q->front = (q->front+1)%q->size;;
        x = q->Q[q->front];
    }
    return x;
}
void display(struct Queue q){
    int i = q.front+1;
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    }while(i!=(q.rare+1)%q.size);
    cout<<endl;
}
int main(){
    struct Queue q;
    q.size = 4;
    q.Q = new int[q.size];
    q.front=q.rare=0;
    enqueue(&q,1);
    enqueue(&q,4);
    enqueue(&q,7);
    display(q);
    dequeue(&q);
    enqueue(&q,10);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    
    return 0;

}