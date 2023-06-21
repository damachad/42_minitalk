# Minitalk
The purpose of this project is to code a small data exchange program between a *client* and a *server* using only two UNIX signals (SIGUSR1 and SIGUSR2).
Allowed functions:   
```
◦ write
◦ ft_printf and any equivalent YOU coded
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit
```
First, the *server* must be started and, after its launch, it has to print its PID. The *client* then takes two arguments: the *server*'s PID and a string to send to the *server*. Once the string has been received, the *server* must print it. Furthermore, the *server* has to display the string pretty quickly and should be able to receive strings from several clients in a row without needing to restart.   
In the bonus part of this project the *server* acknowledges every message received by sending back a signal to the *client*.
