package exercises;

import java.util.EmptyStackException;
import java.util.Stack;

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

    private final Stack<Object> items;
    int size = 0;

    /** Initialize an empty stack. */
    public MyStack() {
        items = new Stack<>();
        size = 0;
    }

    /** Add {@code value} to the top of the stack. */
    public void push(Object value) {
        items.push(value);
        size++;
    }

    /**
     * Remove and return the top value.
     *
     * @throws java.util.EmptyStackException if the stack is empty
     */
    public Object pop() {
        if(items.isEmpty()){
            throw new EmptyStackException ();
        }
        size--;
        return items.pop();
    }

    /**
     * Return the top value WITHOUT removing it.
     *
     * @throws java.util.EmptyStackException if the stack is empty
     */
    public Object peek() {
        if(items.isEmpty())  throw new EmptyStackException ();
        return items.peek();
    }

    /** Return {@code true} if the stack has no elements. */
    public boolean isEmpty() {
      return items.isEmpty();
    }

    /** Return the number of elements in the stack. */
    public int size() {
       return size;
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
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else if (ch == ')' || ch == ']' || ch == '}'){
                if(st.isEmpty()) return false;
                char open = st.pop();
                if (ch == ')' && open != '(') return false;
                if (ch == ']' && open != '[') return false;
                if (ch == '}' && open != '{') return false;
            }
        }
       return st.isEmpty();
    }
}
