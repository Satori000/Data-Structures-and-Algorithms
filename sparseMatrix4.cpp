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
  chain** chainArray;
  int rows;
  int maxCol;
public:
  sparseMatrix(int rows);
  void insert(int row, int column, int element);
  void printElement(int row, int column);
  void printRow(int row);
  void printMatrix();
  void search(int query);
  void setChain(chain** chainArray);
  chain** getChain();
  sparseMatrix addMatrices(sparseMatrix matrix2);

};

sparseMatrix::sparseMatrix(int rows) {
  this->rows = rows;
  //cout << rows << endl;
  this->chainArray = new chain*[rows];
  for(int i = 0; i < rows; ++i) {
    this->chainArray[i] = new chain();

  }
  //sparseMatrix[0].insert(1, 1, 0);
  //sparseMatrix[0].printElement(0);
  this->maxCol = 0;

}

void sparseMatrix::setChain(chain** chainArray) {
  this->chainArray = chainArray;
}
void sparseMatrix::printRow(int row) {
  chain* c1 = this->chainArray[row];
  c1->printList();

}

chain** sparseMatrix::getChain() {
  return this->chainArray;
}

void sparseMatrix::insert(int row, int column, int element) {

  int currentLength = this->chainArray[row]->getLength();
  //cout << "current length: " << endl;
  this->chainArray[row]->insert(column, element, currentLength);
  //cout << rowChain.getNode(currentLength)->element << endl;
  if (column > this->maxCol) {
    //cout << "old max col: " << this->maxCol << endl;
    this->maxCol = column;
    //cout << "new max col: " << this->maxCol << endl;
  }
}


sparseMatrix sparseMatrix::addMatrices(sparseMatrix matrix2) {
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

      int summedLength = summedChain->getLength();
      if(node1Column == -1) {
        summedElement = node2Element;
        summedChain->insert(node2Column, summedElement, summedLength);
        node2 = node2->next;
        //cout << "1summedElement: " << summedElement << endl;
      } else if(node2Column == -1) {
        summedElement = node1Element;
        summedChain->insert(node1Column, summedElement, summedLength);
        node1 = node1->next;
        //cout << "2summedElement: " << summedElement << endl;
      } else if(node1Column == node2Column) {
        summedElement = node1Element + node2Element;
        summedChain->insert(node1Column, summedElement, summedLength);
        node1 = node1->next;
        node2 = node2->next;
        //cout << "3summedElement: " << summedElement << endl;
      } else if(node1Column < node2Column){
        summedElement = node1Element;
        summedChain->insert(node1Column, summedElement, summedLength);
        node1 = node1->next;
        //cout << "4summedElement: " << summedElement << endl;
      } else if(node2Column < node1Column){
        summedElement = node2Element;
        summedChain->insert(node2Column, summedElement, summedLength);
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
    leNode* node = this->chainArray[i]->getNode(0);
    while(node != NULL) {
      if(node->element == query) {
        cout << i << " " << node->column << " ";
      }

      node = node->next;
    }

  }
  cout << "\b";
  cout << endl;

}










int main() {

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

  return 0;
}
