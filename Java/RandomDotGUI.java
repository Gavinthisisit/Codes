
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class RandomDotGUI extends JFrame implements ActionListener{
	public final int NDOTS = 10000;
	private Dotty dotty;
	private JPanel controls = new JPanel();
	private JPanel canvas = new JPanel();
	private JButton draw = new JButton("Draw");
	private JButton clear = new JButton("Clear");
	public RandomDotGUI(){
		getContentPane().setLayout(new BorderLayout());
		draw.addActionListener(this);
		clear.addActionListener(this);
		controls.add(draw);
		controls.add(clear);
		canvas.setBorder(BorderFactory.createTitledBorder("Drawing Canvas"));
		getContentPane().add("North",controls);
		getContentPane().add("Center",canvas);
		getContentPane().setSize(400,400);
	}
	public void actionPerformed(ActionEvent evt){
		if(evt.getSource() == draw){
			dotty = new Dotty(canvas,NDOTS);
			Thread dottyThread = new Thread(dotty);
			dottyThread.start();
		}else{
			dotty.clear();
		}
	}
	public static void main(String args[]){
		RandomDotGUI gui = new RandomDotGUI();
		gui.setSize(400,400);
		gui.setVisible(true);
		gui.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}

}