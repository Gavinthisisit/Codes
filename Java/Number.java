
public class Number{
	public static void main(String args[]){
		NumberThread n1,n2,n3,n4,n5;
/*		n1 = new Thread(new NumberPrinter(1));
		n1.setPriority(1);
		n1.start();
		
		n2 = new Thread(new NumberPrinter(2));
		n2.setPriority(1);
		n2.start();
		
		n3 = new Thread(new NumberPrinter(3));
		n3.setPriority(1);
		n3.start();
		
		n4 = new Thread(new NumberPrinter(4));
		n4.setPriority(1);
		n4.start();
		
		n5 = new Thread(new NumberPrinter(5));
		n5.setPriority(1);
		n5.start();*/
		
		n1 = new NumberThread(1);
		n1.start();
		
		n2 = new NumberThread(2);
		n2.start();
		
		n3 = new NumberThread(3);
		n3.start();
		
		n4 = new NumberThread(4);
		n4.start();
		
		n5 = new NumberThread(5);
		n5.start();
		System.out.println("\n");
		int t = n4.getPriority();
		System.out.println("this is:"+t);
	}
}