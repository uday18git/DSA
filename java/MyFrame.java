import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MyFrame extends JFrame implements ActionListener {

    private JButton btnIndia;
    private JButton btnUSA;
    JLabel myLabel = new JLabel(" ");
    public MyFrame() {
        super("Button Demo");
        setLayout(new FlowLayout());

        btnIndia = new JButton("India");
        btnUSA = new JButton("USA");

        add(btnIndia);
        add(btnUSA);

        btnIndia.addActionListener(this);
        btnUSA.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 100);
        setLocationRelativeTo(null);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnIndia) {
            myLabel.setText("I am in India");
        } else if (e.getSource() == btnUSA) {
            myLabel.setText("I am in USA");
        }
    }
    

    public static void main(String[] args) {
        new MyFrame();
    }
}
