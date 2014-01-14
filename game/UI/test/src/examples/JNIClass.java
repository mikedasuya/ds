package examples;


public class JNIClass {    
    public native String nativeFoo();    

    static {
        System.loadLibrary("foo");
    }        

    public int[][] getComputerMove() {
    	int [][] ar = null;
    	return ar;
    
    }
}