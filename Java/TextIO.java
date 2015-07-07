import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.awt.event.*;

public class TextIO extends JFrame implements ActionListener{
	private JTextArea display = new JTextArea();
	private JButton read = new JButton("Read From File"),
					write = new JButton("Write To File");
	private JTextField nameField = new JTextField();
	private JLabel prompt  = new JLabel("FileName:",JLabel.RIGHT);
	private JPanel commands = new JPanel();
	public TextIO(){
		super("TextIO Demo");
		read.addActionListener(this);
		write.addActionListener(this);
		commands.setLayout(new GridLayout(2,2,1,1));			//control panel
		commands.add(prompt);
		commands.add(nameField);
		commands.add(read);
		commands.add(write);
		display.setLineWrap(true);
		this.getContentPane().setLayout(new BorderLayout());
		this.getContentPane().add("North",commands);
		this.getContentPane().add(new JScrollPane(display));
		this.getContentPane().add("Center",display);
	}
	private void writeTextFile(JTextArea display,String fileName){
		try{
			FileWriter outStream = new FileWriter(fileName);
			outStream.write(display.getText());
			outStream.close();
		}catch(IOException e){
			display.setText("IOERROR: "+e.getMessage()+"\n");
			e.printStackTrace();
		}
	}
	private void readTextFile(JTextArea display,String fileName){
		try{
			BufferedReader inStream = new BufferedReader(new FileReader(fileName));
			String line = inStream.readLine();
			while(line != null){
				display.append(line+"\n");
				line = inStream.readLine();
			}
			inStream.close();
		}catch(FileNotFoundException e){
			display.setText("IOERROR: "+e.getMessage()+"\n");
			e.printStackTrace();
		}catch(IOException e){
			display.setText("IOERROR: "+e.getMessage()+"\n");
			e.printStackTrace();
		}
	}
	public void actionPerformed(ActionEvent evt){
		String fileName = nameField.getText();
		if(evt.getSource() == read){
			display.setText("");
			readTextFile(display,fileName);
		}
		else
			writeTextFile(display,fileName);
	}
	public static void main(String args[]){
		TextIO tio = new TextIO();
		tio.setSize(400,200);
		tio.setVisible(true);
		tio.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
}













