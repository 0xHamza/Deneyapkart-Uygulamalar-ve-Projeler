/*
::::::::::::: ACIKLAMA :::::::::::::
---> Joystick X pini 
*/


#include "deneyap.h"
#include <ESP32Servo.h>
//ELENENLER: D8, D4 , D0 ,D14 , D1
#define soayakpin D11//scl
#define saayakpin D10//sda
#define sodizpin D14
#define sadizpin D15
#define sobacakpin D12
#define sabacakpin D9

Servo soayak, saayak, sodiz, sadiz, sobacak, sabacak;

Servo servolar[6];

int adim = 0;

void setup() {
  pinMode(D4, INPUT_PULLUP);

  soayak.attach(soayakpin);
  saayak.attach(saayakpin);

  sodiz.attach(sodizpin);
  sadiz.attach(sadizpin);
  sobacak.attach(sobacakpin);
  sabacak.attach(sabacakpin);



  Serial.begin(115200);

  servolar[0] = sabacak;
  servolar[1] = sadiz;
  servolar[2] = saayak;
  servolar[3] = sobacak;
  servolar[4] = sodiz;
  servolar[5] = soayak;

  hepsi(90);
  //allTest();
}

void loop() {

  int jX = analogRead(A0);
  int jY = analogRead(A1);
  int buton = digitalRead(D4);

  Serial.print("jX: ");
  Serial.print(jX);
  Serial.print(" / jY: ");
  Serial.print(jY);
  Serial.print(" / buton: ");
  Serial.println(buton);


  if (jY > 2100 || jY < 1600) {

    int aci = ((jY / 4095.0) * 90.0) + 40;

    saayak.write(aci);
    soayak.write(aci);

    Serial.print("Sag sol dondur: ");
    Serial.println(aci);

    delay(100);
  } else {
    saayak.write(90);
    soayak.write(90);
  }


  if (Serial.available()) {
    char veri = Serial.read();

    if (veri == '1') {
      Serial.println("Kontrol 1");

      int bacakAdimi = 140, dizAdimi = 45, ayakAdimi = 110, beklemeSuresi = 15;

      //AYAK ICLERI ADIM ATILACAK YONE DOGRU DONDURULUR      
      saayak.write(ayakAdimi);
      soayak.write(ayakAdimi);

      //SAG ADIM ATILIRKEN SAG AYAK SABIT BIRAKILIR
      sobacak.write(90);
      sodiz.write(90);

      //SAG BACAK VE DIZ UYGUN KONUMA GETITTIRILIR
      //sabacak.write(bacakAdimi);//90+50
      //sadiz.write(dizAdimi);//90-45

      //BURADA FOR KULLANARAK ADIMIN YAVASCA GERCEKLESMESINI DERECELER ARASINDA 15ms beklemesini sagliyoruz. Bu sayede 50*15ms gecikme ile toplamda 750 ms de bir adım atmış oluyoruz.  
      for(int bacakAcisi = 90, dizAcisi=90; bacakAcisi < bacakAdimi || dizAcisi > 45; bacakAcisi++, dizAcisi--){
        
        if(bacakAcisi < bacakAdimi)
          sabacak.write(bacakAcisi);

        if(dizAcisi > dizAdimi)
          sadiz.write(dizAcisi);

        delay(beklemeSuresi);
      }

    } else if (veri == '2') {
      Serial.println("Kontrol 2");


      int bacakAdimi = 140, dizAdimi = 45, ayakAdimi = 70;

      saayak.write(ayakAdimi);
      soayak.write(ayakAdimi);

      sobacak.write(180 - bacakAdimi);//40
      sodiz.write(180 - dizAdimi);//135

      sabacak.write(90);
      sadiz.write(90);

      //BURADA FOR KULLANARAK ADIMIN YAVACA GERCEKLESMESINI DERECELER ARASINDA 15ms beklemesini sagliyoruz. Bu sayede 50*15ms gecikme ile toplamda 750 ms de bir adım atmış oluyoruz.  
      for(int bacakAcisi = 90, dizAcisi=90; bacakAcisi < bacakAdimi || dizAcisi > 45; bacakAcisi++, dizAcisi--){
        
        if(bacakAcisi < bacakAdimi)
          sabacak.write(bacakAcisi);

        if(dizAcisi > dizAdimi)
          sadiz.write(dizAcisi);

        delay(beklemeSuresi);
      }


    } else if (veri == '3') {
      Serial.println("Kontrol 3");

      sobacak.write(90);
      sabacak.write(90);

      sodiz.write(90);
      sadiz.write(90);

      saayak.write(90);
      soayak.write(90);

    } else if (veri == '4') {
      Serial.println("Kontrol 4");
     int bacakAdimi = 145, dizAdimi = 50, ayakAdimi = 105;

      sabacak.write(bacakAdimi);
      sadiz.write(dizAdimi);
      saayak.write(ayakAdimi);
      soayak.write(ayakAdimi);

      delay(1000);

      sobacak.write(90);
      sodiz.write(90);

      delay(1500);

      ayakAdimi = 75;

      sobacak.write(180 - bacakAdimi);
      sodiz.write(180 - dizAdimi);
      saayak.write(ayakAdimi);
      soayak.write(ayakAdimi);

      delay(1000);

      sabacak.write(90);
      sadiz.write(90);

      delay(1500);
          
      sobacak.write(90);
      sodiz.write(90);

    } else {
      Serial.print("Tanımsız veri: ");
      Serial.println(veri);
    }
  }

  if (jX > 3800) {
    //ileri();

    //testTekIleri();

    Serial.println("ILERI");

    sadiz.write(90);
    sobacak.write(90);
    sabacak.write(90);
    sodiz.write(90);

    delay(25);

    sadiz.write(180 - 110);
    sodiz.write(180 - 110);
    sabacak.write(110);
    sobacak.write(110);

    delay(25);

    sadiz.write(180 - 130);
    sodiz.write(180 - 130);
    sabacak.write(130);
    sobacak.write(130);

    delay(25);

  } else if (jX < 200) {


 sadiz.write(90);
    sobacak.write(90);
    sabacak.write(90);
    sodiz.write(90);

    delay(25);

    sadiz.write(110);
    sodiz.write(110);
    sabacak.write(180-110);
    sobacak.write(180-110);

    delay(25);

    sadiz.write(130);
    sodiz.write(130);
    sabacak.write(180-130);
    sobacak.write(180-130);

    delay(25);

    //geri();

    //testTekGeri();
/*
    Serial.println("GERI");

    // sag bacak ileri adım atar
    for (int diz = 90, bacak = 90; diz < 130 && bacak < 160; diz++) {
      sadiz.write(180 - diz);
      sabacak.write(bacak);
      bacak += 2;
      delay(15);
    }

    delay(1000);

    // sol bacak ileri adım atar
    for (int i = 90; i < 130; i++) {
      sodiz.write(i);
      sobacak.write(180 - i);
      delay(15);
    }

    delay(3000);


    for (int i = 130; i < 140; i++) {
      sadiz.write(180 - i);
      sabacak.write(i);
      delay(15);
    }

    delay(3000);

    // sol bacak ileri adım atar
    for (int i = 90; i < 150; i++) {
      sodiz.write(i);
      sobacak.write(180 - i);
      delay(15);
    }

    //dizleri kaldır
    for (int i = 140; i > 90; i--) {
      sadiz.write(180 - i);
      sodiz.write(i + 10);
      delay(15);
    }


    delay(2000);

    // Sağ bacak geri adım atar
    for (int i = 130; i > 90; i--) {
      sabacak.write(i);
      sobacak.write(180 - i);
      delay(15);
    }


    delay(1000);
*/

    /*
    for(int i = 90; i< 130; i++)
    {
      sadiz.write(180-i);     
      sabacak.write(i);   
      delay(15);
    }

    sadiz.write(90);

    delay(1000);
    for(int i = 90; i< 130; i++)
    {
      sodiz.write(i);     
      sobacak.write(180-i);   
      delay(15);
    }
    
    sodiz.write(90);
    delay(1000);
    for(int i = 130; i > 90; i--)
    {
      sadiz.write(180-i); sodiz.write(i);
      delay(15);
    }

     delay(1000);

    for(int i = 130; i > 90; i--)
    {
      sobacak.write(180-i); sabacak.write(i);
      delay(15);
    }
     delay(1000);


     */
    /*
    for(int i = 40; i< 90; i++)
    {
      sodiz.write(i);     sadiz.write(i);
      sabacak.write(180-i);   sobacak.write(180-i);
      delay(15);
    }*/


    /*
    sodiz.write(90);     sadiz.write(90);
    sabacak.write(90);   sobacak.write(90);

    delay(25);    
    
    sodiz.write(110);       sadiz.write(110);
    sobacak.write(180-110); sabacak.write(180-110);

    delay(25);
    
    sodiz.write(130);       sadiz.write(130);
    sobacak.write(180-130); sabacak.write(180-130);
    
    delay(25);
*/

  } else {
    /*Serial.println("HEPSI 90");
    hepsi(90);
    delay(1000);*/
  }

  if (buton == 0) {
    sodiz.write(90);
    sadiz.write(90);
    sabacak.write(90);
    sobacak.write(90);
    soayak.write(90);
    saayak.write(90);

    delay(50);
  }

  delay(250);
}

void testTekIleri() {

  if (adim + 1 <= 5) {

    adim++;

    Serial.print("Testing Servo ");
    Serial.println(adim);

    Serial.print("3 2 1 ");
    delay(1500);
    Serial.println("Lets gooo!");

    test(servolar[adim]);
  } else if (adim + 1 == 6) {
    Serial.print("Testing Servo ALL!");
    delay(1500);
    testAll(hepsi);
  }
}

void testTekGeri() {
  if (adim - 1 >= 0) {
    adim--;

    Serial.print("Testing Servo ");
    Serial.println(adim);

    Serial.print("3 2 1 ");
    delay(1500);
    Serial.println("Lets gooo!");

    test(servolar[adim]);

    Serial.println("TEST BITTI!");
  } else if (adim - 1 == -1) {
    Serial.print("Testing Servo SAG!");
    delay(1500);
    testAll(sag);

    Serial.print("Testing Servo SOL!");
    delay(1500);
    testAll(sol);
  }
}