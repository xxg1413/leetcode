use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::with_capacity(nums.len());
        for(index,num) in nums.iter().enumerate() {
            match map.get(&(target-num)) {
                None => {map.insert(num,index);}
                Some(find) => {return vec![*find as i32, index as i32]}
            }
        } 
        vec![]
    }
}