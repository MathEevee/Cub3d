import random

WIDTH = 100
HEIGHT = 100

def generate_maze():
    maze = [['1' for _ in range(WIDTH)] for _ in range(HEIGHT)]
    
    def carve_passages_from(cx, cy, maze):
        stack = [(cx, cy)]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        while stack:
            (cx, cy) = stack[-1]
            random.shuffle(directions)
            carved = False
            for direction in directions:
                nx, ny = cx + direction[0] * 2, cy + direction[1] * 2
                if 1 <= nx < WIDTH-1 and 1 <= ny < HEIGHT-1 and maze[ny][nx] == '1':
                    maze[cy + direction[1]][cx + direction[0]] = '0'
                    maze[ny][nx] = '0'
                    stack.append((nx, ny))
                    carved = True
                    break
            if not carved:
                stack.pop()
    
    # Start carving from the top-left corner
    maze[1][1] = '0'
    carve_passages_from(1, 1, maze)
    
    # Place letter 'W'
    maze[1][1] = 'W'
    
    return maze

def write_maze_to_file(maze, filename):
    with open(filename, 'w') as file:
        file.write("NO ./wall_no.xpm\n")
        file.write("SO ./wall_so.xpm\n")
        file.write("WE ./wall_we.xpm\n")
        file.write("EA ./wall_ea.xpm\n")
        file.write("F 0,192,96\n")
        file.write("C 0,96,192\n\n")
        
        for row in maze:
            file.write(''.join(row) + '\n')

if __name__ == "__main__":
    maze = generate_maze()
    write_maze_to_file(maze, "map.cub")
