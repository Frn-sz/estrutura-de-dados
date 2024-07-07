use crate::{add_to_open::add_to_open, print_map::MainState, Pos, COLS, ROWS};
use ggez::Context;
use std::{collections::LinkedList, thread::sleep, time::Duration};

pub fn bfs(main_state: &mut MainState, ctx: &mut Context) {
    let mut open: LinkedList<Pos> = LinkedList::new();
    let mut closed: LinkedList<Pos> = LinkedList::new();

    open.push_back(main_state.start.clone());

    while let Some(current) = open.pop_front() {
        println!("X: {}, Y: {}", current.x, current.y);

        main_state.map[current.y as usize][current.x as usize] = "+";

        sleep(Duration::from_millis(10));

        main_state.print_map(ctx).expect("Erro ao desenhar o mapa.");

        if current.x == main_state.goal.x && current.y == main_state.goal.y {
            println!("Destino encontrado!");

            let mut cursor = Some(current);

            while let Some(pos) = cursor {
                if pos == main_state.start || pos == main_state.goal {
                    break;
                }

                main_state.map[pos.y as usize][pos.x as usize] = "*";

                cursor = pos.last.as_deref().cloned();

                main_state.print_map(ctx).expect("Erro ao desenhar o mapa.");
            }

            for row in main_state.map.iter_mut() {
                for cell in row.iter_mut() {
                    if *cell == "+" {
                        *cell = " ";
                    }
                }
            }

            main_state.print_map(ctx).expect("Erro no desenho do mapa.");
            return;
        }

        closed.push_back(current.clone());

        if current.y > 0 && main_state.map[current.y as usize][current.x as usize] == " " {
            add_to_open(
                main_state.map,
                &mut open,
                &mut closed,
                &current,
                current.x,
                current.y - 1,
            );
        }

        if current.y < (ROWS - 1) as u32 {
            add_to_open(
                main_state.map,
                &mut open,
                &mut closed,
                &current,
                current.x,
                current.y + 1,
            );
        }

        if current.x > 0 {
            add_to_open(
                main_state.map,
                &mut open,
                &mut closed,
                &current,
                current.x - 1,
                current.y,
            );
        }

        if current.x < (COLS - 1) as u32 {
            add_to_open(
                main_state.map,
                &mut open,
                &mut closed,
                &current,
                current.x + 1,
                current.y,
            );
        }
    }

    println!("Destino não encontrado!");
}
