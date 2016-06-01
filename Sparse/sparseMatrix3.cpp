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
  leNode *tail;
  int length;
  //leNode *tail;

public:
  chain();
  void insert(int column, int element, int index);
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

void chain::insert(int column, int element, int index) {
  leNode* start;
  leNode* wedge;
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
    this->tail = start;
  } else {
    wedge = new leNode();
    wedge->column = column;
    wedge->element = element;
    tail->next = wedge;
    this->tail = wedge;
    length++;
  }
}

/*void chain::insert(int column, int element, int index) {
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
    start->column = column;
    start->next = NULL;
    this->length = 1;

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

*/

void chain::printElement(int index){
  leNode* start = this->head;
  leNode* current = start;
  for(int i = 0; i < index; ++i){
    current = current->next;
    //cout << "i: " << i << "element: " << current->element << endl;
  }
  int toBePrinted = current->element;
  cout << "column: " << current->column << " element: " << current->element;
}

void chain::printList(){
  for(int i = 0; i < this->length; ++i) {
    printElement(i);
    if(i != (this->length - 1)){
      cout << " ";
    }

  }
  cout << endl;

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


class sparseMatrix {
private:
  chain* chainArray;
  int rows;
  int maxCol;
public:
  sparseMatrix(int rows);
  void insert(int row, int column, int element);
  void printElement(int row, int column);
  void printRow(int row);
  void printMatrix();
  void search(int query);
  void setChain(chain* chainArray);
  chain* getChain();
  sparseMatrix addMatrices(sparseMatrix matrix2);

};

sparseMatrix::sparseMatrix(int rows) {
  this->rows = rows;
  //cout << rows << endl;
  this->chainArray = new chain[rows];
//  for(int i = 0; i < rows; ++i) {
    //this->chainArray[i] = chain();

//  }
  chain* sparseMatrix = this->chainArray;
  //sparseMatrix[0].insert(1, 1, 0);
  //sparseMatrix[0].printElement(0);
  //this->maxCol = 0;

}

void sparseMatrix::setChain(chain* chainArray) {
  this->chainArray = chainArray;
}
void sparseMatrix::printRow(int row) {
  chain c1 = this->chainArray[row];
  c1.printList();

}

chain* sparseMatrix::getChain() {
  return this->chainArray;
}

void sparseMatrix::insert(int row, int column, int element) {

  int currentLength = this->chainArray[row].getLength();
  //cout << "current length: " << endl;
  this->chainArray[row].insert(column, element, currentLength);
  //cout << rowChain.getNode(currentLength)->element << endl;
//  if (column > this->maxCol) {
    //cout << "old max col: " << this->maxCol << endl;
  //  this->maxCol = column;
    //cout << "new max col: " << this->maxCol << endl;
//  }
}


sparseMatrix sparseMatrix::addMatrices(sparseMatrix matrix2) {
  //cout << "you entered the method" << endl;
  int rows = this->rows;
  chain* summedMatrix = new chain[rows];
  chain* sparseMatrix1 = this->chainArray;
  chain* sparseMatrix2 = matrix2.chainArray;
  for(int i = 0; i < rows; ++i) {
    chain rowChain1 = sparseMatrix1[i];
    chain rowChain2 = sparseMatrix2[i];
    chain summedChain = summedMatrix[i];
    leNode* node1 = rowChain1.getNode(0);
    leNode* node2 = rowChain2.getNode(0);
    int node1Element = node1->element;
    int node1Column = node1->column;
    int node2Element = node2->element;
    int node2Column = node2->column;
    int summedElement;
    //cout << "node1: " << node1Element << endl;
    //cout << "node2: " << node2Element << endl;
    while((node1 != NULL) || (node2 != NULL)) {
      if(node1 == NULL) {
        node1Column = -1;
        node1Element = 0;
      } else {
        node1Element = node1->element;
        node1Column = node1->column;
      }
      if(node2 == NULL){
        node2Column = -1;
        node2Element = 0;
      } else {
        node2Element = node2->element;
        node2Column = node2->column;
      }

      //cout << "node1: " << "col: " << node1Column << " element: " << node1Element << endl;
      //cout << "node2: " << "col: " << node2Column << " element: " << node2Element << endl;

      int summedLength = summedChain.getLength();
      if(node1Column == -1) {
        summedElement = node2Element;
        summedChain.insert(node2Column, summedElement, summedLength);
        node2 = node2->next;
        //cout << "1summedElement: " << summedElement << endl;
      } else if(node2Column == -1) {
        summedElement = node1Element;
        summedChain.insert(node1Column, summedElement, summedLength);
        node1 = node1->next;
        //cout << "2summedElement: " << summedElement << endl;
      } else if(node1Column == node2Column) {
        summedElement = node1Element + node2Element;
        summedChain.insert(node1Column, summedElement, summedLength);
        node1 = node1->next;
        node2 = node2->next;
        //cout << "3summedElement: " << summedElement << endl;
      } else if(node1Column < node2Column){
        summedElement = node1Element;
        summedChain.insert(node1Column, summedElement, summedLength);
        node1 = node1->next;
        //cout << "4summedElement: " << summedElement << endl;
      } else if(node2Column < node1Column){
        summedElement = node2Element;
        summedChain.insert(node2Column, summedElement, summedLength);
        node2 = node2->next;
        //cout << "5summedElement: " << summedElement << endl;
      }
    }
    summedMatrix[i] = summedChain;
  }
  sparseMatrix summedSparseMatrix = sparseMatrix(this->rows);
  summedSparseMatrix.setChain(summedMatrix);
  return summedSparseMatrix;
}

void sparseMatrix::search(int query) {
  for(int i = 0; i < this->rows; ++i) {
    leNode* node = this->chainArray[i].getNode(0);
    while(node != NULL) {
      if(node->element == query) {
        cout << i << " " << node->column << " ";
      }

      node = node->next;
    }

  }
 // cout << "\b";
  cout << endl;

}










int main() {
  ios::sync_with_stdio(false);
  /*chain* c1 = new chain();
  c1->insert(3,5, 0);
  c1->insert(2,8,1);
  c1->insert(5,100,2);
  c1->insert(1,500,3);
  c1->insert(4,1000,4);
  c1->insert(1,2000,5);

  c1->insert(4,400,6);
  c1->insert(9,-5, 7);
  c1->insert(10,3000,8);

  //cout << c1->getLength() << endl;
  c1->printList();
  //cout << c1->getNode(8)->element << endl;
 */

 int numRows;
 int numElements;
 int column;
 int value;
 int numSearches;
 int query;
 cin >> numRows;
 sparseMatrix m1 = sparseMatrix(numRows);
 for(int i = 0; i < numRows; ++i) {

   cin >> numElements;
   for(int j = 0; j < numElements; ++j) {
     cin >> column;
     cin >> value;
     m1.insert(i,column, value);
   }
 }


cin >> numRows;
sparseMatrix m2 = sparseMatrix(numRows);
for(int i = 0; i < numRows; ++i) {
  cin >> numElements;
  for(int j = 0; j < numElements; ++j) {
    cin >> column;
    cin >> value;
    m2.insert(i, column, value);
  }
}
sparseMatrix summedMatrix = m1.addMatrices(m2);

cin >> numSearches;
for(int i = 0; i < numSearches; ++i) {
  cin >> query;
  summedMatrix.search(query);
}
//summedMatrix.printRow(0);
//summedMatrix.printRow(1);
//summedMatrix.printRow(2);










/*
 sparseMatrix sm1 = sparseMatrix(3);
 sm1.insert(0, 0, -2);
 sm1.insert(0, 2, 3);
 sm1.insert(1, 2, 1);
 sm1.insert(2, 0, 2);
 sm1.insert(2, 1, -4);

 sm1.printRow(0);
 sm1.printRow(1);
 sm1.printRow(2);

 sparseMatrix sm2 = sparseMatrix(5);
 sm2.insert(0, 0, 4);
 sm2.insert(0, 1, 2);
 sm2.insert(1, 1, 1);
 sm2.insert(1, 2, -2);
 sm2.insert(2, 1, -2);

 sm2.printRow(0);
 sm2.printRow(1);
 sm2.printRow(2);

 chain* summedMatrix = sm1.addMatrices(sm2);
 summedMatrix[0].printList();
 summedMatrix[1].printList();
 summedMatrix[2].printList();

*/




/*  int initialListLength;
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
