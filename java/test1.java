// import javax.naming.spi.ResolveResult;

abstract class Shape {
    String color;
    boolean filled;

    Shape(String c, boolean f) {
        color = c;
        filled = f;
    }

    Shape() {
        color = "Green";
        filled = true;
    }

    boolean isfilled() {
        return filled;
    }

    String getcolor() {
        return color;
    }

    void setFILLED(boolean b) {
        this.filled = b;
    }

    void setColor(String c) {
        this.color = c;
    }

    public String toString() {
        if(this.filled == false)
        {
            return "A shape of color "+ this.color + "is not filled";
        }
        else
        {
            return "A shape of color "+ this.color + "is filled";
        }
    }

}
class Circle extends Shape
{

}
final class Rectangle extends Shape
{

}

public class test1 {

}
