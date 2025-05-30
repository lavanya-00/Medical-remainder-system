# 💊 Medicine Reminder System using LPC2148

This embedded system project is a real-time **Medicine Reminder System** designed using an **LPC2148 ARM7 microcontroller**. It alerts users to take their medication at scheduled times using a **buzzer**, **LCD**, and **4x4 matrix keypad**, making it especially useful for the elderly or chronically ill patients.

---

## 🎯 Project Objectives

- Display real-time clock (RTC) data (date and time) on a 16x2 LCD.
- Allow users to set and store multiple medicine schedules via a 4x4 keypad.
- Trigger an audible and visual alert when medicine time is reached.
- Allow user acknowledgment through a dedicated button to stop the alert.

---

## 🔧 Hardware Requirements

| Component         | Description                      |
|------------------|----------------------------------|
| LPC2148 MCU      | ARM7-based microcontroller       |
| 16x2 LCD         | For displaying RTC and messages  |
| 4x4 Keypad       | For inputting medicine timings   |
| RTC (On-chip)    | Real-time clock functionality    |
| Buzzer           | Audio alert                      |
| Switches (SW1, SW2) | For setting schedules and acknowledgment |
| USB-UART/DB-9    | For programming and debugging    |

---

## 💻 Software Requirements

- **Embedded C** (Keil IDE or equivalent)
- **Flash Magic** (for flashing the LPC2148)
- Optional: Proteus or simulation tools for testing logic

---

## ⚙️ Working Principle

1. **Medicine Time Setup**  
   - User presses **SW1** to enter medicine times via the keypad.  
   - Schedule is stored in microcontroller memory.  
   - LCD displays current RTC info and scheduled times.

2. **Monitoring & Alert**  
   - The system checks RTC time continuously.  
   - If current time matches any stored medicine time:  
     - LCD displays **“Take Medicine Now”**  
     - Buzzer beeps intermittently to notify user

3. **User Acknowledgment**  
   - User presses **SW2** to stop the buzzer and confirm intake.  
   - System returns to normal monitoring.

---

## 📑 Software Flow Summary

1. System Initialization (RTC, LCD, Keypad, Buzzer)  
2. Display current date/time  
3. Wait for SW1 to input medicine time  
4. Compare RTC time with saved schedule  
5. If match found, alert user  
6. Wait for SW2 acknowledgment  
7. Return to monitoring loop

---

## 📈 Features

- Real-time clock based scheduling  
- Multi-time reminder setup  
- Simple hardware interface  
- Low power and cost-effective  
- Ideal for home and healthcare use

---

## 🔮 Future Enhancements

- Battery backup for RTC  
- Voice alert system  
- Integration with mobile app or SMS module  
- Long-term history log in EEPROM
