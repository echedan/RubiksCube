solver: main.o Cube.o Solver_AStar.o Solver_BFS.o 
	g++ main.o Cube.o Solver_AStar.o Solver_BFS.o -o solver
main.o: src/main.cpp include/Headers.h include/Cube.h include/Utilities.h include/Solver.h
	g++ -c src/main.cpp

Cube.o: src/Cube.cpp include/Headers.h include/Cube.h 
	g++ -c src/Cube.cpp

Solver_AStar.o: src/Solver_AStar.cpp
	g++ -c src/Solver_AStar.cpp

Solver_BFS.o: src/Solver_BFS.cpp
	g++ -c src/Solver_BFS.cpp

clean:
	rm main.o Cube.o Solver_AStar.o Solver_BFS.o 