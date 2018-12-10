func removeDuplicates(arr []int) int {

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

