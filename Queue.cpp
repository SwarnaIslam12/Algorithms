#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE 4
int a[SIZE],f=-1,rear=-1;
void enqueue(int value)
{
          if(f==-1)
                    f++;
          if(rear==SIZE-1)
                    cout<<"Overflow"<<endl;
          else
          {
                    rear++;
                    a[rear]=value;
          }
}
void dequeue()
{
          if(rear==-1)
                    cout<<"Underflow"<<endl;
          else if(rear==0)
          {
                    a[rear]=0;
                    rear--;
          }
          else
          {
                    for(ll i=0;i<rear;i++)
                              a[i]=a[i+1];
                    rear--;
          }
}
void display()
{
          for(ll i=0;i<rear+1;i++)
                    cout<<a[i]<<" ";
}
int main()
{
          enqueue(1);
          dequeue();
          dequeue();
          enqueue(4);
          enqueue(8);
          dequeue();
          enqueue(12);
          enqueue(6);
          enqueue(9);
          enqueue(78);
          display();
}
