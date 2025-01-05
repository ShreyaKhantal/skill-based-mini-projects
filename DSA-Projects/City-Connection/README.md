# Graph-Based City Connection System

This is a simple Command Line Interface (CLI) program in C++ that represents a graph-based model for managing cities and their connections. It allows you to create a map of cities, add paths (edges) between cities, add new cities (vertices), and check if there is a connection between two cities using BFS (Breadth-First Search) algorithm.

## Features

1. **Create a Map**: Allows you to create a graph with a specified number of cities (vertices) and their names.
2. **Add Path (Undirected Edge)**: Add a connection (path) between two existing cities (nodes).
3. **Add New City (Vertex)**: Add a new city to the graph.
4. **Display the Graph**: Display the adjacency matrix representing the graph.
5. **Check Connection Between Cities**: Use BFS to check if there's a path from a source city to a destination city.

## How to Run

### Prerequisites:
- A C++ compiler (e.g., g++).
- C++11 or later.

### Compilation:
1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/graph-city-connection.git
    ```

2. Navigate to the project directory:
    ```bash
    cd graph-city-connection
    ```

3. Compile the code:
    ```bash
    g++ main.cpp -o city_connection
    ```

### Running the Program:
Run the compiled program:
```bash
./city_connection
