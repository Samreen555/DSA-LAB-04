#include<iostream>
typedef int Itemtype;
using namespace std;
class Queue {
private:
    int front, rear, maxQue, count;
    Itemtype* items;
public:
    Queue()
    {
        front = 0;
        count = 0;
        rear = 0;
        maxQue = 5;
        items = new Itemtype[maxQue];
    }
    Queue(int max)
    {
        front = 0;
        count = 0;
        rear = 0;
        maxQue = max;
        items = new Itemtype[maxQue];
    }
    ~Queue()
    {
        delete[] items;
    }
    bool isEmpty()
    {
        return (count == 0);
    }
    bool isFull()
    {
        return (count == maxQue);
    }
    void insert(Itemtype new_item)
    {
        if (isFull())
            cout << "Queue OverFlow:\n";
        else
        {
            items[rear] = new_item;
            rear = (rear + 1) % maxQue;
            ++count;
        }
    }
    void remove(Itemtype& old_item)
    {
        if (isEmpty())
            cout << "Queue Underflow:\n";
        else
        {
            old_item = items[front];
            front = (front + 1) % maxQue;
            --count;
        }
    }
    Itemtype display_front()
    {
        if (!isEmpty()) {
            return items[front];
        }
        else {
            cout << "Queue is empty!" << endl;
            return -1;  // Return an invalid value if empty
        }
    }
    Itemtype display_rear()
    {
        if (!isEmpty()) {
            int rearIndex = (rear - 1 + maxQue) % maxQue;  // Adjust for wrap-around
            return items[rearIndex];
        }
        else {
            cout << "Queue is empty!" << endl;
            return -1;  // Return an invalid value if empty
        }
    }
    void display()
    {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Elements of the queue are: ";
        for (int i = front; i != rear; i = (i + 1) % maxQue) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int choice, max_size, num_items;
    Queue q;
    do {
        cout << "Enter your choice (1-3):" << endl;
        cout << "1.Inserting in queue by insert function:" << endl;
        cout << "2.Inserting in queue by user:" << endl;
        cout << "3.Exiting the program:.... " << endl;
        cin >> choice;
        if (choice == 1) {
            q.insert(10);
            q.insert(20);
            q.insert(30);
            q.insert(40);
            q.insert(50);
            cout << "Front item is: " << q.display_front() << endl;
            cout << "Rear item is: " << q.display_rear() << endl;
            Itemtype item;
            q.remove(item);
            cout << "Removed item: " << item << endl;
            q.display();
            cout << "Front item after removal is: " << q.display_front() << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter max_size of queue: ";
            cin >> max_size;
            Queue q(max_size);
            for (int i = 0; i < max_size; i++)
            {
                cout << "Enter item " << i + 1 << ": ";
                cin >> num_items;
                q.insert(num_items);
            }

            cout << "Front item is: " << q.display_front() << endl;
            cout << "Rear item is: " << q.display_rear() << endl;
            Itemtype item;
            q.remove(item);
            cout << "Removed item: " << item << endl;
            q.display();
            cout << "Front item after removal is: " << q.display_front() << endl;
        }
        else if (choice == 3)
        {
            cout << "You exit the program:\n";
        }
        else
            cout << "Invalid choice:" << endl;
    } while (choice != 3);

    return 0;

}