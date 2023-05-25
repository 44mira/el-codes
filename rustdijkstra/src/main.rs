
pub mod graph;

use crate::graph::init_graph;
use crate::graph::Node;
use std::io;


fn main() {
    let mut sz = String::new();
    println!("Input number of vertices: ");
    io::stdin()
        .read_line(&mut sz)
        .expect("Failed to read.");

    let sz : usize = match sz.trim().parse() {
        Ok(x) => x,
        Err(_) => {println!("Failed to parse. Defaulting as 0."); 0},
    };

    let mut distances : Vec<u32> = Vec::new();
    for _ in 0..sz {
        distances.push(u32::MAX);
    }
    distances[0] = 0;

    let graph : Vec<Node> = init_graph(sz);                     // initializes graph
    let queue = 0..sz;

    for curr in queue {
        // update estimates
        for node in &graph[curr].neighbors {
            let check = node.1 + distances[curr];
            Node::get_shortest(node.0, &mut distances, check);
        }
    }

    print_distances(&distances);
}

fn print_distances(arr : &Vec<u32>) {
    println!("\nSHORTEST DISTANCES: ");
    for (idx, item) in arr.iter().enumerate() {
        println!("{}: {}", (idx as u8 +97) as char, *item);
    }
}