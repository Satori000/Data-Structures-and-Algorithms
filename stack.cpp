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
class stack {
private:
  node<T>* tail;
  int size;

public:
  stack();
  void push(T element);
  void pop();
  T top();
  int getSize();
  bool isEmpty();

};



template <class T>
stack<T>::stack() {
  this->size = 0;
  this->tail = NULL;
}

template <class T>
void stack<T>::push(T element) {
  if(isEmpty()) {
    this->tail = new node<T>(element, NULL);

  } else {

    this->tail = new node<T>(element, this->tail);
  }
  this->size++;
}

template <class T>
void stack<T>::pop() {
  if(!isEmpty()) {
    node<T>* temp = this->tail;
    this->tail = this->tail->next;
    delete temp;
  } else {
    cout << "Stack is empty" << endl;
  }
  this->size--;
}

template <class T>
T stack<T>::top() {
  try {
    if (!isEmpty()) {
      return this->tail->element;
    } else {
      throw 1;
    }



  }
  catch(int e) {
    cout << "stack is empty, cannot get top" << endl;
  }
  return -1;
}

template <class T>
bool stack<T>::isEmpty() {
  return size == 0;
}

template <class T>
int stack<T>::getSize() {
  return this->size;
}

int main() {
  //cout << "hello" << endl;
  stack<int> s1 = stack<int>();
  s1.push(5);
  s1.push(8);
  s1.push(12);
  cout << s1.top() << endl;
  s1.pop();
  cout << s1.top() << endl;
  s1.pop();
  cout << s1.top() << endl;
  s1.pop();
  cout << s1.top() << endl;
  s1.pop();

  return 0;
}
