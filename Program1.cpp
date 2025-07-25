// Write a program to all the even numbers between 0 and 20
#include<iostream>
using namespace std;
int main()
{int ar[11];
int index = 0; 
	for(int i =0; i<21;i++)
	{if(index<11){if(i%2 == 0)
		{ar[index]=i;
		index++;}}
	else{break;}
	}
	for(int i= 0;i<11;i++)
		cout<<ar[i]<<'\t';
return 0;}
