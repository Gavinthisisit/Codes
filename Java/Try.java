import java.awt.*;
import java.util.*;
public class Try{
	public Try(){}
	
	public void Out1(String s1,String s2){
		StringTokenizer sTokenizer = new StringTokenizer(s1,s2);
		while(sTokenizer.hasMoreTokens()){
			System.out.println(sTokenizer.nextToken()+"123");
		}
	//	System.out.println("\n");
	}

	public void Out2(String s1,String s2){
		StringTokenizer s = new StringTokenizer(s1,s2);
		while(s.hasMoreTokens()){
			System.out.print(s.nextToken()+" ");
		}
	//	System.out.println("\n");
	}	
	public static void main(String args[]){
		Try t = new Try();
		String url = "http://java.trincoll.edu/~jjj/index.html";
		t.Out1(url,":/.");
		String s = "this is it,how are you doing?";
		t.Out2(s," ,");
	}
}