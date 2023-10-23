abstract class Student {
    String name;
    int id;
    int age;
    double grade;

    abstract Boolean isPassed(double grade);
}

final class Undergrad extends Student {
    Boolean isPassed(double grade) {
        if (grade > 70) {
            return true;
        } else {
            return false;
        }
    }
}

final class Grad extends Student {
    Boolean isPassed(double grade) {
        if (grade > 80) {
            return true;
        } else {
            return false;
        }
    }
}

public class test2 {

}
