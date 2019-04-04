#include <iostream>
#include <stack>

template <typename T>
void insertBottomIterative (std::stack<T>& stack, const T& data) {

  std::stack<T> auxStack;

  while (!stack.empty()) {
    auxStack.push(stack.top());
    stack.pop();
  }

  auxStack.push(data);

  while (!auxStack.empty()) {
    stack.push(auxStack.top());
    auxStack.pop();
  }

}

template <typename T>
void insertBottomRecursive (std::stack<T>& stack, const T& data) {

  if (stack.empty()) {
    stack.push(data);
    return;
  }

  T tmp = stack.top();
  stack.pop();

  insertBottomRecursive(stack, data);

  stack.push(tmp);

}

template <typename T>
void printStack (std::stack<T>& stack) {

  std::stack<T> auxStack;

  while (!stack.empty()) {
    std::cout << stack.top() << "\n";
    auxStack.push(stack.top());
    stack.pop();
  }

  while (!auxStack.empty()) {
    stack.push(auxStack.top());
    auxStack.pop();
  }
}


int main () {
  std::stack<int> stack{{1,2,3}};
  insertBottomIterative(stack, 4);
  printStack(stack);
  insertBottomRecursive(stack, 5);
  printStack(stack);
}
