# C++ Exercises Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Create a `cpp/` folder mirroring the Java and Python exercise structure — four data structure exercises (FixedArray, LinkedList, Stack, Queue+TaskProcessor) with skeleton files (TODO stubs) and complete test files using Google Test.

**Architecture:** Each exercise has a header (`.h`) declaring the class and a skeleton `.cpp` with TODO-annotated method bodies. A single CMake build fetches Google Test via FetchContent and compiles all tests into one runner. Skeletons compile and link; tests fail at runtime until students implement the TODOs. CI is extended with a new `cpp` job.

**Tech Stack:** C++17, CMake 3.14+, Google Test 1.14.0 (fetched automatically), GitHub Actions (ubuntu-latest)

---

## File Map

| Action | Path | Responsibility |
|--------|------|----------------|
| Create | `cpp/CMakeLists.txt` | Build system: fetches gtest, compiles exercises library + test runner |
| Create | `cpp/README.md` | Student instructions for C++ exercises |
| Create | `cpp/exercises/fixed_array.h` | FixedArray class declaration |
| Create | `cpp/exercises/fixed_array.cpp` | FixedArray skeleton with TODO stubs |
| Create | `cpp/exercises/linked_list.h` | LinkedList class declaration |
| Create | `cpp/exercises/linked_list.cpp` | LinkedList skeleton with TODO stubs |
| Create | `cpp/exercises/stack.h` | Stack class declaration |
| Create | `cpp/exercises/stack.cpp` | Stack skeleton with TODO stubs |
| Create | `cpp/exercises/queue.h` | Queue + TaskProcessor class declarations |
| Create | `cpp/exercises/queue.cpp` | Queue + TaskProcessor skeletons with TODO stubs |
| Create | `cpp/tests/test_array.cpp` | Full Google Test suite for FixedArray |
| Create | `cpp/tests/test_linked_list.cpp` | Full Google Test suite for LinkedList |
| Create | `cpp/tests/test_stack.cpp` | Full Google Test suite for Stack + isBalanced |
| Create | `cpp/tests/test_queue.cpp` | Full Google Test suite for Queue + TaskProcessor |
| Modify | `.github/workflows/ci.yml` | Add `cpp` job: cmake configure, build, ctest |

---

### Task 1: CMakeLists.txt and project scaffold

**Files:**
- Create: `cpp/CMakeLists.txt`
- Create: `cpp/README.md`

- [ ] **Step 1: Create `cpp/CMakeLists.txt`**

```cmake
cmake_minimum_required(VERSION 3.14)
project(ds-exercises-cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Test automatically
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Exercise library — students implement the TODO methods in these files
add_library(exercises
  exercises/fixed_array.cpp
  exercises/linked_list.cpp
  exercises/stack.cpp
  exercises/queue.cpp
)
target_include_directories(exercises PUBLIC exercises)

# Test runner
enable_testing()
add_executable(run_tests
  tests/test_array.cpp
  tests/test_linked_list.cpp
  tests/test_stack.cpp
  tests/test_queue.cpp
)
target_link_libraries(run_tests exercises GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(run_tests)
```

- [ ] **Step 2: Create `cpp/README.md`**

```markdown
# Data Structures Exercises — C++

## Prerequisites
- CMake 3.14+
- A C++17 compiler (GCC 9+, Clang 10+, or MSVC 2019+)
- Internet access on first build (CMake fetches Google Test automatically)

## Setup

```bash
cd cpp
cmake -S . -B build
cmake --build build --parallel
```

## Running Tests

```bash
cd cpp/build
ctest --output-on-failure
```

Or run the test binary directly for verbose output:

```bash
./build/run_tests
```

## Exercises

Implement the `// TODO: implement this` methods in `exercises/`:

| File | Class | Points |
|------|-------|--------|
| `exercises/fixed_array.cpp` | `FixedArray` | 25 |
| `exercises/linked_list.cpp` | `LinkedList` | 25 |
| `exercises/stack.cpp` | `Stack` | 25 |
| `exercises/queue.cpp` | `Queue`, `TaskProcessor` | 25 |

**Do not modify the header files (`.h`) or the test files.**

## Grading

Each exercise is graded by running its test suite. Full marks require all tests in the suite to pass.
```

- [ ] **Step 3: Commit scaffold**

```bash
git add cpp/CMakeLists.txt cpp/README.md
git commit -m "feat: add cpp exercise scaffold (CMake + README)"
```

---

### Task 2: FixedArray exercise

**Files:**
- Create: `cpp/exercises/fixed_array.h`
- Create: `cpp/exercises/fixed_array.cpp`
- Create: `cpp/tests/test_array.cpp`

- [ ] **Step 1: Create `cpp/exercises/fixed_array.h`**

```cpp
#pragma once
#include <stdexcept>
#include <string>

