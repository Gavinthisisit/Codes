import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;

public class OrderApplet extends JApplet implements ItemListener,ActionListener{
	private final int NTITLES = 3,NOPTIONS = 3;
	public  JPanel mainPanel = new JPanel(),
				   centerPanel = new JPanel(),
				   choicePanel = new JPanel(),
				   optionPanel = new JPanel(),
				   buttonPanel = new JPanel();
	private ButtonGroup optGroup = new ButtonGroup();
	private JCheckBox titles[] = new JCheckBox[NTITLES];
	private JRadioButton options[] = new JRadioButton[NOPTIONS];
	private String titleLabels[] = {"Chess Master - $59.95","Checkers Pro - $39.95","Crossword Maker - $19.95"};
	private String optionLabels[] = {"Credit Card","Debit Card","E-cash"};
	private JTextArea display = new JTextArea(7,25);
	private JButton submit = new JButton("Submit Order"),
					cancel = new JButton("Cancel");
	
	public void init(){
		mainPanel.setBorder(BorderFactory.createTitledBorder("Acme Software Titles"));
		mainPanel.setLayout(new GridLayout(3,1,1,1));
		cancel.addActionListener(this);
		submit.addActionListener(this);
		initChoices();
		initOptions();
		buttonPanel.setBorder(BorderFactory.createTitledBorder("Order Today"));
		buttonPanel.add(cancel);
		buttonPanel.add(submit);
		centerPanel.add(optionPanel);
		centerPanel.add(choicePanel);			//注意顺序
		
		
		mainPanel.add(display);
		mainPanel.add(centerPanel);
		mainPanel.add(buttonPanel);
		getContentPane().add(mainPanel);
		setSize(400,400);
	}
	private void initChoices(){
		choicePanel.setBorder(BorderFactory.createTitledBorder("Titles"));
		choicePanel.setLayout(new BoxLayout(choicePanel,BoxLayout.Y_AXIS));
		for(int i=0;i<titles.length;i++){
			titles[i] = new JCheckBox(titleLabels[i]);
			titles[i].addItemListener(this);
			choicePanel.add(titles[i]);
		}
	}
	private void initOptions(){
		optionPanel.setBorder(BorderFactory.createTitledBorder("Payment By"));
		optionPanel.setLayout(new BoxLayout(optionPanel,BoxLayout.Y_AXIS));
		for(int i=0;i<options.length;i++){
			options[i] = new JRadioButton(optionLabels[i]);
			options[i].addItemListener(this);
			optionPanel.add(options[i]);
			optGroup.add(options[i]);
		}
		options[0].setSelected(true);
	}
	public void itemStateChanged(ItemEvent e){
		display.setText("Your order so far (Payment By: ");
		for(int i=0;i<options.length;i++)
			if(options[i].isSelected())
				display.append(options[i].getText()+")\n");;
		for(int i=0;i<titles.length;i++)
			if(titles[i].isSelected())
				display.append("\t"+titles[i].getText()+"\n");
	}
	public void actionPerformed(ActionEvent evt){
		String label = submit.getText();
		if(evt.getSource() == submit){
			if(label.equals("Submit Order")){
				display.append("Thank you. Press 'Confirm' to submit your order!\n");
				submit.setText("Confirm Order");
			}
			else{
				display.append("Thank you.You will receive your order tomorrow!\n");
				submit.setText("Submit Order");
			}
		}
		else 
			display.setText("Thank you.Maybe we can server you next time!\n");
	}
	public static void main(String args[]){

        JFrame frame = new JFrame("Applet is in the frame");  
        OrderApplet myJApplet = new OrderApplet();  
        // main方法里创建一个框架来放置applet，applet单独运行时，  
        // 要完成操作必须手动调用init和start方法  
        frame.add(myJApplet, BorderLayout.CENTER);  
        myJApplet.init();  
  
        frame.setLocationRelativeTo(null);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        frame.setSize(700, 700);  
        frame.setVisible(true);  
	}
}








