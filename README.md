# Brother's Gym

This repository contains a minimal Qt application written in C++ that can be
used as a starting point to manage a gym with different classes.

## Getting Started

1. Install **Qt** and **Qt Creator** (or qmake) on your system.
2. Open `gym_manager/gym_manager.pro` in Qt Creator.
3. Use Qt Designer to modify `mainwindow.ui` and add widgets for your gym
   management features (class lists, scheduling, registration, etc.).
4. Build and run the project.

The application now includes a simple home window with buttons for different
types of courses (Taekwondo, Cours Femme, Musculation), a button to add a new
course and another to quit. Each course window provides a table where you can
add or remove members and return to the home screen. The table columns are
editable so you can enter the member's **Nom**, **Prénom**, **Date de
naissance**, whether the payment **Statut** is complete, and the **Validité**
date. A simple `Member` class stores these details for each row so you can
extend the application logic beyond the table widget.