/**
 * A fixed-capacity array of integers.
 *
 * Elements are stored contiguously. Insertion and deletion shift neighbours.
 * Random access is O(1); insertion and deletion are O(n).
 */
class FixedArray {
public:
    /**
     * Construct a FixedArray with the given maximum capacity.
     * @param capacity Maximum number of elements this array can hold.
     */
    explicit FixedArray(int capacity);
    ~FixedArray();

    /**
     * Insert value at index, shifting existing elements one position right.
     * @throws std::out_of_range   if index < 0 or index > size()
     * @throws std::overflow_error if the array is already at capacity
     */
    void insert(int index, int value);

    /**
     * Return the element at index.
     * @throws std::out_of_range if index < 0 or index >= size()
     */
    int get(int index) const;

    /**
     * Delete the element at index, shifting remaining elements left.
     * @throws std::out_of_range if index < 0 or index >= size()
     */
    void deleteAt(int index);

    /**
     * Return the index of the first occurrence of value, or -1 if not found.
     */
    int find(int value) const;

    /** Return the number of elements currently stored. */
    int size() const;

    /**
     * Rotate the occupied portion right by k positions.
     * Example: [1,2,3,4,5] rotateRight(2) → [4,5,1,2,3]
     * Handles k=0 and k >= size() gracefully (k is taken modulo size()).
     */
    void rotateRight(int k);

    /** Return a string representation, e.g. "[1, 2, 3]". */
    std::string toString() const;

private:
    int* data_;
    int  capacity_;
    int  size_;
};
```

- [ ] **Step 2: Create `cpp/exercises/fixed_array.cpp`**

```cpp
#include "fixed_array.h"
#include <sstream>

FixedArray::FixedArray(int capacity)
    : data_(new int[capacity]), capacity_(capacity), size_(0) {}

FixedArray::~FixedArray() {
    delete[] data_;
}

void FixedArray::insert(int index, int value) {
    // TODO: implement this
    // 1. If size_ == capacity_, throw std::overflow_error("array is full")
    // 2. If index < 0 or index > size_, throw std::out_of_range("index out of range")
    // 3. Shift elements at [index .. size_-1] one position right
    // 4. Set data_[index] = value; increment size_
}

int FixedArray::get(int index) const {
    // TODO: implement this
    // 1. If index < 0 or index >= size_, throw std::out_of_range("index out of range")
    // 2. Return data_[index]
    return 0; // placeholder — remove when implemented
}

void FixedArray::deleteAt(int index) {
    // TODO: implement this
    // 1. If index < 0 or index >= size_, throw std::out_of_range("index out of range")
    // 2. Shift elements at [index+1 .. size_-1] one position left
    // 3. Decrement size_
}

int FixedArray::find(int value) const {
    // TODO: implement this
    // Linear scan: return the index of the first element equal to value, or -1
    return -1; // placeholder — remove when implemented
}

int FixedArray::size() const {
    return size_;
}

void FixedArray::rotateRight(int k) {
    // TODO: implement this
    // Rotate the occupied region [0 .. size_-1] right by k positions.
    // Hint: use the "three-reverse" trick —
    //   1. Normalise: k = k % size_ (guard against size_==0 first)
    //   2. Reverse the entire occupied region
    //   3. Reverse the first k elements
    //   4. Reverse elements [k .. size_-1]
}

std::string FixedArray::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (int i = 0; i < size_; ++i) {
        if (i > 0) oss << ", ";
        oss << data_[i];
    }
    oss << "]";
    return oss.str();
}
```

- [ ] **Step 3: Create `cpp/tests/test_array.cpp`**

```cpp
#include <gtest/gtest.h>
#include "fixed_array.h"

// --- Initialization ---

TEST(FixedArrayTest, InitialSizeIsZero) {
    FixedArray arr(5);
    EXPECT_EQ(arr.size(), 0);
}

// --- Insert ---

TEST(FixedArrayTest, InsertSingleElement) {
    FixedArray arr(5);
    arr.insert(0, 42);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.get(0), 42);
}

TEST(FixedArrayTest, InsertAtBeginningShiftsRight) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(0, 2);
    EXPECT_EQ(arr.get(0), 2);
    EXPECT_EQ(arr.get(1), 1);
}

TEST(FixedArrayTest, InsertAtEnd) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 2);
    EXPECT_EQ(arr.get(1), 2);
}

TEST(FixedArrayTest, InsertAtMiddle) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 3);
    arr.insert(1, 2);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);
}

