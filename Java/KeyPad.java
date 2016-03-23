
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KeyPad extends JPanel implements ActionListener{
	private final static int NBUTTON  = 12;
	private KeyPadClient kpc;
	private JButton buttons[];
	private String labels[] = {"1","2","3","4","5","6","7","8","9","C","0","."};
	
	public KeyPad(KeyPadClient kpc){
		setLayout(new GridLayout(4,3,1,1));
		this.kpc = kpc;
		buttons = new JButton[NBUTTON];
		for(int i=0;i<buttons.length;i++){
			buttons[i] = new JButton(labels[i]);
			buttons[i].addActionListener(this);
			add(buttons[i]);
		}
	}
	public void actionPerformed(ActionEvent evt){
		String keylabel = ((JButton)evt.getSource()).getText();
		kpc.KeypressCallback(keylabel);
	}
}