import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;

public class ToggleButton extends JButton implements ActionListener{
	private String lable1;
	private String lable2;
	
	public ToggleButton(String 11,String 12){
		super(11);
		lable1 = 11;
		lable2 = 12;
		addActionListener(this);				
	}
	public void actionPerformed(ActionEvent e){
		String temps = lable1;
		lable1 = lable2;
		lable2 = temps;
		setText(lable1);
	}

}
public class ToggleApplet extends JApplet implements ActionListener{
	private ToggleButton lightSwitch;
	
	public void init(){
		lightSwitch = new ToggleButton("off","on");
		getContentPane().add(lightSwitch);
		lightSwitch.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e){
		showStatus("The light is "+lightSwitch.getText());
	}
	
	public static void main(String args[]){
		ToggleApplet tog = new ToggleApplet();
		tog.init();
//		tog.actionPerformed();
	}
}