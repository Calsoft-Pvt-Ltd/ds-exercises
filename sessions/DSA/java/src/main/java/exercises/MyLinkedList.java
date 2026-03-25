package exercises;

import java.util.ArrayList;
import java.util.List;

/**
 * Exercise 2: Singly Linked List
 * ================================
 * Unlike arrays, linked lists have NO fixed size. Each element (node) holds a
 * value and a pointer (reference) to the next node. There is no contiguous
 * memory block — nodes can live anywhere on the heap.
 *
 * Trade-off: insertion and deletion at the head are O(1), but random access
 * is O(n) because you must walk the chain of references.
 *
 * Your task: implement all methods marked with TODO.
 */
public class MyLinkedList {

    /** A single node in the linked list. */
    public static class Node {
        public Object value;
        public Node next;

        public Node(Object value) {
            this.value = value;
            this.next = null;
        }
    }

    private Node head;
    private int size;

    /**
     * Initialize an empty linked list.
     */
    public MyLinkedList() {
        // TODO: initialize head and size
        head = null;
        size = 0;
    }

    /**
     * Add a new node with {@code value} at the END of the list.
     *
     * If the list is empty, the new node becomes the head.
     * Otherwise, walk to the last node and update its .next reference.
     *
     * Think about: why is this O(n) unless you maintain a tail pointer?
     */
    public void append(Object value) {
        // TODO: implement this

        Node node= new Node(value);
        if(head==null){
            head=node;
        }
        else {
            Node curr= head;
            while(curr.next!=null) {
                curr= curr.next;
            }
            curr.next=node;
        }
        size++;
    }

    /**
     * Add a new node with {@code value} at the BEGINNING of the list.
     *
     * This is O(1) — one of the key advantages of linked lists over arrays.
     * Think about: why can't an array do this in O(1)?
     */
    public void prepend(Object value) {
        // TODO: implement this
        Node node= new Node(value);
        node.next=head;
        head=node;
        size++;
    }

    /**
     * Delete the FIRST node whose value equals {@code value}.
     *
     * Return {@code true} if a node was deleted, {@code false} if not found.
     *
     * Handle three cases:
     *   1. The list is empty.
     *   2. The node to delete is the head.
     *   3. The node to delete is somewhere in the middle or tail.
     *
     * Think about: why do you need a reference to the PREVIOUS node?
     */
    public boolean delete(Object value) {
        // TODO: implement this
        if(head==null) return false;
        if(head.value==value) {
            head=head.next;
            size--;
            return true;
        }
        Node curr = head;
        while (curr.next != null) {
            if (curr.next.value==value) { 
                curr.next = curr.next.next; 
                size--; 
                return true;
            }
            curr = curr.next;
        }
        return false;
    }

    /**
     * Return {@code true} if {@code value} exists in the list, {@code false} otherwise.
     */
    public boolean find(Object value) {
        // TODO: implement this
        Node curr=head;
        while(curr!=null) {
            if(curr.value==value) return true;
            curr=curr.next;
        }
        return false;
        // Node curr = head;
        // while (curr != null) { 
        //     if (curr.value.equals(value)) 
        //         return true; 
        //     curr = curr.next;
        //  }
        // return false;
    }

    /**
     * Reverse the list IN-PLACE by re-wiring the .next references.
     *
     * Do NOT create a new list or use extra data structures.
     * After reversing, the old tail becomes the new head.
     *
     * Hint: you need to track three references simultaneously — prev, current, next.
     */
    public void reverse() {
        // TODO: implement this
        Node curr= head, prev=null, nextt;
        while(curr!=null) {
            nextt=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nextt;
        }
        head=prev;
    }

    /**
     * Return all values as a List in order from head to tail.
     * Useful for testing and printing.
     */
    public List<Object> toList() {
        // TODO: implement this
        List<Object> ls= new ArrayList<>();
        Node curr=head;
        while(curr!=null) {
            ls.add(curr.value);
            curr=curr.next;
        }
        return ls;
    }

    /** Return the number of nodes in the list. */
    public int size() {
        // TODO: implement this
        return size;
    }

    @Override
    public String toString() {
        StringBuilder sb= new StringBuilder();
        Node curr= head;
        while(curr!=null) {
            sb.append(curr.value);
            sb.append("->");
            curr= curr.next;
        }
        return sb.toString();
    }
}
