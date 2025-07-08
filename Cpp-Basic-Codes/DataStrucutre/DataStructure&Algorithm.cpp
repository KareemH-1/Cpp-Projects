#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

namespace DS {
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
    namespace BST{

        class Node {
            public:
                int value;
                Node* left;
                Node* right;

                Node(int value) {
                    this->value = value;
                    left = nullptr;
                    right = nullptr;
                }
        };


        class BinarySearchTree {
            private:
                Node* root;

            public:
                BinarySearchTree() { root = nullptr; }

                void destroy(Node* currentNode) {
                    if (currentNode == nullptr) return;
                    if (currentNode->left) destroy(currentNode->left);
                    if (currentNode->right) destroy(currentNode->right);
                    delete currentNode;
                }

                ~BinarySearchTree() { destroy(root); }

                Node* getRoot() {
                    return root;
                }

                bool insert(int value) {
                    Node* newNode = new Node(value);
                    if (root == nullptr) {
                        root = newNode;
                        return true;
                    }
                    Node* temp = root;
                    while(true) {
                        if (newNode->value == temp->value) return false;
                        if (newNode->value < temp->value) {
                            if (temp->left == nullptr) {
                                temp->left = newNode;
                                return true;
                            }
                            temp = temp->left;
                        } else {
                            if (temp->right == nullptr) {
                                temp->right = newNode;
                                return true;
                            }
                            temp = temp->right;
                        }
                    }
                }

                bool contains(int val){
                    if(root == nullptr) return false;
                    Node * temp = root;
                    while(temp){
                        if(val < temp->value){
                            temp= temp-> left;
                        }
                        else if(val > temp->value){
                            temp= temp->right;
                        }
                        else return true;
                    }
                    return false;
                }

        };

    }

    namespace hashTable{
        class Node {
            public:
                string key;
                int value;
                Node* next;

                Node(string key, int value) {
                    this->key = key;
                    this->value = value;
                    next = nullptr;
                }
                Node(){
                    key = "";
                    value = 0;
                    next = nullptr;
                }
        };

        class HashTable {
            private:
                int SIZE;
                Node** dataMap;

                int hash(string key) {
                    int hash = 0;
                    for (int i = 0; i < key.length(); i++) {
                        int asciiValue = int(key[i]);
                        hash = (hash + asciiValue *  23) % SIZE;
                    }
                    return hash;
                }

            public:
                HashTable() {
                    SIZE = 7;
                    dataMap = new Node*[SIZE];
                    for(int i = 0; i < SIZE; i++) {
                        dataMap[i] = nullptr;
                    }
                }

                HashTable(int size) {
                    this->SIZE = size;
                    dataMap = new Node*[size];
                    for(int i = 0; i < SIZE; i++) {
                        dataMap[i] = nullptr;
                    }
                }
                ~HashTable() {
                    for(int i = 0; i < SIZE; i++) {
                        Node* head = dataMap[i];
                        Node* temp = head;
                        while (head) {
                            head = head->next;
                            delete temp;
                            temp = head;
                        }
                    }
                    delete[] dataMap;
                }

                void printTable() {
                    for(int i = 0; i < SIZE; i++) {
                        cout << "Index " << i << ": ";
                        if(dataMap[i]) {
                            cout << "Contains => ";
                            Node* temp = dataMap[i];
                            while (temp) {
                                cout << "{" << temp->key << ", " << temp->value << "}";
                                temp = temp->next;
                                if (temp) cout << ", ";
                            }
                            cout << endl;
                        } else {
                            cout << "Empty" << endl;
                        }
                    }
                }

                void set(string key, int value) {
                    int index = hash(key);
                    Node* newNode = new Node(key, value);
                    if (dataMap[index] == nullptr) {
                        dataMap[index] = newNode;
                    } else {
                        Node* temp = dataMap[index];
                        while (temp->next != nullptr) {
                            temp = temp->next;
                        }
                        temp->next = newNode;
                    }
                }

                int get(string key) {
                    int index = hash(key);
                    Node* temp = dataMap[index];
                    while (temp != nullptr) {
                        if (temp->key == key) return temp->value;
                        temp = temp->next;
                    }

                }
                vector<string>keys(){
                    vector<string> allkeys;

                    for(int i = 0; i < SIZE; i++){
                        Node* temp = dataMap[i];

                        while(temp != nullptr){
                            allkeys.push_back(temp->key);
                            temp = temp->next;
                        }
                    }
                    return allkeys;
                }

        };

    }

    namespace Graph {

        class Graph {
            private:
                unordered_map<string, unordered_set<string> > adjList;

            public:
                void printGraph() {
                    unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
                    while (kvPair != adjList.end()) {
                        cout << kvPair->first << ": [";
                        unordered_set<string>::iterator edge = kvPair->second.begin();
                        bool first = true;
                        while (edge != kvPair->second.end()) {
                            if (!first) {
                                cout << ", ";
                            }
                            cout << *edge;
                            edge++;
                            first = false;
                        }
                        cout << "]" << endl;
                        kvPair++;
                    }
                }

