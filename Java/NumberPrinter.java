
public class NumberPrinter implements Runnable{
	int num;
	public NumberPrinter(int n){
		num = n;
	}
	public void run(){
		for(int k=0;k<10;k++)
			System.out.print(num);
	}
}