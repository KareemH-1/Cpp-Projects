#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

namespace DSA {
    namespace LL{
        class Node {
        public:
            int value;
            Node * next;

            Node(int value) {
                this->value = value;
                next = nullptr;
            }

        };

        class LinkedList {
        private:
            Node * head;
            Node * tail;
            int length;
        public:
            LinkedList(int value) {
                Node *newNode = new Node(value);
                head = newNode;
                tail = newNode;
                length = 1;
            }

            ~LinkedList() {
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }

            void printList() {
                Node* temp = head;
                if (temp == nullptr) {
                    cout << "empty";
                } else {
                    while (temp != nullptr) {
                        cout << temp->value;
                        temp = temp->next;
                        if (temp != nullptr) {
                            cout << " -> ";
                        }
                    }
                }
                cout << endl;
            }

            Node* getHead() {
                return head;
            }

            Node* getTail() {
                return tail;
            }

            int getLength() {
                return length;
            }

            void append(int value) {
                Node* newNode = new Node(value);
                if (tail == nullptr) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                    tail->next = newNode;
                    tail = newNode;
                }
                length++;
            }

            void deleteLast() {
                if (head == nullptr) return;

                if (head == tail) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                else {
                    Node* temp = head;
                    Node* pre = nullptr;
                    while (temp->next != nullptr) {
                        pre = temp;
                        temp = temp->next;
                    }
                    delete temp;
                    tail = pre;
                    tail->next = nullptr;
                }

                length--;
            }

            void prepend(int value) {
                Node * newNode = new Node(value);
                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                    newNode->next = head;
                    head = newNode;
                }
                length++;

            }

            void deleteFirst() {
                if (head == nullptr) return;
                Node* temp = head;

                if (length == 1){
                    head = nullptr;
                    tail = nullptr;
                }
                else {
                    head = head->next;
                }
                delete temp;
                length--;

            }
            Node * get(int index) {
                if (index < 0 || index >= length) return nullptr;
                Node* temp = head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp;
            }

            bool set (int index , int value){
                Node * temp = get(index);
                if(temp != nullptr){
                    temp->value = value;
                    return true;
                }
                return false;
            }


            bool insert(int index, int value) {
                if (index < 0 || index > length) return false;
                if (index == 0) {
                    prepend(value);
                    return true;
                }
                if (index == length) {
                    append(value);
                    return true;
                }
                Node* newNode = new Node(value);
                Node* temp = get(index - 1);
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
                return true;
            }

            void deleteNode(int index){
                if(index <0 || index >= length) return;

                else if(index == 0) return deleteFirst();
                else if(index == length-1) return deleteLast();
                else {
                    Node * prev = get(index-1);
                    Node * temp = prev->next;


                    prev-> next = temp->next;
                    delete temp;
                    length--;
                }
            }
            void reverse(){

                Node * temp = head;
                head = tail;
                tail = temp;


                Node* after = nullptr;
                Node * before = nullptr;

                for(int i =0 ; i< length; i++){
                    after = temp->next;
                    temp->next =  before;
                    before = temp;
                    temp = after;
                }


            }
        };

    }

namespace DLL{

    class Node {
        public:
            int value;
            Node* next;
            Node* prev;

            Node(int value) {
                this->value = value;
                next = nullptr;
                prev = nullptr;
            }
    };

    class DoublyLinkedList {
        private:
            Node* head;
            Node* tail;
            int length;

        public:
            DoublyLinkedList(int value) {
                Node* newNode = new Node(value);
                head = newNode;
                tail = newNode;
                length = 1;
            }

            ~DoublyLinkedList() {
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }

            void printList() {
                Node* temp = head;
                if (temp == nullptr) {
                    cout << "empty" << endl;
                    return;
                }
                while (temp->next != nullptr) {
                    cout << temp->value << " <-> ";
                    temp = temp->next;
                }
                cout << temp->value << endl;
            }

            Node* getHead() {
                return head;
            }

            Node* getTail() {
                return tail;
            }

            int getLength() {
                return length;
            }

            // This method will make the DLL empty.
            // It will be used to make sure deleteNode works with an empty DLL.
            void makeEmpty() {
                Node* current = head;
                while (current != nullptr) {
                    Node* nodeToDelete = current;
                    current = current->next;
                    delete nodeToDelete;
                }
                head = nullptr;
                tail = nullptr;
                length = 0;
            }

            void append(int value) {
                Node* newNode = new Node(value);
                if (length == 0) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                length++;
            }

