class MyCircularQueue
{
    public:
    int *arr;
    int size = 0;
    int cap = 0;
    int front = -1;
    int back = -1;
    MyCircularQueue(int k)
    {
        arr = new int[k];
        size = 0;
        cap = k;
    }

    bool enQueue(int value)
    {
        if (isFull()) return false;
        if (front == -1)
        {
            front++;
            back++;
            arr[front] = value;
        }
        else
        {
            back = (back + 1) % cap;
            arr[back] = value;
        }
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty()) return false;
        size--;
        front = (front + 1) % cap;
        return true;
    }

    int Front()
    {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty()) return -1;
        return arr[back];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return cap == size;
    }
};

/**
 *Your MyCircularQueue object will be instantiated and called as such:
 *MyCircularQueue* obj = new MyCircularQueue(k);
 *bool param_1 = obj->enQueue(value);
 *bool param_2 = obj->deQueue();
 *int param_3 = obj->Front();
 *int param_4 = obj->Rear();
 *bool param_5 = obj->isEmpty();
 *bool param_6 = obj->isFull();
 */