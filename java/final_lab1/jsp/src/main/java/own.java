import java.sql.*;
import java.util.*;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

/**
 * Servlet implementation class own
 */
@WebServlet("/own")
public class own extends HttpServlet {
	private static final long serialVersionUID = 1L;
    public void service(HttpServletRequest req,HttpServletResponse res)
    {
    	try {
    		Class.forName("com.mysql.jdbc.Driver");
    		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/student","root","");
    		PreparedStatement pt= con.prepareStatement("Insert into student values(?,?,?)");
    		PrintWriter pw = res.getWriter();
    		res.setContentType("text/html");
    		String s1 = req.getParameter("name");
    		String s2 = req.getParameter("usn");
    		String s3 = req.getParameter("sem");
    		
    		pt.setString(1, s1);
    		pt.setString(2,s2);
    		pt.setString(3, s3);
    		int i=pt.executeUpdate();
    		
    		PreparedStatement pt1 = con.prepareStatement("Update student set name=? where name=?");
    		pt1.setString(1,"ud");
    		pt1.setString(2,"uday");
    		int lol=  pt1.executeUpdate();
    		
    		PreparedStatement pt2 = con.prepareStatement("Delete from student where name=?");
    		pt2.setString(1,"ud");
    		int lamao = pt2.executeUpdate();
    		Statement st = con.createStatement();
    		
    		String q = "select * from student";
    		
    		ResultSet rs = st.executeQuery(q);
    		while(rs.next())
    		{
    			String name = rs.getString(1);
    			String usn = rs.getString(2);
    			String sem = rs.getString(3);
    			pw.println(name+" "+usn+" "+sem);
    			pw.println("</br></br>");
    		}
    		
    		
    	}catch(Exception e)
    	{
    		System.out.println(e);
    	}
    }

}