TEST(FixedArrayTest, InsertThrowsWhenFull) {
    FixedArray arr(2);
    arr.insert(0, 1);
    arr.insert(1, 2);
    EXPECT_THROW(arr.insert(2, 3), std::overflow_error);
}

TEST(FixedArrayTest, InsertThrowsOnNegativeIndex) {
    FixedArray arr(5);
    EXPECT_THROW(arr.insert(-1, 1), std::out_of_range);
}

TEST(FixedArrayTest, InsertThrowsOnIndexBeyondSize) {
    FixedArray arr(5);
    // size is 0; only index 0 is valid
    EXPECT_THROW(arr.insert(1, 1), std::out_of_range);
}

// --- Get ---

TEST(FixedArrayTest, GetThrowsOnNegativeIndex) {
    FixedArray arr(5);
    arr.insert(0, 10);
    EXPECT_THROW(arr.get(-1), std::out_of_range);
}

TEST(FixedArrayTest, GetThrowsOnIndexAtSize) {
    FixedArray arr(5);
    arr.insert(0, 10);
    EXPECT_THROW(arr.get(1), std::out_of_range);
}

// --- Delete ---

TEST(FixedArrayTest, DeleteAtReducesSizeAndShifts) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 2);
    arr.deleteAt(0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.get(0), 2);
}

TEST(FixedArrayTest, DeleteAtThrowsWhenEmpty) {
    FixedArray arr(5);
    EXPECT_THROW(arr.deleteAt(0), std::out_of_range);
}

TEST(FixedArrayTest, DeleteAtThrowsOnInvalidIndex) {
    FixedArray arr(5);
    arr.insert(0, 1);
    EXPECT_THROW(arr.deleteAt(1), std::out_of_range);
}

// --- Find ---

TEST(FixedArrayTest, FindReturnsCorrectIndex) {
    FixedArray arr(5);
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    EXPECT_EQ(arr.find(20), 1);
}

TEST(FixedArrayTest, FindReturnsMinusOneWhenAbsent) {
    FixedArray arr(5);
    arr.insert(0, 10);
    EXPECT_EQ(arr.find(99), -1);
}

TEST(FixedArrayTest, FindReturnsFirstOccurrence) {
    FixedArray arr(5);
    arr.insert(0, 5);
    arr.insert(1, 5);
    EXPECT_EQ(arr.find(5), 0);
}

// --- Rotate Right ---

TEST(FixedArrayTest, RotateRightByTwo) {
    FixedArray arr(5);
    for (int v : {1, 2, 3, 4, 5}) arr.insert(arr.size(), v);
    arr.rotateRight(2);
    EXPECT_EQ(arr.get(0), 4);
    EXPECT_EQ(arr.get(1), 5);
    EXPECT_EQ(arr.get(2), 1);
    EXPECT_EQ(arr.get(3), 2);
    EXPECT_EQ(arr.get(4), 3);
}

TEST(FixedArrayTest, RotateRightByZeroIsNoOp) {
    FixedArray arr(3);
    for (int v : {1, 2, 3}) arr.insert(arr.size(), v);
    arr.rotateRight(0);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);
}

TEST(FixedArrayTest, RotateRightByFullSizeIsNoOp) {
    FixedArray arr(3);
    for (int v : {1, 2, 3}) arr.insert(arr.size(), v);
    arr.rotateRight(3);
    EXPECT_EQ(arr.get(0), 1);
}

TEST(FixedArrayTest, RotateRightKLargerThanSize) {
    FixedArray arr(3);
    for (int v : {1, 2, 3}) arr.insert(arr.size(), v);
    arr.rotateRight(4); // 4 % 3 == 1, so equivalent to rotateRight(1)
    EXPECT_EQ(arr.get(0), 3);
    EXPECT_EQ(arr.get(1), 1);
    EXPECT_EQ(arr.get(2), 2);
}
```

- [ ] **Step 4: Build and verify tests compile**

```bash
cd cpp
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Expected: build succeeds (skeleton compiles).

```bash
cd build && ctest --output-on-failure -R FixedArray
```

Expected: most tests **FAIL** with assertion errors (not build errors). Note: `InitialSizeIsZero` will pass immediately — the constructor correctly sets `size_` to 0. All behavioural tests (insert, get, delete, find, rotate) will fail because those stubs are no-ops or return placeholder values. Cascading stub failures are expected: e.g. the rotate tests fail partly because `insert` is also a stub.

- [ ] **Step 5: Commit**

