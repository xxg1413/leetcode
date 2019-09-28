pub fn reverse_string(s: &mut Vec<char>) {

    let n = s.len();

    if n == 0 {
        return;
    }

    for i in 0..n/2 {
            let j = n -1 -i;
            s[i] = ((s[i] as u8) ^ (s[j] as u8)) as char;
            s[j] = ((s[i] as u8) ^ (s[j] as u8)) as char;
            s[i] = ((s[i] as u8) ^ (s[j] as u8)) as char;
        }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut test = vec!['x','x','g'];
        reverse_string(&mut test);
        assert_eq!(vec!['g','x','x'], test);
    }
}
