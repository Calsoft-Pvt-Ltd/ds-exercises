# Java Exercises

## Requirements

- Java 11 or higher
- Maven 3.6 or higher

Verify your setup:
```bash
java -version
mvn -version
```

## Running Tests

From the `java/` directory:

```bash
# Run all tests
mvn test

# Run a single test class
mvn test -Dtest=FixedArrayTest
mvn test -Dtest=LinkedListTest
mvn test -Dtest=StackTest
mvn test -Dtest=QueueTest
```

## Files to Edit

Only edit files inside `src/main/java/exercises/`. Do **not** modify anything in `src/test/`.

```
java/
├── src/
│   ├── main/java/exercises/
│   │   ├── FixedArray.java        ← edit this
│   │   ├── MyLinkedList.java      ← edit this
│   │   ├── MyStack.java           ← edit this
│   │   └── MyQueue.java           ← edit this
│   └── test/java/exercises/
│       ├── FixedArrayTest.java
│       ├── LinkedListTest.java
│       ├── StackTest.java
│       └── QueueTest.java
└── pom.xml
```
