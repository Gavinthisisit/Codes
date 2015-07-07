
import java.awt.*;
import javax.swing.*;

public class Dotty implements Runnable{
	private static final int HREF = 20,VREF = 20,LEN = 20;
	private JPanel canvas;
	private int nDots;
	private int nDrawn;
	private int firstRed = 0;
	private boolean isCleared = false;
	
	public void run(){
		draw();
	}
	
	public Dotty(JPanel canv,int dots){
		canvas = canv;
		nDots = dots;
	}
	public void draw(){
		Graphics g = canvas.getGraphics();
		for(nDrawn = 0;!isCleared && nDrawn<nDots;nDrawn++){
			int x = HREF + (int)(Math.random()*LEN);
			int y = VREF + (int)(Math.random()*LEN);
			g.fillOval(x,y,3,3);
			if((Math.random()<0.001)&&(firstRed == 0)){
				g.setColor(Color.green);
				firstRed = nDrawn;
			}
			try{
				Thread.sleep(1);
			}catch(InterruptedException e){
				System.out.println(e.getMessage());
			}
		}
	}
	public void clear(){
		isCleared = true;
		Graphics g = canvas.getGraphics();
		g.setColor(canvas.getBackground());
		g.fillRect(HREF,VREF,LEN+3,LEN+3);
		System.out.println("Number of dots drawn since first Red = "+(nDrawn-firstRed));
		
	}
}
make change