```bash
cd /path/to/ds-exercises
git add cpp/exercises/fixed_array.h cpp/exercises/fixed_array.cpp cpp/tests/test_array.cpp
git commit -m "feat: add FixedArray exercise skeleton and tests (cpp)"
```

---

### Task 3: LinkedList exercise

**Files:**
- Create: `cpp/exercises/linked_list.h`
- Create: `cpp/exercises/linked_list.cpp`
- Create: `cpp/tests/test_linked_list.cpp`

- [ ] **Step 1: Create `cpp/exercises/linked_list.h`**

```cpp
#pragma once
#include <string>
#include <vector>

/**
 * A singly-linked list of integers.
 *
 * Head insertions are O(1); tail insertions and traversals are O(n).
 * No tail pointer is maintained — this is intentional.
 */
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    /** Append value to the end of the list. O(n). */
    void append(int value);

    /** Insert value at the front of the list. O(1). */
    void prepend(int value);

    /**
     * Delete the first node whose value equals the given value.
     * @return true if a node was removed, false if not found.
     */
    bool deleteValue(int value);

    /**
     * Search the list for value.
     * @return true if found, false otherwise.
     */
    bool find(int value) const;

    /** Reverse the list in-place by rewiring pointers. O(n). */
    void reverse();

    /** Return all values in order from head to tail. */
    std::vector<int> toVector() const;

    /** Return the number of nodes. */
    int size() const;

    /** Return a string like "1 -> 2 -> 3". */
    std::string toString() const;

private:
    struct Node {
        int   value;
        Node* next;
        explicit Node(int v) : value(v), next(nullptr) {}
    };

    Node* head_;
    int   size_;
};
```

- [ ] **Step 2: Create `cpp/exercises/linked_list.cpp`**

```cpp
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
    // 2. If head_ is nullptr, set head_ = new node; done
    // 3. Otherwise traverse to the last node (node->next == nullptr)
    // 4. Set last->next = new node
    // 5. Increment size_
}

void LinkedList::prepend(int value) {
    // TODO: implement this
    // 1. Create a new Node with value
    // 2. Set new_node->next = head_
    // 3. Set head_ = new_node
    // 4. Increment size_
}

bool LinkedList::deleteValue(int value) {
    // TODO: implement this
    // Special case: if head_->value == value, set head_ = head_->next, delete old head, decrement size_, return true
    // General case: traverse with a `prev` pointer until current->value == value
    //   Rewire: prev->next = current->next, delete current, decrement size_, return true
    // If the end is reached without a match, return false
    return false; // placeholder
}

bool LinkedList::find(int value) const {
    // TODO: implement this
    // Traverse from head_; return true if any node's value equals the target
    return false; // placeholder
}

void LinkedList::reverse() {
    // TODO: implement this
    // Use three pointers: prev (starts nullptr), current (starts head_), next
    // Each iteration: save current->next, point current->next = prev, advance prev and current
    // When current is nullptr, set head_ = prev
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
```

- [ ] **Step 3: Create `cpp/tests/test_linked_list.cpp`**

```cpp
#include <gtest/gtest.h>
#include "linked_list.h"

// --- Initialization ---

TEST(LinkedListTest, InitialSizeIsZero) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.toVector(), (std::vector<int>{}));
}

// --- Append ---

TEST(LinkedListTest, AppendSingleElement) {
    LinkedList list;
    list.append(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1}));
}

TEST(LinkedListTest, AppendMaintainsOrder) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2, 3}));
}

// --- Prepend ---

TEST(LinkedListTest, PrependAddsToFront) {
    LinkedList list;
    list.append(2);
    list.prepend(1);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2}));
}

TEST(LinkedListTest, PrependOnEmptyList) {
    LinkedList list;
    list.prepend(5);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.toVector(), (std::vector<int>{5}));
}

// --- Delete ---

TEST(LinkedListTest, DeleteMiddleNode) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    EXPECT_TRUE(list.deleteValue(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 3}));
}

TEST(LinkedListTest, DeleteHeadNode) {
    LinkedList list;
    list.append(1);
    list.append(2);
    EXPECT_TRUE(list.deleteValue(1));
    EXPECT_EQ(list.toVector(), (std::vector<int>{2}));
}

TEST(LinkedListTest, DeleteTailNode) {
    LinkedList list;
    list.append(1);
    list.append(2);
    EXPECT_TRUE(list.deleteValue(2));
    EXPECT_EQ(list.toVector(), (std::vector<int>{1}));
}

TEST(LinkedListTest, DeleteValueReturnsFalseWhenNotFound) {
    LinkedList list;
    list.append(1);
    EXPECT_FALSE(list.deleteValue(99));
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedListTest, DeleteOnEmptyListReturnsFalse) {
    LinkedList list;
    EXPECT_FALSE(list.deleteValue(1));
}

TEST(LinkedListTest, DeleteOnlyFirstOccurrence) {
    LinkedList list;
    list.append(1); list.append(2); list.append(2); list.append(3);
    EXPECT_TRUE(list.deleteValue(2));
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2, 3}));
}

// --- Find ---

TEST(LinkedListTest, FindReturnsTrueWhenPresent) {
    LinkedList list;
    list.append(5);
    EXPECT_TRUE(list.find(5));
}

TEST(LinkedListTest, FindReturnsFalseWhenAbsent) {
    LinkedList list;
    list.append(1);
    EXPECT_FALSE(list.find(42));
}

TEST(LinkedListTest, FindOnEmptyListReturnsFalse) {
    LinkedList list;
    EXPECT_FALSE(list.find(1));
}

// --- Reverse ---

TEST(LinkedListTest, ReverseMultipleElements) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.reverse();
    EXPECT_EQ(list.toVector(), (std::vector<int>{3, 2, 1}));
}

TEST(LinkedListTest, ReverseSingleElement) {
    LinkedList list;
    list.append(1);
    list.reverse();
    EXPECT_EQ(list.toVector(), (std::vector<int>{1}));
}

TEST(LinkedListTest, ReverseEmptyListIsNoOp) {
    LinkedList list;
    list.reverse();
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListTest, ReverseTwiceRestoresOriginal) {
    LinkedList list;
    list.append(1); list.append(2); list.append(3);
    list.reverse();
    list.reverse();
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2, 3}));
}
```

