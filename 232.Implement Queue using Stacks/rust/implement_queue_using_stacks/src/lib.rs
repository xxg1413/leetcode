pub struct Solution {}

struct MyQueue {
    vec1: Vec<i32>,
    vec2: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    /** Initialize your data structure here. */
    fn new() -> Self {

        MyQueue {
            vec1: Vec::new(),
            vec2: Vec::new(),
        }
    }

    /** Push element x to the back of queue. */
    fn push(&mut self, x: i32) {

        while let Some(v)  = self.vec1.pop() {
            self.vec2.push(v);
        }
        self.vec2.push(x);
        while let Some(v) = self.vec2.pop(){
            self.vec1.push(v);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    fn pop(&mut self) -> i32 {

        self.vec1.pop().unwrap()
    }

    /** Get the front element. */
    fn peek(&self) -> i32 {
        *self.vec1.last().unwrap()

    }

    /** Returns whether the queue is empty. */
    fn empty(&self) -> bool {
        self.vec1.is_empty()

    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut queue = MyQueue::new();

        queue.push(1);
        queue.push(2);
        assert_eq!(queue.peek(), 1);  // returns 1
        assert_eq!(queue.pop(), 1);   // returns 1
        assert_eq!(queue.empty(), false); // returns false
    }
}
