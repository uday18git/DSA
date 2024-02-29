package lab1;
import java.sql.*;
public class lab1 {
	public static void main(String[] args)
	{
		Connection conn = null;
		Statement stmt = null;
		ResultSet rs = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb","root","");
			stmt = conn.createStatement();
			rs = stmt.executeQuery("Select * from emp where project='web'");
			while(rs.next())
			{
				System.out.println("ID: "+rs.getString(1)+ " fname: "+rs.getString(2)+ "lname:"+rs.getString(3)+"project:" + rs.getString(4)+rs.getInt(5));
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
