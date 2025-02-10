#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h> // подключаем библиотеку Keypad
LiquidCrystal lcd(8,9,10,11,12,13); 
const byte ROWS = 4; // 4 строки
const byte COLS = 3; // 3 столбца
Servo srv;
 
// определим символы для кнопок
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
 char zakaz="";
byte rowPins[ROWS] = {6, 5, 4, 3}; // цифровые выводы строк 
byte colPins[COLS] = {A0, A1, A2, 2}; // цифровые выводы столбцов 6
// используем класс библиотеки
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS );  
char last_customKey ="";
char num1[4];
int position=0;


void setup(){
  lcd.begin(16,2); 
  Serial.begin(9600);
  lcd.setCursor(0,0);
int x = 0;
srv.attach(7);
srv.write(0);
delay(1000);
}   

void char_add(char key1){
  if((int)key1== 42){ //42 - код звёздочки *. очистка дисплея
    num1[0]=0;
    num1[1]=0;
    num1[2]=0;
    position=0;
    lcd.clear(); 
    lcd.setCursor(0,0);
      lcd.print(num1);
    //Serial.println("qwreqwrewqer");
  }else
  if((int)key1== 35){ //35 - код решетки №. Принять заказ
    lcd.clear(); 
    lcd.setCursor(0,0);
      lcd.print((String)"Order #"+num1);
    num1[0]=0;
    num1[1]=0;
    num1[2]=0;
    position=0;
  }else 
  if(position<3){
    num1[position]=key1;
    position++;
    //Serial.println("asdfasdfsadf");
    lcd.clear(); 
    lcd.setCursor(0,0);
      lcd.print(num1);  
  }
  
  //Serial.println((String)"num "+num1);
  //Serial.println((String)"pos "+position);
  //Serial.println((String)"key "+key1);
  //Serial.println((int)key1);



}

void loop(){
  char customKey = customKeypad.getKey(); 
  if((int)customKey!=0) {
  char_add(customKey);
  while((int)customKey!=0){
    customKey = customKeypad.getKey();
    };
  }
 //lcd.setCursor(0,0);
   // lcd.print(zakaz);

    //Serial.println("dsf");
delay(20);
    //delay(1000);

}
