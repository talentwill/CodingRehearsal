//https://docs.microsoft.com/en-us/learn/modules/rust-generic-types-traits/6-exercise-implement-generic-type

struct Container {
    value: u32,
}

impl Container {
    pub fn new(value: u32) -> Self {
        Container { value }
    }
}

pub fn test() {
    assert_eq!(Container::new(42).value, 42);
    // assert_eq!(Container::new(3.14).value, 3.14);
    // assert_eq!(Container::new("Foo").value, "Foo");
    // assert_eq!(Container::new(String::from("Bar")).value, String::from("Bar"));
    // assert_eq!(Container::new(true).value, true);
    // assert_eq!(Container::new(-12).value, -12);
    // assert_eq!(Container::new(Some("text")).value, Some("text"));
}