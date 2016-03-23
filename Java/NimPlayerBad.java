public class NimPlayerBad implements IPlayer{
	private OneRowNim game;
	
	public NimPlayerBad(OneRowNim game){
		this.game = game;
	}
	public String makeAMove(String prompt){
		return ""+randomMove();
	}
	private int randomMove(){
		int sticksLeft = game.getSticks();
		return 1+(int)(Math.random()*Math.min(sticksLeft,game.MAX_PICKUP));
	}
	public String toString(){
		String className = this.getClass().toString();
		return className.substring(5);
	}
	public static void main(String args[]){
		KeyboardReader kb = new KeyboardReader();
		OneRowNim game = new OneRowNim();
		kb.prompt("How many computers are playing,0,1,or 2?");
		int m = kb.getKeyboardInteger();
		for(int k=0;k<m;k++){
			kb.prompt("What type of playre,NimPlayerBad = 1,or NimPlayer = 2?");
		}
		int choice = kb.getKeyboardInteger();
		if(choice == 1){
			IPlayer computer = new NimPlayerBad(game);
			game.addComputerPlayer(computer);
		}
		else{
			IPlayer computer = new NimPlayer(game);
			game.addComputerPlayer(computr);
		}
	}
	game.paly(kb);
}