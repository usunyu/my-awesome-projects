<%@ page language="java" contentType="text/html; charset=US-ASCII"
    pageEncoding="US-ASCII"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=US-ASCII">
<title>Insert title here</title>
</head>
<body>

<jsp:useBean id="user3" class="beans.User" scope="request"></jsp:useBean>

<jsp:setProperty name="user3" property="email" value="sun@usc.edu"/>
<jsp:setProperty name="user3" property="password" value="letmein"/>

<%-- <% response.sendRedirect("getrequestbean.jsp"); %> --%>
<jsp:forward page="getrequestbean.jsp"></jsp:forward>

</body>
</html>