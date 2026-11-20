# Robots Simulation (C++ OOP Project)

A C++ Object-Oriented Programming (OOP) simulation modeling interactions and combat mechanics between different types of robots (`DefensiveRobot` and `NormalRobot`).

---

## Overview

The application simulates a system of robots managed polymorphically through base class pointers. It demonstrates core C++ OOP principles including:
- **Inheritance** (`Robot` base class with `DefensiveRobot` and `NormalRobot` derived classes)
- **Polymorphism & Abstract Classes** (Pure virtual `Attack()` and `Print()` functions)
- **Runtime Type Identification (RTTI)** (`dynamic_cast` for type-safe interactions and attribute modification)
- **Dynamic Memory Management** (Heap allocation with `new` and proper cleanup using `virtual` destructors)

---

## Class Architecture & Design Decisions

### 1. `Robot` (Abstract Base Class)
Represents the common attributes and shared behavior of all robots.
- **Members:** `name` (`std::string`), `batteryLevel` (`float`)
- **Functions:**
  - `Robot(string name, float batteryLevel)`: Non-default constructor.
  - `RechargeBattery()` *(Non-virtual, Base only)*: Restores `batteryLevel` to `100`.
  - `DecreaseBatteryLevel(float amount)` *(Non-virtual, Base only)*: Reduces `batteryLevel` by `amount`; automatically triggers `RechargeBattery()` if battery drops to `<= 0`.
  - `Compare(Robot* other)` *(Non-virtual, Base only)*: Compares battery levels (`1` if current > other, `-1` if current < other, `0` if equal).
  - `Attack(Robot* other)` *(Pure virtual)*: Enforces custom combat logic in each derived class.
  - `Print()` *(Pure virtual)*: Enforces custom status output in each derived class.
  - `virtual ~Robot()`: Ensures proper destructor chaining when deleting derived objects via base pointers.

### 2. `DefensiveRobot` (Derived Class)
Inherits publicly from `Robot` and adds offensive capability.
- **Additional Member:** `firePower` (`float`)
- **Functions:**
  - `DefensiveRobot(string name, float batteryLevel, float fp = 0)`: Constructor with default argument.
  - `SetFirePower(float p)` & `GetFirePower()` *(Non-virtual, Derived only)*: Accessors for `firePower`.
  - `Attack(Robot* other)` *(Overridden)*:
    - Prevents self-attack (`other == this`).
    - **vs. `DefensiveRobot`**: Uses `Compare()` so the stronger robot reduces the weaker robot's battery by the stronger robot's `firePower`.
    - **vs. `NormalRobot`**: Decreases the `NormalRobot`'s battery by this robot's `firePower`.

### 3. `NormalRobot` (Derived Class)
Inherits publicly from `Robot` with passive defense behavior.
- **Functions:**
  - `NormalRobot(string name, float batteryLevel)`: Constructor.
  - `Attack(Robot* other)` *(Overridden)*:
    - **vs. `NormalRobot`**: Does nothing.
    - **vs. `DefensiveRobot`**: Decreases its own battery by the `DefensiveRobot`'s `firePower`.

---

##  Project Structure

```text
├── Robot.h / Robot.cpp                   # Abstract base class definition & implementation
├── DefensiveRobot.h / DefensiveRobot.cpp # DefensiveRobot class definition & implementation
├── NormalRobot.h / NormalRobot.cpp       # NormalRobot class definition & implementation
├── main.cpp                              # Simulation driver & memory cleanup
└── README.md                             # Project documentation
```

---

##  How to Build and Run

### Using Visual Studio (Windows)
1. Open the solution/project in **Visual Studio Community**.
2. Press **`Ctrl + Shift + B`** to build the solution.
3. Press **`Ctrl + F5`** (or **Debug > Start Without Debugging**) to run the simulation.

### Using g++ (Command Line)
```bash
g++ -std=c++17 main.cpp Robot.cpp DefensiveRobot.cpp NormalRobot.cpp -o robots_sim
./robots_sim
```

---

##  Sample Output

```text
Type : Defensive Robot
Name : Defensive1
BatteryLevel : 90
FirePower : 5

Type : Defensive Robot
Name : Defensive2
BatteryLevel : 80
FirePower : 10

Type : Normal Robot
Name : Normal1
BatteryLevel : 70
...
// After Defensive1 attacks Defensive2 (90 > 80 -> Defensive2 loses 5 battery)
BatteryLevel : 75
...
// After Defensive1 attacks Normal1 (Normal1 loses 5 battery)
BatteryLevel : 65
```
