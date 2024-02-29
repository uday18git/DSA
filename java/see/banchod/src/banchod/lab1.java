package banchod;
import java.sql.*;

public class lab1 {

    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/mydb";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "";

    public static void main(String[] args) {
        try {
            // Register JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Open a connection
            Connection connection = DriverManager.getConnection(JDBC_URL, USERNAME, PASSWORD);
            System.out.println("banchod");
            // Display details of all employees
            System.out.println("Details of all Employees:");
            String query = "SELECT * FROM student";
            try (Statement statement = connection.createStatement();
                 ResultSet rs = statement.executeQuery(query)) {
            	
                while (rs.next()) {
                    System.out.println("USN: "+ rs.getString(1) + "Name: " +  rs.getString(2) );
                }
            }
//
//            // Display details of employees working on "Web Development" project
//            System.out.println("\nDetails of Employees working on 'Web Development' project:");
//            displayEmployeesByProject(connection, "Web Development");

            // Close the connection
            connection.close();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

    
}
