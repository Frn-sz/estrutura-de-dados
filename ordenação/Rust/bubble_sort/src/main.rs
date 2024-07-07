extern crate rand;
use rand::Rng;

fn bubble_sort(v: &mut [u32], n: usize) {
    for i in 0..n {
        for j in 0..n - i - 1 {
            if v[j] > v[j + 1] {
                v.swap(j, j + 1);
            }   
        }
    }
}

fn main() {
    const SIZE: usize = 500;

    let mut rng = rand::thread_rng();
    let mut v: [u32; SIZE] = [0; SIZE];

    for i in 0..v.len() {
        v[i] = rng.gen_range(0..100);
    }

    bubble_sort(&mut v, SIZE );

    print!("Vetor Ordenado: \n");
    for i in 0..v.len() {
        println!("{},", v[i]);
    }
}
