<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%@ page import="java.util.ArrayList" %>
	<%
	int numbers[] = new int[11];
	ArrayList<Integer> duplicate = new ArrayList<>();
	double avg = 0.0;
	int sum=0,count=0,k=0;
	for(int i=0;i<11;i++)
	{
		numbers[i] = Integer.parseInt(request.getParameter("num"+(i+1)));
	}
	for(int i=0;i<11;i++)
	{
		sum += numbers[i];
	}
	avg = sum/11;
	out.println("<h2>Average: "+avg+"</h2><br>");
	for(int i=0;i<11;i++)
	{
		if(numbers[i]<avg)
		{
			count++;
		}
	}
	out.println("<h2>Below average count: "+count+"</h2><br>");
	for(int i=0;i<11;i++)
	{
		for(int j=i+1;j<11;j++)
		{
			if(numbers[i] == numbers[j])
			{
				if(!duplicate.contains(numbers[i]))
				{
					duplicate.add(numbers[i]);
				}
				break;
			}
				
		}
	}
	out.println("<h2>Duplicate elements:</h2><br>");
	for(int i=0;i<duplicate.size();i++)
	{
		out.println("<h3>"+duplicate.get(i)+"</h3>");
	}
	%>
</body>
</html>