#include<iostream>
#include<stack>
using namespace std;

int findprecedance(char ch){
    switch(ch){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return 0; // Default case added to handle non-operator characters
    }
}

int main(){
    int i,j;
    char ch;
    char infix[100], postfix[100];
    stack<char> s1;
    cout<<"Enter Infix Expression: "<<endl;
    cin>>infix;

    // Parenthesize the infix expression
    for(i=0;infix[i]!='\0';++i);
    for(j=i;j>=0;j--){
        infix[j+1]=infix[j]; 
    }
    infix[0]='(';
    infix[i+2]='\0';
    infix[i+1]=')';
    cout<<"Infix Parenthesized: "<<infix<<endl;

    // Convert infix to postfix
    i=0;
    j=0;
    for(i=0;infix[i]!='\0';i++){
        if(infix[i]=='('){
            s1.push(infix[i]);
        }
        else if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')){
            postfix[j]=infix[i];
            j=j+1;
        }
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/'){
            while(findprecedance(s1.top())>=findprecedance(infix[i])){
                char popped = s1.top();
                s1.pop();
                postfix[j]= popped;
                j=j+1;
            }
            s1.push(infix[i]);
        }
        else if(infix[i]==')'){
            char ch;
            while((ch = s1.top())!='('){
                s1.pop();
                postfix[j]=ch;
                j=j+1;
            }
            s1.pop(); // Pop '('
        }
    }
    postfix[j]='\0'; // Null-terminate the postfix expression

    // Print the postfix expression
    cout<<"Postfix Expression: "<<postfix<<endl;

    return 0;
}
