package main

import (
	"fmt"
)

func plusOne(arr []int) []int {

	one := 1

	for i := len(arr) - 1; i >= 0; i-- {

		sum := arr[i] + one
		one = sum / 10
		arr[i] = sum % 10
	}

	res := make([]int, len(arr)+1)

	if one > 0 {
		copy(res[1:], arr)
		res[0] = 1

		return res
	} else {

		return arr
	}X

}

func main() {
	arr := []int{9, 9, 9, 9, 8}
	res := plusOne(arr)

	fmt.Println(res)

}
