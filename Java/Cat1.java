 interface Speakable{
	public String speak();
}

 class Animal{
	protected String kind;
	public Animal(){}
	public String toString(){
		return "I am a "+kind+" and I can go "+((Speakable)this).speak();
	}
}

public class Cat1 extends Animal implements Speakable{
	public Cat1(){
		kind = "Cat";
	}
	public String speak(){
		return "mwow";
	}
	public static void main(String args[]){
		Cat1 cat  = new Cat1();
		System.out.println(cat.toString());
	}	
}