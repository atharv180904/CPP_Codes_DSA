#include<iostream>
#include<string>
using namespace std;

#define size 5

class Element {
public:
    Element(int d, int p) {
        data = d;
        priority = p;
    }
    int getdata() {
        return data;
    }
    int getpriority() {
        return priority;
    }
    void setdata(int val) {
        data = val;
    }
    void setpriority(int val) {
        priority = val;
    }

private:
    int data;
    int priority;
};

class PriorityQueue {
private:
    int front;
    int rear;
    Element arr[size];

public:
    PriorityQueue() {
        front = -1;
        rear = -1;
        for(int i = 0; i < size; i++) {
            arr[i].setdata(0);
            arr[i].setpriority(0);
        }
    }

    void enqueue(Element e) {
        if(rear == size - 1) {
            cout << "Queue Is Full!" << endl;
        }
        else if(rear == -1 && front == -1) {
            rear = 0;
            front = 0;
            arr[rear] = e;
        }
        else {
            int i;
            for(i = rear; i >= front; i--) {
                if(e.getpriority() < arr[i].getpriority()) {
                    arr[i + 1] = arr[i];
                }
                else {
                    break;
                }
            }
            arr[i + 1] = e;
            rear = rear + 1;
        }
    }

    void dequeue() {
        int x;
        if(rear == -1 && front == -1) {
            cout << "Queue Is Empty!" << endl;
        }
        else {
            x = arr[front].getdata();
            arr[front].setdata(0);
            arr[front].setpriority(0);
            if(front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = front + 1;
            }
        }
    }
};
