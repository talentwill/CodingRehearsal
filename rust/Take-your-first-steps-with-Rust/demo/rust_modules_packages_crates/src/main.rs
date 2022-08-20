mod authentication {
    pub struct User {
        username: String,
        password_hash: u64,
    }

    impl User {
        pub fn new(username: &str, password: &str) -> User {
            User {
                username: username.to_string(),
                password_hash: hash_password(password),
            }
        }

        pub fn get_username(&self) -> &String {
            // because this is a read-only method, return borrowed form is enough
            // so outsider cannot modify it's value
            &self.username
        }

        pub fn set_password(&mut self, new_password: &str) {
            self.password_hash = hash_password(new_password);
        }
    }

    fn hash_password(password: &str) -> u64 {
        123
    }
}

fn main() {
    let mut user = authentication::User::new("Hello World", "123456");
    println!("The username is: {}", user.get_username());
    user.set_password("abcdef");
}
