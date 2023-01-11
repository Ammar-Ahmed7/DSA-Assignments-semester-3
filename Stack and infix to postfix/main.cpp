
#include <iostream>

using namespace std;

struct stk{
    char a[10];
    int top=-1;
}s;
bool isEmpty(){
    if(s.top<0)
        return true;
    return false;
}
void push(char num){
    if(s.top>9)
        cout<<"OverFlow!!!";
    else{
        s.top++;
        s.a[s.top]=num;
    }
}

void pop(){
    if(isEmpty())
        cout<<"UnderFlow!!!"<<endl;
    else
        s.top--;
}
//int stack
struct stk_int{
    int a[10];
    int top=-1;
}st;
bool isEmptyst(){
    if(st.top<0)
        return true;
    return false;
}
void pushst(int num){
    if(st.top>9)
        cout<<"OverFlow!!!";
    else{
        st.top++;
        st.a[st.top]=num;
    }
}

void popst(){
    if(isEmptyst())
        cout<<"UnderFlow!!!"<<endl;
    else
        st.top--;
}

void display(){
    for(int i=s.top;i>=0;i--){
        cout<<s.a[i];
    }
}


void displayst(){
    for(int i=st.top;i>=0;i--){
        cout<<st.a[i];
    }
}
//To check if a expression is balanced
void balance_expression(string ch){
 for(int i=0;ch[i]!='\0';i++){
    if(ch[i]=='{' || ch[i]=='[' || ch[i]=='(')
        push(ch[i]);
    if(s.a[s.top]=='{' && ch[i]=='}' || s.a[s.top]=='[' && ch[i]==']' || s.a[s.top]=='(' && ch[i]==')')
        pop();
    }
  if(s.top<0){
    cout<<"Balance";
  }
  else
    cout<<"Not Balance";
}
//To reverse a string
void reverse_string(string str){
    for(int i=0;str[i]!='\0';i++)
        push(str[i]);
    display();
}
// To Check priority.
int priority (char alpha)
{
    if(alpha == '+' || alpha =='-')
        return 1;
    if(alpha == '*' || alpha =='/')
        return 2;

    return 0;
}

//For infix to postfix conversion
void infix_postfix(string ch){
    string output="";
for(int i=0;ch[i]!='\0';i++){
        if(ch[i]>96 && ch[i]<123){
            output+=ch[i];
        }

        else if(ch[i]=='(')
            push(ch[i]);

        else if(ch[i]==')'){
            while(s.a[s.top]!='('){
                output+=s.a[s.top];
                pop();
            }
            pop();
        }
        else {
               while( s.a[s.top]!='(' && priority(ch[i])<=priority(s.a[s.top]) && !isEmpty() ){
                    output += s.a[s.top];
                    pop();
                }
                push(ch[i]);
        }
    }
    while(!isEmpty()){
                output+=s.a[s.top];
                pop();
            }
    cout<<output;
}
void evalPostfix(string str){
    int a,b;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>=48 && str[i]<=57){
            pushst(int(str[i]-'0'));
           // cout<<endl<<int(str[i]);
            }
        else if(str[i]=='+' || str[i]=='-' ||str[i]=='*' ||str[i]=='/' ){
            a=st.a[st.top];
            popst();
            b=st.a[st.top];
            popst();
            if(str[i]=='+')
                pushst(b+a);
            else if(str[i]=='-')
                pushst(b-a);
            else if(str[i]=='*')
                pushst(b*a);
            else if(str[i]=='/')
                pushst(b/a);

        }
        }

       /* while(!isEmptyst()){
                sum+=st.a[st.top];
                popst();
            }*/

      cout<<st.a[st.top];
    }
//decimal to binary conversion using stack
void decimal_binary(int num){
    while(num!=0){
        pushst(num%2);
        num = num/2;
    }
    displayst();
}

int main()
{
    string ch;
    cout<<"Enter:";
    cin>>ch;
    //balance_expression(ch);
    //reverse_string(ch);
    //infix_postfix(ch);
    evalPostfix(ch);
    //decimal_binary(122);

    return 0;
}
