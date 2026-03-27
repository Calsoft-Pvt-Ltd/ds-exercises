package exercises;
import java.util.ArrayList;
import java.util.EmptyStackException;

public class MyStack {

    private final ArrayList<Object> items;

    public MyStack() {
        items = new ArrayList<>();
    }

    public void push(Object value) {
        items.add(value);
    }

    public Object pop() {
        if (items.isEmpty()) throw new EmptyStackException();
        return items.remove(items.size() - 1);
    }

    public Object peek() {
        if (items.isEmpty()) throw new EmptyStackException();
        return items.get(items.size() - 1);
    }

    public boolean isEmpty() {
        return items.isEmpty();
    }

    public int size() {
        return items.size();
    }

    public static boolean isBalanced(String s) {
        MyStack stack = new MyStack();

        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {

                if (stack.isEmpty()) return false;

                char top = (char) stack.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}