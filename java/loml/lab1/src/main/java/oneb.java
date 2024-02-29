

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class oneb
 */
@WebServlet("/oneb")
public class oneb extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public oneb() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
//		response.getWriter().append("Served at: ").append(request.getContextPath());
		PrintWriter out = response.getWriter();
		String ename = request.getParameter("ename");
		int hours = Integer.parseInt(request.getParameter("hours"));
		int payrate = Integer.parseInt(request.getParameter("payrate"));
		int tax = Integer.parseInt(request.getParameter("tax"));
		double tot_pay = payrate*hours;
		double gross_pay = tot_pay - tot_pay*tax/100;
		out.println("<html><title>Payroll Statement</title><body>Employee Name: "+ename+"<br>");
		out.println("Hours Worked: "+hours+"<br>");
		out.println("Pay Rate: "+payrate+"<br>");
		out.println("Tax: "+tax+"<br>");
		out.println("Total Pay: "+tot_pay+"<br>");
		out.println("Gross Pay: "+gross_pay+"<br>");
		out.println("</body></html>");
		out.close();
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
