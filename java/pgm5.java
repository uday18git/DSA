//make constructors for all the classes modify regularprice only
// in subclass constructors call super class constructor
class Car {
    int speed;
    double regularPrice;
    String color;

    Car(int speed, double regularPrice, String color) {
        this.speed = speed;
        this.regularPrice = regularPrice;
        this.color = color;
    }

    double getSalePrice() {
        return regularPrice;
    }
}

class Truck extends Car {
    int weight;

    Truck(int s, double price, String c, int w) {
        super(s, price, c);
        weight = w;
    }

    double getSalePrice() {
        if (weight > 2000) {
            regularPrice = regularPrice * 0.9;
            return regularPrice;
        } else {
            regularPrice = regularPrice * 0.8;
            return regularPrice;
        }
    }
}

class Ford extends Car {
    int year;
    double manufacturerDiscount;
    Ford(int s,double price,String c,int m)
    {
        super(s,price,c);
        manufacturerDiscount = m;
    }
    double getSalePrice()
    {
        regularPrice-=manufacturerDiscount;
        return regularPrice;
    }

}
class Sedan extends Car
{
    int length;
    Sedan(int s,double price,String c,int l)
    {
        super(s,price,c);
        length = l;
    }
    double getSalePrice()
    {
        if(length>20)
        {
            return regularPrice*0.95;
        }
        else
        {
            return regularPrice*0.90;
        }
    }
}

public class pgm5 {

}