- [ ] **Step 4: Build and verify tests compile but fail**

```bash
cmake --build cpp/build
cd cpp/build && ctest --output-on-failure -R LinkedList
```

Expected: tests compile. `InitialSizeIsZero` passes immediately (constructor sets `size_` to 0 and `toVector()` is pre-implemented). All behavioural tests (append, prepend, delete, find, reverse) **FAIL** because those stubs are no-ops or return placeholder values.

- [ ] **Step 5: Commit**

```bash
git add cpp/exercises/linked_list.h cpp/exercises/linked_list.cpp cpp/tests/test_linked_list.cpp
git commit -m "feat: add LinkedList exercise skeleton and tests (cpp)"
```

---

### Task 4: Stack exercise

**Files:**
- Create: `cpp/exercises/stack.h`
- Create: `cpp/exercises/stack.cpp`
- Create: `cpp/tests/test_stack.cpp`

- [ ] **Step 1: Create `cpp/exercises/stack.h`**

```cpp
#pragma once
#include <stdexcept>
#include <string>
#include <vector>

/**
 * A LIFO stack of integers backed by std::vector.
 */
class Stack {
public:
    Stack();

    /** Push value onto the top. */
    void push(int value);

    /**
     * Remove and return the top element.
     * @throws std::underflow_error if the stack is empty.
     */
    int pop();

    /**
     * Return the top element without removing it.
     * @throws std::underflow_error if the stack is empty.
     */
    int peek() const;

    /** Return true if the stack contains no elements. */
    bool isEmpty() const;

    /** Return the number of elements in the stack. */
    int size() const;

    /**
     * Return true if every opening bracket in s has a matching closing bracket
     * in the correct order. Valid pairs: (), [], {}
     *
     * Examples:
     *   "({[]})"  → true
     *   "({)}"    → false
     *   ""        → true
     *   "("       → false
     */
    static bool isBalanced(const std::string& s);

    /** Return a string like "Stack[1, 2, 3] (top→right)". */
    std::string toString() const;

private:
    std::vector<int> items_;
};
```

- [ ] **Step 2: Create `cpp/exercises/stack.cpp`**

```cpp
#include "stack.h"
#include <sstream>

Stack::Stack() {}

void Stack::push(int value) {
    // TODO: implement this
    // Add value to the end of items_ (the "top" of the stack)
}

int Stack::pop() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("pop from empty stack")
    // 2. Save the back element, remove it from items_, return it
    return 0; // placeholder
}

int Stack::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty stack")
    // 2. Return items_.back() without modifying the stack
    return 0; // placeholder
}

bool Stack::isEmpty() const {
    return items_.empty();
}

int Stack::size() const {
    return static_cast<int>(items_.size());
}

bool Stack::isBalanced(const std::string& s) {
    // TODO: implement this using a Stack
    // For each character c in s:
    //   If c is '(', '[', or '{' → push it
    //   If c is ')', ']', or '}' → if stack is empty, return false
    //                              if top doesn't match → return false
    //                              otherwise pop the top
    // After the loop, return true only if the stack is empty
    return false; // placeholder
}

std::string Stack::toString() const {
    std::ostringstream oss;
    oss << "Stack[";
    for (int i = 0; i < static_cast<int>(items_.size()); ++i) {
        if (i > 0) oss << ", ";
        oss << items_[i];
    }
    oss << "] (top→right)";
    return oss.str();
}
```

