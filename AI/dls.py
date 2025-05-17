def dls_2d():
    # Directions for movement (down, up, right, left)
    x_move = [1, -1, 0, 0]
    y_move = [0, 0, 1, -1]
    directions = 4
    
    # Initialize the graph/maze
    graph = [
        [0, 0, 1, 0, 1],
        [0, 1, 1, 1, 1],
        [0, 1, 0, 0, 1],
        [1, 1, 0, 1, 1],
        [1, 0, 0, 0, 1]
    ]
    N = len(graph)
    
    # Source and goal positions
    source_x, source_y = 0, 2
    goal_x, goal_y = 4, 4
    
    # Maximum depth limit for the search
    max_depth = 10  # You can adjust this value as needed
    
    # Global variables
    found = [False]  # Using list to make it mutable in nested function
    goal_depth = [999999]  # Using list to make it mutable in nested function
    
    def print_direction(m, x, y):
        if m == 0:
            print(f"Moving Down ({x}, {y})")
        elif m == 1:
            print(f"Moving Up ({x}, {y})")
        elif m == 2:
            print(f"Moving Right ({x}, {y})")
        else:
            print(f"Moving Left ({x}, {y})")
    
    def dls(x, y, depth, limit):
        # If depth exceeds limit, stop exploring this path
        if depth > limit:
            return
        
        # Make a copy of the graph to restore explored paths when backtracking
        current_state = graph[x][y]
        graph[x][y] = 0  # Mark current position as visited
        
        # Try all four directions
        for j in range(directions):
            v_x = x + x_move[j]
            v_y = y + y_move[j]
            
            # Check boundary conditions and if position is valid
            if (0 <= v_x < N) and (0 <= v_y < N) and graph[v_x][v_y] == 1:
                v_depth = depth + 1
                print_direction(j, v_x, v_y)
                
                # Check if goal is reached
                if v_x == goal_x and v_y == goal_y:
                    found[0] = True
                    goal_depth[0] = v_depth
                    return
                
                # Continue DLS with new position and current depth
                dls(v_x, v_y, v_depth, limit)
                
                # If goal found in this path, return
                if found[0]:
                    return
        
        # Backtrack: Restore the current position for other paths to explore
        graph[x][y] = current_state
    
    # Iterative deepening - try increasing depth limits
    for depth_limit in range(max_depth + 1):
        print(f"\nTrying with depth limit: {depth_limit}")
        
        # Make a fresh copy of the original graph for each depth limit
        original_graph = [row[:] for row in graph]
        
        # Start DLS from source position with current depth limit
        dls(source_x, source_y, 0, depth_limit)
        
        # Restore the original graph for the next iteration
        graph = [row[:] for row in original_graph]
        
        # If goal found, break out of the loop
        if found[0]:
            break
    
    # Print result
    if found[0]:
        print("\nGoal found")
        print(f"Number of moves required = {goal_depth[0]}")
        print(f"Solution found at depth limit: {depth_limit}")
    else:
        print("\nGoal can not be reached from starting block within the depth limit")

# Run the DLS algorithm
dls_2d()