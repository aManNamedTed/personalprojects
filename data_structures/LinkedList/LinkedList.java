/*
    Linked List implementation, as of 5 April, 2018.

    Background: *some of this information is from the Linked List wikipedia page
        IMO one of the ancestral data structures that make up other data 
        structures. 

        Disadvantages:
        - Linked lists use more memory than arrays bc of storing pointers.
        - Must be searched in order; no indexing technically.
        - Nodes are stored incontiguously, greatly increasing time to access 
          elements
        - Reverse traversal is cumbersome if not doubly linked. If doubly
          linked, memory is consumed allocating space for a back pointer.

    Big O:
        Indexing: O(n)
        Insert/delete at beginning: O(1)
        Insert/delete at end: O(1) when last element known; O(n) when not known
        Insert/delete in middle: Search Time + O(1)
        Wasted Space (average): O(n)

    Uses:
        1. When you need O(1) insert/delete from list
        2. When you don't know how many items at runtime
        3. You don't need random access to any elements
        4. You want to be able to insert items in the middle of the list

    TODO:      
        how to reverse a ll? 
*/
class LinkedList  
{   
    Node head; // head node

  class Node 
  
      int data;
      Node next;

    Node(int d) { data = d; next = null; }
  }


  public void push(int new_data)
  {
    Node new_node = new Node(new_data);

    new_node.next = head;

    head = new_node;
  }

  public void append(int new_data) 
  {
    Node new_node = new Node(new_data);

    if(head == null)
    {
      head = new Node(new_data);
      return;
    }

    new_node.next = null;

    Node last = head;
    while(last.next != null) 
    {
      last = last.next;
    }

    last.next = new_node;
  }

  public void printList() 
  {
    Node n = head;
    while(n != null)
    {
      System.out.print(n.data + " ");
      n = n.next;
    }
  }

  public static void main(String[] args)
  {
    LinkedList l = new LinkedList();

    l.head = new Node(1);
    Node second = new Node(2);
    Node third = new Node(3);

    l.head.next = second;
    second.next = third;

    l.printList();
  }
}