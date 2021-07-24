package java_test;
public class StrDemo {
    public static void main(String[] args) {
        Parser parser = new Parser();
        //balanced case
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("{[(())]()}"));  
        //unbalanced case
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("{[(()])()}")); 
        //balanced case + noise
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("{[!(%%(^))](#)}")); 
        //balanced case + noise
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("{[(!)$][]}!*&@^#@%$@%^!%@!@")); 
        //unbalanced case
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("{{")); 
        //unbalanced case
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("]")); 
        //balanced case
        System.out.format("string is balanced? %s\n" ,parser.IsBalenced("!%$")); 
    }
}
