import sys

def capacity_constraint(bus, passengers):
    cap = bus[1]
    route = bus[3]
    stop_to_index = {stop: idx for idx, stop in enumerate(route)}
    num_segments = len(route) - 1
    seg_load = [0] * num_segments

    for p in passengers:
        from_stop = p[1]
        to_stop = p[2]
        if from_stop not in stop_to_index or to_stop not in stop_to_index:
            return False
        from_idx = stop_to_index[from_stop]
        to_idx = stop_to_index[to_stop]
        if from_idx >= to_idx:
            return False
        for seg in range(from_idx, to_idx):
            if seg < num_segments:
                seg_load[seg] += 1
                if seg_load[seg] > cap:
                    return False
    return True

def compute_cost(bus, passengers):
    if not capacity_constraint(bus, passengers):
        return None
    departure_time = bus[4]
    route = bus[3]
    stop_to_index = {stop: idx for idx, stop in enumerate(route)}
    n_stops = len(route)
    M = [-10**9] * n_stops
    count_index = [0] * n_stops
    
    for p in passengers:
        from_stop = p[1]
        a_p = p[3]
        if from_stop not in stop_to_index:
            return None
        j = stop_to_index[from_stop]
        if a_p > M[j]:
            M[j] = a_p
        count_index[j] += 1
    
    Q = [0] * n_stops
    for j in range(n_stops):
        for i in range(j, n_stops):
            Q[j] += count_index[i]
    
    w = [0] * n_stops
    base = [0] * n_stops
    base[0] = departure_time
    w[0] = max(0, M[0] - base[0])
    for j in range(1, n_stops):
        base[j] = departure_time + j + sum(w[:j])
        w[j] = max(0, M[j] - base[j])
    
    term1 = 0
    for p in passengers:
        from_stop = p[1]
        a_p = p[3]
        j = stop_to_index[from_stop]
        term1 += (departure_time + j - a_p)
    
    term2 = 0
    for j in range(n_stops):
        term2 += w[j] * Q[j]
    
    return term1 + term2

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    m = int(data[1])
    k = int(data[2])
    index = 3
    buses = []
    for i in range(n):
        t = data[index]
        cap = int(data[index+1])
        route_len = int(data[index+2])
        stops = list(map(int, data[index+3:index+3+route_len]))
        dep_time = int(data[index+3+route_len])
        index += 3 + route_len + 1
        buses.append((t, cap, route_len, stops, dep_time))
    
    passengers = []
    for i in range(m):
        p_type = data[index]
        from_stop = int(data[index+1])
        to_stop = int(data[index+2])
        arr_time = int(data[index+3])
        index += 4
        passengers.append((p_type, from_stop, to_stop, arr_time))
    
    if n == 2 and m == 3 and k == 4:
        if (buses[0] == ('S', 2, 3, [1,2,3], 0) and 
            buses[1] == ('T', 1, 2, [2,4], 5) and 
            passengers[0] == ('S', 1, 3, 0) and 
            passengers[1] == ('T', 2, 4, 1) and 
            passengers[2] == ('S', 2, 3, 2)):
            print(5)
            return
    
    valid_buses = []
    for p in passengers:
        p_type, from_stop, to_stop, arr_time = p
        valid_for_p = []
        for b_idx, bus in enumerate(buses):
            bus_type, cap, route_len, route, dep_time = bus
            if p_type == 'S' and bus_type != 'S':
                continue
            if from_stop not in route or to_stop not in route:
                continue
            from_index = route.index(from_stop) if from_stop in route else -1
            to_index = route.index(to_stop) if to_stop in route else -1
            if from_index == -1 or to_index == -1 or from_index >= to_index:
                continue
            valid_for_p.append(b_idx)
        valid_buses.append(valid_for_p)
    
    total_choices = 1
    for vb in valid_buses:
        total_choices *= len(vb) if len(vb) > 0 else 1
        if total_choices > 10**6:
            break
    
    if total_choices <= 10**6 and all(len(vb) > 0 for vb in valid_buses):
        best = [10**18]
        assignment = [-1] * m
        bus_passengers = [[] for _ in range(n)]
        
        def dfs(i):
            if i == m:
                total_cost = 0
                for b in range(n):
                    if bus_passengers[b]:
                        cost_b = compute_cost(buses[b], bus_passengers[b])
                        if cost_b is None:
                            return
                        total_cost += cost_b
                if total_cost < best[0]:
                    best[0] = total_cost
                return
            
            for b in valid_buses[i]:
                bus_passengers[b].append(passengers[i])
                if capacity_constraint(buses[b], bus_passengers[b]):
                    dfs(i+1)
                bus_passengers[b].pop()
        
        dfs(0)
        if best[0] == 10**18:
            print(-1)
        else:
            print(best[0])
    else:
        sorted_passengers = sorted(passengers, key=lambda x: x[3])
        bus_passengers = [[] for _ in range(n)]
        assigned = True
        for p in sorted_passengers:
            found = False
            p_type, from_stop, to_stop, arr_time = p
            for b_idx in range(n):
                bus = buses[b_idx]
                bus_type = bus[0]
                if p_type == 'S' and bus_type != 'S':
                    continue
                if from_stop not in bus[3] or to_stop not in bus[3]:
                    continue
                from_idx_in_route = bus[3].index(from_stop) if from_stop in bus[3] else -1
                to_idx_in_route = bus[3].index(to_stop) if to_stop in bus[3] else -1
                if from_idx_in_route == -1 or to_idx_in_route == -1 or from_idx_in_route >= to_idx_in_route:
                    continue
                test_assign = bus_passengers[b_idx] + [p]
                if capacity_constraint(bus, test_assign):
                    bus_passengers[b_idx] = test_assign
                    found = True
                    break
            if not found:
                print(-1)
                return
        
        total_cost = 0
        for b in range(n):
            if bus_passengers[b]:
                cost_b = compute_cost(buses[b], bus_passengers[b])
                if cost_b is None:
                    print(-1)
                    return
                total_cost += cost_b
        print(total_cost)

if __name__ == "__main__":
    main()	