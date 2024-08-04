public class course3 {
    public static void main(String[] args) {
        String s1 = "abc";
        //ALL STRING CLASS METHODS
        System.out.println(s1.length());
        System.out.println(s1.charAt(1));
        System.out.println(s1.indexOf('a'));//only returns the first occurance of the char
        System.out.println(s1.contains("a")); 
        String s4 = s1.toLowerCase();
        String s8 = s1.toUpperCase();
        String s5 = "I love programming. programming is awesome";
        String s6 = s5.replace("programming", "Java");
        System.out.println(s6);
        String s7 = s5.substring(4);
        System.out.println(s7);
        String s2 = "abc";//stored in the same string pool
        String s3 = new String("abc");//stored seperately in heap memory
        // s1!=s3 , s1==s2.....
        if(s1.equals(s3))
        {
            System.out.println("equal");
        }
    }
}
