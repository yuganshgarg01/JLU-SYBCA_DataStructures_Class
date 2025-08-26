// Implementing a Circular Queue using Array
#include <iostream>
using namespace std;

const int SIZE = 5;
int Que[SIZE];
int Front = -1;
int Rear = -1;

void display();
void Enq(int element);
void Deq();

int main()
{
	Enq(0);
	Enq(1);
	Enq(2);
	Enq(3);
	Enq(4);
	Enq(5);
display();
Deq();
Enq(5);
display();
    return 0;}

void display()
{
    if (Front == -1)
    {
        cout << "\nQueue is Empty\n\n";
        return;
    }

    cout << "\nElements in Queue are : ";
    int i = Front;
    while (true)
    {
        cout << Que[i] << " ";
        if (i == Rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << "\n\n";
}

void Enq(int element)
{
    if ((Front == 0 && Rear == SIZE - 1) || (Front == (Rear + 1) % SIZE))
    {
        cout << "\nQueue Full\n";
        return;
    }

    if (Front == -1) // first element
        Front = 0;

    Rear = (Rear + 1) % SIZE;
    Que[Rear] = element;
}

void Deq()
{
    if (Front == -1)
    {
        cout << "\nQueue Empty\n";
        return;
    }

    if (Front == Rear)
    {
        // only one element left
        Front = -1;
        Rear = -1;
    }
    else
    {
        Front = (Front + 1) % SIZE;
    }
}

