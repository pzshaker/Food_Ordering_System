# Food Ordering System

## Project Overview

This Food Ordering System is a comprehensive C++ application built using the Qt framework, designed to simulate the food ordering process. It showcases the ability to create an interactive, user-friendly application that handles user authentication, food selection, and order processing.

## Key Features

1. **User Authentication**:
   - Secure sign-in functionality to authenticate users based on pre-defined credentials.
   - User data management, including username, password, and account balance.

2. **Food Selection**:
   - A dynamic menu interface allowing users to choose from various chicken and meat options.
   - Real-time price updates and total cost calculation based on selected items.

3. **Order Management**:
   - Real-time feedback on the user’s account balance and total order cost.
   - Options for users to recharge their account balance within the application.

## Technical Details

### Technologies Used

- **C++**: Core programming language for the application.
- **Qt Framework**: Used for building the graphical user interface and managing user interactions.

### Application Flow

1. **Sign-In Process**:
   - Users are greeted with a sign-in window where they enter their credentials.
   - Upon successful authentication, the application retrieves the user's data and proceeds to the food selection interface.

2. **Food Selection Interface**:
   - Users can browse through available food items (chicken and meat) presented in dropdown menus.
   - The interface dynamically updates the item price and the user’s account balance as selections are made.
   - Users can add items to their order and proceed to the next step.

3. **Order Review and Payment**:
   - The application provides a summary of the selected items and the total cost.
   - Users can finalize their order and complete the payment process using their account balance.
   - Option to recharge account balance if insufficient funds are available.
