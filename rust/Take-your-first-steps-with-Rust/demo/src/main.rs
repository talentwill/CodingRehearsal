trait AsJson {
    fn as_json(&self) -> String;
}

trait AsXml {
    fn as_xml(&self) -> String;
}

struct Person {
    age: i32
}

impl AsJson for Person {
    fn as_json(&self) -> String {
        let mut s = String::from("person:");
        s.push_str(&self.age.to_string());
        s
    }
}
impl AsXml for Person {
    fn as_xml(&self) -> String {
        let mut s = String::from("<person>");
        s.push_str(&self.age.to_string());
        s.push_str("</person>");
        s
    }
}

fn send_data_as_json(value: &impl AsJson) {
    println!("Sending JSON data to server...");
    println!("-> {}", value.as_json());
    println!("Done!\n");
}

fn send_data_as_all(value: &(impl AsJson + AsXml)) {
    println!("Sending JSON data to server...");
    println!("-> {}, {}", value.as_json(), value.as_xml());
    println!("Done!\n");
}

fn main() {
    let p1 = Person {
        age: 100
    };
    send_data_as_json(&p1);
    send_data_as_all(&p1);
}
