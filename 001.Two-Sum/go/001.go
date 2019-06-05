
func twoSum(nums []int, target int) []int {

	int_map := make(map[int]int, len(nums))

	for index, value := range nums {

		//find the value
		if find, ok := int_map[target-value]; ok {
			//index is not add, find < index
			return []int{find, index}
		}

		//not find, add the map
		int_map[value] = index
	}
	return nil
}
