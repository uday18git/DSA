import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/cook")
public class cook extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public cook() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PrintWriter out = response.getWriter();
		response.setContentType("text/html");
		Cookie cookie1 = new Cookie("cookie1","1");
		cookie1.setMaxAge(10);
		Cookie cookie2 = new Cookie("cookie2","2");
		cookie2.setMaxAge(10);
		Cookie cookie3 = new Cookie("cookie3","3");
		Cookie cookie4 = new Cookie("cookie4","4");
		response.addCookie(cookie1);
		response.addCookie(cookie2);
		response.addCookie(cookie3);
		response.addCookie(cookie4);
		Cookie[] cookies = request.getCookies();
		for(int i=0;i<cookies.length;i++)
		{
			out.println("<br/>"+cookies[i].getName());
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
