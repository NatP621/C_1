# Compilation flags to control the warnings and debugging information
COMPILE_OPTS = -Wall -g
# Compiler to use for building the project
GCC = gcc

# Dependencies for the graph-related targets
GRAPH_DEPS = my_graph.o my_mat.o
# Dependencies for the knapsack-related target
KNAPSACK_DEPS = my_Knapsack.o

# The 'all' target builds all the executables
all: my_graph my_Knapsack

# Build the graph executable
my_graph: $(GRAPH_DEPS)
	$(GCC) $(COMPILE_OPTS) -o my_graph $(GRAPH_DEPS)

# Build the knapsack executable
my_Knapsack: $(KNAPSACK_DEPS)
	$(GCC) $(COMPILE_OPTS) -o my_Knapsack $(KNAPSACK_DEPS)

# Compile the matrix object file
my_mat.o: my_mat.c my_mat.h
	$(GCC) $(COMPILE_OPTS) -c my_mat.c

# Compile the knapsack object file
my_Knapsack.o: my_Knapsack.c
	$(GCC) $(COMPILE_OPTS) -c my_Knapsack.c

# Compile the graph object file
my_graph.o: my_graph.c my_mat.h
	$(GCC) $(COMPILE_OPTS) -c my_graph.c

# Clean up the build directory
clean:
	rm -f *.o my_Knapsack my_graph

# Mark 'clean' and 'all' as phony targets
.PHONY: clean all