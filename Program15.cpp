//Implementing a linear Queue using Array
#include<iostream>
using namespace std;
const int SIZE = 5;
int Que[SIZE];
int Front = 0;
int Rear = -1;
void display();
void Enq(int element);
void Deq();
int main()
{Enq(12);
Enq(5);
Enq(7);
display();
Enq(9);
Enq(3);
display();
Enq(23);
Deq();
display();
return 0;}
void display()
{cout<<"\n Elements in Queue are :";
	for(int i=Front;i<=Rear;i++)
		cout<<Que[i]<<" ";
cout<<"\n\n";}
void Enq(int element)
{if(Rear == SIZE -1)
	cout<<"\nQueue Full";
else
{Rear++;
	Que[Rear]=element;}}
void Deq()
{if(Front ==0)
	cout<<"\\n Queue Empty";
else
	Front ++;}
