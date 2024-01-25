<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%@page import="java.sql.*"%>
	
<%
try{
		String s1,s2,s3;
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/student","root","");
		PreparedStatement ps=con.prepareStatement("select * from student where name=?");
		s1=request.getParameter("name");
		ps.setString(1,s1);
		ResultSet rs=ps.executeQuery();
		out.println("<table border:2px solid black>");
		out.println("<tr><th>name</th><th>usn</th><th>sec</th><tr>");
		while (rs.next())
		{
			out.println("<tr><td>"+rs.getString(1)+"</td><td>"+rs.getString(2)+"</td><td>"+rs.getString(3)+"</td></tr>");
		}
		con.close();
		
}
catch(SQLException e) {
	  out.println("SQLException: " + e.getMessage() + "<BR>");
	  while((e = e.getNextException()) != null)
	     out.println(e.getMessage() + "<BR>");
	  }
	catch(ClassNotFoundException e) {
	  out.println("ClassNotFoundException: " + e.getMessage() + "<BR>");
	  }
catch(Exception e ){
	e.printStackTrace();
}

%>
</body>	
</html>