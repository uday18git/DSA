package pgm1;
import java.sql.*;
// Database connection details
// class.forname
// step1 establish connection to database using conncetion driver manager
// step2 statement createStatement
public class second {
	public static void main(String args[])
	{
		String jdbcUrl = "jdbc:mysql://localhost:3306/mydb";
		String username = "root";
		String passwd = "";
		String driver = "com.mysql.jdbc.Driver";
		String query = "Select * from stud";
		try {
			Class.forName(driver);
			Connection connection = DriverManager.getConnection(jdbcUrl,username,passwd);
			Statement statement = connection.createStatement();
			ResultSet rs=statement.executeQuery(query); 
			while(rs.next())
			{
				System.out.println(rs.getInt("ID"))
			}
		}
	}
	
}
