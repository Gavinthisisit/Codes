import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Converter extends JFrame implements ActionListener,KeyPadClient{
	private JLabel prompt = new JLabel("Distance in miles: ");
	private JTextField input = new JTextField(6);
	private JTextArea display = new JTextArea(10,20);
	private JButton convert = new JButton("Convert!");
	private KeyPad keypad = new KeyPad(this);
	private JPanel panel1 = new JPanel();
	
	public Converter(){
		getContentPane().setLayout(new BorderLayout());	
		JPanel panel1 = new JPanel();
		panel1.add(prompt);
		panel1.add(input);
//		getContentPane().add(prompt);
		getContentPane().add(panel1,"North");
		JPanel contrlPane = new JPanel(new BorderLayout(0,0)); 
		contrlPane.add(keypad,"Center");
		contrlPane.add(convert,"South");
		getContentPane().add(contrlPane,"East");
//		getContentPane().add(convert);
		getContentPane().add(display,"Center");
//		getContentPane().add(keypad);
//		panel1.add(keypad);
		display.setLineWrap(true);
		display.setEditable(false);
		convert.addActionListener(this);
		input.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e){
		double miles = Double.valueOf(input.getText()).doubleValue();
		double km = MetricConverter.milesToKm(miles);
		display.setText("");
		display.append(miles+"miles equals "+km+" kilometers\n");
	}
	public void KeypressCallback(String s){
		if(s.equals("C"))
			input.setText("");
		else 
			input.setText(input.getText()+s);
	}
	public static void main(String args[]){
		Converter f = new Converter();
		f.setSize(400,300);
		f.setVisible(true);
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
}