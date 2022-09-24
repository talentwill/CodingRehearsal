use enum_iterator::{all, cardinality, Sequence};
use int_enum::IntEnum;

#[repr(u32)]
#[derive(Clone, Copy, Debug, Eq, PartialEq, IntEnum, Sequence)]
pub enum ResistorColor {
    Black = 0,
    Brown = 1,
    Red = 2,
    Orange = 3,
    Yellow = 4,
    Green = 5,
    Blue = 6,
    Violet = 7,
    Grey = 8,
    White = 9,
}

pub fn color_to_value(_color: ResistorColor) -> u32 {
    // _color as u32
    _color.int_value() // IntEnum的方法，自动返回对应的类型
}

// My version，Not good
pub fn value_to_color_string_1(value: u32) -> String {
    let size = cardinality::<ResistorColor>();
    // Because I forgot the match clause, so use cardinality to get size.
    // othewise, it reports out of range error.
    if value as usize >= size {
        String::from("value out of range")
    } else {
        format!("{:?}", ResistorColor::from_int(value).unwrap())
    }
}

pub fn value_to_color_string(value: u32) -> String {
    // let cast: Result<ResistorColor, IntEnumError<ResistorColor>> = ResistorColor::from_int(value);
    let cast = ResistorColor::from_int(value); // 可以自动推导类型
    match cast {
        Ok(x) => format!("{:?}", x),
        Err(_) => "value out of range".to_string(),
    }
}

pub fn colors() -> Vec<ResistorColor> {
    all::<ResistorColor>().collect()
    // all::<ResistorColor>().collect::<Vec<_>>(), 可以直接collect就返回vec
}
