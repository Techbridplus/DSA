import javax.swing.*;
import java.awt.*;

public class Drawing extends Canvas {
    public void paint(Graphics g) {
        // Set the background and foreground colors
        setBackground(Color.BLUE);
        setForeground(Color.BLACK);
        g.setColor(getForeground()); // Use the foreground color for drawing

        // Draw the face
        g.drawOval(100, 100, 125, 125);

        // Draw the eyes
        g.drawOval(80, 140, 20, 35);
        g.fillOval(80, 140, 20, 35);

        g.drawOval(125, 125, 25, 25);
        g.fillOval(125, 125, 25, 25);

        g.drawOval(175, 125, 25, 25);
        g.fillOval(175, 125, 25, 25);

        g.drawOval(225, 140, 20, 35);
        g.fillOval(225, 140, 20, 35);

        // Draw the nose
        g.drawLine(160, 150, 160, 175);

        // Draw the mouth
        g.drawArc(110, 130, 100, 75, 0, -180);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Drawing");
        Drawing drawing = new Drawing();

        frame.add(drawing);
        frame.setSize(400, 400); // Increased size to fit all elements
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
