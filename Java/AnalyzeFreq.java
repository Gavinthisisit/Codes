  class LetterFreq{
	private char letter;
	private int freq;
	
	public LetterFreq(char ch,int fre){
		letter = ch;
		freq = fre;
	}
	public char getLetter(){
		return letter;
	}
	public int getFreq(){
		return freq;
	}
	public void incFreq(){
		freq++;
	}
}
public class AnalyzeFreq{
	private LetterFreq[] freqArr;
	public AnalyzeFreq(){
		freqArr = new LetterFreq[26];
		for(int k=0;k<26;k++)
			freqArr[k] = new LetterFreq((char)('A'+k),0);
	}
	public void counterLetter(String str){
		char let;
		str = str.toUpperCase();
		for(int k=0;k<str.length();k++){
			let = str.charAt(k);
			if((let>='A')&&(let<='Z'))
				freqArr[let-'A'].incFreq();
		}
	}
	public void printArry(){
		for(int k=0;k<26;k++){
			System.out.print("letter: "+freqArr[k].getLetter());
			System.out.println("freq: "+freqArr[k].getFreq());
		}
	}
	public static void main(String args[]){
		AnalyzeFreq af = new AnalyzeFreq();
		af.counterLetter("Now is the time for all good student"+"to study computer related topics.");
		af.printArry();
	}
}