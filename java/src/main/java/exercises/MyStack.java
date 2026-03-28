package exercises;
 
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
        this.items = new java.util.ArrayList<>();
    }
 
    /** Add {@code value} to the top of the stack. */
    public void push(Object value) {
        items.add(value);
    }
 
    /**
     * Remove and return the top value.
     *
     * @throws java.util.EmptyStackException if the stack is empty
     */
    public Object pop() {
        if (items.isEmpty()) {
            throw new java.util.EmptyStackException();
        }
        return items.remove(items.size() - 1);
    }
 
    /**
     * Return the top value WITHOUT removing it.
     *
     * @throws java.util.EmptyStackException if the stack is empty
     */
    public Object peek() {
        if (items.isEmpty()) {
            throw new java.util.EmptyStackException();
        }
        return items.get(items.size() - 1);
    }
 
    /** Return {@code true} if the stack has no elements. */
    public boolean isEmpty() {
        return items.isEmpty();
    }
 
    /** Return the number of elements in the stack. */
    public int size() {
        return items.size();
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
        MyStack stack = new MyStack();
 
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
 
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
 
                if (stack.isEmpty()) {
                    return false;
                }
 
                char top = (char) stack.pop();
 
                if (!isMatchingPair(top, ch)) {
                    return false;
                }
            }
        }
 
        return stack.isEmpty();
    }
 
    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
}