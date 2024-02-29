import java.sql.*;

public class sevena {
	public static void main(String args[])
	{
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb","root","");
			Statement stmt = con.createStatement();
			String q = "Select * from emp where salary>2000";
			ResultSet rs = stmt.executeQuery(q);
			while(rs.next())
			{
				System.out.println("Id: "+rs.getString(1)+ " fname: "+rs.getString(2)+ " lname : "
			+rs.getString(3)+" project: "+rs.getString(4)+"salary: "+rs.getInt(5));
			}
			
	}catch(Exception e)
		{
			System.out.println(e);
		}
}
}
