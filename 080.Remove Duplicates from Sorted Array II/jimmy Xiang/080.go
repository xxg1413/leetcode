package main

import (
	"fmt"
)

func removeDuplicate(arr []int) int {

	if len(arr) == 0 {
		return 0
	}

	if len(arr) == 1 {
		return 1
	}

	num := 0
	count := 0

	for i := 1; i < len(arr); i++ {
		if arr[i] == arr[num] {
			count++
			if count < 2 {
				num += 1
				arr[num] = arr[i]
			}
		} else {
			num += 1
			arr[num] = arr[i]
			count = 0
		}
	}

	return num + 1
}

func main() {

	arr := []int{1, 1, 1, 2, 2, 4, 5, 100, 100, 100, 299}
	num := removeDuplicate(arr)

	fmt.Println(arr[:num], num)

}
