#include<iostream>
#include<string>
// #include<stack>
using namespace std;
class stack{
    public:
        stack(){
            top=-1;
            for(int i=0;i<10;i++){
                arr[i]=0;
            }
        }
        void pushele(int val){
            if(top==9){
                cout<<"Stack Overflow!"<<endl;
            }
            else{
                top=top+1;
                arr[top]=val;
                cout<<"Value = "<<val<<" pushed succesfully"<<endl; 
            }
        }
        void popele(){
            if(top==-1){
                cout<<"Stack Underflow!"<<endl;
            }
            else{
                int tempele;
                tempele=arr[top];
                arr[top]=0;
                cout<<"Last Element poped succesfully"<<endl; 
            }
        }
        void display(){
            for(int i=9;i>=0;i--){
                cout<<"Stack Element "<<i<<" is: "<<arr[i]<<endl;
            }
        }
    private:
        int top;
        int arr[10];
};
int main(){
    stack s1;

    s1.pushele(10);
    s1.display();
    s1.popele();
    s1.display();
}
