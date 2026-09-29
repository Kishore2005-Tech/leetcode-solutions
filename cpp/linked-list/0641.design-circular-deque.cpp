class MyCircularDeque {
    int* arr;
    int front, rear, noOfEle, capacity;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        front = rear = noOfEle = 0;
        capacity = k;
    }
    bool insertFront(int value) {
        if (isFull())
            return false;
        if (noOfEle != 0) // if ele are 0,  let them remain same
            front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        noOfEle++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty())
            return false;
        if (noOfEle == 1) // reset pointers bcz deque empty
            front = rear = 0;
        else
            front = (front + 1) % capacity;
        noOfEle--;
        return true;
    }
    bool insertLast(int value) {
        if (isFull())
            return false;
        if (noOfEle != 0)
            rear = (rear + 1) % capacity;
        arr[rear] = value;
        noOfEle++;
        return true;
    }
    bool deleteLast() {
        if (isEmpty())
            return false;
        if (noOfEle == 1) // reset pointers bcz deque empty
            rear = front = 0;
        else
            rear = (rear - 1 + capacity) % capacity;
        noOfEle--;
        return true;
    }
    int getFront() {
        if (!isEmpty())
            return arr[front];
        return -1;
    }
    int getRear() {
        if (!isEmpty())
            return arr[rear];
        return -1;
    }
    bool isEmpty() { return noOfEle == 0; }
    bool isFull() { return capacity != 0 && noOfEle == capacity; }
};
