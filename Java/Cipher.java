import java.util.*;

public abstract class Cipher{
	public String encrypt(String s){
		StringBuffer result = new StringBuffer("");
		StringTokenizer words = new StringTokenizer(s);
		while(words.hasMoreTokens()){
			result.append(encode(words.nextToken())+" ");
		}
		return result.toString();
	}
	
	public String decrypt(String s){
		StringBuffer result = new StringBuffer("");
		StringTokenizer words =  new StringTokenizer(s);
		while(words.hasMoreTokens()){
			result.append(decode(words.nextToken())+" ");
		}
		return result.toString();
	}
	public abstract String encode(String word);
	
	public abstract String decode(String word);
}