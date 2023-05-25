use std::io;

/// vertex, weight
pub struct Node{
    pub neighbors : Vec<(usize, u32)>   
}

impl Node {
    pub fn get_shortest(idx : usize, distances : &mut Vec<u32>, check : u32) {
        if distances[idx] > check{
            distances[idx] = check;
        }
    }
    fn new(neighbors : Vec<(usize,u32)>) -> Self {
        Self {
            neighbors
        }
    }
}

pub fn init_graph(sz : usize) -> Vec<Node> {
    let mut graph : Vec<Node> = Vec::new();

    println!("[PUT (a|0) FOR LAST UNCONNECTED NODE]\n");

    for idx in 97..sz+97{
        graph.push(get_vertex(idx as u8));
    }

    graph
}

fn get_vertex(idx : u8) -> Node {
    let mut temp = String::new();

    println!("NODE {} // Input space-separated (connecting vertex|edge weight) :", idx as char);
    io::stdin()
        .read_line(&mut temp)
        .expect("Failed to read");

    let temp = temp.trim()
        .split(" ")
        .map(|x| {
            let temp = &x[1..x.len()-1].split("|").collect::<Vec<_>>();
            let v : char = match temp[0].parse() {
                Ok(x) => x,
                Err(_) => 'a',
            };
            let v = (v as u8 - 97) as usize;
            let e : u32 = match temp[1].parse() {
                Ok(x) => x,
                Err(_) => u32::MAX
            };
            
            (v,e)
        });

    let mut result : Vec<(usize, u32)> = Vec::new();
    for i in temp {
        result.push(i);
    }

    Node::new(result)
}