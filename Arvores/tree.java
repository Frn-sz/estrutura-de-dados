/**
 * tree
 */
public class tree {

  public tree() {
  }

  public tree(tree t) {
    preOrderInsertRec(t.root);
  }

  public class Node {
    public int key;
    public Node parent;
    public Node right;
    public Node left;

    public Node(int key) {
      this.key = key;
    }

    public Node(int key, Node parent) {
      this.key = key;
      this.parent = parent;
    }
  }

  public Node root;

  public Node insert(int key) {
    if (this.root == null) {
      this.root = new Node(key);
      return this.root;
    }

    Node y = null;
    Node x = this.root;

    while (x != null) {
      y = x;

      if (key == x.key) {
        return null;
      } else if (key < x.key) {
        x = x.left;
      } else {
        x = x.right;
      }
    }
    Node n_node = new Node(key, y);

    if (key < y.key) {
      y.left = n_node;
    } else {
      y.right = n_node;
    }

    return n_node;
  }

  public void inOrder() {
    System.out.print("{");
    if (this.root != null) {
      inOrderRec(this.root);
      System.out.print("\b");
    }
    System.out.println("}");
  }

  private void inOrderRec(Node node) {
    if (node == null) {
      return;
    }

    inOrderRec(node.left);
    System.out.print(node.key + ",");
    inOrderRec(node.right);
  }

  public void posOrder() {
    System.out.print("{");
    if (this.root != null) {
      posOrderRec(this.root);
      System.out.print("\b");
    }
    System.out.println("}");
  }

  private void posOrderRec(Node node) {
    if (node == null) {
      return;
    }

    posOrderRec(node.left);
    posOrderRec(node.right);
    System.out.print(node.key + ",");
  }

  public void emptytree(Node node) {
    if (node == null) {
      return;
    }

    emptytree(node.left);
    emptytree(node.right);
    remove(node);
  }

  public Node search(int key) {
    Node dummy = this.root;

    while (dummy != null && key != dummy.key) {
      if (key > dummy.key) {
        dummy = dummy.right;
      } else {
        dummy = dummy.left;
      }
    }

    return dummy;
  }

  public void remove(Node node) {
    if (node == null)
      return;

    if (node.left == null && node.right == null) {
      if (node.parent == null) {
        this.root = null;
      } else if (node.parent.left == node) {
        node.parent.left = null;
      } else {
        node.parent.right = null;
      }
    }
  }

  public void preOrderInsertRec(Node node) {
    if (node == null)
      return;

    insert(node.key);
    preOrderInsertRec(node.left);
    preOrderInsertRec(node.right);
  }
}