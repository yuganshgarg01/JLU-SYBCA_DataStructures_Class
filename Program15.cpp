// Implementing a linear Queue using Array
#include <iostream>
using namespace std;

const int SIZE = 5;
int Que[SIZE];
int Front = 0;
int Rear = -1;

void display();
void Enq(int element);
void Deq();

int main()
{
    Enq(12);
    Enq(5);
    Enq(7);
    display();

    Enq(9);
    Enq(3);
    display();

    Enq(23);   // should say queue full
    Deq();
    display();

    Deq();
    Deq();
    Deq();
    Deq();     // should say queue empty
    display();
    Enq(85);
    Enq(15);
    display();

    return 0;
}

void display()
{
    if (Front > Rear)
    {
        cout << "\nQueue is Empty\n\n";
        return;
    }

    cout << "\nElements in Queue are : ";
    for (int i = Front; i <= Rear; i++)
        cout << Que[i] << " ";
    cout << "\n\n";
}

void Enq(int element)
{
    if (Rear == SIZE - 1)
        cout << "\nQueue Full\n";
    else
    {
        Rear++;
        Que[Rear] = element;
    }
}

void Deq()
{
    if (Front > Rear)
        cout << "\nQueue Empty\n";
    else
        Front++;

    // Reset queue if all elements removed
    if (Front > Rear)
    {
        Front = 0;
        Rear = -1;
    }
}
