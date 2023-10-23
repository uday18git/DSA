import java.util.*;
//*abstact class student */
abstract class Student
{
    private String Name;
    int ID;
    double grade;
    int age;
    abstract boolean isPassed(double grade);
    final void setter(String name)
    {
        Name = name;
    }
    String getter()
    {
        return Name;
    }

}
class Undergrad extends Student
{
    void getData()
    {
        Scanner sc  = new Scanner(System.in);
        System.out.println("Enter name,id,age");
        setter(sc.next()); //************//
        ID = sc.nextInt();
        age = sc.nextInt();
        
    }
    boolean isPassed(double Grade)
    {
        grade = Grade;
        if(grade>70)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        System.out.println("Name"+getter()+"\nAge"+age+"\nID:"+ID);
    }
}
class Grad extends Student
{
    void getData()
    {
        Scanner sc = new Scanner(System.in);
        setter(sc.next());
        age = sc.nextInt();
        ID= sc.nextInt();
    }
}
public class pgm4 {
    //normal main function create instanace of classes and demonstrate ispassed 
    // u.display() also give;
}
