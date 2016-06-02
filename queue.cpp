#include <iostream>
using namespace std;

template <class T>
struct node  {
  T element;
  node *next;
  node(T element, node* next) {
    this->element = element;
    this->next = next;
  }
};

template <class T>
class queue {
private:
  node<T>* front;
  node<T>* back;
  int size;

public:
  queue();
  void enqueue(T element);
  T dequeue();
  int getSize();
  bool isEmpty();

};



template <class T>
queue<T>::queue() {
  this->size = 0;
  this->back = NULL;
  this->front = NULL;
}

template <class T>
void queue<T>::enqueue(T element) {
  if(isEmpty()) {
    this->front = new node<T>(element, NULL);
    this->back = this->front;
  } else {
    this->back->next = new node<T>(element, NULL);
    this->back = this->back->next;
  }
  this->size++;
}

template <class T>
T queue<T>::dequeue() {
  if(!isEmpty()) {
    node<T>* temp = this->front;
    this->front = this->front->next;
    T element = temp->element;
    delete temp;
    this->size--;
    return element;
  } else {
    cout << "Stack is empty" << endl;
    return 0;
  }
}

template <class T>
bool queue<T>::isEmpty() {
  return size == 0;
}

template <class T>
int queue<T>::getSize() {
  return this->size;
}

int main() {
  //cout << "hello" << endl;
  queue<int> q1 = queue<int>();
  q1.enqueue(5);
  q1.enqueue(8);
  q1.enqueue(2);
  cout << q1.dequeue() << endl;

  cout << q1.dequeue() << endl;

  cout << q1.dequeue() << endl;

  cout << q1.dequeue() << endl;


  return 0;
}
