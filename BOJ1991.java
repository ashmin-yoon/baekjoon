import java.io.*;
import java.util.StringTokenizer;

public class BOJ1991 {
    private static int N;
    private static Node[] node = new Node[26];

    static class Node {
        public char ch;
        public Node leftChild;
        public Node rightChild;

        public Node(char ch, Node leftChild, Node rightChild) {
            this.ch = ch;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        init();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            char me = st.nextToken().charAt(0);
            char left = st.nextToken().charAt(0);
            char right = st.nextToken().charAt(0);

            // 자식 노드 설정
            if (left != '.')
                node[me - 'A'].leftChild = node[left - 'A'];
            if (right != '.')
                node[me - 'A'].rightChild = node[right - 'A'];
        }

        StringBuilder sb = new StringBuilder();
        preorder(0, sb); sb.append("\n");
        inorder(0, sb); sb.append("\n");
        postorder(0, sb); sb.append("\n");
        System.out.print(sb.toString());
        br.close();
    }

    private static void init() {
        for (int i = 0; i < 26; i++) {
            node[i] = new Node((char)('A' + i), null, null);
        }
    }


    // 전위 순회 root, left, right
    private static StringBuilder preorder(int index, StringBuilder sb) {
        char ch = node[index].ch;
        Node leftChild = node[index].leftChild;
        Node rightChild = node[index].rightChild;

        sb.append(ch); // 방문 처리
        if (leftChild != null)
            preorder(leftChild.ch - 'A', sb);
        if (rightChild != null)
            preorder(rightChild.ch - 'A', sb);

        return sb;
    }

    // 중위 순회 left, root, right
    private static StringBuilder inorder(int index, StringBuilder sb) {
        char ch = node[index].ch;
        Node leftChild = node[index].leftChild;
        Node rightChild = node[index].rightChild;


        if (leftChild != null)
            inorder(leftChild.ch - 'A', sb);
        sb.append(ch); // 방문 처리
        if (rightChild != null)
            inorder(rightChild.ch - 'A', sb);

        return sb;
    }

    // 후위 순회 left, right, root
    private static StringBuilder postorder(int index, StringBuilder sb) {
        char ch = node[index].ch;
        Node leftChild = node[index].leftChild;
        Node rightChild = node[index].rightChild;

        if (leftChild != null)
            postorder(leftChild.ch - 'A', sb);

        if (rightChild != null)
            postorder(rightChild.ch - 'A', sb);

        sb.append(ch); // 방문 처리
        return sb;
    }
}
