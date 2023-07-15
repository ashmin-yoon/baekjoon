import java.io.*;

public class BOJ5639 {
    private static StringBuilder sb = new StringBuilder();
    private static Node head = null;

    public static void main(String[] args) throws IOException {

        try {
            input();
        } catch(Exception e) {
            //System.out.println("e = " + e);
        }
        finally {
            solution();
            System.out.println(sb);
        }
    }


    static class Node {
        int value;
        Node left, right;
        public Node(int value) {
           this(value, null, null);
        }

        public Node(int value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int value = Integer.parseInt(br.readLine());
        head = new Node(value);

        while((value = Integer.parseInt(br.readLine())) > 0) {
            Node node = new Node(value);
            Node parent = head;

            while (parent != null) {
                if (value < parent.value) {
                    if (parent.left == null) {
                        parent.left = node;
                        break;
                    }
                    parent = parent.left;
                } else {
                    if (parent.right == null) {
                        parent.right = node;
                        break;
                    }
                    parent = parent.right;
                }
            }
        }
    }

    // postorder
    private static void solution() {
        postOrder(head);
    }

    private static void postOrder(Node node) {
        if (node == null)
            return;
        postOrder(node.left);
        postOrder(node.right);
        sb.append(node.value).append('\n');
    }
}
