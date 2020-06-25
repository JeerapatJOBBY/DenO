# Den-O belt simulator
คือ อุปกรณ์ที่จำลองการทำงานของเข็มขัดมาสไรเดอร์เดนโอ โดยที่เมื่อเรากดปุ่มเพื่อเปิดการทำงานของเข็มขัด หลังจากนั้นให้กดปุ่มเพื่อเลือกฟอร์ม(ร่าง)ต่างๆที่เราต้องการ หลังจากนั้นให้เราทำการสแกนบัตรเพื่อให้อุปกรณ์เลือกฟอร์ที่เราต้องการ และถ้าเราทำการสแกนบัตรอีกครั้งจะเป็นการใช้งานของท่าเฉพาะของร่างนั้นๆ

## ที่มาและความสำคัญ
ในปัจจุบันมีผู้ที่หลงไหลซีรี่ย์มาสไรเดอร์อยู่เป็นจำนวนมาก แต่ราคาของเล่นที่มีในท้องตลาดนั้นสวนทางกับความต้องการเหลือเกิน แต่ถ้าหากเราสามารถทำของเล่นนั้นขึ้นมาในราคาที่ถูกกว่าท้องตลาดจะเป็นเช่นไร ทางผู้จัดทำนั้นได้ทำอุปกรณ์นี้ไว้ให้สำหรับผู้ที่มีความต้องการจะรู้หลักการทำงรานเบื้องต้นของของเล่น และยังสามารถสร้างมันขึ้นมาในราคาที่ไม่สูงมากจนเกินไป

## ขอบเขตการศึกษา
+ สามารถกดปุ่มหมายเลขเพื่อเลือกฟอร์มที่ต้องการได้
+ สามารถสแกนบัตรเพื่อยืนยันฟอร์มนั้นๆ
+ สามารถมีเสียงเพื่อบอกว่าเราอยู่ในฟอร์มที่เราเลือกแล้ว
+ สามารถแสกนเหรี่ยญเพื่อใช้งานท่าไม้ตายได้


## กลุ่มตัวอย่าง
+ ผู้ที่หลงไหลในการดูซีรี่ย์มาสไรเดอร์เดนโอ
+ ผู้ที่ที่ต้องการเข้าใจการทำงานของเข็มขัดมาสไรเดอร์เดนโอ

## รายละเอียดโปรเจค

### Perception Module
- Button module
- RFID Reader
- 4X4 Keypad

### Behavior
1. กดปุ่มเพื่อเปิดการทำงาน
2. กดเลขใน keypad เพื่อเลือกฟอร์มต่างๆ
3. สแกนบัตรบน rffid reader
4. มีเสียงออกมาตามฟอร์มนั้นๆ

### Manipulation Module
- Passive Buzzer
- OLED 0.91” Display I^2C

### โครงสร้างพื้นฐาน
![diagram picture][diagram]

[diagram]: https://github.com/JeerapatJOBBY/DenO/blob/master/Image/Diagram.png "diagram"

### ระบบการทำงาน
![flowchart picture][flowchart]

[flowchart]:https://github.com/JeerapatJOBBY/DenO/blob/master/Image/Flowchart.png "flowchart"

### การต่อสายไฟ
![Project picture][Project]

[Project]: https://github.com/JeerapatJOBBY/DenO/blob/master/Image/Project.png "Project"

