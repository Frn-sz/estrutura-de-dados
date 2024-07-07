use crate::Pos;
use std::collections::LinkedList;
pub fn add_to_open(
    map: [[&str; 20]; 20],
    open: &mut LinkedList<Pos>,
    closed: &mut LinkedList<Pos>,
    current: &Pos,
    x: u32,
    y: u32,
) {
    let e = map[y as usize][x as usize];

    if e != " " && e != "G" {
        return;
    }

    let dummy = Pos::new(x as u32, y as u32, Some(Box::new(current.clone())));
    if check_lists(open, closed, &dummy) {
        open.push_back(dummy);
    }
}

fn check_lists(open: &LinkedList<Pos>, closed: &LinkedList<Pos>, pos: &Pos) -> bool {
    for e in open.iter() {
        if e.x == pos.x && e.y == pos.y {
            return false;
        }
    }

    for e in closed.iter() {
        if e.x == pos.x && e.y == pos.y {
            return false;
        }
    }

    true
}
