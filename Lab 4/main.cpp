#include <iostream>

using namespace std;

/*int sum(int a,int b,int c,int d){
    int sum;
     sum=a+b+c+d;
     return sum;

}

int sub(int a,int b){
     int sub;
     sub=a-b;
     return sub;

}

int divd(int a,int b){
    int divi;
    divi=a/b;
    return divi;

}

int mul(int a,int b){
    int mul;
    mul=a*b;
    return mul;

}*/



int rsum(int a){
    int sum=0;
if(a==a-9){
    return a;
}
 else
 {
     if(a>0){
    sum+=a;
    cout<<endl<<a;
     }
   return rsum(a-1);


 }

}



int main()
{
   /* int a[10],s,su,m,d;

    cout << "Enter 10 values"<< endl;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    s=sum(a[0],a[1],a[2],a[3]);
    cout<<"Sum of the function is = "<<s;

     su=sub(a[4],a[5]);
    cout<<endl<<"Sub of the function is = "<<su;

    d=divd(a[6],a[7]);
    cout<<endl<<"div of the function is = "<<s;

    m=mul(a[8],a[9]);
    cout<<endl<<"mul of the function is = "<<m;*/


    int b;
    cin>>b;
    rsum(b);

    return 0;


}
