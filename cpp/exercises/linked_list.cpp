#include "linked_list.h"
#include <sstream>

// Constructor
LinkedList::LinkedList() : head_(nullptr), size_(0) {}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head_;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}


// ─── append ───────────────────────────────────────────────────────────────

void LinkedList::append(int value) {
    Node* newNode = new Node(value);

    // If list is empty
    if (!head_) {
        head_ = newNode;
        size_++;
        return;
    }

    // Traverse to last node
    Node* current = head_;
    while (current->next) {
        current = current->next;
    }

    current->next = newNode;
    size_++;
}


// ─── prepend ──────────────────────────────────────────────────────────────

void LinkedList::prepend(int value) {
    Node* newNode = new Node(value);

    newNode->next = head_;
    head_ = newNode;
    size_++;
}


// ─── deleteValue ──────────────────────────────────────────────────────────

bool LinkedList::deleteValue(int value) {
    // Case: empty list
    if (!head_) return false;

    // Case: delete head
    if (head_->value == value) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        size_--;
        return true;
    }

    // General case
    Node* prev = head_;
    Node* current = head_->next;

    while (current) {
        if (current->value == value) {
            prev->next = current->next;
            delete current;
            size_--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}


// ─── find ─────────────────────────────────────────────────────────────────

bool LinkedList::find(int value) const {
    Node* current = head_;

    while (current) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}


// ─── reverse ──────────────────────────────────────────────────────────────

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head_;

    while (current) {
        Node* next = current->next; // save next
        current->next = prev;       // reverse link
        prev = current;             // move prev
        current = next;             // move current
    }

    head_ = prev;
}


// ─── toVector (already correct) ───────────────────────────────────────────

std::vector<int> LinkedList::toVector() const {
    std::vector<int> result;
    Node* current = head_;
    while (current) {
        result.push_back(current->value);
        current = current->next;
    }
    return result;
}


// ─── size ─────────────────────────────────────────────────────────────────

int LinkedList::size() const {
    return size_;
}


// ─── toString ─────────────────────────────────────────────────────────────

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