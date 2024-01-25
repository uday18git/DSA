import java.sql.*;
import java.util.*;
import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/servlet_jdbc")
public class servlet_jdbc extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	public void service(HttpServletRequest req,HttpServletResponse res)throws ServletException, IOException{
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/bro","root","");
			PreparedStatement pt = con.prepareStatement("Insert into stdu1 values(?,?,?)");
			
			PrintWriter pw = res.getWriter();
			res.setContentType("text/html");
			String s1 = req.getParameter("name");
			String s2 = req.getParameter("usn");
			String s3 = req.getParameter("sec");
			
			pt.setString(1, s1);
			pt.setString(2, s2);
			pt.setString(3, s3);
			
			int i=pt.executeUpdate();
			
			try {
			PreparedStatement pt1= con.prepareStatement("update stdu1 set name=? where name=?");
			pt1.setString(1,"uday");
			pt1.setString(2,"good boy");
			
			int bb =pt1.executeUpdate();
			
			}
			catch(Exception e) {
				System.out.println(e);
			}
			
			PreparedStatement pt2= con.prepareStatement("delete from stdu1 where name=?");
			pt2.setString(1, "uday");
			
			boolean b1=pt2.execute();
			
			Statement stmt = con.createStatement();
			String q = "select * from stdu1";
			
			ResultSet rs = stmt.executeQuery(q);
			while(rs.next()) {
				String name = rs.getString(1);
				String usn = rs.getString(2);
				String sec=rs.getString(3);
				pw.println(name+" "+usn+" "+sec);
				pw.println("<br/><br/>");

			}
			
//			res.sendRedirect("/update")
		}
		catch(ClassNotFoundException e)
		{
			System.out.println(e);
		}
		catch(SQLException e)
		{
			System.out.println(e);
			
			
		}
		catch(Exception e)
		{
			System.out.println();
		}
		
		
	

}}