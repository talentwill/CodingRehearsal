//https://docs.microsoft.com/en-us/learn/modules/rust-generic-types-traits/6-exercise-implement-generic-type

struct Container<T> {
    value: T,
}

// https://doc.rust-lang.org/stable/book/ch10-01-syntax.html#in-method-definitions
// however, if is weird to add T twice.
impl<T> Container<T> {
    pub fn new(value: T) -> Self {
        Container { value }
    }
}

pub fn test() {
    assert_eq!(Container::new(42).value, 42);
    assert_eq!(Container::new(3.14).value, 3.14);
    assert_eq!(Container::new("Foo").value, "Foo");
    assert_eq!(
        Container::new(String::from("Bar")).value,
        String::from("Bar")
    );
    assert_eq!(Container::new(true).value, true);
    assert_eq!(Container::new(-12).value, -12);
    assert_eq!(Container::new(Some("text")).value, Some("text"));
}
