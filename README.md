# ATTENDIFY-RFID: SMART EMPLOYEE TRACKING & REPORTING SYSTEM

## 📌 Project Overview

The **RFID Smart Employee Tracking and Attendance System** is an embedded-based employee attendance management system designed to automate employee **IN/OUT tracking** and reduce errors associated with manual attendance systems.

The system uses an **RFID reader** to identify employees through their unique RFID card ID. An **LPC2148 ARM7 microcontroller** processes the RFID information, obtains the current date and time from an RTC, and communicates with a Linux-based PC application through UART.

The Linux application maintains employee information and attendance records in a **CSV file**.

---

## 🎯 Objectives

* Automate employee attendance tracking.
* Reduce manual attendance errors.
* Identify employees using RFID cards.
* Record employee IN and OUT times.
* Maintain employee details in a CSV database.
* Calculate employee working hours.
* Provide administrator functions for employee management.
* Provide date and time configuration through an LCD and keypad.

---

## 🔧 Hardware Components

* LPC2148 ARM7 Microcontroller
* RFID Reader
* RFID Cards
* Real-Time Clock (RTC)
* SPI EEPROM
* 16×2 LCD
* 4×4 Matrix Keypad
* MAX232 / USB-to-Serial interface
* Power Supply
* Linux PC

---

## 💻 Software / Technologies

* Embedded C
* C Programming
* ARM7 / LPC2148
* UART
* SPI
* RTC
* Interrupts
* Linux
* Serial Communication
* CSV File Handling
* Keil µVision
* GCC / Linux C compiler
  
---

## 🔌 Communication Interfaces

### UART1 – RFID Communication

UART1 is used for communication between the RFID reader and the LPC2148.

```text
RFID Reader
     │
     │ Serial Data
     ▼
   UART1
     │
     ▼
  LPC2148
```

The RFID reader transmits the card's unique ID serially to the microcontroller.

The UART1 receive interrupt is used to collect the RFID data.

---

### UART0 – LPC2148 to Linux PC

UART0 is used for communication between the LPC2148 and the Linux PC.

```text
LPC2148
   │
 UART0
   │
   ▼
MAX232 / USB Serial
   │
   ▼
Linux PC
```

The microcontroller sends employee-related requests and receives responses from the Linux application.

---

### SPI – EEPROM Communication

SPI is used to communicate with the external EEPROM.

The EEPROM can be used for storing required system data.

```text
LPC2148
   │
  SPI
   │
   ▼
SPI EEPROM
```

---

## ⏰ RTC

The Real-Time Clock is used to maintain:

* Hours
* Minutes
* Seconds
* Date
* Month
* Year
* Day of the week

The current time is displayed on the LCD and is also used for employee attendance records.

The system allows the administrator to modify the RTC time and date using the keypad.

---

## 🖥️ Linux PC Application

A C-based Linux application communicates with the LPC2148 through a serial port.

The application performs operations such as:

* Adding employees
* Editing employee details
* Deleting employees
* Checking employee IDs
* Recording employee login
* Recording employee logout
* Calculating working hours
* Maintaining attendance records

Employee information is stored in:

```text
employee_details.csv
```

---

## 👤 Employee Operations

When an employee scans an RFID card, the system verifies the employee ID.

Depending on the current attendance status, the system can:

### IN

Record the employee's entry time.

### OUT

Record the employee's exit time and update the total working hours.

The system also performs checks such as:

* Employee ID existence
* Maximum IN/OUT operations
* Invalid time sequence
* Very fast IN/OUT operations
* Attendance time restrictions

---

## 👨‍💼 Administrator Operations

The administrator can perform employee management operations such as:

* Add employee
* Edit employee name
* Delete employee
* Modify RTC time
* Modify RTC date
* Modify day of the week

Administrator access is controlled using an authorized RFID card.

---

## ⚡ Interrupts Used

Interrupt-based mechanisms are used in the project for efficient event handling.

### UART1 Interrupt

The UART1 receive interrupt is used to receive RFID data.

```text
RFID Reader
     │
     ▼
 UART1 Receive
     │
     ▼
 UART1 ISR
     │
     ▼
RFID ID Buffer
     │
     ▼
Main Application
```

### UART0 Interrupt

UART0 receive interrupt is used to receive responses from the Linux PC.

### External Interrupt

An external interrupt is used for administrator-related operations.

---

## 📊 Attendance Data

The CSV file maintains information such as:

```text
S.NO
EMPLOYEE NAME
EMPLOYEE ID
WORKING HOURS
IN TIME
OUT TIME
IN TIME
OUT TIME
IN TIME
OUT TIME
```

This allows multiple IN/OUT sessions to be recorded for an employee.

---

## 📁 Project Structure

```text
Major_project/
│
├── admin.c
├── admin.h
├── interrupt.c
├── interrupt.h
├── kpm.c
├── kpm.h
├── lcd.c
├── lcd.h
├── rtc.c
├── rtc.h
├── rtc_edit.c
├── uart.c
├── uart1.c
├── uart1.h
├── uart1_function.h
├── SPI_Protocol.c
├── SPI_defines.h
├── SPI_functions.h
├── pin_connect_block.c
├── pin_connect_block.h
├── delay.c
├── delay.h
├── types.h
└── ...
```

Linux application:

```text
linux_t/
│
├── main.c
├── employee_details.csv
└── ...
```

---

## 🔄 Working Flow

```text
1. Employee scans RFID card
             ↓
2. RFID reader reads unique ID
             ↓
3. RFID ID is transmitted through UART1
             ↓
4. LPC2148 receives the ID using UART1 ISR
             ↓
5. LPC2148 identifies the operation
             ↓
6. Request is sent to Linux PC through UART0
             ↓
7. Linux application checks employee database
             ↓
8. Attendance information is updated
             ↓
9. Response is sent back to LPC2148
             ↓
10. LCD displays the result
```

---

## 🖥️ Project Output
![image alter](https://github.com/jyothichikati01-pixel/RFID/blob/a55e0362d0189dbef4fe19b243a173e855460a30/output1.jpeg)

![image alter](https://github.com/jyothichikati01-pixel/RFID/blob/3a474d38e500b751b04a3cbe52ace779d55c682b/output2.jpeg)

---

## 🛠️ Key Features

* RFID-based employee identification
* Automated attendance management
* UART serial communication
* Interrupt-based RFID reception
* RTC-based time and date tracking
* SPI EEPROM interface
* LCD display
* Keypad interface
* Linux-based database application
* CSV-based employee records
* Working-hours calculation
* Administrator authentication
* Employee add/edit/delete operations

---

## 📌 Future Enhancements

Possible future improvements include:

* Web-based attendance dashboard
* Cloud database integration
* Wi-Fi/Bluetooth connectivity
* Automatic attendance reports
* Mobile application
* Secure authentication
* Real-time monitoring
* Database migration from CSV to SQL

---

## ⭐ Project Summary

**RFID Smart Employee Tracking and Attendance System** is an embedded system designed to automate employee attendance and reduce manual errors. The system uses an **RFID reader** to identify employees through their unique RFID IDs. An **LPC2148 ARM7 microcontroller** receives the RFID data through **UART1**, obtains the current date and time from an **RTC**, and communicates with a **Linux-based PC application through UART0**. Employee attendance details, including **IN/OUT time and working hours**, are maintained in a CSV file. The system also uses **LCD, keypad, SPI EEPROM, interrupts, and MAX232/serial communication** for user interaction, data storage, and reliable communication.


