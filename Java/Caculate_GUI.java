package gui;

import java.io.*;
import java.net.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Caculate_GUI extends JFrame implements ActionListener{
	private JTextField xArea = new JTextField(5);
	private JTextField yArea = new JTextField(5);
	private JTextField rArea = new JTextField(5);
	
	private JButton btnCaculate = new JButton("Caculate");
	private JButton btnClear = new JButton("Clear");
	
	private JTextArea display = new JTextArea(5,15);
	
	private JPanel inPanel = new JPanel();
	private JPanel btnPanel = new JPanel();
	private JPanel disPanel = new JPanel();
	public Caculate_GUI(){
		super("计算");
		getContentPane().setLayout(new BorderLayout());
		inPanel.add(xArea);
		inPanel.add(yArea);
		inPanel.add(rArea);
		
		btnCaculate.addActionListener(this);
		btnClear.addActionListener(this);
		
		btnPanel.add(btnCaculate);
		btnPanel.add(btnClear);
		btnPanel.add(display);
//		disPanel.add(display);
		
		getContentPane().add("North",inPanel);
		getContentPane().add("Center",btnPanel);
//		getContentPane().add(disPanel);
			
	}
	
	public void actionPerformed(ActionEvent evt){
		if(evt.getSource() == btnCaculate){
			double x,y,z;
			x = y = z = 0;
			String retval = "";
			Caculate ca = new Caculate();
			int flag = 0;
			if(!xArea.getText().equals("")){
				x = Double.valueOf(xArea.getText());
				flag = 1;
			}
			if(!yArea.getText().equals("")){
				y = Double.valueOf(yArea.getText());
				flag = 2;
			}
			if(!rArea.getText().equals("")){
				z = Double.valueOf(rArea.getText());
				flag = 3;
			}
			if(flag == 0)
				JOptionPane.showMessageDialog(null,"您并没有输入数据!");
			else if(flag == 1)
				retval = ca.Muti_Caculate(x);
			else if(flag == 2)
				retval = ca.Muti_Caculate(x,y);
			else
				retval = ca.Muti_Caculate(x,y,z);
			
			display.setText(retval);
		}
		
		if(evt.getSource() == btnClear)
			display.setText("");
	}
	public static void main(String args[]){
		Caculate_GUI cal = new Caculate_GUI();
		cal.setSize(500,500);
		cal.setVisible(true);
		cal.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
}