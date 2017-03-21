import java.awt.*;
import java.awt.event.InputEvent; 
import javax.swing.SwingUtilities;
import java.awt.event.KeyEvent;


Robot mouse; 

import processing.serial.*;

Serial port1;

void setup() {
  size(100, 100);
  try { 
 port1 = new Serial(this, "com7", 38400);  
 delay(100);
 port1.bufferUntil('\n');
 delay(100);
} 
  catch(Exception ex) {

    text("There is no serial port communication!", 10, 14);
  } 
  try {

    mouse = new Robot();
  } 
  catch (AWTException e) {

    println("Not Supported robot class!"); 
    exit();
  }
}
void draw()
{ 
  
}

void serialEvent(Serial myPort) {
  String input1 = myPort.readStringUntil('\n');
  
   if (myPort==port1)
     
     
  if (input1 != null) {
    input1 = trim(input1);
   //int [] legs = int(split(input1, ","));
    int legs =parseInt(input1,10);
  if (legs!=0)
    { 
      mouse.keyPress(KeyEvent.VK_W); // Forward
    }
   else 
   mouse.keyRelease(KeyEvent.VK_W); // Stop
   }
     //delay(10);
}
