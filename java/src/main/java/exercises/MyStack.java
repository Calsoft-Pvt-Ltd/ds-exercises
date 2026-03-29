package exercises;

import java.util.ArrayList;
import java.util.EmptyStackException;

/**
 * Exercise 3: Stack (LIFO)
 * =========================
 * A stack is a Last-In, First-Out (LIFO) structure. The last element pushed
 * is the first element popped. Think of a stack of plates — you add and
 * remove from the top only.
 *
 * Real-world example: the CALL STACK. Every time a method is invoked, a
 * frame is pushed onto the JVM stack. When the method returns, its frame is
 * popped. This is why infinite recursion causes a StackOverflowError.
 *
 * Your task: implement all methods marked with TODO, plus the static
 * isBalanced() method.
 */
public class MyStack {

    private final java.util.ArrayList<Object> items;

    /** Initialize an empty stack. */
    public MyStack() {
        // TODO: initialize items
        items = new ArrayList<>();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /** Add {@code value} to the top of the stack. */
    public void push(Object value) {
        // TODO: implement this
        items.add(value);
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Remove and return the top value.
     *
     * @throws java.util.EmptyStackException if the stack is empty
     */
    public Object pop() {
        // TODO: implement this
        if (items.isEmpty()) {
            throw new EmptyStackException();
        }
        return items.remove(items.size() - 1);
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Return the top value WITHOUT removing it.
     *
     * @throws java.util.EmptyStackException if the stack is empty
     */
    public Object peek() {
        // TODO: implement this
        if (items.isEmpty()) {
            throw new EmptyStackException();
        }
        return items.get(items.size() - 1);
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /** Return {@code true} if the stack has no elements. */
    public boolean isEmpty() {
        // TODO: implement this
        return items.isEmpty();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /** Return the number of elements in the stack. */
    public int size() {
        return items.size();
        // TODO: implement this
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Use a MyStack to determine whether the bracket/paren/brace characters
     * in {@code s} are balanced.
     *
     * Rules:
     *   - Every opening bracket must have a matching closing bracket.
     *   - Brackets must close in the correct order.
     *   - Valid pairs: () [] {}
     *   - Non-bracket characters are ignored.
     *
     * Examples:
     *   isBalanced("()")           → true
     *   isBalanced("({[]})")       → true
     *   isBalanced("hello(world)") → true
     *   isBalanced("({[})")        → false  (wrong closing order)
     *   isBalanced("(((")          → false  (unclosed brackets)
     *   isBalanced("))")           → false  (closes before any open)
     *
     * Algorithm hint:
     *   - Push every opening bracket onto the stack.
     *   - When you see a closing bracket, check that it matches the top.
     *   - At the end, the stack should be empty.
     */
    public static boolean isBalanced(String s) {
        // TODO: implement this using MyStack
        MyStack stack = new MyStack();

        for (char c : s.toCharArray()) {

            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }

            // Handle closing brackets
            else if (c == ')' || c == '}' || c == ']') {

                if (stack.isEmpty()) return false;

                char top = (char) stack.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty → balanced
        return stack.isEmpty();
     }
        //throw new UnsupportedOperationException("Not implemented yet");
    }
