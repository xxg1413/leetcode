package main

import (
	"fmt"
)

func removeDuplicate(arr []int) int {

	if len(arr) == 0 {
		return 0
	}

	num := 0

	for _, value := range arr {
		if value != arr[num] {
			num += 1
			arr[num] = value
		}

	}

	return num + 1
}

func main() {

	arr := []int{1,1,1,2,2,2,3,3,6,6,6,6,9}
	num := removeDuplicate(arr)

	fmt.Println(arr[:num], num)

}