                bool addVertex(string vertex) {
                    if (adjList.count(vertex) == 0) {
                        adjList[vertex];
                        return true;
                    }
                    return false;
                }

                bool addEdge(string vertex1, string vertex2) {
                    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                        adjList.at(vertex1).insert(vertex2);
                        adjList.at(vertex2).insert(vertex1);
                        return true;
                    }
                    return false;
                }


        bool removeVertex(string vertex) {
            if (adjList.count(vertex) == 0) {
                return false;
            }

            for (string neighbor : adjList[vertex]) {
                adjList[neighbor].erase(vertex);
            }

            adjList.erase(vertex);

            return true;
        }

                bool removeEdge(string vertex1, string vertex2) {
                    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                        adjList.at(vertex1).erase(vertex2);
                        adjList.at(vertex2).erase(vertex1);
                        return true;
                    }
                    return false;
                }

        };
    }

    namespace  heap {

        class Heap {
            private:
                vector<int> heap;

                int leftChild(int index) {
                    return 2 * index + 1;
                }

                int rightChild(int index) {
                    return 2 * index + 2;
                }

                int parent(int index) {
                    return (index - 1) / 2;
                }

                void swap(int index1, int index2) {
                    int temp = heap[index1];
                    heap[index1] = heap[index2];
                    heap[index2] = temp;
                }



            public:
                void printHeap() {
                    cout << "\n[";
                    for (size_t i = 0; i < heap.size(); i++) {
                        cout << heap[i];
                        if (i < heap.size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << "]" << endl;
                }

                const vector<int>& getHeap() const {
                    return heap;
                }

                void insert(int value) {
                    heap.push_back(value);
                    int current = heap.size() - 1;

                    while (current > 0 && heap[current] > heap[parent(current)]) {
                        swap(current, parent(current));
                        current = parent(current);
                    }
                }
            void sinkDown(int index) {
                    int maxIndex = index;
                    while (true) {
                        int leftIndex = leftChild(index);
                        int rightIndex = rightChild(index);

                        if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
                            maxIndex = leftIndex;
                        }

                        if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
                            maxIndex = rightIndex;
                        }

                        if (maxIndex != index) {
                            swap(index, maxIndex);
                            index = maxIndex;
                        } else {
                            return;
                        }
                    }
                }



                int remove() {
                    if (heap.empty()) {
                        return INT_MIN;
                    }

                    int maxValue = heap.front();

                    if (heap.size() == 1) {
                        heap.pop_back();
                    } else {
                        heap[0] = heap.back();
                        heap.pop_back();
                        sinkDown(0);
                    }

                    return maxValue;
                }

        };


              class MinHeap {
              private:
                  vector<int> heap;

                  int leftChild(int index) {
                      return 2 * index + 1;
                  }

                  int rightChild(int index) {
                      return 2 * index + 2;
                  }

                  int parent(int index) {
                      return (index - 1) / 2;
                  }

                  void swap(int index1, int index2) {
                      int temp = heap[index1];
                      heap[index1] = heap[index2];
                      heap[index2] = temp;
                  }

              public:
                  void printHeap() {
                      cout << "\n[";
                      for (size_t i = 0; i < heap.size(); i++) {
                          cout << heap[i];
                          if (i < heap.size() - 1) {
                              cout << ", ";
                          }
                      }
                      cout << "]" << endl;
                  }

                  const vector<int>& getHeap() const {
                      return heap;
                  }

                  void insert(int value) {
                      heap.push_back(value);
                      int current = heap.size() - 1;

                      while (current > 0 && heap[current] < heap[parent(current)]) {
                          swap(current, parent(current));
                          current = parent(current);
                      }
                  }
                  void sinkDown(int index) {
                      int minIndex = index;
                      while (true) {
                          int leftIndex = leftChild(index);
                          int rightIndex = rightChild(index);

                          if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex]) {
                              minIndex = leftIndex;
                          }

                          if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex]) {
                              minIndex = rightIndex;
                          }

                          if (minIndex != index) {
                              swap(index, minIndex);
                              index = minIndex;
                          } else {
                              return;
                          }
                      }
                  }


                  int remove() {
                      if (heap.empty()) {
                          return INT_MIN;
                      }

                      int minValue = heap.front();

                      if (heap.size() == 1) {
                          heap.pop_back();
                      } else {
                          heap[0] = heap.back();
                          heap.pop_back();
                          sinkDown(0);
                      }

                      return minValue;
                  }
              };
    }
}


namespace algorithms{
    //Time: Best: O(n) | Average: O(n^2) | Worst: O(n^2)
    //space 0(1)
    void bubbleSort(int array[], int size) {
         for(int i = size-1 ; i> 0 ; i--){
             for(int j = 0 ; j< i ; j++){
                 if(array[j] > array[j+1]){
                     int temp = array[j];
                     array[j] = array[j+1];
                     array[j+1] = temp;
                 }
             }
         }
    }

