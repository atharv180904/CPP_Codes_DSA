#include<iostream>
using namespace std;
class queue{
    private:
        int rear;
        int front;
        int arr[5];
    public: 
        queue(){
            rear=-1;
            front=-1;
            for(int i=0;i<5;i++){
                arr[i]=0;
            }
        }
        void enqueue(int val){
            if(rear==(rear+1)%5){
                cout<<"Queue Is Full!"<<endl;
            }
            else if(front==-1 && rear==-1){
                cout<<"Queue is completely empty"<<endl;
                front=0;
                rear=0;
                arr[rear]=val;

            }
            else{
                rear=(rear+1)%5;
                arr[rear]=val;
            }
        }
        void dequeue(){
            int x;
            if(front==-1 && rear==-1){
                cout<<"Queue is Empty!"<<endl;
            }
            else if(front == rear){
                cout<<"Only one element exists"<<endl;
                x=arr[front];
                arr[front]=0;
                front=-1;
                rear=-1; 

            }
            else{
                x=arr[front];
                arr[front]=0;
                front=(front+1)%5;
            }

        }
        void display(){
            for(int i=0;i<5;i++){
                cout<<arr[i]<<endl;
            }

        }
        
};
int main(){
    return 0;
}