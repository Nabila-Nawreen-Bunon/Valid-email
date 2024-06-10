String inputString="";
bool stringComplete=false;
void setup()
{
 Serial.begin(9600);
  inputString.reserve(200);
  Serial.println("Enter an email address:");
}

void loop()
{
  if(stringComplete){
    bool isValid=isValidEmail(inputString);
    if(isValid){
      Serial.println("Valid Email Address");
    }
    else{
      Serial.print("Invalid Email address");
    }
    inputString="";
      stringComplete=false;
    Serial.println("Enter the string");
  }
}
bool isValidEmail(String email){
  int atIndex=email.indexOf('@');
  int dotIndex=email.lastIndexOf('.');
  if(atIndex<=0||atIndex<=email.length()-1){
    return false;
  }
  if(dotIndex<=atIndex+1||dotIndex>=email.length()-1){
    return false;
  }
  if(email.indexOf("..")!=-1){
    return false;
  }
  return true;
}
void serialEvent(){
  while(Serial.available()){
    char inChar=(char)Serial.read();
    inputString+=inChar;
    if (inChar=='\n'){
      stringComplete=true;
    }
  }
}
    
    