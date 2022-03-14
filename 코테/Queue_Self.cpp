#include<iostream>
#define MAX 101
using namespace std;

template<class T>
class Queue
{
public:
	int size;
	int front;
	int rear;
	T* values;
	Queue()
	{
		size = MAX;
		front = 0;
		rear = 0;
		values = new T[size];
	}
	~Queue()
	{
		delete[]values;
	}
	bool isEmpty()
	{
		if (rear == front)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if ((rear + 1) % size == front)
			return true;
		else
			return false;
	}
	void push(T value)
	{
		if (!isFull()) {
			values[rear] = value;
			rear = (rear + 1) % size;
		}
	}
	void pop()
	{
		if (!isEmpty()) {
			front = (front + 1) % size;
		}
	}
	T Front()
	{
		return values[front];
	}
};

int main()
{
	Queue<int>q;
	q.push(1);
	q.push(2);
	int temp = q.Front();
	cout << temp << endl;
	q.pop();
	temp = q.Front();
	cout << temp << endl;
}