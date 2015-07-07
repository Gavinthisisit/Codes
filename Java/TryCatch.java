//TryCach.java

public class TryCatch{
	public static void main(String args[]){
		int i,j;
		try{
			i = Integer.parseInt(args[0]);
			j = Integer.parseInt(args[1]);
			int iResult = i/j;
			System.out.println("you want to count ["+i+"/"+j+"]:");
			System.out.println("the result is:"+iResult);
		}
		catch(ArrayIndexOutOfBoundsException err){
			System.out.println("please input two parameter,such as:java TryCatch 20 5");
		}
		catch(NumberFormatException err){
			System.out.println("the parameters must are number:");
		}
		catch(ArithmeticException err){
			System.out.println("the second parameter can not be 0!");
		}
	}
}