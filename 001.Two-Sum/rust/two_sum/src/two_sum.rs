use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map = HashMap::with_capacity(nums.len());
    for(index,num) in nums.iter().enumerate() {
        if let Some(&find) = map.get(&(target-num)) {
            return vec![find as i32, index as i32];
        }
        map.insert(num,index);
     }
     vec![]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn internal() {
        assert_eq!(vec![0, 1], two_sum(vec![2, 7, 11, 15], 9));
        assert_eq!(vec![1, 3], two_sum(vec![40, 50, 60, 70], 120));
        assert_eq!(vec![1, 2], two_sum(vec![3, 2, 4], 6));
        assert_eq!(vec![0, 2], two_sum(vec![3, 2, 3], 6));
        assert_eq!(vec![0, 1], two_sum(vec![3, 3, 2], 6));
    }
}
