import java.awt.Color;

import javax.swing.JFrame; //library
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class enk {

  JFrame frame;
  JTextField field; //to get username
  JPasswordField p;
  JLabel 1;
  JButton button;

  startWindow(){

    frame = new JFrame("Encrypted USB 0.1.1"); //initializing frame, you can pass anything as to appear on title bar
    frame.setSize(500,500);
    frame.setLocation(300, 200);
    frame.setLayout(null);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    1 = new JLabel("Enter username");
    1.setLocation(10,10);
    1.setSize(1.getPreferredSize());
    frame.add(1);

    field = new JTextField();
    field.setSize(field.getPreferredSize());
    field.setColumns(25);
    field.setLocation(30, 10);
    field.setToolTipText("Enter User Name: ");
    field.add(field);


    frame.setVisible(true);

  } //end of enk constructor

  public static void main(String args[]){
    new startWindow();
  }
}
