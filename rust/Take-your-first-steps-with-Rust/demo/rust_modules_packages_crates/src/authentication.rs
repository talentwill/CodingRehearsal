use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

pub struct User {
    username: String,
    password_hash: u64,
}

impl User {
    pub fn new(username: &str, password: &str) -> User {
        User {
            username: username.to_string(),
            // because str doesn't support Sized trait, which will be used by Hash,
            // so here, we create a String from str by to_owned() which copies the data.
            password_hash: hash_password(&password.to_owned()),
        }
    }

    pub fn get_username(&self) -> &String {
        // because this is a read-only method, return borrowed form is enough
        // so outsider cannot modify it's value
        &self.username
    }

    pub fn set_password(&mut self, new_password: &str) {
        self.password_hash = hash_password(&new_password.to_owned());
    }
}

fn hash_password<T: Hash>(password: &T) -> u64 {
    let mut s = DefaultHasher::new(); // 1. get a default hasher
    password.hash(&mut s); // 2. feed password's value to hasher
    s.finish() // return the hash value.
}

