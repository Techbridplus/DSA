#include<iostream>
#include<string>
#include<stack>
using namespace std;
int precedence(char c){
    if(c=='+' or c=='-'){
        return 0;
    }else if(c=='/' or c=='*'){
        return 1;
    }else{
        return 2;
    }
}
void infix_to_postfix(string inf,string& postf){
    stack<char> st;
    for(char c:inf){
        if(c=='+' or c=='-' or c=='/' or c=='*' or c=='^'){
            if(st.empty() or precedence(st.top())<precedence(c) or st.top()=='('){
            st.push(c);
            }else if(precedence(st.top())>=precedence(c)){
                while(!st.empty() and st.top()!='(' and precedence(st.top())>=precedence(c)){
                    postf+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }else if(c=='('){
            st.push(c);
        }else if(c==')'){
            char a;
            while((a=st.top())!='('){
                postf+=a;
                st.pop();
            }
            st.pop();
        }else{
            postf+=c;
        }
    }
    postf+=st.top();
}
int main(){
    string infix;
    string postfix="";
    cout<<"enter an infix expression : ";
    cin>>infix;
    infix_to_postfix(infix,postfix);
    cout<<"the postfix expression is : "<<postfix<<endl;
    return 0;
}