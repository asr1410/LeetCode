class MyCircularDeque {
public:
    int k = 0;
    deque<int> dq;
    MyCircularDeque(int k) {
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(dq.size() < k) {
            dq.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(dq.size() < k) {
            dq.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(dq.empty() == false) {
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(dq.empty() == false) {
            dq.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(dq.empty() == false) {
            return dq.front();
        }
        return -1;
    }
    
    int getRear() {
        if(dq.empty() == false) {
            return dq.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        if(dq.size() == k) {
            return true;
        }
        return false;
    }
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