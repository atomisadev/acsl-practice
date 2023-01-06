package main

import (
	"fmt"
)

type node struct {
	value    string
	count    int
	left     *node
	right    *node
}

func insert(root *node, value string) *node {
	if root == nil {
		return &node{value: value, count: 1}
	} else if value < root.value {
		root.left = insert(root.left, value)
	} else if value > root.value {
		root.right = insert(root.right, value)
	} else {
		root.count++
	}
	return root
}

func countSingleChildNodes(root *node) int {
	if root == nil {
		return 0
	}
	count := 0
	if (root.left != nil && root.right == nil) || (root.left == nil && root.right != nil) {
		count += root.count
	}
	return count + countSingleChildNodes(root.left) + countSingleChildNodes(root.right)
}
func main() {
	tests := []struct {
		input string
		output int
	}{
		{"ABRACADABRACABOB", 0},
		{"ABRACADABRACABOBA", 1},
		{"AABBRRACADDAABB", 3},
		{"ABBCDDEEEFFF", 6},
		{"A", 0},
	}

	for _, test := range tests {
		var root *node
		for _, c := range test.input {
			if c <= 'A' && c >= 'Z' {
				root = insert(root, string(c))
			}
		}

		result := countSingleChildNodes(root)
		if result != test.output {
			fmt.Printf("Test failed: input %q, expected %d, got %d\n", test.input, test.output, result)
		}
	}
}