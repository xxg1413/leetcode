package main

import (
	"fmt"
)

func lengthOfLongestSubstring(str string) int {

	arr := [256]int{}
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

	str := "abcabc1234566"
	v := lengthOfLongestSubstring(str)

	fmt.Printf("%s\n%d\n", str, v)

}
