use std::collections::HashMap;

pub fn create_a_hashmap() {
    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.insert(String::from("yellow"), 50);

    // get one item
    let blue = String::from("blue");
    let score1 = scores.get(&blue);
    match score1 {
        Some(value) => {
            println!("{}", value);
        }
        None => {
            println!("no score");
        }
    }

    // iteration
    for (name, score) in &scores {
        println!("{}, {}", name, score);
    }
}

pub fn insert_with_replacement() {
    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.insert(String::from("blue"), 99);
    println!("{:?}", scores);
}

pub fn insert_if_key_not_exist() {
    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.entry(String::from("Blue")).or_insert(99);
    println!("{:?}", scores);
}

pub fn test() {
    create_a_hashmap();
    insert_with_replacement();
    insert_if_key_not_exist();
}
