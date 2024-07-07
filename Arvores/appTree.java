public class appTree {
  public static void main(String[] args) {
    tree t = new tree();

    int[] arr = { 4, 2, 1, 3, 6, 5, 7, 8, 9 };

    for (int element : arr)
      t.insert(element);

    t.remove(t.search(60));

    tree t2 = new tree(t);

    t.inOrder();

    t.emptytree(t.root);
    t.inOrder();
    t2.inOrder();

  }
}
