import java.util.*;
public class VectorDemo{
	public static void printVector(Vector v){
		for(int k=0;k<v.size();k++)
			System.out.print(v.elementAt(k).toString()+" ");
		System.out.println();
	}
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		System.out.println("Input the length of the array:");
		int bound = input.nextInt();
		Vector vector = new Vector();
//		int bound = (int)(Math.random()*20);
		int num; 
		for(int k=0;k<bound;k++){
			num =(int)(Math.random()*100);
			vector.addElement(new Integer(num));
			}
		printVector(vector);
	}
}