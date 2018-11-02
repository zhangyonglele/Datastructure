import JDBC.JDBC;

import java.sql.ResultSet;

public class Test {
    public static void main(String[] args){
        JDBC.init();
        ResultSet rs = JDBC.selectData("SELECT * FROM manager WHERE id='1'");
        System.out.println(rs);
    }
}
