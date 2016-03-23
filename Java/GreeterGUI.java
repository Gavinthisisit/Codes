import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GreeterGUI extends JFrame implements ActionListener
{
	private Greeter greeter;
	private JTextField inField;
	private JTextArea dispaly;
	private	JButton goButton;
	
	public GreeterGUI(String title)
	{
		greeter = new Greeter();
		buildGUI();
		setTitle(title);
		pack();
		setVisiblr(true);
	}
	
	private void buildGUI()
	{
		Container contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());
		inField = new JTextField(10);
		dispaly = new JTextArea(10,30);
		goButton = new JButton("Click here for a greeting!");
		JPanel inputPanel = new JPanel();
		inputPanel.add(new JLabel("Input your name here:"));
		inputPanel.add(inField);
		inputPanel.add(goButton);
		contentPane.add("Crener",display);
		contentPane.add("South",inputPanel);
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()== goButton)
		{
			String name = inField.getText();
			display.append(greeter.greet(name)+"\n");
		}
	}
	
}