    //Time: Best: O(n^2) | Average: O(n^2) | Worst: O(n^2)
    //space 0(1)
    void selectionSort(int array[], int size) {
        for(int i =0 ; i< size ; i++){
            int  min = i;
            for(int j = i+1 ; j< size ; j++){
                if(array[j] < array[min]){
                    min = j;
                }
            }
            if(i != min){
                int temp = array[min];
                array[min] = array[i];
                array[i] = temp;
            }
        }
    }

    //Time: Best: O(n) | Average: O(n^2) | Worst: O(n^2)
    //space 0(1)
    void insertSort(int array[], int size) {
        for (int i = 1 ;i< size ; i++) {
            int temp = array[i];
            int j = i-1;
            while (j >= 0 && temp < array[j]) {
                array[j+1] = array[j];
                array[j] = temp;
                j--;
            }
        }
    }


    //Time: Best: O(n log n) | Average: O(n log n) | Worst: O(n log n)
    //space 0(n)
    namespace mergeSort {
        void merge(int array[] , int leftIndex , int midIndex , int rightIndex) {
            int leftArraySize = midIndex - leftIndex + 1;
            int rightArraySize = rightIndex - midIndex;
            int *leftArray = new int[leftArraySize];
            int *rightArray = new int[rightArraySize];

            for (int i = 0; i < leftArraySize; i++) {
                leftArray[i] = array[leftIndex + i];
            }
            for (int i = 0; i < rightArraySize; i++) {
                rightArray[i] = array[midIndex + i + 1];
            }
            int index = leftIndex;
            int i =0 , j =0;

            while (i < leftArraySize && j < rightArraySize) {
                if (leftArray[i] <= rightArray[j]) {
                    array[index] = leftArray[i];
                    index++;
                    i++;
                }
                else {
                    array[index] = rightArray[j];
                    index++;
                    j++;
                }
            }
            while (i < leftArraySize) {
                array[index] = leftArray[i];
                index++;
                i++;
            }
            while (j < rightArraySize) {
                array[index] = rightArray[j];
                index++;
                j++;
            }

            delete [] leftArray;
            delete [] rightArray;
        }

        void mergeSort(int array[], int leftIndex , int rightIndex) {
            if (leftIndex >= rightIndex) return;
            int midIndex = leftIndex; + (rightIndex - leftIndex) /2;
            mergeSort(array, leftIndex, midIndex);
            mergeSort(array, midIndex + 1, rightIndex);
            merge(array , leftIndex , midIndex , rightIndex);
        }
    }



    //Time: Best: O(n log n) | Average: O(n log n) | Worst: O(n^2)
    //space: Average: 0(log n) | Worst: O(n)
    namespace QuickSort{

        void swap(int array[] , int firstIndex , int secondIndex){
            int temp = array[firstIndex];
            array[firstIndex] = array[secondIndex];
            array[secondIndex] = temp;
        }

        int pivot(int array[] , int pivotIndex , int endIndex){
            int swapIndex = pivotIndex;
            for (int i = pivotIndex+1 ; i <= endIndex ; i++) {
                if (array[i] < array[pivotIndex]) {
                    swapIndex++;
                    swap(array, swapIndex , i);

                }
            }
            swap(array , pivotIndex , swapIndex);
            return swapIndex;
        }

        void QuickSort(int array[] , int leftIndex , int rightIndex) {
            if (leftIndex>=rightIndex) return;

            int pivotIndex = pivot(array , leftIndex , rightIndex);
            QuickSort(array , leftIndex, pivotIndex-1);
            QuickSort(array, pivotIndex+1, rightIndex);

        }

    }



}

namespace Memoization {

    namespace Fibonacci {
        //Time: 0(2^n)
        // when n = 41, function is called over 500 million times
        int InEffecientFibonacci(int n) {
            if (n == 0 || n == 1) {
                return n;
            }
            return InEffecientFibonacci(n-1) + InEffecientFibonacci(n-2);
        }

        //Time: O(n) simplified from O(2n-1)
        //when n = 41, function is called 81 times
        namespace EffecientFibonacci {
            vector<int>memo(100, -1);

            int Fibonacci(int n) {
                if (memo[n] != -1) return memo[n];

                if (n == 0 || n == 1) {
                    return n;
                }
                memo[n] = Fibonacci(n-1) + Fibonacci(n-2);
                return memo[n];
            }
        }


    }
}

//Time: O(n-1) ,simplified to O(n)
//when n = 41, function is called 40 times
namespace EffecientFibonacciWithoutMemoization{
    int Fibonacci(int n) {
        vector<int> fiblist;
        fiblist.push_back(0);
        fiblist.push_back(1);
        for (int i = 2 ; i<= n ; i++) {
            fiblist[i] = fiblist[i-1] + fiblist[i-2];
        }
        return fiblist[n-1];
    }
}
