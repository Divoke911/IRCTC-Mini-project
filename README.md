# IRCTC-Mini-project
This is a C language-based program that simulates a simple ticket booking system for Indian Railways Catering and Tourism Corporation (IRCTC). The program allows users to sign up, log in, and book train tickets with randomly generated PNR numbers and train names.

## Features
- **User Authentication**: Users can sign up with a unique username and password and log in to the system securely.
- **Ticket Booking**: Users can book tickets by entering their personal information such as name, age, gender, source, and destination.
- **PNR and Train Name Generation**: The system automatically generates a unique PNR number and assigns a random train name for each booking.
- **Ticket Display**: After booking, the ticket details are displayed in a formatted manner, including the train name, PNR number, source, destination, and passenger details.

##Program Structure
-struct info: A structure that holds user and booking details, including name, age, gender, source, destination, PNR number, train name, username, and password.
-login(): A function that allows users to log in to the system using their username and password.
-signup(): A function that allows new users to create an account by providing a unique username and password.
-booking(): A function that collects passenger details and generates a PNR number and train name.
-display(): A function that displays the booked ticket details in a formatted output.
-generate_pnr(): A function that generates a random 10-digit PNR number.
-generate_train_name(): A function that assigns a random train name from a predefined list.

##Future Enhancements
-Integration with payment gateways for online transactions.
-Real-time train status updates using API integration.
-Enhanced user profile management with booking history and cancellation options.
-Development of a mobile application version.
-AI-powered travel recommendations based on user preferences.
