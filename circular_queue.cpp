#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5
ll a[MAX],front=-1,rear=-1;
bool isFull()
{
          if(front==rear+1||(front==0&&rear==MAX-1))
                    return true;
          return false;
}
bool isEmpty()
{
          if(front==-1)
                    return true;
          return false;
}
void enqueue(int value)
{
          if(isFull())
                    cout<<"Overflow"<<endl;
          else{
                    if(front==-1)
                              front=0;
                    rear=fmod(rear+1,MAX);
                    a[rear]=value;
          }
}
void dequeue()
{
          if(isEmpty())
                    cout<<"Underflow"<<endl;
          else{
                    if(rear==front)
                              rear=-1,front=-1;
                    else
                              front=fmod(front+1,MAX);
          }
}
void display()
{
          ll i=front;
          if(i==-1){
                    cout<<"Empty"<<endl;
                    return;
          }
          while(i!=rear){
                    cout<<a[i]<<" ";
                    i=fmod(i+1,MAX);
          }
          cout<<a[i]<<endl;
}
int main()
{
          cout<<"Enter:\n1.'e' to enqueue\n2.'d' to dequeue\n3.'w' to display the queue\n4.'q' to quit"<<endl;
          char ch;
          ll x;
          cin>>ch;
          while(ch!='q')
          {
                    switch(ch)
                    {
                              case 'e':
                                        cout<<"Enter value"<<endl;
                                        cin>>x;
                                        enqueue(x);
                                        break;
                              case 'd':
                                        dequeue();
                                        break;
                              case 'w':
                                        display();
                                        break;
                    }
                    cout<<"Enter your choice"<<endl;
                    cin>>ch;
          }
}
