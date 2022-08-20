mod authentication;

fn main() {
    let mut user = authentication::User::new("Hello World", "123456");
    println!("The username is: {}", user.get_username());
    user.set_password("654321");
}
