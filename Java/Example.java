import java.io.*;

public class Example{
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	public void doRead()throws IOException{
		String inputString = input.readLine();
		System.out.print(inputString);
	}
	public static void main(String args[]) throws IOException{
		Example ex = new Example();
		ex.doRead();
	}
}