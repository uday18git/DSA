package lab1;




import java.sql.*;
public class twoa {
	public static void main(String args[])throws Exception
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3310/department","root","");
		Statement stmt = con.createStatement();
		ResultSet rs;
		PreparedStatement ps = con.prepareStatement("insert into dep values(?,?,?,?,?)");
		ps.setInt(1, 2);
		ps.setString(2, "ECE");
		ps.setInt(3, 1999);
		ps.setString(4, "Rahul");
		ps.setInt(5, 45);
		int i = ps.executeUpdate();
		System.out.println(i+" row(s) added");
		rs = stmt.executeQuery("select * from dep");
		while(rs.next())
		{
			System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getInt(3)+" "+rs.getString(4)+" "+rs.getInt(5));
		}
		con.close();
	}
}