pub mod add_to_open;
mod bfs;
mod pos;
mod print_map;

use crate::print_map::MainState;
use bfs::bfs;
use ggez::ContextBuilder;
use pos::Pos;
const ROWS: usize = 20;
const COLS: usize = 20;

fn main() {
    let (mut ctx, _event_loop) = ContextBuilder::new("BFS", "Fernando")
        .build()
        .expect("Falha");

    let mut map = [[" "; COLS]; ROWS];

    let start = Pos::new(0, 0, None);
    let goal = Pos::new(10, 10, None);

    map[start.y as usize][start.x as usize] = "S";
    map[goal.y as usize][goal.x as usize] = "G";

    for j in 0..ROWS / 2 {
        map[j][5] = "#";
    }

    let mut main_state =
        MainState::new(map, start, goal).expect("Falha ao criar o estado principal.");

    bfs(&mut main_state, &mut ctx);
}
