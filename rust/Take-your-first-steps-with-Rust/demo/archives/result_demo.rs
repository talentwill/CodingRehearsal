use std::fs::File;
use std::io::{Error, ErrorKind, Read};
use std::path::PathBuf;

fn read_file_contents(path: PathBuf) -> Result<String, Error> {
    let mut content = String::new();

    let mut file: File = match File::open(path) {
        Ok(file_handle) => file_handle,
        Err(io_error) => return Err(io_error),
    };

    match file.read_to_string(&mut content) {
        Ok(_) => (),
        Err(io_error) => return Err(io_error),
    }

    Ok(content)
}

fn main() {
    if read_file_contents(PathBuf::from("src/main.rs")).is_ok() {
        println!("the main.rs is ok.");
    }
    if read_file_contents(PathBuf::from("dummy.rs")).is_err() {
        println!("the file doesn't exist.")
    }
}
