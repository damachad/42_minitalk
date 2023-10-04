# MiniTalk - UNIX Signal Data Exchange 📡

MiniTalk is a small data exchange program between a client and a server, designed to operate using only two UNIX signals: SIGUSR1 and SIGUSR2. This project was completed as part of the 42 curriculum.

## Purpose 🎯
The primary purpose of this project is to create a simple communication system using UNIX signals. It demonstrates the use of signals for interprocess communication between a server and multiple clients.

## Allowed Functions ✅
In this project, you are allowed to use the following functions in addition to those previously coded in the Libft project:

- `write`
- `signal`
- `sigemptyset`
- `sigaddset`
- `sigaction`
- `kill`
- `getpid`
- `malloc`
- `free`
- `pause`
- `sleep`
- `usleep`
- `exit`

## Getting Started 🚀
1. Start the server, which will print its Process ID (PID) after launch.
2. The client takes two arguments:
   - The server's PID.
   - A string to send to the server.
3. Once the server receives the string, it will print it (pretty quickly).
4. The server is designed to handle multiple client connections in succession without needing to restart.

## Bonus Features 🔁
In the bonus part of this project, the server acknowledges every message received by sending back a signal to the client. Additionally, MiniTalk supports Unicode characters for enhanced functionality.
