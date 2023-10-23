// java is a programming language and a runtime environment
// we are talking about java runtime environment
// java fx is a library for creating rich client applications , java ee is a library for creating web applications used to highly scalable enterprise applications , java me is a library for creating mobile applications (iot) heavily based on jre , all these technologies comes from oracle 
// android uses java as a programming language but not jre , it uses dalvi 
// nice
public class intro {
    public static void main(String args[])
    {
        System.out.println("Hello World");
        Thread t = Thread.currentThread();
        System.out.println(t);
        t.setName("myThread");
        System.out.println(t);
    }
}
