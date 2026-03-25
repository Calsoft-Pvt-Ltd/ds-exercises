# Data Structures Exercises — C++

## Prerequisites
- CMake 3.14+
- A C++17 compiler (GCC 9+, Clang 10+, or MSVC 2019+)
- Internet access on first build (CMake fetches Google Test automatically)

> All commands below assume you are in the repo root (`ds-exercises/`).

## Setup

```bash
cmake -S cpp -B cpp/build
cmake --build cpp/build --parallel
```

## Running Tests

```bash
ctest --test-dir cpp/build --output-on-failure
```

Or run the test binary directly for verbose output:

```bash
./cpp/build/run_tests
```

## Exercises

Implement the `// TODO: implement this` methods in `exercises/`:

| File | Class | Points |
|------|-------|--------|
| `exercises/fixed_array.cpp` | `FixedArray` | 25 |
| `exercises/linked_list.cpp` | `LinkedList` | 25 |
| `exercises/stack.cpp` | `Stack` | 25 |
| `exercises/queue.cpp` | `Queue`, `TaskProcessor` | 25 |

Each skeleton file compiles as-is but tests will fail until you implement the TODO methods.

**Do not modify the header files (`.h`) or the test files.**

## Grading

Each exercise is graded by running its test suite. Full marks require all tests in the suite to pass.
