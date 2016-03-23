public class Word{
	private String word;
	
	public Word(String s){
		word = s;
	}
	public void printReverse(){
		String x;
		if(word.length()>0){
			x = word.substring(1);
//			printReverse();
			System.out.print(word+" "+x);
		}
		
	}
	public static void main(String args[]){
		Word w = new Word("hello");
		w.printReverse();
	}
}