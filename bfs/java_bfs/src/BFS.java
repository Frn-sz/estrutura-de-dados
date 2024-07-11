import java.util.LinkedList;

public class BFS {

    private static final int ROWS = Main.ROWS;
    private static final int COLS = Main.COLS;


    public static void bfs(char[][] map, Pos start, Pos goal) {

        LinkedList<Pos> open = new LinkedList<Pos>();

        open.add(start);

        while (!open.isEmpty()) {
            Pos current = open.pop();

            Main.clearScreen();
            Main.printMap(map);

            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }

            if (current.x == goal.x && current.y == goal.y) {
                System.out.println("Destino encontrado!");
                Main.clear_map(map);
                Main.backtrack(map, current);
                return;
            }


            if (current.y > 0 && (map[current.y - 1][current.x] == ' ' || map[current.y - 1][current.x] == 'G')) {
                Pos dummy = new Pos(current.y - 1, current.x, current);
                check_lists(map, open, dummy);
            }

            if (current.y < ROWS - 1 && (map[current.y + 1][current.x] == ' ' || map[current.y + 1][current.x] == 'G')) {
                Pos dummy = new Pos(current.y + 1, current.x, current);
                check_lists(map, open, dummy);
            }

            if (current.x > 0 && (map[current.y][current.x - 1] == ' ' || map[current.y][current.x - 1] == 'G')) {
                Pos dummy = new Pos(current.y, current.x - 1, current);
                check_lists(map, open, dummy);
            }

            if (current.x < COLS - 1 && (map[current.y][current.x + 1] == ' ' || map[current.y][current.x + 1] == 'G')) {
                Pos dummy = new Pos(current.y, current.x + 1, current);
                check_lists(map, open, dummy);
            }
        }
    }

    public static void check_lists(char[][] map, LinkedList<Pos> open, Pos current) {
        map[current.y][current.x] = '+';
        open.add(current);
    }


}
