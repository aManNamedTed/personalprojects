import java.awt.Color;

import javax.swing.JFrame; //library
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class enk {

  JFrame frame;
  JTextField field; //to get username
  JPasswordField p;
  JLabel l;
  JButton button;

  public enk(){

    frame = new JFrame("Encrypted USB 1.0.0.a"); //initializing frame, you can pass anything as to appear on title bar
    frame.setSize(500,500);
    frame.getContentPane().setBackground(Color.black);
    frame.setLocation(300, 200);
    frame.setLayout(null);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    l = new JLabel("Enter username: ");
    l.setLocation(10,10);
    l.setSize(l.getPreferredSize());
    frame.add(l);

    field = new JTextField();
    field.setColumns(15);
    field.setSize(field.getPreferredSize());

    l = new JLabel("Enter password");
    l.setLocation(10,40);
    l.setSize(l.getPreferredSize());
    frame.add(l);

    frame.setVisible(true);

  } //end of enk constructor

  public static void main(String args[]){
    new enk();
  }
}
