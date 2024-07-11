import java.util.Objects;

public class Pos implements Comparable<Pos> {
    public int x;
    public int y;
    public Pos last;
    public int g;
    public int h;
    public int f;

    public Pos(int y, int x, Pos last) {
        this.x = x;
        this.y = y;
        this.last = last;
    }

    @Override
    public int compareTo(Pos other) {
        return Integer.compare(this.f, other.f);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pos pos = (Pos) o;
        return x == pos.x && y == pos.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
