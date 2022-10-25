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
    if(q->rare==q->size-1)  // condition for Full
    cout<<"Queue is Full";
    else{
        q->rare++;
        q->Q[q->rare] = x;
    }
}
int dequeue(struct Queue* q){ // Use to remove elements from first
    int x = -1;
    if(q->front==q->rare)  // Condition for empty
    cout<<"Queue is Empty";
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
bool isEmpty(struct Queue q){
    if(q.front==q.rare)
    return true;
    else
    return false;
}
bool isFull(struct Queue q){
    if(q.rare==q.size-1)
    return true;
    else
    return false;
}
void display(struct Queue q){
    for(int i=q.front+1;i<q.size;i++){ // Here i start from q.front+1 because front is pointing to that index which is deleted
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
}
int main(){
    struct Queue q;
    q.size = 4;
    q.Q = new int[q.size];
    q.front=q.rare=-1;
    enqueue(&q,1);
    enqueue(&q,4);
    enqueue(&q,7);
    enqueue(&q,3);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    cout<<isEmpty(q);

    return 0;

}