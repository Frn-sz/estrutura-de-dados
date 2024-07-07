use crate::{Pos, COLS, ROWS};
use ggez::glam::Vec2;
use ggez::graphics::{self, Color, Rect};
use ggez::{Context, GameResult};

pub const CELL_SIZE: f32 = 50.0;

pub struct MainState {
    pub map: [[&'static str; ROWS]; COLS],
    pub start: Pos,
    pub goal: Pos,
}

impl MainState {
    pub fn new(map: [[&'static str; ROWS]; COLS], start: Pos, goal: Pos) -> GameResult<MainState> {
        let s = MainState { map, start, goal };
        Ok(s)
    }

    pub fn print_map(&self, ctx: &mut Context) -> GameResult {
        let mut canvas =
            graphics::Canvas::from_frame(ctx, graphics::Color::from([0.1, 0.2, 0.3, 1.0]));

        for y in 0..ROWS {
            for x in 0..COLS {
                let color = match self.map[y][x] {
                    " " => Color::WHITE,
                    "#" => Color::BLACK,
                    "+" => Color::RED,
                    "*" => Color::GREEN,
                    _ => Color::WHITE,
                };

                let rect = graphics::Mesh::new_rectangle(
                    ctx,
                    graphics::DrawMode::fill(),
                    Rect::new(
                        x as f32 * CELL_SIZE,
                        y as f32 * CELL_SIZE,
                        CELL_SIZE,
                        CELL_SIZE,
                    ),
                    color,
                )?;

                canvas.draw(&rect, Vec2::new(x as f32, y as f32));
            }
        }

        Ok(())
    }
}
