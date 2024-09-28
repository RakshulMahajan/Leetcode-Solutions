struct Node {
    int data;
    Node* next, * last;
    // Constructor initializes
    Node(int x, Node* next = NULL, Node* last = NULL)
        : data(x), next(next), last(last) {}
};

class MyCircularDeque {
    Node* dummy; // Dummy node
    int k;
    int len;

public:
    // Constructor to initialize deque with given capacity
    MyCircularDeque(int k) : k(k), len(0) {
        dummy = new Node(-1); // Create a dummy node
        dummy->next = dummy->last = dummy;
    }

    bool insertFront(int value) {
        if (len == k)
            return 0; // full

        Node* newNode = new Node(value, dummy->next, dummy);
        dummy->next->last = newNode; // Link old front's last to newNode
        dummy->next = newNode;       // Link dummy to new front (newNode)

        if (len == 0) {
            dummy->last = newNode; // inserting the first element
        }

        len++;
        return 1;
    }

    bool insertLast(int value) {
        if (len == k)
            return 0; // full

        Node* newNode = new Node(value, dummy, dummy->last);
        dummy->last->next = newNode; // Link old back's next to newNode
        dummy->last = newNode;       // Link dummy's last to newNode

        if (len == 0) {
            dummy->next = newNode; // inserting the first element
        }

        len++;
        return 1;
    }

    bool deleteFront() {
        if (len == 0)
            return 0; // empty

        Node* curr = dummy->next;
        dummy->next = curr->next;
        curr->next->last = dummy;

        delete curr;
        len--;

        return 1;
    }

    bool deleteLast() {
        if (len == 0)
            return 0; // empty

        Node* curr = dummy->last;
        dummy->last = curr->last;
        curr->last->next = dummy;

        delete curr;
        len--;

        return 1;
    }

    int getFront() { return (len == 0) ? -1 : dummy->next->data; }

    int getRear() { return (len == 0) ? -1 : dummy->last->data; }

    bool isEmpty() { return len == 0; }

    bool isFull() { return len == k; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */