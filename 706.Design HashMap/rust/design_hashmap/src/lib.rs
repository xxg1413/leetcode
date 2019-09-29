use std::cell::RefCell;
use std::rc::{Rc, Weak};

#[derive(Clone, Debug)]
pub struct MyLinkedList {
    len: i32,
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

#[derive(Clone, Debug)]
struct Node {
    pub key: i32,
    pub val: i32,
    pub prev: Option<Weak<RefCell<Node>>>,
    pub next: Option<Rc<RefCell<Node>>>,
}

impl Node {
    pub fn new(key: i32, val: i32) -> Self {
        Node {
            key,
            val,
            prev: None,
            next: None,
        }
    }
}


impl MyLinkedList {
    pub fn new() -> Self {
        let ret = MyLinkedList {
            len: 0,
            head: Some(Rc::new(RefCell::new(Node::new(0, 0)))),
            tail: Some(Rc::new(RefCell::new(Node::new(0, 0)))),
        };
        ret.head.as_ref().unwrap().borrow_mut().next = ret.tail.clone();
        ret.tail.as_ref().unwrap().borrow_mut().prev = Some(Rc::downgrade(ret.head.as_ref().unwrap()));
        ret
    }

    pub fn push(&mut self, key: i32, val: i32) {
        if let Some(p) = self.find_by_key(key) {
            p.borrow_mut().val = val;
            return;
        }

        let p = self.tail.clone().unwrap();
        let p = p.borrow().prev.as_ref().unwrap().upgrade().clone().unwrap();


        let next = p.borrow().next.clone().unwrap();
        let prev = p;


        let node = Rc::new(RefCell::new(Node::new(key, val)));
        node.borrow_mut().prev = Some(Rc::downgrade(&prev));
        node.borrow_mut().next = Some(next.clone());

        next.borrow_mut().prev = Some(Rc::downgrade(&node));
        prev.borrow_mut().next = Some(node);

        self.len += 1;
    }

    #[inline]
    fn find_by_key(&self, key: i32) -> Option<Rc<RefCell<Node>>> {
        let mut p = self.head.clone().unwrap();
        for _ in 0..self.len {
            let next = p.borrow().next.clone().unwrap();
            p = next;
            if p.borrow().key == key {
                return Some(p);
            }
        }
        None
    }

    pub fn get(&self, key: i32) -> i32 {
        self.find_by_key(key).map(|p| p.borrow().val).unwrap_or(-1)
    }

    pub fn remove_by_key(&mut self, key: i32) {
        if let Some(p) = self.find_by_key(key) {
            let prev = p.borrow().prev.as_ref().unwrap().upgrade().clone().unwrap();
            let next = p.borrow().next.clone().unwrap();

            prev.borrow_mut().next = Some(next.clone());
            next.borrow_mut().prev = Some(Rc::downgrade(&prev));
            self.len -= 1;
        }
    }
}


struct MyHashMap {
    map: Vec<Option<MyLinkedList>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashMap {

    /** Initialize your data structure here. */
    fn new() -> Self {

        Self {
            map: vec![None; 1001],
        }
    }


    /** value will always be non-negative. */
    fn put(&mut self, key: i32, value: i32) {

    let idx = (key % 1001) as usize;
        if self.map[idx].is_none() {
            self.map[idx] = Some(MyLinkedList::new());
        }
        self.map[idx].as_mut().unwrap().push(key, value);

    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    fn get(&self, key: i32) -> i32 {
        let idx = (key % 1001) as usize;
        match self.map[idx].as_ref() {
            None => -1,
            Some(sub_map) => sub_map.get(key)
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    fn remove(&mut self, key: i32) {
        let idx = (key % 1001) as usize;
        if let Some(sub_map) = self.map[idx].as_mut() {
            sub_map.remove_by_key(key);
        }
    }
}

#[cfg(test)]
mod tests {

    use super:: *;

    #[test]
    fn it_works() {

        let mut obj = MyHashMap::new();
        obj.put(1, 1);
        let ret_2: i32 = obj.get(1);
        assert_eq!(ret_2, 1);
        obj.remove(1);
    }
}
