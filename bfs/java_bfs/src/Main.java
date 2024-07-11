//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {

    public static final boolean A_STAR = true;
    public static int ROWS = 20;
    public static int COLS = 20;


    public static void main(String[] args) {

        char[][] map = new char[ROWS][COLS];

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                map[i][j] = ' ';
            }
        }

        Pos start = new Pos(0, 0, null);
        start.g = 0;

        Pos goal = new Pos(ROWS - 1, COLS - 1, null);

        map[start.y][start.x] = 'S';
        map[goal.y][goal.x] = 'G';

        Map guiMap = new Map(map);

        AStar.a_star(map, start, goal, guiMap);

        guiMap.updateMap(map);
    }

    public static void printMap(char[][] map) {
        for (int i = 0; i < ROWS; i++) {
            System.out.print("|");
            for (int j = 0; j < COLS; j++) {
                System.out.print(map[i][j]);
            }
            System.out.print("|");
            System.out.println();
        }
        System.out.println();
    }

    public static void clear_map(char[][] map) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {

                map[i][j] = ' ';

            }
        }
    }

    public static void backtrack(char[][] map, Pos current) {
        current = current.last;
        while (current.last != null) {
            map[current.y][current.x] = '#';
            current = current.last;
        }
    }

    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
    }

    public static void restartAStar(Pos newGoal, char[][] map, Map guiMap) {
        clear_map(map);
        Pos start = new Pos(0, 0, null);

        map[0][0] = 'S';
        map[newGoal.y][newGoal.x] = 'G';
        System.out.println("Novo destino: " + newGoal.x + " " + newGoal.y);
        guiMap.updateMap(map);
        AStar.a_star(map, start, newGoal, guiMap);
        guiMap.updateMap(map);
    }
}

