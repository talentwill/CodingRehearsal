// https://docs.microsoft.com/en-us/learn/modules/rust-generic-types-traits/5-iterators

#[derive(Debug)]
struct Counter {
    length: usize,
    count: usize,
}

impl Counter {
    fn new(length: usize) -> Counter {
        Counter { count: 0, length }
    }
}

impl Iterator for Counter {
    type Item = usize; // we have to specify the Item's type
    fn next(&mut self) -> Option<Self::Item> {
        self.count += 1;
        if self.count <= self.length {
            Some(self.count)
        } else {
            None
        }
    }
}

#[test]
fn case1() {
    let mut counter = Counter::new(3);
    println!("Counter just created: {:#?}", counter);

    assert_eq!(counter.next(), Some(1));
    assert_eq!(counter.next(), Some(2));
    assert_eq!(counter.next(), Some(3));
    assert_eq!(counter.next(), None);

    println!("Counter exhaused: {:#?}", counter);
}

#[test]
fn case2() {
    // ressemble to java, for statement is a syntactic sugar. 
    for number in Counter::new(10) {
        println!("{}", number);
    }
}

#[test]
fn case3() {
    // sum is default, based on top of next()
    // but we need to specify the type usize
    let sum_until_10: usize = Counter::new(10).sum();
    assert_eq!(sum_until_10, 55);

    // interger has pow method by default.
    // map's callback gets item by next(), and passes the new item returned by its lambda to collect().
    // collect append each item to a new list
    let power_of_2: Vec<usize> = Counter::new(5).map(|n| 2usize.pow(n as u32)).collect();
    assert_eq!(power_of_2, vec![2, 4, 8, 16, 32]);
}
