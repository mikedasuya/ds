package examples;
import java.sql.*;

    public class Example {
      public static void main( String[] args ) {
        System.out.println("Hello, Java!");
        String str = "test";
        char[] arr = str.toCharArray();
        int i = 0,j = str.length()-1; 
        while (i < j) {
        	char ch = str.charAt(j);
        	arr[j] = arr[i];
        	arr[i] = ch;
        	i++;
        	j--;
        	if (i > j) {
        		break;
        	}
        	     	
        }
        String strReverse = new String(arr);
        System.out.println(strReverse);
        doJDBC();
      }
      
      static void doJDBC() {
    	  final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    	  final String DB_URL = "jdbc:mysql://localhost/locationdb";

      //  Database credentials
    	  final String USER = "newuser";
    	  final String PASS = "password";
          Connection conn = null;
          Statement stmt = null;
          try {
         //STEP 2: Register JDBC driver
         Class.forName("com.mysql.jdbc.Driver");

         //STEP 3: Open a connection
         System.out.println("Connecting to a selected database...");
         conn = DriverManager.getConnection(DB_URL, USER, PASS);
         System.out.println("Connected database successfully...");
         
         //STEP 4: Execute a query
         System.out.println("Creating statement...");
         stmt = conn.createStatement();

         String sql = "INSERT into location values ('test', 'test1', 'test2')";
         int rs = stmt.executeUpdate(sql);
         //STEP 5: Extract data from result set
       
      }catch(SQLException se){
         //Handle errors for JDBC
         se.printStackTrace();
      }catch(Exception e){
         //Handle errors for Class.forName
         e.printStackTrace();
      }finally{
         //finally block used to close resources
         try{
            if(stmt!=null)
               conn.close();
         }catch(SQLException se){
         }// do nothing
         try{
            if(conn!=null)
               conn.close();
         }catch(SQLException se){
            se.printStackTrace();
         }//end finally try
      }//end try
      System.out.println("Goodbye!");
      }
      
    }