#include <iostream>
using namespace std;


struct leNode{
  int element;
  leNode *next;
};

class chain {
private:
  leNode *head;
  int length;
  //leNode *tail;

public:
  chain();
  void insert(int element, int index);
  void singleMerge(int step, int data);
  void printElement(int index);
  void printList();
  int getLength();
  int getIndex(leNode* node);
  leNode* getNode(int index);

};

chain::chain(){
  this->length = 0;
  //this->head = new leNode();
}

void chain::insert(int element, int index) {
  leNode* start;
  leNode* before;
  leNode* wedge;
  leNode* after;
  if(index > length){
    cout << "index out of bounds" << endl;
  }
  else if(this->length == 0) {
    //first node instantiated with null pointer and integer element
    this->head = new leNode();
    start = this->head;
    start->element = element;
    start->next = NULL;
    this->length = 1;

  }
  else if(index == 0){
      wedge = new leNode();
      wedge->element = element;
      wedge->next = this->head;
      this->head = wedge;
      this->length++;
  }
  else {
    before = this->head;
    after = before->next;

    for(int i = 1; i < index; ++i){
      before = after;
      after = before->next;
    }
    wedge = new leNode();
    wedge->element = element;
    wedge->next = after;
    before->next = wedge;
    this->length++;
  }


}



void chain::printElement(int index){
  leNode* start = this->head;
  leNode* current = start;
  for(int i = 0; i < index; ++i){
    current = current->next;
    //cout << "i: " << i << "element: " << current->element << endl;
  }
  int toBePrinted = current->element;
  cout << toBePrinted;
}

void chain::printList(){
  for(int i = 0; i < this->length; ++i) {
    printElement(i);
    if(i != (this->length - 1)){
      cout << " ";
    }

  }


}

int chain::getLength(){
  return this->length;

}

int chain::getIndex(leNode* node){
  int index = 0;
  leNode* start = this->head;
  leNode* current = start;
  while(current != node){
    current = current->next;
    index++;
  }
  return index;
}

leNode* chain::getNode(int index){
  leNode* start = this->head;
  leNode* current = start;
  for(int i = 0; i < index; ++i){
    current = current->next;

  }
  return current;
}










int main() {
  chain* c1 = new chain();
  /*c1->insert(5, 0);
  c1->insert(8,1);
  c1->insert(100,2);
  c1->insert(500,3);
  c1->insert(1000,4);
  c1->insert(2000,5);

  c1->insert(400,3);
  c1->insert(-5, 0);
  c1->insert(3000,8);

  //cout << c1->getLength() << endl;
  c1->printList();
  //cout << c1->getNode(8)->element << endl;
*/
  int initialListLength;
  int element;
  int numAddedLists;
  int step;
  int numElements;
  int currentIndex;

  cin >> initialListLength;

  for(int i = 0; i < initialListLength; ++i){
    cin >> element;
    c1->insert(element, i);
  }
  //c1->printList();

  cin >> numAddedLists;
  for(int i = 0; i < numAddedLists; ++i){
    currentIndex = -1;
    cin >> step;
    cin >> numElements;
    for(int j = 0; j < numElements; ++j){
      cin >> element;
      currentIndex+=(step + 1);
      c1->insert(element, currentIndex);
    }


  }
  c1->printList();




  return 0;
}
