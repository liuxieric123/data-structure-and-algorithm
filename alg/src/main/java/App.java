import linked.singlelist;
import stack.stackWithNode;
public class App {

    public static void main(String[] args) {
        int[] test = {1,2,3};
        final Integer DEFAULT_CAPACITY = 10;
        // System.out.println(ttt);
        for (int i=0; i<test.length; i++){
            System.out.println(DEFAULT_CAPACITY);
        }
        int a = 1000;
        singlelist.SNode node = new singlelist.SNode(a, null);
        System.out.println(node);
        stackWithNode s = new stackWithNode();
        s.push(1);
        s.push(2);
        s.push(7);
        s.printAll();
    }
}