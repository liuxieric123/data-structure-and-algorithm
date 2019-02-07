package linked;

public class singlelist {
    public static class SNode{

        private int element;

        private SNode next;

        public SNode(int element, SNode next) {
            this.element = element;
            this.next = next;
        }

        public int getData() {
            return element;
        }


        
    }
}