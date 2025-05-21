
bool isfb = true; // Move this OUTSIDE the function (make it global)

void decisionfunctoin() {
  if (distance > 30) {
    forward();
    isfb = true; // Reset the flag when robot starts moving again
  }

  if (distance < 40) {
    if (isfb) {
      backward();
      delay(50);  // brief backward motion
      isfb = false;
    } else {
      stopp();    // stop the robot
    }
  }
}


//if(leftinf==1){stopp();}
//if(rightinf==1){stopp();}
//if((fdistance-distance)>=100){stopp();}

  