            void deleteLast() {
                if (length == 0) return;
                Node* temp = tail;
                if (length == 1) {
                    head = nullptr;
                    tail = nullptr;
                } else {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                delete temp;
                length--;
            }

            void prepend(int value) {
                Node* newNode = new Node(value);
                if (length == 0) {
                    head = newNode;
                    tail = newNode;
                } else {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                length++;
            }

            void deleteFirst() {
                if (length == 0) return;
                Node* temp = head;
                if (length == 1) {
                    head = nullptr;
                    tail = nullptr;
                } else {
                    head = head->next;
                    head->prev = nullptr;
                }
                delete temp;
                length--;
            }

            Node* get(int index) {
                if (index < 0 || index >= length) return nullptr;
                Node* temp = head;
                if (index < length/2) {
                    for (int i = 0; i < index; ++i) {
                        temp = temp->next;
                    }
                } else {
                    temp = tail;
                    for (int i = length - 1; i > index; --i) {
                        temp = temp->prev;
                    }
                }
                return temp;
            }

            bool set(int index, int value) {
                Node* temp = get(index);
                if (temp) {
                    temp->value = value;
                    return true;
                }
                return false;
            }

            bool insert(int index, int value) {
                if (index < 0 || index > length) return false;
                if (index == 0) {
                    prepend(value);
                    return true;
                }
                if (index == length) {
                    append(value);
                    return true;
                }

                Node* newNode = new Node(value);
                Node* before = get(index - 1);
                Node* after = before->next;
                newNode->prev = before;
                newNode->next = after;
                before->next = newNode;
                after->prev = newNode;
                length++;
                return true;
            }
            void deleteNode(int index) {
                if(index < 0 || index > length){
                    return;
                }

                if(index == 0){
                    deleteFirst();

                }
                else if(index == length -1){
                    deleteLast();

                }
                else{
                    Node * temp = get(index);
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    delete temp;
                    length--;
                }
            }

        };
    }

    namespace Queue {

        class Node {
            public:
                int value;
                Node* next;

                Node(int value) {
                    this->value = value;
                    next = nullptr;
                }
        };

        class Queue {
            private:
                Node* first;
                Node* last;
                int length;

            public:
                Queue(int value) {
                    Node* newNode = new Node(value);
                    first = newNode;
                    last = newNode;
                    length = 1;
                }

                ~Queue() {
                    Node* temp = first;
                    while (first) {
                        first = first->next;
                        delete temp;
                        temp = first;
                    }
                }

                void printQueue() {
                    if (length == 0) {
                        cout << "Queue: empty" << endl;
                        return;
                    }
                    Node* temp = first;
                    cout << "Queue: ";
                    while (temp) {
                        cout << temp->value;
                        temp = temp->next;
                        if (temp) {
                            cout << " -> ";
                        }
                    }
                    cout << endl;
                }


                Node* getFirst() {
                    return first;
                }

                Node* getLast() {
                    return last;
                }

                int getLength() {
                    return length;
                }

                void makeEmpty() {
                    Node* temp;
                    while (first) {
                        temp = first;
                        first = first->next;
                        delete temp;
                    }
                    first = nullptr;
                    last = nullptr;
                    length = 0;
                }

                bool isEmpty() {
                    if (length == 0) return true;
                    return false;
                }

                void enqueue(int value) {
                    Node* newNode = new Node(value);
                    if (length == 0) {
                        first = newNode;
                        last = newNode;
                    } else {
                        last->next = newNode;
                        last = newNode;
                    }
                    length++;
                }
                int dequeue() {
                    if(length == 0) return INT_MIN;
                    else{
                        Node * temp = first ;
                        int val = temp->value;

                        if(length ==1){
                            first = nullptr;
                            last = nullptr;
                        }

                        else{
                            first = first->next;

                        }
                        delete temp;
                        length--;
                        return val;
                    }
                }

        };

    }


    namespace Stack {

        class Node {
            public:
                int value;
                Node* next;
                Node(int value) {
                    this->value = value;
                    next = nullptr;
                }
        };

        class Stack {
            private:
                Node* top;
                int height;

            public:
                Stack(int value) {
                    Node* newNode = new Node(value);
                    top = newNode;
                    height = 1;
                }

                ~Stack() {
                    Node* temp = top;
                    while (top) {
                        top = top->next;
                        delete temp;
                        temp = top;
                    }
                }

                void printStack() {
                    Node* temp = top;
                    while (temp) {
                        cout << temp->value << endl;
                        temp = temp->next;
                    }
                }

                Node* getTop() {
                    return top;
                }

                int topValue() {
                    if (top) return top->value;
                    return INT_MIN;
                }

                int getHeight() {
                    return height;
                }

                void makeEmpty() {
                    Node* temp;
                    while (top) {
                        temp = top;
                        top = top->next;
                        delete temp;
                    }
                    height = 0;
                }

                void push(int value) {
                    Node* newNode = new Node(value);
                    newNode->next = top;
                    top = newNode;
                    height++;
                }
                int pop (){
                    if(height == 0) return INT_MIN;

                    Node * node = top;
                    int val = top->value;

                    top = node->next;

                    delete node;

                    height--;
                    return val;
                }

        };
    }
}
