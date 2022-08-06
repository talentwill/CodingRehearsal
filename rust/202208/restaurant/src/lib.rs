mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}

        fn seat_at_table() {}
    }

    mod serving {
        fn take_order() {}

        fn serve_order() {}

        fn take_payment() {}
    }
}

// 和 front_of_house 是 siblings，所以可以相互访问。
fn how_to_refer_to_items() {
    // absolute path，用crate开头
    crate::front_of_house::hosting::add_to_waitlist();
    // relative path
    front_of_house::hosting::add_to_waitlist();
}

fn deliver_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        // sibling之间可以相互refer to，不需要pub
        cook_order();
        // 通过super去调用parent scope的函数，表示向上一层
        // 因为back_of_house是子模块，所以可以直接访问上一级的private方法
        super::deliver_order();
    }

    fn cook_order() {}

    // 早餐品类：吐司+水果
    // 从业务的角度看，顾客可以点任何吐司，但是水果就是随机的，看哪个有就给哪个
    pub struct Breakfast {
        pub toast: String,      //可以被访问和直接修改
        seasonal_fruit: String, // private 外部不可见
    }

    // 业务：用户点一份早餐
    impl Breakfast {
        // 类似工厂函数，用类函数返回Breakfast的实例
        // a public associated function that constructs an instance
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }

    // enum 只需要在前面加一个pub即可
    pub enum Appetize {
        Soup,
        Salad,
    }
}

pub fn eat_at_restaurant() {
    // mut 让整个meal是mutable的
    let mut meal = back_of_house::Breakfast::summer("Rye");
    // 只能修改pub field
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    let order1 = back_of_house::Appetize::Soup;
    let order2 = back_of_house::Appetize::Salad;
}
