BFS(Graph G, Start_Vertex S) {
	mark S as explored
	Let Q = queue data structure initialised with S
	
	while(Q is not empty) {
		remove the first node of Q, call it v;
		
		for each edge(v,w) {
			if(w is unexplored) {
				mark w as explored
				add w to Q
			}
		}
	}
}
