import java.rmi.StubNotFoundException;

class Person
{
    private String name;
    private String address;
    Person(String name,String address)
    {
        this.name = name;
        this.address = address;
    }
    String getName()
    {
        return name;
    }
    String getAddress()
    {
        return address;
    }
    void setAddress(String address)
    {
        this.address = address;
    }
    public String toString()
    {
        return  name + " (" +address +")";
    }
}
class Student extends Person{
    int numCourses =0;
    String courses[] = new String[30];
    int grades[] = new int[30];
    Student(String name,String address)
    {
        super(name, address);
    }
    void addCourseGrade(String course,int grade)
    {
        if(numCourses<=29)
        {
            courses[numCourses]=course;
            grades[numCourses]=grade;
            numCourses++;

        }
        else
        {
            System.out.println("Max courses reached");
        }
    }
    void printGrades()
    {
        for(int i=0;i<numCourses;i++)
        {
            System.out.println("course : "+ courses[i]+"grades: "+grades[i]);
        }
    }
    double getAverageGrades()
    {
        double d=0;
        for(int i=0;i<numCourses;i++)
        {
            d+=grades[i];
        }
        d/=numCourses;
        return d;
    }
    public String toString()
    {
        return getName() + "("+ getAddress()+")";
    }
}
class Teacher extends Person
{
    int numCourses=0;
    String courses[] = new String[5];
    Teacher(String name,String address)
    {
        super(name,address);
    }
    boolean addCourse(String course)
    {
        if(numCourses<=4)
        {
            for(int i=0;i<numCourses;i++)
            {
                if(courses[i].equals(course))
                    return false;
            }
            courses[numCourses] = course;
            numCourses++;
            return true;
        }
        else
        {
            return false;
        }
    }
    boolean removeCourse(String course)
    {
        if(numCourses!=0)
        {
            for(int i=0;i<numCourses;i++)
            {
                if(courses[i].equals(course))
                {
                    courses[i] = "";
                    return true;
                }
                else return false;
            }
        }
        return false;
    }
    public String toString()
    {
        return getName() + "(" + getAddress() + ")";
    }


}
public class pgm8 {
    public static void main(String[] args) {
        Student s = new Student("raju", "Banglore");
        System.out.println(s);
        s.addCourseGrade("maths", -100);
        s.addCourseGrade("english", -2000);
    }
}
