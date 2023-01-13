#include <iostream>
using namespace std;



int frnt=-1,rear=-1;
int q[5],priority[5];
int qSize=5;

void ENQ(int data, int p){
if(frnt==-1 && rear==-1){
  frnt=rear=0;
    q[rear]=data;
    priority[rear]=p;
    return;}
else if(rear==qSize-1){
   cout<<"The queue is full"<<endl;
    return;}
else{
    rear++;
    q[rear]=data;
    priority[rear]=p;
    return;}
}
void DEQ(){
    if(frnt==-1 && rear==-1){
        cout<<"The queue is already empty"<<endl;
        return;}
else if(frnt==rear){
        frnt=rear=-1;
        cout<<"Element deleted" <<endl;
    }
else{
        //get the lowest number index in priority queue
        int highPriIndex=frnt,highPriNo=priority[frnt], temp=0;//-1,p[-1]
     for(int i=frnt+1;i<rear+1;i++){//i=0,i<2+1
         if(priority[i]>highPriNo){//p[0]<max
                highPriNo=priority[i];//assign larger
                highPriIndex=i;}}//assign indexnumber
for(int i=highPriIndex;i>frnt;i--){  //shift it till front -1 and do front ++
           temp=q[i];
            q[i]=q[i-1];
            q[i-1]=temp;
            temp=priority[i];
            priority[i]=priority[i-1];
            priority[i-1]=temp;
        }
        frnt++;
        return;
    }
}

void pdisplay(){

for(int i=frnt;i<=rear;i++)
    cout<<q[i]<<" ";

cout<<endl;
return;
}
int main()
{
    
    return 0;
}