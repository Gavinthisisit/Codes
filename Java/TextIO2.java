import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.awt.event.*;

public class TextIO2 extends JFrame implements ActionListener{
	private JTextArea display = new JTextArea();
	private JButton read = new JButton("Read from File"),
					write = new JButton("Write To File");
	private JTextField nameField = new JTextField("File name",20);
	private JLabel prompt = new JLabel("File name: ",JLabel.RIGHT);
	private JPanel pane = new JPanel();
	
	public TextIO2(){
		super("TextIO again");
		read.addActionListener(this);
		write.addActionListener(this);
		pane.setLayout(new GridLayout(2,2,1,1));
		pane.add(prompt);
		pane.add(read);
		pane.add(write);
	//	pane.add(display);
		pane.add(nameField);
		display.setLineWrap(true);			//自动换行
		this.getContentPane().setLayout(new BorderLayout());
		this.getContentPane().add("North",pane);
		this.getContentPane().add(new JScrollPane(display));
		this.getContentPane().add("Center",display);
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
			display.setText("IOERROR: "+fileName+"Not found\n");
			display.setText("IOERROR: "+fileName+"Not found\n");
			e.printStackTrace();
		}catch(IOException e){
			display.setText("IOERROR: "+e.getMessage()+"\n");
			e.printStackTrace();
		}
	}
	public void wrtieTextFile(JTextArea display,String fileName){
		try{
			FileWriter outStream = new FileWriter(fileName);
			outStream.write(display.getText());
			outStream.close();
		}catch(IOException e){
			display.setText("IOERROE: "+e.getMessage()+"\n");
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
			wrtieTextFile(display,fileName);
	}
	private boolean isReadableFile(String fileName){
		try{
			File file = new File(fileName);
			if(!file.exists())
				throw (new FileNotFoundException("No such File: "+fileName));
			if(!file.canRead())
				throw (new IOException("Flie can not readable: "+fileName));
			return true;
		}catch(FileNotFoundException e){
			System.out.println("IOERROR: File NOT Found: "+fileName+"\n");
			return false;
		}catch(IOException e){
			System.out.println("IOERROR: "+e.getMessage()+"\n");
			return false;
		}
	}
	
	private boolean isWriteableFile(String fileName){
	try{
			File file = new File(fileName);
			if(fileName.length() == 0)
				throw (new IOException("Invalid file name: "+fileName));
			if(file.exists() && !file.canWrite())
				throw (new IOException("IOERROE:File not writeable: "+fileName));
			return true;
		}catch(IOException e){
			display.setText("IOERROE: "+e.getMessage()+"\n");
			return false;
		}
	}
	public static void main(String args[]){
		TextIO2 tio = new TextIO2();
		tio.setSize(400,200);
		tio.setVisible(true);
		tio.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});			//关闭窗口
	}
	
	
	
	
	
	
}