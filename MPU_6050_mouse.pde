import java.awt.*;
import java.awt.event.InputEvent; 
import javax.swing.SwingUtilities;

import java.awt.MouseInfo;

import java.awt.Point;

int xx =0, yy =0, nxx =0, nyy =0,pp=0;

Robot mouse; 

import processing.serial.*;
Serial port;

void setup(){
size(100,100);

try{ port = new Serial(this,"com3",75000); //com= arduino com (Arduino ide -> Tool -> Port:"comX"

port.bufferUntil('\n');

} catch(Exception ex){

text("There is no serial port communication!",10,14); 

} try {

mouse = new Robot(); 

} catch (AWTException e) {

println("Not Supported robot class!"); exit(); 

}

}void draw()

{ System.out.println("("+nxx+", "+nyy+")"); nxx=MouseInfo.getPointerInfo().getLocation().x; nyy=MouseInfo.getPointerInfo().getLocation().y;}

void serialEvent(Serial myPort) {
String input = myPort.readStringUntil('\n');

if (input != null) {

input = trim(input);

int[] pointer = int(split(input, ","));

if (pointer.length >=2) {

//if (nxx>xx+0 || nyy>yy+0 || nxx<xx-0||nyy<yy-0)
//{ xx=nxx; yy=nyy;delay(0); }

//else
{ 
xx= nxx-pointer[0]; yy=nyy+pointer[1]; mouse.mouseMove(xx,yy); }} 
//if (time==debound)

if (pointer[2]==1)
mouse.mousePress(InputEvent.BUTTON1_MASK); // left mouse click
else if (pointer[2]==0)
mouse.mouseRelease(InputEvent.BUTTON1_MASK ); // left mouse release


if (pointer[3]==1)
mouse.mousePress(InputEvent.BUTTON3_MASK); // right mouse click
else if (pointer[3]==0)
mouse.mouseRelease(InputEvent.BUTTON3_MASK ); // right mouse release
}

}

 
