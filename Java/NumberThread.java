
public class NumberThread extends Thread{
	int num;
	
	public NumberThread(int n){
		num = n;
		setPriority(n);
	}
	
	public void run(){
		for(int i=0;i<10;i++)
			System.out.print(num);
	}
}