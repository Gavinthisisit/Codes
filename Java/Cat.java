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

 class Cat extends Animal{
	public Cat(){
		super("Cat");
	}
	public String speak(){
		return "maio";
	}
	public static void main(String args[]){
		Cat c = new Cat();
		
		System.out.println(c.toString());
	}
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