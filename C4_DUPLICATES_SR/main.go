package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

type Node struct {
	key   rune
	count int
	left  *Node
	right *Node
}

func insert(root **Node, key rune) {
	if *root == nil {
		*root = &Node{key: key, count: 1}
	} else if key == (*root).key {
		(*root).count++
	} else if key < (*root).key {
		insert(&(*root).left, key)
	} else {
		insert(&(*root).right, key)
	}
}

func countSingleChildNodes(root *Node) int {
	if root == nil {
		return 0
	}
	count := 0
	if (root.left != nil && root.right == nil) || (root.left == nil && root.right != nil) {
		count = root.count
	}
	return count + countSingleChildNodes(root.left) + countSingleChildNodes(root.right)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	for i := 0; i < 5; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.ToUpper(input)
		var root *Node
		for _, c := range input {
			if unicode.IsLetter(c) {
				insert(&root, c)
			}
		}

		count := countSingleChildNodes(root)
		fmt.Println(count)
	}
}