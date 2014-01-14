package examples;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class CreateUI {
	
	JButton jbutton1;
	JButton jbutton2;
	JButton jbutton3;
	JButton jbutton4;
	JButton jbutton5;
	JButton jbutton6;
	JButton jbutton7;
	JButton jbutton8;
	JButton jbutton9;
	int ar[][] = null;
	JNIClass jniclass = null;
	
	CreateUI() {
		initialise();
		ar = new int[3][3];
		for (int i = 0; i <3; i++) {
			for(int j = i; j<3;j++) {
				ar[i][j] = 0;
			}
		}
	}
		
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */
    public void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        //Add the ubiquitous "Hello World" label.
        JLabel label = new JLabel("Hello World");
        frame.getContentPane().add(label);
 
        //Display the window.
        frame.setSize(800, 800);
       // frame.pack();
        JPanel p = new JPanel(); 
        frame.getContentPane().add(p);
       
        GridLayout layout = new GridLayout(0,3);
        p.setLayout(layout);
        p.add(jbutton1);
        p.add(jbutton2);
        p.add(jbutton3);
        p.add(jbutton4);
        p.add(jbutton5);
        p.add(jbutton6);
        p.add(jbutton7);
        p.add(jbutton8);
        p.add(jbutton9);
     // setImage();
        frame.setVisible(true);
    }
    
    public void setUI() {
    	JButton button = null;
    	for (int i = 0; i < 3; i++) {
    		for (int j = 0; j < 3;j++) {
    			button = getButton(i, j);
    			if (ar[i][j] == 1) {
    				button.setIcon(new ImageIcon("/home/m1.sharma/X-icon.png"));
    			} else if (ar[i][j] == 0) {
    				button.setIcon(new ImageIcon("/home/m1.sharma/zero1.jpeg"));
    			}
    		}
    	}
    }
    
    private JButton getButton(int i, int j) {
		// TODO Auto-generated method stub
    	JButton button = null;
		if (i == 0 && j == 0) {
			button = jbutton1;
		} else if (i == 0 && j ==1) {
			button = jbutton2;
		} else if (i ==0 && j == 2){
			button = jbutton3;
		} else if (i == 1 && j ==0) {
			button = jbutton4;
		} else if (i ==1 && j == 1) {
			button = jbutton5;
		} else if (i ==1 && j==2) {
			button = jbutton6;
		} else if ( i ==2 && j==0) {
			button = jbutton7;
		} else if (i ==2 && j ==1) {
			button = jbutton8;
		} else if (i==2 && j == 2) {
			button = jbutton9;
		}
		return button;
	}
    
    class ButtonActionListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			if (e.getSource() == jbutton1) {
				ar[0][0] = 2;
			} else if (e.getSource() == jbutton2) {
				ar[0][1] = 2;
			} else if (e.getSource() == jbutton3) {
				ar[0][2] = 2;
			} else if (e.getSource() == jbutton4) {
				ar[1][0] = 2;
			} else if (e.getSource() == jbutton5) {
				ar[1][1] = 2;
			} else if (e.getSource() == jbutton6) {
				ar[1][2] = 2;
			} else if (e.getSource() ==  jbutton7) {
				ar[2][0] = 2;
			} else if (e.getSource() == jbutton8) {
				ar[2][1] = 2;
			} else if (e.getSource() == jbutton9) {
				ar[2][2] = 2;
			}
			int val[][] = jniclass.getComputerMove();
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j< 3; j++) {
					ar[i][j] = val[i][j];
					if (ar[i][j] == 1 ||
						ar[i][j] == 2	) {
						JButton button = getButton(i, j);
						button.setEnabled(false);
					}
				}
			}
			
		}
    	
    }

	public void initialise() {
    	jbutton1 = new JButton();
    	jbutton2 = new JButton();
    	jbutton3 = new JButton();
    	jbutton4 = new JButton();
    	jbutton5 = new JButton();
    	jbutton6 = new JButton();
    	jbutton7 = new JButton();
    	jbutton8 = new JButton();
    	jbutton9 = new JButton();
    	jniclass = new JNIClass();
    	ButtonActionListener listener = new ButtonActionListener();
    	jbutton1.addActionListener(listener);
    	jbutton2.addActionListener(listener);
    	jbutton3.addActionListener(listener);
    	jbutton4.addActionListener(listener);
    	jbutton5.addActionListener(listener);
    	jbutton6.addActionListener(listener);
    	jbutton7.addActionListener(listener);
    	jbutton8.addActionListener(listener);
    	jbutton9.addActionListener(listener);
    	
    	
    }
 };
    public class TicTacToe {
    public static void main(String argv[]) {
    	CreateUI obj = new CreateUI();
    	obj.createAndShowGUI();
    }
    
};