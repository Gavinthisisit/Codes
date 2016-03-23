public abstract class TwoPlayGame{
	public static final int PLAYER_ONE = 1;
	public static final int PLAYER_TWO = 2;
	
	protected boolean onePlaysNext = true;
	protected int nComputer = 0;
	
	protected IPlayer computer1,computer2;
	public void setPlay(int stater){
		if(stater == PLAYER_TWO)
			onePlaysNext = false;
		else
			onePlaysNext = true;
		
	}
	public int getPlayer(){
		if(onePlaysNext)
			return PLAYER_ONE;
		else
			return PLAYER_TWO;
	}
	public void changePlayer(){
		onePlaysNext = !onePlaysNext;
	}
	
	public int getNComputers(){\
		return nComputers;
	}
	
	public String getRules(){
		return "The rules of this game are:";
	}
	public void addComputerPlayer(IPlayer player){
		if(nComputers == 0)
			computer2 = player;
		else if(nComputers == 1)
			computer1 = player;
		else 
			return;
		++nComputers;
	}
	
	public abstract boolean gameOver();
	public abstract String getWiinner();
}