import java.util.Scanner;

class Node {
  char key;
  int count;
  Node left, right;

  Node(char key) {
    this.key = key;
    this.count = 1;
    this.left = null;
    this.right = null;
  }
}

public class Main {
  static Node insert(Node root, char key) {
    if (root == null) {
      root = new Node(key);
    } else if (key == root.key) {
      root.count++;
    } else if (key < root.key) {
      root.left = insert(root.left, key);
    } else {
      root.right = insert(root.right, key);
    }
    return root;
  }

  static int countSingleChildNodes(Node root) {
    if (root == null) {
      return 0;
    }
    int count = 0;
    if ((root.left != null && root.right == null) || (root.left == null && root.right != null)) {
      count = root.count;
    }
    return count + countSingleChildNodes(root.left) + countSingleChildNodes(root.right);
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    for (int i = 0; i < 5; i++) {
      String input = scanner.nextLine().toUpperCase();
      Node root = null;
      for (int j = 0; j < input.length(); j++) {
        char c = input.charAt(j);
        if (Character.isLetter(c)) {
          root = insert(root, c);
        }
      }

      int count = countSingleChildNodes(root);
      System.out.println(count);
    }
    scanner.close();
  }
}