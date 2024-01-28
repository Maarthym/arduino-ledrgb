const int button = 2;
const int ledR = 3;
const int ledG = 5;
const int ledB = 6;

boolean enabled = true;

int r = 0;
int g = 0;
int b = 0;

boolean augmentation = true;
int color = 0;
int value = 0;
int first = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) == HIGH){
    if (enabled == false){
      enabled = true;
      Serial.println("Lumière allumée");
      delay(200);
    } else {
      enabled = false;
      Serial.println("Lumière éteinte");
      analogWrite(ledR, 0);
      analogWrite(ledG, 0);
      analogWrite(ledB, 0);
      delay(200);
    }
    
  } 
  if (enabled == true){
      analogWrite(ledR, r);
      analogWrite(ledG, g);
      analogWrite(ledB, b);

      if (augmentation){
        moreColor();
        value++;
      } else {
        lessColor();
        value++;
      }
      
      if (value >= 255){
        value = 1;
        if (color == 0){
          color = 1;
        } else if (color == 1){
          color = 2;
        } else {
          color = 0;
          if (augmentation){
            augmentation = false;
          } else {
            augmentation = true;
            first++;
            if (first > 2){
              first = 0;
            }
          }
        }
      }
  }
  delay(1);
}


void moreColor(){
  if (first == 0){
    if (color == 0){
      r++;
    } else if (color == 1){
      g++;
    } else {
      b++;
    }
  } else if (first == 1){
    if (color == 0){
      g++;
    } else if (color == 1){
      r++;
    } else {
      b++;
    }
  } else {
    if (color == 0){
      b++;
    } else if (color == 1){
      g++;
    } else {
      r++;
    }
  }
}


void lessColor(){
  if (first == 0){
    if (color == 0){
      r--;
    } else if (color == 1){
      g--;
    } else {
      b--;
    }
  } else if (first == 1){
    if (color == 0){
      g--;
    } else if (color == 1){
      r--;
    } else {
      b--;
    }
  } else {
    if (color == 0){
      b--;
    } else if (color == 1){
      g--;
    } else {
      r--;
    }
  }
}
