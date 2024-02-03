import numpy as np
import random

V = 20  # Number of vertices in the graph
INF = "INF"

def randFloat(fMin, fMax):
    return random.uniform(fMin, fMax)

def generateRandomGraph(vertices, fMin, fMax):
    graph = np.full((vertices, vertices), INF, dtype=object)
    for i in range(vertices):
        for j in range(vertices):
            if i == j:
                graph[i][j] = 0.0  # Distance to itself is 0
            else:
                randWeight = randFloat(fMin, fMax)
                # Randomly decide whether to have an edge between i and j
                graph[i][j] = randWeight if random.randint(1, 5) > 1 else INF  # 20% chance of no direct path
    return graph

# Generate a random graph with weights between 1.0 and 10.0
graph = generateRandomGraph(V, 1.0, 10.0)

# Format the graph as a C-style initialization string
graph_str = "float graph[V][V] = { "
graph_str += ",\n                          ".join("{" + ", ".join(f"{weight:.2f}" if weight != INF else 'INF' for weight in row) + "}" for row in graph)
graph_str += " };"

# Specify the filename
filename = f"floyd_warshall_{V}.txt"

# Write the string to a file
with open(filename, 'w') as file:
    file.write(graph_str)

print(f"Array saved to {filename}")
