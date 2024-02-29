import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.*;
import java.io.PrintWriter;
import javax.servlet.http.Cookie;

/**
 * Servlet implementation class See2
 */
@WebServlet("/eightb")
public class eightb extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public eightb() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		PrintWriter out=res.getWriter();
		res.setContentType("text/html");
		Cookie c1=new Cookie("c1","1");
		c1.setMaxAge(60);
		res.addCookie(c1);
		Cookie c2=new Cookie("c2","2");
		c2.setMaxAge(60);
		res.addCookie(c2);
		Cookie c3=new Cookie("c3","3");
		//c1.setMaxAge(60);
		res.addCookie(c3);
		Cookie c4=new Cookie("c4","4");
		//c1.setMaxAge(60);
		res.addCookie(c4);
		
		Cookie[] cookies=req.getCookies();
		for(Cookie cookie:cookies) {
			out.print("<p><b>"+cookie.getName()+"  "+cookie.getValue()+"</b></p>");
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}