- [ ] **Step 3: Create `cpp/tests/test_stack.cpp`**

```cpp
#include <gtest/gtest.h>
#include "stack.h"

// --- Initialization ---

TEST(StackTest, InitiallyEmpty) {
    Stack s;
    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.size(), 0);
}

// --- Push ---

TEST(StackTest, PushIncreasesSize) {
    Stack s;
    s.push(1);
    EXPECT_EQ(s.size(), 1);
    EXPECT_FALSE(s.isEmpty());
}

// --- Peek ---

TEST(StackTest, PeekReturnsTopWithoutRemoving) {
    Stack s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.peek(), 2);
    EXPECT_EQ(s.size(), 2);
}

TEST(StackTest, PeekThrowsWhenEmpty) {
    Stack s;
    EXPECT_THROW(s.peek(), std::underflow_error);
}

// --- Pop ---

TEST(StackTest, PopReturnsTopAndRemoves) {
    Stack s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.size(), 1);
}

TEST(StackTest, PopThrowsWhenEmpty) {
    Stack s;
    EXPECT_THROW(s.pop(), std::underflow_error);
}

TEST(StackTest, LIFOOrdering) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_TRUE(s.isEmpty());
}

// --- isBalanced ---

TEST(StackTest, IsBalancedEmptyStringIsTrue) {
    EXPECT_TRUE(Stack::isBalanced(""));
}

TEST(StackTest, IsBalancedSimpleParen) {
    EXPECT_TRUE(Stack::isBalanced("()"));
}

TEST(StackTest, IsBalancedNestedMixed) {
    EXPECT_TRUE(Stack::isBalanced("({[]})"));
}

TEST(StackTest, IsBalancedSequential) {
    EXPECT_TRUE(Stack::isBalanced("()[]{}"));
}

TEST(StackTest, IsBalancedMismatchedParen) {
    EXPECT_FALSE(Stack::isBalanced("(]"));
}

TEST(StackTest, IsBalancedWrongOrder) {
    EXPECT_FALSE(Stack::isBalanced("({)}"));
}

TEST(StackTest, IsBalancedUnclosedOpen) {
    EXPECT_FALSE(Stack::isBalanced("("));
}

TEST(StackTest, IsBalancedExtraClosing) {
    EXPECT_FALSE(Stack::isBalanced(")"));
    EXPECT_FALSE(Stack::isBalanced("())"));
}

TEST(StackTest, IsBalancedIgnoresNonBracketChars) {
    EXPECT_TRUE(Stack::isBalanced("hello(world[!])"));
    EXPECT_TRUE(Stack::isBalanced("int main() { return 0; }"));
}
```

- [ ] **Step 4: Build and verify tests compile but fail**

```bash
cmake --build cpp/build
cd cpp/build && ctest --output-on-failure -R Stack
```

Expected: tests compile. `InitiallyEmpty` passes immediately — `isEmpty()` and `size()` are pre-implemented and delegate to the backing vector. All behavioural tests (push, pop, peek, isBalanced) **FAIL** because those stubs are no-ops or return placeholder values.

- [ ] **Step 5: Commit**

```bash
git add cpp/exercises/stack.h cpp/exercises/stack.cpp cpp/tests/test_stack.cpp
git commit -m "feat: add Stack exercise skeleton and tests (cpp)"
```

---

### Task 5: Queue + TaskProcessor exercise

**Files:**
- Create: `cpp/exercises/queue.h`
- Create: `cpp/exercises/queue.cpp`
- Create: `cpp/tests/test_queue.cpp`

- [ ] **Step 1: Create `cpp/exercises/queue.h`**

