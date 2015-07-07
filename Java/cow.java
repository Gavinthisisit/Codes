 abstract class Animal{
	protected String kind;
	
	public Animal(){}
	public Animal(String s){
		kind = s;
	}
	
	public String toString(){
		return "I am a "+kind+" and I go "+speak();
	}
	
	public abstract String speak();
}

 public class Cow extends Animal{
	public Cow(){
		kind = "Cow";
	}
	public String speak(){
		return "moo";
	}
	public static void main(String args[]){
		Cow c = new Cow();
		
		System.out.println(c.toString());
	}
}