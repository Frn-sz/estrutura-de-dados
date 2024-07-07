package main

import "fmt"

type TreeNode struct {
	key    int
	right  *TreeNode
	left   *TreeNode
	parent *TreeNode
}

func main() {
	var Tree *TreeNode

	insert(&Tree, 10)
	insert(&Tree, 12)

	in_order(Tree)
}

func insert(root **TreeNode, key int) {

	var y *TreeNode = nil
	var x *TreeNode = *root

	for {
		if x == nil {
			break
		}

		y = x

		if key == x.key {
			return
		} else if key < x.key {
			x = x.left
		} else {
			x = x.right
		}
	}

	new_node := &TreeNode{}

	new_node.key = key
	new_node.parent = y

	if y == nil {
		*root = new_node
	} else if new_node.key < y.key {
		y.left = new_node
	} else {
		y.right = new_node
	}
}

func in_order(root *TreeNode) {
	if root == nil {
		return
	}

	in_order(root.right)
	fmt.Println(root.key)
	in_order(root.left)
}
