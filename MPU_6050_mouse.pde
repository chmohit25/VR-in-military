import java.awt.*;
import java.awt.event.InputEvent; 
import javax.swing.SwingUtilities;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.event.KeyEvent;

int xx =0, yy =0, nxx =0, nyy =0, pp=0;

Robot mouse; 

import processing.serial.*;

Serial port;
Serial port1;

void setup() {
  size(100, 100);
  try { 
    port = new Serial(this, "com12", 38400); //com= arduino com (Arduino ide -> Tool -> Port:"comX"
// port1 = new Serial(this, "com7", 38400);  
 delay(100);
 port.bufferUntil('\n');
 //port1.bufferUntil('\n');
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
 // System.out.println("("+nxx+", "+nyy+")"); 
  nxx=MouseInfo.getPointerInfo().getLocation().x; 
  nyy=MouseInfo.getPointerInfo().getLocation().y;
}

void serialEvent(Serial myPort) {
 String input = myPort.readStringUntil('\n');
  //if (myPort==port){
  //try{

  if (input != null) {

    input = trim(input);

    int[] pointer = int(split(input, ","));
    if (pointer.length==5) {

      //if (nxx>xx+0 || nyy>yy+0 || nxx<xx-0||nyy<yy-0)
      //{ xx=nxx; yy=nyy;delay(0); }
      //else
      { 
        xx= nxx+pointer[0]; 
        yy=nyy+pointer[1]; 
        mouse.mouseMove(xx, yy);
      }
    
    //if (time==debound)

    if (pointer[2]==1)
      mouse.mousePress(InputEvent.BUTTON1_MASK); // left mouse click 
    else if (pointer[2]==0)
      mouse.mouseRelease(InputEvent.BUTTON1_MASK ); // left mouse release

    if (pointer[3]==1)
      mouse.mousePress(InputEvent.BUTTON3_MASK); // right mouse click
    else if (pointer[3]==0)
      mouse.mouseRelease(InputEvent.BUTTON3_MASK ); // right mouse release
 
  if (pointer[4]==1)
      mouse.keyPress(KeyEvent.VK_R); // Reload
    else if (pointer[4]==0)
      mouse.keyRelease(KeyEvent.VK_R); // Reload
}
  
  /* if (myPort==port1){
     
     String input1 = myPort.readStringUntil('\n');
  if (input1 != null) {
    input1 = trim(input1);
   int [] legs = int(split(input1, ","));
    if (legs.length==1) {
 
  if (legs[0]!=0)
      mouse.keyPress(KeyEvent.VK_W); // Forward
    else if (legs[1]==0)
      mouse.keyRelease(KeyEvent.VK_W); // Forward
    
    }
   }
     //delay(10);
}*/
  }
}
