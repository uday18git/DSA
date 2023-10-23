package java 8 fundamentals;
// stream is an ordered sequence of data
// provides a common i/o model
// abstracts details of underlying source or destination
// stream are unidirectional
// they are either byte streams or text streams
// interact as unicode characters
// each stream is used to read from or write to
// read from a stream
// for binary data use inputstream ->  int read() method
// for text data use reader class -> int read() method

// reading one byte at a time

InputStream input  = // create input stream
int intVal;
while((intval == input.read())>=0)// .read() returns -1 if end of stream is reached and returns the next byte if not
{
    byte byteVal = (byte) intVal; //typecasting to byte
    // there are also functions that read multiple bytes at a time
    // int read(byte[] b) -> notice this also returns an int , it returns the number of characters that were read

}

// reading array of bytes
InputStream input = // create input stream
int length;
byte[] byteBuff = new byte[10];
while((length = input.read(byteBuff))>=0)
{
    for(int i=0;i<length;i++)
    {
        byte byteVal = byteBuff[i];
        // do something with byteVal
    }
}

// reading one character at a time

Reader reader = // 
int intVal;
while((intVal = reader.read())>=0)
{
    char charVal = (char) intVal; //typecasting to char
    // do something with charVal
}

// reading array of characters

Reader reader = // create reader
int length;
char[] charBuff = new char[10];
while((length = reader.read(charBuff))>=0)
{
    for(int i=0;i<length;i++)
    {
        char charVal = charBuff[i];
        // do something with charVal
    }
}


// writing to a stream
// a bit ambiguous than read methods.. ambigous meaning does not have a single meaning
// void write(int b) it accepts a bit as the read function returns a int

// Writing bytes

OutputStream output = // create output stream

byte byteVal = 100;
output.write(byteVal);
byte[] byteBuff = {0,63,127};
output.write(byteBuff);

// Writing characters

// Writer allows us to write a single character , array of characters , or a string
// void write(int ch)
// void write(char[] buff)
// void write(String str)

Writer writer = // create writer
char charVal = 'a';
writer.write(charVal);

char[] charBuff = {'a','b','c'};
writer.write(charVal);

String stringVal = "Hello World";
writer.write(stringVal);


// common i/o stream derived classes
// input stream and output stream are base classes and abstract classes 
// there are number of classes that derive from these classes and provide concrete implementations
// input stream -
// ByteArrayInputStream
// PipedInputStream -> works well for producer consumer model
// FileInputStream

// output stream -
// ByteArrayOutputStream
// PipedOutputStream
// FileOutputStream

// Reader and Writer are also abstract classes

// Reader -
// CharArrayReader
// StringReader
// PipedReader
// InputStreamReader -> filereader

// Writer -
// CharArrayWriter
// StringWriter
// PipedWriter
// OutputStreamWriter -> filewriter


// Stream realities
// realities of working with streams
// error handling
// cleaning up streams -> streams are backed by physical storage , often exisiting outside the jvm , runtime may not reliably clean up
// providing realiable cleanup -> Streams implement the Closeable interface , which defines a close() method
Reader reader;
try {
    reader = // 
    // do something with reader
}catch(IDException e)
{
    // handle excpetion
}finally{
    reader.close(); //isnt quite as simple ,  what happens if when opening a reader comes exception , then reader is null and we cannot call close on it
    if(reader!=null)
        reader.close(); // for this also a trycatch is needed
}
// automating cleanup
// Autoclosable interface
// 1 method: close
// Base interface of closable interface
//provides support for try with resources
interface AutoClosable{
    void close() throws Exception;
}
interface Closeable extends AutoCloseable{
    void close() throws IOException;
}


// Try with resources
// Automates cleanup of 1 or more resoures
// a resources is any type that implements autoclosable
// syntax similar to traditional try catch
// optionally includes catch blocks
// handle try body
// handle close method call
