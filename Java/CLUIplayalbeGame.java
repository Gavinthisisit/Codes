public interface CLUIPlayableGame extends IGame{
	public abstract void play(UserInterface ui);
}
public interface IGame{
	public String getGamePrompt();
	public String reportGameState();
}

public interface UserInterface {
	public String getUserInput(String s);
	public void report(String s);
	public void prompt(String s);
	
}
public interface IPlayer{
	public String makeAMove(String prompt);
}