<%@ page language="java" contentType="text/html; charset=US-ASCII"
    pageEncoding="US-ASCII"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=US-ASCII">
<title>Insert title here</title>
</head>
<body>

<%/* directive tag */%>
<%@ page import="java.util.*" %>

<p/>

<%/* expression tag */%>
<%= new Date() %>

<p/>

<%/* declaration tag */%>
<%! public String info = "Some info here."; %>

<p/>

<%/* scriptlet tag */%>
<% for(int i = 0; i < 5; i++) { %>
This is looped.<p/>
<% } %>

</body>
</html>