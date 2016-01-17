package main

import (
	"fmt"
)

func twoSum(arr []int, value int) (result [2]int) {

	var res [2]int = [2]int{-1, -1}

	for i, v := range arr {

		for j, o := range arr {

			if i < j && (value-v) == o {

				res[0] = i
				res[1] = j

				return res
			}
		}
	}

	return res

}

func main() {

	arr := []int{222, 333, 11, 2, 3, 0, -2, 1, 2, 3}

	var sum = 0

	result := twoSum(arr, sum)

	if result[0] != -1 {

		fmt.Printf("arr[%d]:%d  + arr[%d]:%d  =  %d \n", result[0], arr[result[0]], result[1], arr[result[1]], sum)
	} 
	else {
		fmt.Println("cann't find the numbers")
	}

}
