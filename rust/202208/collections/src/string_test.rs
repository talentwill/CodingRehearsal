fn create_new_strings() {
    // 创建一个empty的string
    let s0 = String::new();

    // 声明一个str slice，然后使用tostring方法
    let str_slice1 = "s1";
    let s1 = str_slice1.to_string();

    // 使用from构造方法
    let s2 = String::from("s2");

    // 直接用string literal来创建
    let s3 = "s3".to_string();

    println!("{}, {}, {}, {}", s0, s1, s2, s3);
}

fn update_strings_with_push() {
    let mut s0 = String::new();
    s0.push_str("hello");
    let s1 = String::from("world");
    s0.push_str(&s1); // append a str slice
    s0.push('!'); // append a char
    println!("{}", s0);
}

fn update_strings_with_add() {
    let s1 = String::from("Hello");
    let s2 = String::from("World");
    // s1 会被夺取owner，不需要拷贝，而是直接在s1的内容移动过来，然后追加s2，返回出s3
    let mut s3 = s1 + &s2 + "!"; // 只有第一个需要夺取所有权
    println!("{}", s3);

    s3 += "?"; // 直接追加，类似s3.push() 操作。
    println!("{}", s3);
}

fn update_strings_with_format() {
    let s1 = "You";
    let s2 = "are";
    let s3 = "bad";
    let s = format!("{}-{}-{}", s1, s2, s3); // 三次copy，保留ownership
    println!("{}", s);
}

// string 不同按下标访问，但是可以使用string slice切换
// 但是必须知道具体的char的字节数的边界，否则就无法切取正确
fn read_string_with_string_slice() {
    let hello = String::from("Здравствуйте");
    println!("{}", &hello[0..2]); // З
    println!("{}", &hello[2..4]); // д

    let world = String::from("a中国b");
    println!("{} len: {}", world, world.len()); // 3 bytes
    let c1 = &world[0..1]; // a，ascii占一个字节
    let c2 = &world[1..4]; //
    let c3 = &world[4..7];
    let c4 = &world[7..8];
    println!("{}, {}, {}, {}", c1, c2, c3, c4);
}

fn read_string_with_for() {
    let china = String::from("abc中国вуй");
    // 打印utf-8字符，可以正常打印大部分字符
    for c in china.chars() {
        println!("{}", c);
    }
    // 打印单个字节
    for b in china.as_bytes() {
        println!("{}", b);
    }
}

pub fn test() {
    create_new_strings();
    update_strings_with_push();
    update_strings_with_add();
    update_strings_with_format();
    read_string_with_string_slice();
    read_string_with_for();
}






