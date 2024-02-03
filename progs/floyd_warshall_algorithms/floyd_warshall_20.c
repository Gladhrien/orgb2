#include <stdio.h>

#define V 20 // Number of vertices in the graph
#define INF 1e7 // A large value representing infinity in floating-point

// Function to print the shortest distance matrix
// void printSolution(float dist[][V]);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall(float graph[][V]) {
    float dist[V][V];
    int i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

// /* A utility function to print solution */
// void printSolution(float dist[][V]) {
//     printf("The following matrix shows the shortest distances"
//            " between every pair of vertices \n");
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             if (dist[i][j] == INF)
//                 printf("%7s", "INF");
//             else
//                 printf("%7.2f", dist[i][j]);
//         }
//         printf("\n");
//     }
// }

// Driver program to test the above function
int main() {
    /* Example graph with floating-point weights */
    float graph[V][V] = { {0.00, 2.03, 1.42, 5.38, 6.30, INF, 4.99, 1.43, 6.83, INF, 4.94, 6.01, 6.76, INF, 9.96, 8.60, 8.22, 4.58, 7.07, 4.70},
                          {6.16, 0.00, INF, INF, INF, INF, 9.37, 5.94, 4.55, 2.05, 3.56, 1.65, INF, INF, 1.52, 2.72, 2.35, 5.69, 9.29, 3.53},
                          {1.53, 9.98, 0.00, INF, 5.54, 9.53, INF, 6.58, 1.31, INF, INF, 9.19, 6.07, INF, 1.34, 5.07, 1.96, 8.08, 9.57, 4.44},
                          {2.99, 2.84, 6.49, 0.00, 9.48, 2.28, 8.79, INF, 2.61, 8.92, 5.29, 8.04, 2.15, 9.83, 5.95, 5.69, 7.07, 1.64, 4.00, 2.89},
                          {4.30, INF, 7.62, 3.65, 0.00, 7.25, 2.64, 7.78, 9.11, 2.95, 1.67, 7.19, INF, 5.99, 2.34, 1.20, INF, 3.58, INF, 2.46},
                          {4.21, 5.71, 6.96, 8.85, 4.11, 0.00, 9.78, 6.45, INF, 2.82, 1.70, INF, 3.36, 8.87, 3.15, INF, 1.02, 1.57, 2.58, 7.78},
                          {9.59, 6.99, 7.66, 3.00, 8.95, INF, 0.00, 3.64, 8.33, 2.90, 7.99, 4.14, 3.45, 6.52, 3.21, 7.58, INF, INF, 1.10, 7.94},
                          {2.07, 3.39, 2.08, 5.84, 4.90, 3.72, 7.74, 0.00, 4.83, 4.34, INF, 7.94, 4.40, 5.65, INF, 6.43, 6.62, INF, 8.30, 5.88},
                          {6.86, INF, 6.59, INF, INF, 7.74, 1.93, 4.80, 0.00, 1.35, 3.42, INF, 3.60, 3.01, INF, 7.51, INF, 1.73, INF, 3.89},
                          {2.45, 3.98, 1.70, 9.82, 3.66, 5.34, 3.87, 7.95, 2.58, 0.00, 1.20, 9.96, 7.13, 2.23, 3.80, 1.86, 6.72, 6.30, 2.77, INF},
                          {6.34, 2.28, INF, 8.18, 1.11, 1.15, 7.39, 3.30, 7.57, 9.52, 0.00, 5.15, 9.73, 4.97, 8.37, INF, 6.52, 1.15, 7.41, 2.52},
                          {9.38, 8.92, 7.11, 1.78, INF, 6.70, 1.82, 6.65, 6.90, 7.38, 3.31, 0.00, 3.78, 4.60, INF, INF, 1.11, INF, INF, 1.08},
                          {1.47, 1.41, 9.26, 1.62, INF, 2.81, 4.06, 5.62, 5.29, 5.27, 3.25, 7.38, 0.00, 6.30, INF, INF, INF, INF, INF, 9.70},
                          {INF, INF, INF, INF, 7.45, 8.54, 3.15, 8.70, 7.76, INF, 8.71, 6.53, 6.91, 0.00, 7.71, 6.69, 1.83, 9.62, 2.50, 9.69},
                          {5.06, INF, 8.53, INF, INF, 1.96, 4.60, 7.68, 6.20, 5.83, 2.77, 7.00, 7.13, 2.34, 0.00, 6.25, 4.97, 5.83, 6.95, 5.00},
                          {1.14, 7.83, 8.02, 6.04, INF, 8.53, INF, 8.07, INF, 9.77, 2.67, 7.40, 9.60, 5.51, 8.28, 0.00, 7.29, 8.20, INF, 2.83},
                          {7.45, 8.45, 3.92, 4.72, 2.09, 3.72, 9.12, INF, INF, INF, 9.85, 6.57, INF, 4.65, INF, INF, 0.00, INF, 3.70, 8.07},
                          {INF, 8.40, 2.04, 5.64, 1.42, 3.31, 9.79, 2.00, INF, 4.43, 1.04, 3.41, 7.26, 8.14, 4.45, 2.44, 6.56, 0.00, 7.43, 1.31},
                          {3.47, 2.15, INF, 7.26, 5.31, 5.99, 3.24, 2.19, 5.05, 1.30, INF, 1.18, 2.19, INF, INF, INF, 7.56, 1.60, 0.00, 5.30},
                          {1.98, 9.22, INF, INF, 2.77, 8.86, INF, 5.27, 6.46, 8.07, 6.33, 1.05, INF, 5.08, 4.01, 8.99, 4.86, INF, 4.41, 0.00} };
    // Print the solution
    floydWarshall(graph);

    return 0;
}
