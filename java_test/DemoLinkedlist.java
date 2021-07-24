package java_test;

public class DemoLinkedlist {
    public static void main(String[] args) {
      DoublyLinkedlist list = new DoublyLinkedlist();
      list.AddHead(6);
      list.AddHead(5);
      list.AddTail(7);
      list.AddTail(8);
      list.printNodes();
      Node head = list.GetHead();
      Node tail = list.GetTail();
      list.DeleteNode(head);
      list.DeleteNode(tail);
      list.printNodes();
      list.AddTail(9);
      list.AddTail(6);
      list.AddHead(2);
      list.AddHead(3);
      list.AddHead(5);
      list.printNodes();
      list.DeleteNode(list.GetHead());
      list.printNodes();
      list.DeleteNode(list.GetTail());
      list.printNodes();
      list.DeleteNode(list.GetNode(697));
      list.printNodes();
      list.DeleteNode(list.GetNode(2));
      list.printNodes();

    }
}
