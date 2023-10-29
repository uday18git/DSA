package lab1;
import java.sql.*;
public class pgm2 {
	public static void main(String args[])
	{
		System.out.println("MySQL connect example");
		Connection conn = null;
		String url = "jdbc:mysql://localhost:3306/";
		String dbName = "empdb";
		String driver = "com.mysql.jdbc.Driver";
		String userName = "root";
		String password = "";
		String f1,f2,f3,f4;
		try
		{
			Class.forName(driver);
			conn = DriverManager.getConnection(url+dbName,userName,password);
			String query = "Select * FROM stud";
			System.out.println("Connected to the database");
			Statement stmt = conn.createStatement();
			
		}
	}
}
