import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class MyColorChooser {
    private JFrame myFrame;
    private JLabel header;
    private JLabel status;
    private JLabel lower;
    private JPanel control;

    public MyColorChooser(){
        initiate();
    }

    public void initiate(){
        myFrame = new JFrame("My First GUI model");
        myFrame.setSize(400, 400);
        myFrame.setLayout(new BorderLayout());

        myFrame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent windowEvent){
               System.exit(0);
            }        
        });


        header = new JLabel("", JLabel.CENTER);
        status = new JLabel("", JLabel.CENTER);
        status.setSize(300, 100);
        control = new JPanel();
        control.setLayout(new FlowLayout());

        lower = new JLabel("", JLabel.CENTER);
        

        myFrame.add(header, BorderLayout.NORTH);
        myFrame.add(status, BorderLayout.SOUTH);
        // myFrame.add(lower, BorderLayout.CENTER);
        myFrame.add(control);
        myFrame.setVisible(true);

    }

    public void showColorChooser(){
        header.setText("color chooser");

        JButton submitButton = new JButton("CHOOSE BG");

        submitButton.addActionListener(new MyActionListener());

        control.add(submitButton);
        myFrame.setVisible(true);
    }

    public static void main(String args[]){
        MyColorChooser lb = new MyColorChooser();
        lb.showColorChooser();
    }

    private class MyActionListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            Color clr = JColorChooser.showDialog(myFrame, "Choose a color", Color.white);
            if(clr != null){
                control.setBackground(clr);
                myFrame.getContentPane().setBackground(clr);
            }
        }
    }

}

