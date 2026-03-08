# STM32F401 Keypad Calculator with 16x2 LCD

## 📌 Project Overview

This project implements a **basic calculator using the STM32F401 microcontroller**, a **4x4 matrix keypad**, and a **16x2 LCD display**.
The keypad is used to input numbers and mathematical operations, while the LCD displays the entered values and the computed result.

The calculator supports basic arithmetic operations:

* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`)

The project is written completely in **Embedded C using register-level programming**, without using HAL libraries.

---

## 🧠 Features

* 4×4 Matrix Keypad input
* 16×2 LCD interface (8-bit mode)
* Supports integer arithmetic operations
* Handles **division by zero error**
* Custom GPIO driver implementation
* Modular driver structure
* Clean LCD display for inputs and results

---

## 🧰 Hardware Requirements

* STM32F401RE / STM32F401 MCU
* 16x2 LCD Display (HD44780 compatible)
* 4x4 Matrix Keypad
* Breadboard / PCB
* Connecting Wires
* 10k Potentiometer (for LCD contrast)

---

## 🔌 Pin Configuration

### LCD Connection (8-bit Mode)

| LCD Pin | STM32 Pin |
| ------- | --------- |
| D0      | PA0       |
| D1      | PA1       |
| D2      | PA2       |
| D3      | PA3       |
| D4      | PA4       |
| D5      | PA5       |
| D6      | PA6       |
| D7      | PA7       |
| RS      | PB1       |
| RW      | PB2       |
| EN      | PB0       |

### Keypad Connection

| Keypad Pin | STM32 Pin |
| ---------- | --------- |
| Row1       | PB12      |
| Row2       | PB13      |
| Row3       | PB14      |
| Row4       | PB15      |
| Col1       | PC0       |
| Col2       | PC1       |
| Col3       | PC2       |
| Col4       | PC3       |

---

## 🏗️ Project Structure

```
STM32-Keypad-Calculator
│
├── Core
│   ├── main.c
│
├── Drivers
│   ├── STM32F401_GPIO.c
│   ├── STM32F401_GPIO.h
│   ├── STM32F401_LCD.c
│   ├── STM32F401_LCD.h
│   ├── STM32F401_KEYPAD.c
│   ├── STM32F401_KEYPAD.h
│
└── README.md
```

---

## ⚙️ How It Works

### 1️⃣ Keypad Scanning

The keypad is scanned using a **row-column matrix technique**.

Steps:

1. All rows are set HIGH.
2. One row is pulled LOW at a time.
3. Columns are read to detect a key press.
4. The pressed key is mapped to a character using the keypad lookup table.

Example keypad mapping:

```
7  8  9  /
4  5  6  *
1  2  3  -
c  0  =  +
```

---

### 2️⃣ LCD Interface

The LCD operates in **8-bit mode**, meaning all data pins are used.

LCD control signals:

* **RS** → Register select (command/data)
* **RW** → Read/Write control
* **EN** → Enable signal

Data is written by:

1. Setting RS and RW appropriately
2. Writing data to pins D0–D7
3. Triggering the **Enable pulse**

---

### 3️⃣ Calculator Logic

The calculator stores two operands:

```
num1  → first number
num2  → second number
op    → operator
```

Example flow:

```
Input:  25 + 10 =
Process:
num1 = 25
op   = '+'
num2 = 10

Result = num1 + num2
Output = 35
```

After computation, the result becomes the next `num1` so chained operations are possible.

Example:

```
10 + 5 + 2 =
Result → 17
```

---

## 🚨 Error Handling

### Division by Zero

If the user attempts:

```
10 / 0
```

The LCD displays:

```
Math Error
```

The calculator then resets its internal values.

---

## ▶️ How to Run the Project

1. Clone the repository

```bash
git clone https://github.com/yourusername/stm32-keypad-calculator.git
```

2. Open the project in **STM32CubeIDE** or your preferred ARM toolchain.

3. Compile the project.

4. Flash the firmware to the STM32 board.

5. Connect the keypad and LCD according to the pin configuration.

6. Start performing calculations using the keypad.

---

## 📷 Example Output

```
Input:
12+8=

LCD Display:
20
```

---

## 📚 Concepts Used

* Embedded C
* Register-level GPIO programming
* Matrix keypad scanning
* LCD interfacing
* Basic calculator logic
* Modular driver development

---

## 🔮 Possible Improvements

* Floating point calculations
* Backspace key
* Scientific functions
* Interrupt-based keypad scanning
* Power optimization
* 4-bit LCD interface

---

## 👨‍💻 Author

**Srinath Gatla**

Embedded Systems Enthusiast
Focused on **STM32 Driver Development and Low-Level Programming**


