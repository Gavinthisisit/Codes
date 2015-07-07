public class OneRowNim extends TwoPlayerGame implements CLUIPlayableGame{
	public static final int MAX_PICKUP = 3;
	public static final int MAX_STICKS = 11;
	private int nSticks = MAX_STICKS;
	
	public OneRowNim(){}
	
	public OneRowNim(int sticks){
		nSticks = sticks;
	}
	public OneRowNim(int sticks,int starter){
		nSticks = sticks;
		setPlayer(starter);
	}
	public boolean takeSticks(int num){
		if(num < 1||num > MAX_PICKUP || num> nSticks)
			return false;
		else{
			nSticks = nSticks - num;
			return true;
		}
	}
	
	public int getSticks(){
		return nSticks;
	}
	public String getRules(){
		return \n***The Rules of One Row Nim ***\n"+
		"(1) Anumber of sticks between 7 and "+MAX_STICKS+"is chosen.\n";
	}
	public boolean gameOver(){
		return (nSticks <= 0);
	}
	public String getWinner(){
		if(gameOver())
			return ""+getPlayer()+"Nice game.";
		return "The game is over yet.";
	}
	public String getGamePrompt(){
		return "\nYou can pick up between 1 and "+Math.min(MAX_PICKUP,nSticks)+" : ";
	}
	public String reportGameState(){
		if(!gameOver())
			return ("\nSticks left: "+getSticks()+"Who's turn : Player "+getPlayer());
		else{
			return return ("\nSticks left: "+getSticks()+"Game Over! The winner is Player "+getWinner()+"\n");
		}
		public void play(UserInterfaec ui){
			int sticks = 0;
			ui.report(getRules());
			if(computer1 != null)
				ui.report("\nPlayer 1 is a "+compter1.toString());
			else 
				ui.report("\nPlayer 2 is a "+computer2.toString());
			while(!gameOver()){
				IPlayer computer = null;
				ui.report(repotGameState());
				switch(getPlayer()){
					case PLAYER_ONE:	
						computer = computer1;
						break;
					case PLAYER_TWO:
						computer = computer2;
						break;
					break;
				}
				if(computer != null){
					sticks = Integer.parseInt(computer.makeAMove(""));
					ui.report(computer.toString()+" takes "+sticks+" sticks.\n");
				}
				else{
					ui.prompt(getGamePrompt());
					sticks = Integer.parseInt(ui.getUserInput());
				}
				if(takeSticks(sticks))
					changePlayer();
			}
			ui.report(reportGameState());
		}
	}
}






