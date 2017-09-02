from collections import deque

def dfs(graph, pre, start, end, visited, step=0):
    if (start == end):
        return step
   
    l = len(graph) 
    visited[start] = True

    for i in xrange(l):
        if graph[start][i] == 1 and visited[i] == False and i != pre:
            result = dfs(graph, start, i, end, visited, step+1)
            if (result > 0):
                return (result)
            visited[i] = False
    return 0 

def find_cycle(graph, node):
    l = len(graph)
    visited = [False] * l
    for n in xrange(l):
        if n != node and graph[n][node] == 1:
            r = dfs(graph, node, n, node, visited)
            if (r > 0):
                return r + 1
    return 0
   
def flip(i):
    return 1-i
     
def is_2_colorable(graph):
    l = len(graph)
    colors  = [-1] * l # no color yet
    queue = deque([])
    queue.append(0)

    color = 0
    colors[0] = color   # 0 is black
    
    while (len(queue) > 0):
        ele = queue.popleft() 

        for n in graph[ele]:
            if colors[n] != -1:
                if colors[n] != flip(color):
                    return False
            else:
                colors[n] = flip(color)
                queue.append(n)
        color = flip(color)

    return True

g = dict()
g[0] = [5] 
g[1] = [5,6]
g[2] = [7,8]
g[3] = [6]
g[4] = [5,8]
g[5] = [0,4,8]
g[6] = [1, 3]
g[7] = [2]
g[8] = [2,4,5]
print is_2_colorable(g)

            
    
