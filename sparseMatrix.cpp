#include <iostream>
using namespace std;


struct leNode{
  int element;
  int column;
  leNode *next;
};

class chain {
private:
  leNode *head;
  //leNode *tail;
  int length;
  //leNode *tail;

public:
  chain();
  void insert(int element,int column, int index);
  void singleMerge(int step, int data);
  void printElement(int index);
  void printList();
  int getLength();
  int getIndex(leNode* node);
  leNode* getNode(int index);


};



chain::chain(){
  this->length = 0;
  //cout << "hey this was instantiated" << endl;
  //this->head = new leNode();
}

void chain::insert(int element,int column, int index) {

  /*else {
    end = new leNode();
    end->element = element;
    end->column = column;
    this->tail->next = end;
    length++;
  } */

  leNode* start;
  //leNode* end;
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
    start->column = column;
    start->next = NULL;
    this->length = 1;
    //this->tail = start;
  }
  else if(index == 0){
      wedge = new leNode();
      wedge->element = element;
      wedge->column = column;
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
    wedge->column = column;
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
  //cout << "col: " << current->column << " element: " <<  current->element << endl;
  //cout << toBePrinted;
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
  //cout << "print: " << this->length << endl;
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



class sparseMatrix {
private:

  int rows;
  int maxCol;
public:
  sparseMatrix(int rows);
  void insert(int row, int column, int element);
  void printElement(int row, int column);
  void printRow(int row);
  void printMatrix();
  chain** addMatrices(sparseMatrix matrix2);
  chain** chainArray;
};

sparseMatrix::sparseMatrix(int rows) {
  this->rows = rows;
  //cout << rows << endl;
  this->chainArray = new chain*[rows];
  /*for(int i = 0; i < rows; ++i) {
    this->chainArray[i] = new chain();

  } */
  //chain* sparseMatrix = this->chainArray;
  //sparseMatrix[0].insert(1, 1, 0);
  //sparseMatrix[0].printElement(0);
  this->maxCol = 0;

}

void sparseMatrix::insert(int row, int column, int element) {
  chain* rowChain = chainArray[row];
  int currentLength = rowChain->getLength();
  //cout << "current length: " << endl;
  rowChain->insert(element, column, currentLength);
  //cout << rowChain.getNode(currentLength)->element << endl;
  if (column > this->maxCol) {
    //cout << "old max col: " << this->maxCol << endl;
    this->maxCol = column;
    //cout << "new max col: " << this->maxCol << endl;
  }
}

chain** sparseMatrix::addMatrices(sparseMatrix matrix2) {
  //cout << "you entered the method" << endl;
  int rows = this->rows;
  chain** summedMatrix = new chain*[rows];
  chain** sparseMatrix1 = this->chainArray;
  chain** sparseMatrix2 = matrix2.chainArray;
  for(int i = 0; i < rows; ++i) {
    chain* rowChain1 = sparseMatrix1[i];
    chain* rowChain2 = sparseMatrix2[i];
    chain* summedChain = summedMatrix[i];
    leNode* node1 = rowChain1->getNode(0);
    leNode* node2 = rowChain2->getNode(0);
    int node1Element = node1->element;
    int node1Column = node1->column;
    int node2Element = node2->element;
    int node2Column = node2->column;
    int summedElement;
    //cout << "node1: " << node1Element << endl;
    //cout << "node2: " << node2Element << endl;
    while((node1 != NULL) && (node2 != NULL)) {
      if(node1 == NULL) {
        node1Column = 0;
        node1Element = 0;
      } else {
        node1Element = node1->element;
        node1Column = node1->column;
      }
      if(node2 == NULL){
        node2Column = 0;
        node2Element = 0;
      } else {
        node2Element = node2->element;
        node2Column = node2->column;
      }

      //cout << "node1: " << node1Element << endl;
      //cout << "node2: " << node2Element << endl;

      int summedLength = summedChain->getLength();
      if(node1Column == 0) {
        summedElement = node2Element;
        summedChain->insert(summedElement, node1Column, summedLength);
        node2 = node2->next;

      } else if(node2Column == 0) {
        summedElement = node1Element;
        summedChain->insert(summedElement, node1Column, summedLength);
        node1 = node1->next;

      } else if(node1Column == node2Column) {
        summedElement = node1Element + node2Element;
        summedChain->insert(summedElement, node1Column, summedLength);
        node1 = node1->next;
        node2 = node2->next;
      } else if(node1Column < node2Column){
        summedElement = node1Element;
        summedChain->insert(summedElement, node1Column, summedLength);
        node1 = node1->next;
      } else if(node2Column < node1Column){
        summedElement = node2Element;
        summedChain->insert(summedElement, node2Column, summedLength);
        node2 = node2->next;
      }
    }
  }
  return summedMatrix;
}






int main() {
  sparseMatrix sm1 = sparseMatrix(5);
  sm1.insert(0, 0, -2);
  sm1.insert(0, 2, 3);
  sm1.chainArray[0]->printElement(0);
  sm1.insert(1, 2, 1);
  sm1.chainArray[1]->printList();
  sm1.insert(2, 0, 2);
  sm1.insert(2, 1, -4);
  sm1.chainArray[2]->printList();
  sparseMatrix sm2 = sparseMatrix(5);
  sm2.insert(0, 0, 4);
  sm2.insert(0, 1, 2);
  sm2.insert(1, 1, 1);
  sm2.insert(1, 2, -2);
  sm2.insert(2, 1, -2);
  //sm1.addMatrices(sm2);


/*  chain* c1 = new chain();
  c1->insert(5, 0);
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

*/


  return 0;
}
