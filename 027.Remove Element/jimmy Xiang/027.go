package main

import (
	"fmt"
)

func removeElement(arr []int, val int) int {

	num := 0

	for i, value := range arr {

		if value == val {
			continue
		}

		arr[num] = arr[i]
		num += 1

	}

	return num

}

func main() {

	arr := []int{1, 2, 2, 2, 11, -2, 333, 111, 2, -2, 3333}
	num := removeElement(arr, 2)

	fmt.Println(arr[:num], num)

}
