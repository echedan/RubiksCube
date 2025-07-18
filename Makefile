solver: main.o Cube.o Solver_AStar.o Solver_BFS.o 

main.o: main.cpp
	gcc src/main.cpp

Cube.o: Cube.cpp
	gcc src/Cube.cpp

Solver_AStar.o: Solver_AStar.cpp
	gcc src/Solver_AStar.cpp

Solver_BFS.o: Solver_BFS.cpp
	gcc src/Solver_BFS.cpp

clean:
	rm main.o Cube.o Solver_AStar.o Solver_BFS.o solver
