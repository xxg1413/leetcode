package main

import (
	"fmt"
)

func lengthOfLongestSubstring(str string) int {

	arr := [256]int{}

	for _, v := range arr {

		arr[byte(v)] = -1
	}

	start := -1
	max := 0

	for i, v := range str {

		if arr[byte(v)] > start {
			start = arr[byte(v)]
		}

		if i-start > max {

			max = i - start
		}

		arr[byte(v)] = i
	}

	return max

}

func main() {

	str := "ab"
	v := lengthOfLongestSubstring(str)

	fmt.Printf("%s\n%d\n", str, v)

}
