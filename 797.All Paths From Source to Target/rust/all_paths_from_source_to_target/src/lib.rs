pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {


	let mut paths = Vec::with_capacity(graph.len());
	let mut path = Vec::with_capacity(graph.len());

	path.push(0);

	find_N(0,&mut path,&mut paths,&graph);

	return paths;
}

pub	fn find_N(poient:i32,mut path:&mut Vec<i32>,mut paths:&mut Vec<Vec<i32>>,graph:&Vec<Vec<i32>>){
		if poient == (graph.len()-1)  as i32 {
			paths.push(path.clone());
		}
        else {
                for next in &graph[poient as usize]{
                    path.push(*next);
                    find_N(*next,&mut path,&mut paths,& graph);
                    path.pop();
			}
		}
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let graph: Vec<Vec<i32>> = vec![vec![1,2],vec![3],vec![3],vec![]];
        let ret = all_paths_source_target(graph);
        assert_eq!(ret, vec![[0,1,3],[0,2,3]]);
    }
}
