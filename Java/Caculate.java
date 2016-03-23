package gui;

public class Caculate{
	public String Muti_Caculate(double x){
		double area1;
		double area2;
		double area3;
		area1 = x*x;
		area2 = x*x*3.14;
		area3 = x*x*x;
		String s1 = "边长为"+x+"的正方形的面积为："+area1;
		String s2 = "半径为"+x+"的圆的面积为："+area2;
		String s3 = "边长为"+x+"的正方体的体积为："+area3;
		String s = s1+"\n"+s2+"\n"+s3;
		return s;
	}
	public String Muti_Caculate(double x,double y){
		double area1;
		double area2;
		area1 = x*y;
		String s = "长和高为"+x+","+y+"的长方形的面积为："+area1;
		return s;
	}
	public String Muti_Caculate(double x,double y,double z){
		double area1;
		area1 = x*y*z;
		String s = "长宽高为"+x+","+y+","+z+"的长方体的体积为："+area1;
		return s;
	}
	public static void main(String args[]){
		Caculate ca = new Caculate();
		String ss;
		ss = ca.Muti_Caculate(2.0);
		System.out.println(ss);
		ss = ca.Muti_Caculate(4.0,5.0);
		System.out.println(ss);
		ss = ca.Muti_Caculate(2.0,4.0,5.0);
		System.out.println(ss);
	} 
}