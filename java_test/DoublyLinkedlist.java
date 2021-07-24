package java_test;

public class DoublyLinkedlist {
    private Node head;
    private Node tail;

    public DoublyLinkedlist(){
        head=null;
        tail=null;
    }

    // public void AddNode(int newVal){

    //     //create new node
    //     Node newNode = new Node(newVal);

    //     //if list is empty, head and tail points to newNode
    //     if (head==null){
    //         head = tail = newNode;  
    //         head.previous = null;  
    //         tail.next = null;  
    //     }
    //     else{
    //         //add newNode to the end of list. tail->next points to newNode  
    //         tail.next = newNode;  
    //         newNode.previous = tail;  
    //         tail = newNode;  
    //         tail.next = null;  
    //     }

    // }

    public void AddHead(int newVal){
        //create new node
        Node newNode = new Node(newVal);

        //if list is empty
        if(head==null){
            head = tail = newNode;  
            head.previous = null;  
            tail.next = null;  
        }
        else{
            newNode.next=head;
            newNode.previous=null;
            head.previous = newNode;
        }

        head = newNode;
    }

    public void AddTail(int newVal){
        //create new node
        Node newNode = new Node(newVal);

        //if list is empty
        if(tail==null){
            head = tail = newNode;  
            head.previous = null;  
            tail.next = null; 
        }
        else{
            tail.next = newNode;
            newNode.previous = tail;
            newNode.next = null;
        }
        tail = newNode;

    }
    
    public void DeleteNode(Node node){
        
        if(node!=null){
            //if only one node
            if (node.previous==null && node.next ==null){
                head=null;
                tail=null;
            }
            //if node is the head node
            else if (node.previous==null){
                head=node.next;
                head.previous=null;
            }
            // if node is the tail node
            else if(node.next ==null){
                tail = node.previous;
                tail.next = null;
            }
            //in the middle
            else{
                node.previous.next = node.next;
                node.next.previous = node.previous;
            }
            node=null;
        }
        else{
            System.out.println("this to be deleted node is null\n"); 
        }
    }

    public Node GetHead(){
        if (head!=null)
            System.out.format("Head node val is %d \n" ,head.val);  
        else
            System.out.println("Doubly linked list is empty\n"); 
        return head;
    }

    public Node GetTail(){
        if (tail!=null)
            System.out.format("Tail node val is %d \n" ,tail.val);  
        else
            System.out.println("Doubly linked list is empty\n"); 
        return tail;
    }

    public Node GetNode(int val){
        Node current = head;  
        if(current == null) {  
            System.out.println("Doubly linked list is empty\n");  
        }  
        while(current != null) {  
            //iterate list  
            if(current.val==val)
                break;
            current = current.next;  
        }
        if (current == null)
            System.out.format("%d node did't exist in the list. \n" ,val);   
        return current;
    }

    public void printNodes() {  
        //Node current will point to head  
        Node current = head;  
        if(current == null) {  
            System.out.println("Doubly linked list is empty\n");  
            return;  
        }  
        System.out.println("Nodes of doubly linked list: ");  
        while(current != null) {  
            System.out.print(current.val + " ");
            current = current.next;  
        }
        System.out.println("\n");  
    }
    
    
}
