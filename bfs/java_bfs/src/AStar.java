import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

public class AStar {

    public static final int ROWS = Main.ROWS;
    public static final int COLS = Main.COLS;

    public static void a_star(char[][] map, Pos start, Pos goal, Map guiMap) {

        PriorityQueue<Pos> open = new PriorityQueue<Pos>();
        Set<Pos> closed = new HashSet<Pos>();

        open.add(start);

        while (!open.isEmpty()) {
            Pos current = open.poll();

            clearScreen();


            if (current.equals(goal)) {
                System.out.println("Destino encontrado!");
                Main.clear_map(map);
                Main.backtrack(map, current);
                return;
            }

            closed.add(current);

            explore_neighbours(map, goal, open, closed, current, guiMap);
        }
    }

    private static void explore_neighbours(char[][] map, Pos goal, PriorityQueue<Pos> open, Set<Pos> closed, Pos current, Map guiMap) {
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int[] dir : directions) {
            Pos adj = new Pos(current.y + dir[0], current.x + dir[1], current);
            if (isValidPosition(map, adj) && !closed.contains(adj)) {
                guiMap.updateMap(map);

                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    System.out.println(e.getMessage());
                }
                calc_cost(map, goal, open, current, adj);
            }
        }
    }

    private static boolean isValidPosition(char[][] map, Pos pos) {
        return pos.y >= 0 && pos.y < ROWS && pos.x >= 0 && pos.x < COLS && (map[pos.y][pos.x] == ' ' || map[pos.y][pos.x] == 'G');
    }

    private static void calc_cost(char[][] map, Pos goal, PriorityQueue<Pos> open, Pos current, Pos dummy) {
        if (!open.contains(dummy)) {
            dummy.g = current.g + 1;
            dummy.h = Main.A_STAR ? Math.abs(goal.x - dummy.x) + Math.abs(goal.y - dummy.y) : 0;
            dummy.f = dummy.g + dummy.h;
            check_lists(map, open, dummy);
        }
    }

    public static void check_lists(char[][] map, PriorityQueue<Pos> open, Pos current) {
        map[current.y][current.x] = '+';
        open.add(current);
    }


    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
