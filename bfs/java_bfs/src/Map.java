import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;

public class Map extends JFrame {

    private final int squareSize = 50;
    BufferedImage mapImage;

    public Map(char[][] map) {

        int frameWidth = Main.COLS * squareSize;
        int frameHeight = Main.ROWS * squareSize;
        this.setSize(frameWidth, frameHeight);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.mapImage = convert_to_buffered_image(map);

        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(java.awt.Graphics g) {
                super.paintComponent(g);
                g.drawImage(mapImage, 0, 0, null);
            }
        };

        // Dentro do construtor da classe Map
        this.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                int col = e.getX() / squareSize;
                int row = e.getY() / squareSize;
                Pos newGoal = new Pos(row, col, null);
                Main.restartAStar(newGoal, map, Map.this);
            }
        });

        add(panel);

        setVisible(true);
    }

    public void updateMap(char[][] newMap) {
        this.mapImage = convert_to_buffered_image(newMap);
        repaint();
    }

    private BufferedImage convert_to_buffered_image(char[][] map) {
        BufferedImage image = new BufferedImage(Main.COLS * squareSize, Main.ROWS * squareSize, BufferedImage.TYPE_INT_RGB);
        Graphics2D g2d = image.createGraphics();

        for (int i = 0; i < Main.ROWS; i++) {
            for (int j = 0; j < Main.COLS; j++) {
                char valor = map[i][j];
                switch (valor) {
                    case '+':
                        g2d.setColor(Color.GREEN);
                        break;
                    case 'S':
                        g2d.setColor(Color.BLUE);
                        break;
                    case 'G':
                        g2d.setColor(Color.RED);
                        break;
                    case '#':
                        g2d.setColor(Color.YELLOW);
                        break;
                    default:
                        g2d.setColor(Color.WHITE);
                        break;
                }
                g2d.fillRect(j * squareSize, i * squareSize, squareSize, squareSize);
            }
        }
        return image;
    }


}

