#include <iostream>
using namespace std;
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <string>
void printStack(stack<char> operators) {
  while(operators.size() != 0) {
    //cout << "selement: " << operators.top() << endl;
    operators.pop();
  }

}

void printStack(stack<double> operators) {
  while(operators.size() != 0) {
    //cout << "selement: " << operators.top() << endl;
    operators.pop();
  }

}

void printQueue(queue<string> output) {
  while(output.size() != 0) {
    //cout << "qelement: " << output.front() << endl;
    output.pop();
  }

}

double evaluateExpression(string expression, unordered_map<string, double> vars) {
  int i;
  queue<string> output;
  stack<char> operators;
  double number;
  string name;
  unordered_map<char, int> precedence;
  precedence.insert(make_pair<char, int>('+', 1));
  precedence.insert(make_pair<char, int>('-', 1));
  precedence.insert(make_pair<char, int>('*', 2));
  precedence.insert(make_pair<char, int>('/', 2));
  precedence.insert(make_pair<char, int>('^', 3));
  //cout << "expression: "  << expression << endl;
  for(i = 0; i < expression.length(); ++i) {

    if(isalpha(expression[i])) {
      name = "";
      name+=expression[i];
      i++;
      while(isalpha(expression[i])) {
        name+=expression[i];
        i++;
      }
      try {
        number = vars.at(name);
      } catch(exception e) {
        return -.003;
      }


      ostringstream strs;
      strs << number;
      string numString = strs.str();
      //cout << "number: " << numString << endl;
      output.push(numString);
    }

    if(isdigit(expression[i])) {
      //cout << "NUMBER: " << expression[i] << endl;
      bool decimal = false;
      int place = 0;
      number = expression[i] - '0';

      //cout << expression[i] << " is a digit" << endl;
      i++;


      while(isdigit(expression[i]) || expression[i] == '.') {
        //cout << expression[i] << " is a digit" << endl;
        if(decimal) {
          place++;

        }
        if(isdigit(expression[i])) {
          number = (number * 10) + (expression[i] - '0');
        }

        if(expression[i] == '.') {
          decimal = true;
        }


        i++;
      }


      number = number / (pow(10.0, place));
      ostringstream strs;
      strs << number;
      string numString = strs.str();
      //cout << "number: " << numString << endl;
      output.push(numString);
      //end of number if statement
      //cout << "number times 2: " << number * 2 << endl;
    }
    if(expression[i] == '(') {
      operators.push(expression[i]);

    }
    if(expression[i] == ')') {
      while(operators.top() != '(') {
        char temp = operators.top();
        stringstream strs;
        string charString;
        //int n = 1;
        strs << temp ;
        strs >> charString;
        output.push(charString);
        operators.pop();
      }
      operators.pop();

    }
    if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
      char Operator = expression[i];
      //cout << "Operator: " << Operator << endl;

      if(operators.size() == 0) {
        //cout << "access1" << endl;
        operators.push(Operator);
        //cout << "top1: " << operators.top() << endl;
        //cout << "operators size1: " << operators.size() << endl;
        //  cout << "output size1" << output.size() << endl;
      } else if((operators.top() != '(') && (precedence.at(operators.top()) > precedence.at(Operator))) {
        //cout << "access2" << endl;
        char temp;
        while((operators.size() != 0) && (operators.top() != '(') && (precedence.at(operators.top()) > precedence.at(Operator))) {

          temp = operators.top();
          stringstream strs;
          string charString;
          //int n = 1;
          strs << temp ;
          strs >> charString;
          output.push(charString);
          //cout << temp << " was popped" << endl;

          operators.pop();
          if (operators.size() != 0 && operators.top() == '(') {
            break;
          }

        }
        operators.push(Operator);
        //cout << "top2: " << operators.top() << endl;
      //  cout << "operators size2: " << operators.size() << endl;
          //cout << "output size2" << output.size() << endl;
      } else {
      //  cout << "access3" << endl;
        operators.push(Operator);
        //cout << "top3: " << operators.top() << endl;
        //cout << "operators size3: " << operators.size() << endl;
        //cout << "output size3" << output.size() << endl;


      }


    }

  }
  while(operators.size() != 0) {
    char temp = operators.top();
    stringstream strs;
    string charString;
    //int n = 1;
    strs << temp ;
    strs >> charString;
    output.push(charString);
    operators.pop();
  }
  //printQueue(output);
  //printStack(operators);
  stack<double> reversePolish;

  while(output.size() != 0) {

    if(!output.front().compare("+") || !output.front().compare("-") || !output.front().compare("*") || !output.front().compare("/") || !output.front().compare("^")) {
      double secondOp = reversePolish.top();
      reversePolish.pop();

      double firstOp = reversePolish.top();
      reversePolish.pop();
      string op = output.front();

      if(!op.compare("+")) {
        double sum = firstOp + secondOp;
        reversePolish.push(sum);
      }
      if(!op.compare("-")) {
        double diff = firstOp - secondOp;
        reversePolish.push(diff);
      }
      if(!op.compare("*")) {
        double product = firstOp * secondOp;
        reversePolish.push(product);
      }
      if(!op.compare("/")) {
        if(secondOp == 0) {
          return -.004;
        }
        double quotient = firstOp / secondOp;
        reversePolish.push(quotient);
      }

      if(!op.compare("^")) {
        double exponential = pow(firstOp, secondOp);
        reversePolish.push(exponential);
      }


      output.pop();
    } else {
      reversePolish.push(stod(output.front()));
      output.pop();
    }



  }
  //WOO
  //printStack(reversePolish);
  return reversePolish.top();
}


int main() {
  unordered_map<string, double> variables;
  string tokenGen = "not quit";
  string varName;
  string equals;
  string expression;
  int i = 0;
  //stack<char> operators;
  while (tokenGen.compare("quit")) {
    cin >> tokenGen;

    if (!tokenGen.compare("let")) {
      double variable;
      cin >> varName;
      cin >> equals;
      getline(cin, expression);
      variable = evaluateExpression(expression, variables);
      variables.insert(make_pair<string, double>(varName, variable));
      //cout << "variable: " << varName << " set to " << variables.at(varName) << endl;
      //cout << "tokenGen: " << tokenGen << " varName: " << varName  << " equals:" << equals << " expression: " << expression << endl;
    } else if (!tokenGen.compare("quit")){
      break;
    } else {
      getline(cin, expression);
      tokenGen += expression;
      if(evaluateExpression(tokenGen, variables) == -.004) {
        cout << "Divide-By-Zero" << endl;
      } else if (evaluateExpression(tokenGen, variables) == -.003){
        cout << "Undeclared-Variable" << endl;
      } else{
        cout << evaluateExpression(tokenGen, variables) << endl;
      }

    }


  }

  return 0;
}
