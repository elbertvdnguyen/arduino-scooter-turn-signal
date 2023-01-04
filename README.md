# Arduino scooter turn signal
Whether you're riding a Razor or electric scooter, it is difficult to communicate turn signals to others on the road. And even when you do, people simply do not acknowledge you!

I have created a simple turn signal that allows you to communicate with those around you about your intention to make a turn.

## Purpose
The purpose of this project was to develop a tool for electric scooter riders, such as myself, to stay safe on the roads and communicate with others. Unlike a cyclist, electric scooter riders are not given the same amount of respect on the roads: hand signals are ignored, no one wants to give you the right of way, etc. This can cause unsafe riding conditions that may lead to accidents. I have personally had several incidents where a pedestrian or vehicle has not given me right of way, despite me communicating with hand signals.

## Required Parts
To bring this project to fruition, I used the following hardware parts:
- 1x Arduino MEGA 2560
- 1x MAX7219 8x8 LED Dot Matrix
- 1x KY-023 joystick

On the software side, I implemented the LedControl library to output the appropriate values to the LED matrix.

## Functionality
To initiate the turn signal indicator, the joystick must either be pushed up (right turn) or down (left turn). Once indicated, the front-mounted LED matrix flashes an arrow reflecting the turn the rider wishes to make. This occurs for approximately 6-8 seconds before the matrix shuts off again.

## Demo video
Here is the [link](https://youtu.be/qDhFgfHtOVE) to a video demonstrating the functionality of the turn signal.

## Notes
This project was created for a class assignment.

Course Information: 
- CS122A - Intermediate Embedded and Real-Time Systems
- Professor Frank Vahid
- University of California, Riverside
- Spring 2022

*Made with :heart: in Riverside, CA.*
