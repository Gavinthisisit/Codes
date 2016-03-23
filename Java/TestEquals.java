import java.awt.*;

public class TestEquals
{
	static Button b1 = new Button("a");
	static Button b2 = new Button("b");
	static Button b3 = b2;
	
	private static void isEqual(Object o1,Object o2){
		
		if(o2.equals(o2))
			System.out.println(o1.toString()+"equals"+o2.toString());
		else
			System.out.println(o1.toString()+"does not equals"+o2.toString());
	}
	private static void isIdentical(Object o1,Object o2){
		
		if(o1 == o2)
			System.out.println(o1.toString()+"is identical to "+o2.toString());
		else 
			System.out.println(o1.toString()+"is not identical to "+o2.toString());
	}
	
	public static void main(String args[]){
		isEqual(b1,b2);
		isEqual(b1,b3);
		isEqual(b2,b3);
		
		isIdentical(b1,b2);
		isIdentical(b1,b3);
		isIdentical(b2,b3);
	}
}