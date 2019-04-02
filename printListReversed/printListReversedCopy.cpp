#include <iostream>
#include <stack>

template <typename T>
struct Node {
  Node(T d, Node<T>* n) : data(d), next(n){}
  T data;
  Node<T>* next;
};

template <typename T>
void printListReversedIterative (const Node<T>* head) {

  std:: stack<T> data;

  while (head != nullptr) {
    data.push(head->data);
    head = head->next;
  }

  while (!data.empty()) {
    std::cout << data.top() << "\n";
    data.pop();
  }
}

template <typename T>
void printListReversedRecursive (const Node<T>* head) {

  if (head == nullptr) return;
  printListReversedRecursive(head->next);
  std::cout << head->data << "\n";
}

int main () {
  Node<int>* head = new Node<int>(1, new Node<int> (2, new Node<int> (3, nullptr)));
  printListReversedIterative(head);
  printListReversedRecursive(head);
}
