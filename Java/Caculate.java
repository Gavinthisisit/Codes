package gui;

public class Caculate{
	public String Muti_Caculate(double x){
		double area1;
		double area2;
		double area3;
		area1 = x*x;
		area2 = x*x*3.14;
		area3 = x*x*x;
		String s1 = "�߳�Ϊ"+x+"�������ε����Ϊ��"+area1;
		String s2 = "�뾶Ϊ"+x+"��Բ�����Ϊ��"+area2;
		String s3 = "�߳�Ϊ"+x+"������������Ϊ��"+area3;
		String s = s1+"\n"+s2+"\n"+s3;
		return s;
	}
	public String Muti_Caculate(double x,double y){
		double area1;
		double area2;
		area1 = x*y;
		String s = "���͸�Ϊ"+x+","+y+"�ĳ����ε����Ϊ��"+area1;
		return s;
	}
	public String Muti_Caculate(double x,double y,double z){
		double area1;
		area1 = x*y*z;
		String s = "�����Ϊ"+x+","+y+","+z+"�ĳ���������Ϊ��"+area1;
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