```cpp
#pragma once
#include <stdexcept>
#include <string>
#include <deque>
#include <vector>

/**
 * A FIFO queue of integers backed by std::deque.
 */
class Queue {
public:
    Queue();

    /** Add value to the back of the queue. */
    void enqueue(int value);

    /**
     * Remove and return the front element.
     * @throws std::underflow_error if the queue is empty.
     */
    int dequeue();

    /**
     * Return the front element without removing it.
     * @throws std::underflow_error if the queue is empty.
     */
    int peek() const;

    /** Return true if the queue is empty. */
    bool isEmpty() const;

    /** Return the number of elements in the queue. */
    int size() const;

    /** Return a string like "Queue[1, 2, 3] (front→left)". */
    std::string toString() const;

private:
    std::deque<int> items_;
};

/**
 * A task processor that queues and processes string tasks in FIFO order.
 *
 * Models a simple producer–consumer: tasks are submitted, then processed one
 * at a time. Processed tasks are recorded in history.
 */
class TaskProcessor {
public:
    TaskProcessor();

    /** Add a task to the back of the pending queue. */
    void submitTask(const std::string& task);

    /**
     * Process (dequeue and record) the next pending task.
     * @throws std::runtime_error("no pending tasks") if there is nothing to process.
     * @return the task string that was just processed.
     */
    std::string processNext();

    /** Process all pending tasks in FIFO order. */
    void processAll();

    /** Return the number of tasks still pending. */
    int pendingCount() const;

    /** Return all processed tasks in the order they were processed. */
    std::vector<std::string> getProcessed() const;

private:
    std::deque<std::string>  pending_;
    std::vector<std::string> processed_;
};
```

- [ ] **Step 2: Create `cpp/exercises/queue.cpp`**

```cpp
#include "queue.h"
#include <sstream>

// ── Queue ────────────────────────────────────────────────────────────────────

Queue::Queue() {}

void Queue::enqueue(int value) {
    // TODO: implement this
    // Add value to the back of items_
}

int Queue::dequeue() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("dequeue from empty queue")
    // 2. Save items_.front(), remove it, return it
    return 0; // placeholder
}

int Queue::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty queue")
    // 2. Return items_.front() without removing it
    return 0; // placeholder
}

bool Queue::isEmpty() const {
    return items_.empty();
}

int Queue::size() const {
    return static_cast<int>(items_.size());
}

std::string Queue::toString() const {
    std::ostringstream oss;
    oss << "Queue[";
    bool first = true;
    for (int v : items_) {
        if (!first) oss << ", ";
        oss << v;
        first = false;
    }
    oss << "] (front→left)";
    return oss.str();
}

// ── TaskProcessor ─────────────────────────────────────────────────────────────

TaskProcessor::TaskProcessor() {}

void TaskProcessor::submitTask(const std::string& task) {
    // TODO: implement this
    // Add task to the back of pending_
}

std::string TaskProcessor::processNext() {
    // TODO: implement this
    // 1. If pending_ is empty, throw std::runtime_error("no pending tasks")
    // 2. Take the front task from pending_
    // 3. Add it to processed_
    // 4. Return it
    return ""; // placeholder
}

void TaskProcessor::processAll() {
    // TODO: implement this
    // Repeatedly call processNext() until pendingCount() == 0
}

int TaskProcessor::pendingCount() const {
    return static_cast<int>(pending_.size());
}

std::vector<std::string> TaskProcessor::getProcessed() const {
    return processed_;
}
```

- [ ] **Step 3: Create `cpp/tests/test_queue.cpp`**

