#include <iostream>
#include <stack>
#include <memory>

template <typename T>
struct Node {
  Node(T data, Node<T>* next) : data(data), next(next){}
  T data;
  std::shared_ptr<Node<T>> next;
};

template <typename T>
void printListReversedIterative (std::shared_ptr<Node<T>> head) {

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
void printListReversedRecursive (const std::shared_ptr<Node<T>>& head) {

  if (head == nullptr) return;
  printListReversedRecursive(head->next);
  std::cout << head->data << "\n";
}

int main () {
  std::shared_ptr<Node<int>> head(new Node<int> (3, new Node<int> (4, new Node<int> (5, nullptr))));
  printListReversedIterative(head);
  printListReversedRecursive(head);
}
