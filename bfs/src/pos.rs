#[derive(PartialEq, Clone)]
pub struct Pos {
    pub x: u32,
    pub y: u32,
    pub last: Option<Box<Pos>>,
}

impl Pos {
    pub fn new(x: u32, y: u32, last: Option<Box<Pos>>) -> Pos {
        Pos { x, y, last }
    }
}
