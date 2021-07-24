package java_test;
import java.util.*;

//Non-bracket characters in the string should be ignored(TBC!!!!)
public class Parser {
    // String s;
    Hashtable<Character, Character>  rigtBrackettable=null;
    Hashtable<Character, Character>  leftBracketTable=null;
    // Stack<Character> stack=null;
    public Parser(){
        // s="";
        rigtBrackettable = new Hashtable<Character,Character>();
        leftBracketTable = new Hashtable<Character,Character>();
        rigtBrackettable.put(')','(');
        rigtBrackettable.put(']','[');
        rigtBrackettable.put('}','{');
        leftBracketTable.put('(','(');
        leftBracketTable.put('[','[');
        leftBracketTable.put('{','{');
    }
    // public Parser(String val){
    //     s=val;
    //     rigtBrackettable = new Hashtable<Character,Character>();
    //     leftBracketTable = new Hashtable<Character,Character>();
    //     stack = new Stack<Character>();
    //     rigtBrackettable.put(')','(');
    //     rigtBrackettable.put(']','[');
    //     rigtBrackettable.put('}','{');
    //     leftBracketTable.put('(','(');
    //     leftBracketTable.put('[','[');
    //     leftBracketTable.put('{','{');
    // }
    public boolean IsBalenced(String val){
         Stack<Character> stack = new Stack<Character>();
         // s=val;
         // Creating array of string length
         char[] ch = new char[val.length()];
         // Copy character by character into array
         for (int i = 0; i < val.length(); i++) {
             ch[i] = val.charAt(i);
         }
         // Printing content of array
        //  for (char c : ch) {
        //      System.out.println(c);
        //  }
        for(char c: ch){
            if (leftBracketTable.containsKey(c)){
                stack.push(c);
            }
            else if (rigtBrackettable.containsKey(c)){
                if (stack.empty())
                    return false;
                else if(!stack.empty() && stack.peek()!= rigtBrackettable.get(c))
                    return false;
                else
                    stack.pop();
            }
            // else
            //     System.out.println("other chars");    
        }
        if(stack.empty())
            return true;
        else
            return false;
    }
}
