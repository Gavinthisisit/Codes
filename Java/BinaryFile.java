import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class BinaryFile extends JFrame implements ActionListener{
	private JTextArea display = new JTextArea();
	private JButton write = new JButton("Write to File");
	private JButton read = new JButton("Read from file");
	private JLabel  prompt = new JLabel("Filename",JLabel.RIGHT);
	private JTextField nameField = new JTextField(20);
	private JPanel pane = new JPanel();
	
	public BinaryFile(){
		super("Deal with Binary File");
		read.addActionListener(this);
		write.addActionListener(this);
		pane.setLayout(new GridLayout(2,2,1,1));
		pane.add(prompt);									//组件加入到pane的顺序与其布局有关
		pane.add(nameField);
		pane.add(read);
		pane.add(write);
		
		display.setLineWrap(true);
		this.getContentPane().setLayout(new BorderLayout());
		this.getContentPane().add("North",pane);
		this.getContentPane().add(new JScrollPane(display));
		this.getContentPane().add("Center",display);
	}
	private void writeRecords(String fileName){
		try{
			DataOutputStream outStream = new DataOutputStream(new FileOutputStream(fileName));
			for(int i=0;i<5;i++){
				String name = "Name"+i;
				outStream.writeUTF("Name"+i);
				outStream.writeInt((int)(20+Math.random()*25));
				outStream.writeDouble(5.00+Math.random()*100);
			}
			outStream.close();
		}catch(IOException e){
			display.setText("IOERROR: "+e.getMessage()+"\n");
		}
	}
	
	private void readRecords(String fileName){
		try{
			DataInputStream inStream = new DataInputStream(new FileInputStream(fileName));
			display.setText("Name    Age   Pay\n");
			try{
					String name = inStream.readUTF();
					int age = inStream.readInt();
					double pay = inStream.readDouble();
					display.append(name+"    "+age+"   "+pay+"\n");
				while(name!=null){
						 name = inStream.readUTF();
						 age = inStream.readInt();
						 pay = inStream.readDouble();
						display.append(name+"    "+age+"   "+pay+"\n");
					}
				}catch(EOFException e){
					
				}finally{
					inStream.close();
				}
			}catch(FileNotFoundException e){
				display.setText("IOERROR+ "+fileName+"Not Found!");
			}catch(Exception e){
				display.setText("IOERROR: "+e.getMessage()+"\n");
			}
	}
	public void actionPerformed(ActionEvent evt){
		String fileName = nameField.getText();
		
		if(evt.getSource()==read){
			display.setText("");
			readRecords(fileName);
		}
		else 
			writeRecords(fileName);
	}
	
	public static void main(String args[]){
		BinaryFile bf = new BinaryFile();
		bf.setSize(600,400);
		bf.setVisible(true);
		bf.addWindowListener(new WindowAdapter(){
				public void windowClosing(WindowEvent e){
					System.exit(0);
				}
		});
	}
}