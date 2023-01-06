package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func transform(n int, p int) int {
	s := strconv.Itoa(n)

	pthDigit := int(s[len(s)-p] - '0')

	var transformed strings.Builder
	for i, c := range s {
		digit := int(c - '0')
		if i < len(s) - p {
			transformed.WriteByte(byte((digit + pthDigit) % 10 + '0'))
		} else if i > len(s) - p {
			transformed.WriteByte(byte(abs(digit - pthDigit) + '0'))
		} else {
			transformed.WriteByte(byte(digit + '0'))
		}
	}

	result, _ := strconv.Atoi(transformed.String())
	return result
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, "  ")
		n, _ := strconv.Atoi(parts[0])
		p, _ := strconv.Atoi(parts[1])
		fmt.Println(transform(n, p))
	}
}