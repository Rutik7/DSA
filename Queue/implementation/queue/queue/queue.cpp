#include<iostream>
using namespace std;
#define MAX 100
class Queue
{
	int front;
    int rear;
	int arr[MAX];
    
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}

	void enqueue(int iNo);
	int dequeue();
	void display();
	int getRear();
	int getFront();
	int getSize();
	bool isEmpty();
	bool isFull();
};

int main()
{
	Queue q;
	q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Displaying status of the queue after enqueuing
    cout << "\nAfter Enqueueing:" << endl;

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.display();

    // Enqueueing more elements
    q.enqueue(4);
    q.enqueue(5);

    // Displaying the updated queue
    q.display();

    // Enqueueing one more element to demonstrate overflow
    // condition
    q.enqueue(6);

    // Dequeueing elements
    cout << "\nDequeueing elements:" << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    // Displaying status of the queue after dequeueing
    cout << "\nAfter Dequeueing:" << endl;

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.display();

    return 0;
}

void Queue::enqueue(int iNo)
{
	if (isFull())
	{
		cout << "Queue is full" << endl;
		return;
	}
	// if queue is empty, set front to 0
	if (isEmpty())
		front = 0;



	rear++;
	arr[rear] = iNo;
}

int Queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue underflow"<<endl;
		return -1;
	}

	int ans = arr[front];


	 // Shift all elements to the left
    for (int i = front; i < rear; i++)
    {
        arr[i] = arr[i + 1];
    }
    rear--;  // Decrease rear since we removed one element
	
	if(isEmpty())
	{
		front = -1;
		rear = -1;
	}
	return ans;
}

void Queue::display()
{
	if(isEmpty())
	{
		cout<<"Queue underflow"<<endl;
		return ;
	}
	cout<<"Queue:";
	for(int i = front; i<=rear ;i++)
	{
		cout<<" "<<arr[i];
	}

	cout<<endl;
}

int Queue:: getRear()
{
	return arr[rear];
}

int Queue::getFront()
{
	return arr[front];
}

int Queue::getSize()
{
	if(isEmpty())
	{
		return -1;
	}

	if(isFull())
	{
		return MAX;
	}

	return rear-front+1;
}

bool Queue::isEmpty()
{
	return (front==-1 || front>rear);
}

bool Queue::isFull()
{
	return rear==MAX-1;
}