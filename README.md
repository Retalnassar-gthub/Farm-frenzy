# Farm Frenzy

**CIE101: Fundamentals of Computer Programming**  
*University of Science and Technology in Zewail City*  
**Course Project - Summer 2026**

---

## 📖 Introduction
**Farm Frenzy** is a 2D resource-management and strategy game developed in C++ using Object-Oriented Programming (OOP) principles. Players are tasked with running a successful farm by managing resources, protecting livestock, and meeting specific level goals before the time runs out.

## 🚀 Gameplay Features
*   **Farm Management & Economy:** Start with a budget to purchase animals (e.g., cows, chickens). Animals produce core products (like milk) over time which can be stored in the warehouse and sold to grow the farm's budget.
*   **Resource Management (Food & Water):** Animals need grass to survive and produce. Players must purchase water from a well and click the ground to plant grass for the animals to graze on.
*   **Disease & Antidote Mechanics:** Animals can get sick after continuous production (e.g., cows get sick after producing 10 bottles of milk). Players must quickly purchase and deploy an Antidote from the shop to cure them before they die.
*   **Predators:** Wolves will randomly attack the farm and attempt to eat the livestock. Players must defend their farm by rapidly clicking on the wolves to destroy them.
*   **Progression & Goals:** Each level features a strict timer and a primary goal (e.g., reaching a specific budget or owning a certain number of animals). 

## 🛠️ Tech Stack
*   **Language:** C++ (C++11 or later)
*   **Graphics:** [CMUgraphicsLib](https://github.com/CMUgraphicsLib) (Integrated within the source code for simple, primitive-based 2D rendering).

## ⚙️ Build & Run Instructions
1.  **Clone or Download** the repository to your local machine.
2.  **Open the Solution:** Open `graphics_prj.sln` using **Microsoft Visual Studio**.
3.  **Compile:** Build the solution (Ctrl + Shift + B). The `CMUgraphicsLib` dependencies are bundled and will compile automatically.
4.  **Run:** Execute the compiled program to launch the game window.

## 🏛️ Architecture & Standards (Development)
This project adheres to strict OOP and memory management standards:
*   Entities are drawn using **geometric primitives** (No external JPEGs to avoid alpha-channel artifacts).
*   **Deferred Deletion:** Game entities are never deleted mid-loop to prevent dangling pointers. They are garbage-collected at the end of the tick.
*   **Encapsulation:** Object states are modified solely through domain-driven methods (e.g., `animal->feed()`, `wolf->takeDamage()`).

## 👨‍🏫 Instructors & TAs
*   **Dr. Elmahdy Maree**
*   Eng. Mahmoud Farhat
*   Eng. Aya Eman
*   Eng. Heba Omar
*   Eng. Yasmine Eldesoukie
