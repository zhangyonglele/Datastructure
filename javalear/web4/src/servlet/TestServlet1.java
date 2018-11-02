package servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class TestServlet1 extends HttpServlet {
    public TestServlet1(){
        System.out.println("TestServlet1构造方法被执行");
    }

    @Override
    public void destroy() {
        System.out.println("TestServlet1销毁方法被执行");
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        PrintWriter out = resp.getWriter();
        out.println("<h1>Hello Servlet个鬼啊</h2>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req,resp);      //把doPost方法与doGet方法同化
    }

    @Override
    public void init() throws ServletException {
        System.out.println("TestServlet1初始化方法被执行");
    }
}
