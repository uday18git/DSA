import java.io.IOException;
import java.io.Reader;
public class Main {
    public static void main(String[] args) {
        doMyCatchFinally();
        // doTryWithResources();
    }
    public static void doMyCatchFinally(){
        char[] buff = new char[8];
        int length;
        Reader reader = null;
        try{
            reader = Helper.openReader("file1.txt");
            while((length = reader.read(buff))>=0){
                System.out.println("\nlength: "+length);
                for(int i=0;i<length;i++)
                    System.out.print(buff[i]);
            }
        }catch(IOException e){
            System.out.println("Exception: "+e.getClass().getSimpleName()+" Message: "+e.getMessage());
    }finally{
        try{
            if(reader!=null)
                reader.close();
        }catch(IOException e2)
        {
            System.out.println("Exception: "+e2.getClass().getSimpleName()+" Message: "+e2.getMessage());
        }
    }
    }
    public static void doTryWithResources(){
        char[] buff = new char[8];
        int length;
        // Reader reader = null;
        try(Reader reader = Helper.openReader("file1.txt")){
            while((length = reader.read(buff))>=0){
                System.out.println("\nlength: "+length);
                for(int i=0;i<length;i++)
                    System.out.print(buff[i]);
            }
        }catch(IOException e){
            System.out.println("Exception: "+e.getClass().getSimpleName()+" Message: "+e.getMessage());
        }
    }    
}

