package main

import (
	"fmt"
	"unicode"
)

type Node struct {
	letter    rune
	count     int
	leftNode  *Node
	rightNode *Node
}

func main() {
	var inputStrings [5]string
	for i := 0; i < 5; i++ {
		fmt.Scan(&inputStrings[i])
	}

	var root *Node

	for i := 0; i < 5; i++ {
		for _, letter := range inputStrings[i] {
			letter = unicode.ToUpper(letter)
			if !unicode.IsLetter(letter) {
				continue
			}

			if root == nil {
				root = &Node{letter: letter, count: 1}
				continue
			}

			node := root
			for {
				if letter < node.letter {
					if node.leftNode == nil {
						node.leftNode = &Node{letter: letter, count: 1}
						break
					}
					node = node.leftNode
					continue
				}

				if letter > node.letter {
					if node.rightNode == nil {
						node.rightNode = &Node{letter: letter, count: 1}
						break
					}
					node = node.rightNode
					continue
				}

				node.count++
				break
			}
		}
	}

	var sum int
	var findSingleChildNodes func(*Node)
	findSingleChildNodes = func(node *Node) {
		if node == nil {
			return
		}
		if (node.leftNode == nil) != (node.rightNode == nil) {
			sum += node.count
		}
		findSingleChildNodes(node.leftNode)
		findSingleChildNodes(node.rightNode)
	}
	findSingleChildNodes(root)
	fmt.Println(sum);
}