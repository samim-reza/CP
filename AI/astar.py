import heapq
from collections import defaultdict

def astar_all_paths(start, goal, graph, h):
    """
    A* algorithm that finds all possible paths from start to goal and returns them sorted by cost.
    
    Args:
        start: Starting node
        goal: Goal node
        graph: Dictionary of node -> [(neighbor, cost), ...]
        h: Dictionary of node -> heuristic value
        
    Returns:
        A list of tuples (path, cost) sorted by cost
    """
    if start not in graph or goal not in graph:
        return []  # Invalid input
    
    # Priority queue: (f, g, node, path)
    pq = [(h.get(start, 0), 0, start, [start])]
    
    # Store all complete paths
    all_paths = []
    
    # Track visited nodes and their costs to avoid cycles
    # For finding all paths, we need to be careful about cycle detection
    visited = {}  # node -> best cost so far
    
    while pq:
        f, g, current, path = heapq.heappop(pq)
        
        # Check if we've reached the goal
        if current == goal:
            all_paths.append((path, g))
            continue
        
        # Skip if we've seen this node with a better cost
        if current in visited and visited[current] < g:
            continue
            
        # Mark the current node as visited with its current cost
        visited[current] = g
        
        # Explore neighbors
        for neighbor, cost in graph.get(current, []):
            # Avoid cycles in the path
            if neighbor in path:
                continue
                
            new_g = g + cost
            new_f = new_g + h.get(neighbor, 0)
            new_path = path + [neighbor]
            
            heapq.heappush(pq, (new_f, new_g, neighbor, new_path))
    
    # Sort paths by cost
    all_paths.sort(key=lambda x: x[1])
    return all_paths

def find_optimal_path(start, goal, graph, h):
    """
    Standard A* implementation to find the optimal path
    """
    if start not in graph or goal not in graph:
        return None, float('inf')
        
    pq = []  # priority queue: (f = g + h, g, node, path)
    heapq.heappush(pq, (h.get(start, 0), 0, start, [start]))
    best_g = {start: 0}
    
    while pq:
        f, g, current, path = heapq.heappop(pq)
        
        if current == goal:
            return path, g
            
        for neighbor, cost in graph.get(current, []):
            g2 = g + cost
            if g2 < best_g.get(neighbor, float('inf')):
                best_g[neighbor] = g2
                f2 = g2 + h.get(neighbor, 0)
                heapq.heappush(pq, (f2, g2, neighbor, path + [neighbor]))
                
    return None, float('inf')  # no path found

# Define the graph based on the image
graph = {
    'A': [('B', 2), ('C', 3)],
    'B': [('D', 4)],
    'C': [('F', 2)],
    'D': [('G', 2)],
    'E': [('G', 3), ('H', 4)],
    'F': [('H', 3)],
    'G': [('I', 2)],
    'H': [('I', 2)],
    'I': [('J', 1)],
    'J': []
}

# Heuristic values from the image
h = {
    'A': 7,
    'B': 6,
    'C': 6,
    'D': 5,
    'E': 4,
    'F': 5,
    'G': 3,
    'H': 2,
    'I': 1,
    'J': 0
}

# Find all paths and the optimal path
start_node = 'A'
goal_node = 'J'

# Get all paths
all_paths = astar_all_paths(start_node, goal_node, graph, h)

# Find the optimal path
optimal_path, optimal_cost = find_optimal_path(start_node, goal_node, graph, h)

# Print results
print(f"All paths from {start_node} to {goal_node}:")
for i, (path, cost) in enumerate(all_paths, 1):
    path_str = " -> ".join(path)
    print(f"Path {i}: {path_str} (Cost: {cost})")

print("\nOptimal path:")
if optimal_path:
    print(f"{' -> '.join(optimal_path)} (Cost: {optimal_cost})")
else:
    print("No path found!")