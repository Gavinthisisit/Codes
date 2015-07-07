import java.awt.*;
import javax.swing.*;

public class CenterText extends JFrame{
	public void paint(Graphics g){
		String str = "Hello World!";
		g.setFont(new Font("Random",Font.PLAIN,24));
			FontMetrics metrics = g.getFontMetrics();
			Dimension d = getSize();
			
			g.setColor(getBackground());
			g.fillRect(0,0,d.width,d.height);
			g.setColor(Color.black);
			
			int x = (d.width - metrics.stringWidth(str))/2;
			int y = (d.height + metrics.getHeight())/2;
			
			g.drawString(str,x,y);
	}
	public static void main(String args[])
	{
		CenterText ct = new CenterText();
		ct.setSize(400,400);
		ct.setVisible(true);
	}
	
}