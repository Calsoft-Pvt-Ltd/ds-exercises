#include "linked_list.h"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
    Node* current = head_;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::append(int value) {
    // TODO: implement this
    // 1. Create a new Node with value
    // 2. If head_ is nullptr, set head_ = new node, increment size_, and return
    // 3. Otherwise traverse to the last node (node->next == nullptr)
    // 4. Set last->next = new node
    // 5. Increment size_

    // 1. Create new node
    Node* newNode = new Node(value);

    // 2. If list is empty
    if (head_ == nullptr) {
        head_ = newNode;
        size_++;
        return;
    }

    // 3. Traverse to last node
    Node* temp = head_;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // 4. Attach new node
    temp->next = newNode;

    // 5. Increase size
    size_++;
}

void LinkedList::prepend(int value) {
    // TODO: implement this
    // 1. Create a new Node with value
    // 2. Set new_node->next = head_
    // 3. Set head_ = new_node
    // 4. Increment size_

     // 1. Create new node
    Node* newNode = new Node(value);

    // 2. Point new node to current head
    newNode->next = head_;

    // 3. Update head
    head_ = newNode;

    // 4. Increase size
    size_++;
}

bool LinkedList::deleteValue(int value) {
    // TODO: implement this
    // Special case: if head_ is not nullptr and head_->value == value,
    //   set head_ = head_->next, delete old head, decrement size_, return true
    // General case: traverse with a `prev` pointer while current != nullptr and current->value != value
    //   When found: rewire prev->next = current->next, delete current, decrement size_, return true
    // If current reaches nullptr without a match, return false
    // return false; // placeholder

    // Case 1: Empty list
    if (head_ == nullptr) return false;

    // Case 2: Head node contains value
    if (head_->value == value) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        size_--;
        return true;
    }

    // Case 3: Traverse for value
    Node* prev = head_;
    Node* current = head_->next;

    while (current != nullptr) {
        if (current->value == value) {
            prev->next = current->next;
            delete current;
            size_--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    // Not found
    return false;
}

bool LinkedList::find(int value) const {
    // TODO: implement this
    // Traverse from head_; return true if any node's value equals the target
    // return false; // placeholder

     Node* current = head_;   // start from head

    while (current != nullptr) {
        if (current->value == value) {
            return true;     // value mil gaya
        }
        current = current->next; // next node pe jao
    }

    return false; // pura traverse kiya, nahi mila
}

void LinkedList::reverse() {
    // TODO: implement this
    // Use three pointers: prev (starts nullptr), current (starts head_), next
    // Each iteration: save current->next, point current->next = prev, advance prev and current
    // When current is nullptr, set head_ = prev

    Node* prev = nullptr;
    Node* current = head_;

    while (current != nullptr) {
        Node* next = current->next;  // step 1
        current->next = prev;        // step 2
        prev = current;              // step 3
        current = next;              // step 4
    }

    head_ = prev;
}

std::vector<int> LinkedList::toVector() const {
    std::vector<int> result;
    Node* current = head_;
    while (current) {
        result.push_back(current->value);
        current = current->next;
    }
    return result;
}

int LinkedList::size() const {
    return size_;
}

std::string LinkedList::toString() const {
    std::ostringstream oss;
    Node* current = head_;
    while (current) {
        oss << current->value;
        if (current->next) oss << " -> ";
        current = current->next;
    }
    return oss.str();
}
