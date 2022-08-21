// https://docs.microsoft.com/en-us/learn/modules/rust-generic-types-traits/7-exercise-implement-iterator
struct Groups<T> {
    inner: Vec<T>,
    cur_index: usize,
}

impl<T> Groups<T> {
    fn new(inner: Vec<T>) -> Self {
        Groups {
            inner,
            cur_index: 0,
        }
    }
}

// https://docs.microsoft.com/en-us/learn/modules/rust-loop-expressions/3-for-while-loop
// https://doc.rust-lang.org/stable/book/ch08-01-vectors.html

impl<T: PartialEq + Clone> Iterator for Groups<T> {
    type Item = Vec<T>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.cur_index == self.inner.len() {
            return None;
        }

        let x = self.inner[self.cur_index].clone(); // we have to clone this current item
        let mut v = vec![x.clone()]; // push this item to our result vector

        self.cur_index += 1; // move to next item's index
        while self.cur_index < self.inner.len() {
            if self.inner[self.cur_index].eq(&x) {
                // if next item is same to the x
                v.push(x.clone()); // count this item as result
                self.cur_index += 1; // move to next's index
            } else {
                break;
            }
        }

        Some(v)
    }
}

// Find the same items in the vector, and group them into sub vector
pub fn test() {
    let data = vec![4, 1, 1, 2, 1, 3, 3, -2, -2, -2, 5, 5];
    // groups:     |->|---->|->|->|--->|----------->|--->|
    assert_eq!(
        Groups::new(data).into_iter().collect::<Vec<Vec<_>>>(),
        vec![
            vec![4],
            vec![1, 1],
            vec![2],
            vec![1],
            vec![3, 3],
            vec![-2, -2, -2],
            vec![5, 5],
        ]
    );

    let data2 = vec![1, 2, 2, 1, 1, 2, 2, 3, 4, 4, 3];
    let groups = Groups::new(data2.clone());
    let data21 = groups.into_iter().collect::<Vec<Vec<_>>>();
    assert_eq!(
        data21,
        vec![
            vec![1],
            vec![2, 2],
            vec![1, 1],
            vec![2, 2],
            vec![3],
            vec![4, 4],
            vec![3],
        ]
    )
}

#[test]
fn case1() {
    test();
}

#[test]
fn case2() {
    for v in Groups::new(vec![1, 2, 2, 1, 1, 2, 2, 3, 4, 4, 3]) {
        println!("{:#?}", v);
    }
}