```cpp
#include <gtest/gtest.h>
#include "queue.h"

// ── Queue tests ───────────────────────────────────────────────────────────────

TEST(QueueTest, InitiallyEmpty) {
    Queue q;
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, EnqueueIncreasesSize) {
    Queue q;
    q.enqueue(1);
    EXPECT_EQ(q.size(), 1);
    EXPECT_FALSE(q.isEmpty());
}

TEST(QueueTest, PeekReturnsFrontWithoutRemoving) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.size(), 2);
}

TEST(QueueTest, PeekThrowsWhenEmpty) {
    Queue q;
    EXPECT_THROW(q.peek(), std::underflow_error);
}

TEST(QueueTest, DequeueReturnsFrontAndRemoves) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_EQ(q.dequeue(), 1);
    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, DequeueThrowsWhenEmpty) {
    Queue q;
    EXPECT_THROW(q.dequeue(), std::underflow_error);
}

TEST(QueueTest, FIFOOrdering) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQ(q.dequeue(), 1);
    EXPECT_EQ(q.dequeue(), 2);
    EXPECT_EQ(q.dequeue(), 3);
    EXPECT_TRUE(q.isEmpty());
}

// ── TaskProcessor tests ───────────────────────────────────────────────────────

TEST(TaskProcessorTest, InitiallyNoPending) {
    TaskProcessor tp;
    EXPECT_EQ(tp.pendingCount(), 0);
    EXPECT_TRUE(tp.getProcessed().empty());
}

TEST(TaskProcessorTest, SubmitIncreasesPendingCount) {
    TaskProcessor tp;
    tp.submitTask("task1");
    EXPECT_EQ(tp.pendingCount(), 1);
}

TEST(TaskProcessorTest, ProcessNextReturnsFIFO) {
    TaskProcessor tp;
    tp.submitTask("first");
    tp.submitTask("second");
    EXPECT_EQ(tp.processNext(), "first");
    EXPECT_EQ(tp.pendingCount(), 1);
}

TEST(TaskProcessorTest, ProcessNextDecreasesCount) {
    TaskProcessor tp;
    tp.submitTask("a");
    tp.processNext();
    EXPECT_EQ(tp.pendingCount(), 0);
}

TEST(TaskProcessorTest, ProcessNextThrowsWhenNoPending) {
    TaskProcessor tp;
    EXPECT_THROW(tp.processNext(), std::runtime_error);
}

TEST(TaskProcessorTest, ProcessAllClearsQueue) {
    TaskProcessor tp;
    tp.submitTask("a");
    tp.submitTask("b");
    tp.submitTask("c");
    tp.processAll();
    EXPECT_EQ(tp.pendingCount(), 0);
}

TEST(TaskProcessorTest, GetProcessedReturnsHistoryInOrder) {
    TaskProcessor tp;
    tp.submitTask("task1");
    tp.submitTask("task2");
    tp.processAll();
    auto processed = tp.getProcessed();
    ASSERT_EQ(processed.size(), 2u);
    EXPECT_EQ(processed[0], "task1");
    EXPECT_EQ(processed[1], "task2");
}

TEST(TaskProcessorTest, SubmitAfterProcessingWorks) {
    TaskProcessor tp;
    tp.submitTask("first");
    tp.processNext();
    tp.submitTask("second");
    EXPECT_EQ(tp.pendingCount(), 1);
    EXPECT_EQ(tp.processNext(), "second");
}

TEST(TaskProcessorTest, ProcessedHistoryAccumulates) {
    TaskProcessor tp;
    tp.submitTask("job-1");
    tp.submitTask("job-2");
    tp.processNext();            // processes job-1
    tp.submitTask("job-3");
    tp.processAll();             // processes job-2 then job-3
    auto processed = tp.getProcessed();
    ASSERT_EQ(processed.size(), 3u);
    EXPECT_EQ(processed[0], "job-1");
    EXPECT_EQ(processed[1], "job-2");
    EXPECT_EQ(processed[2], "job-3");
}
```

- [ ] **Step 4: Build and verify all tests compile**

```bash
cmake --build cpp/build
cd cpp/build && ctest --output-on-failure
```

Expected: all tests compile. `QueueTest.InitiallyEmpty` and `TaskProcessorTest.InitiallyNoPending` pass immediately — their `isEmpty()`/`pendingCount()` helpers are pre-implemented. All behavioural tests (enqueue, dequeue, peek, submitTask, processNext, processAll) **FAIL** because those stubs are no-ops or return placeholder values.

- [ ] **Step 5: Commit**

```bash
git add cpp/exercises/queue.h cpp/exercises/queue.cpp cpp/tests/test_queue.cpp
git commit -m "feat: add Queue + TaskProcessor exercise skeleton and tests (cpp)"
```

---

### Task 6: Update CI/CD for C++

**Files:**
- Modify: `.github/workflows/ci.yml`

- [ ] **Step 1: Read the existing CI file**

Read `.github/workflows/ci.yml` to understand the current job structure before editing.

- [ ] **Step 2: Add a `cpp` job**

Add the following job alongside the existing `python` and `java` jobs:

```yaml
  cpp:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4

      - name: Configure
        run: cmake -S cpp -B cpp/build -DCMAKE_BUILD_TYPE=Debug

      - name: Build
        run: cmake --build cpp/build --parallel

      - name: Test
        run: ctest --test-dir cpp/build --output-on-failure
```

> Note: `ubuntu-latest` on GitHub Actions already ships CMake 3.25+, which is sufficient. No third-party CMake action needed.

- [ ] **Step 3: Verify the YAML is valid**

```bash
python3 -c "import yaml; yaml.safe_load(open('.github/workflows/ci.yml'))" && echo "YAML valid"
```

Expected: `YAML valid`

- [ ] **Step 4: Commit**

```bash
git add .github/workflows/ci.yml
git commit -m "ci: add C++ build and test job to workflow"
```

---

## Done

All four exercise skeletons and their test suites are in place. The C++ build is wired into CI.

**What students do next:**
1. Check out a feature branch
2. Open `cpp/exercises/*.cpp` and implement every `// TODO` method
3. Run `cmake --build cpp/build && ctest --test-dir cpp/build --output-on-failure` locally until all tests pass
4. Push and open a PR — the CI `cpp` job will run automatically
