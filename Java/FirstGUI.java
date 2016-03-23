import javax.swing.JFrame;

 class FirstGUI extends JFrame
{

	public FirstGUI(String title)
	{
		setSize(200,150);
		setLocation(100,150);
		setTitle(title);
		setVisible(true);
	}
	
	public static void main(String args[])
	{
		new FirstGUI("My Firdt GUI!");
	}
}