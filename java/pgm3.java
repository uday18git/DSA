abstract class Shape
{
    String color;
    boolean filled;
    abstract double getArea();
    Shape()
    {
        color = "green";
        filled = true;

    }
    Shape(String color,boolean filled)
    {
        this.color = color;
        this.filled = filled;
    }
    void setColor(String color)
    {
        this.color=color;
    }
    void setFilled(boolean filled)
    {
        this.filled = filled;
    }
    boolean isFilled()
    {
        return filled;
    }
    String getColor()
    {
        return color;
    }
    public String toString()
    {
        return "A shape with color" + getColor() + isFilled();
    }
}
public class pgm3 {
    
}
