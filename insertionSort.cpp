#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
  //initializes array
  int N;
  cin >> N;
  int* a = new int[N];


  //reads in numbers
  for(int i = 0; i < N; ++i){
    cin >> a[i];

  }



  //loop goes through inserting every element
  /*for(int i = 1; i < N; ++i)
  {
    //t is the element being inserted
   int t = a[i];
   //j is the index which decides the insertion point
   int j;
   loop goes through every element in array with index less than i and compares them
    with t to find insertion point

   for (j = i - 1; j >= 0 && t < a[j]; --j)
     a[j + 1] = a[j];

  //inserts element
   a[j + 1] = t;

 } */


  for(int i = 0; i < N; ++i){
    int insertion = a[i];

    int j;

    for(j = i + 1; j < N && a[j] < insertion; ++j){
      a[j-1] = a[j];


    }
    a[j-1] = insertion;

  }
  // 8 5 4 23 1 5
  //12 19 16 17 13

  //prints the sorted array
  for(int i = 0; i < N; ++i){
    cout << a[i] << endl;
  }

  return 0;
}
