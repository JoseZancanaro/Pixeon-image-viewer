# Pixeon-image-viewer

[Portuguese](./README-en.md)

## About this repository
This project consisted of solving the challenge for Pixeon's C++ Developer Analyst position. It was required to develop, in the C++ programming language and in the QT environment, an image viewer application. With image selection, visualization and transformations, such as: zoom, displacement, rotation and brightness.

**/Image-viewer/** contains the .cpp, .hpp, .ui and cmake files for this project,
**/Images/** contains three image files .bmp, .jpeg and .png, for testing this project.

Also, the repository contains two branches, **dev** which presents the entire code implementation history, and **main** which contains the latest current version of this project.

## Application Controls
| key | action                         |
|-------|------------------------------|
| +     | zoom in    	               |
| -     | zoom out                     |
| W     | move up                      |
| D     | move right                   |
| S     | move down                    |
| A     | move left                    |
| R     | rotation right               |
| E     | rotation left                |
| →     | more brightness              |
| ←     | less brightness              |

## Methodology
A Qt Widgets Application project was started using the Qt Creator IDE, in the C++ 17 programming language. Using Qt Design (which is included in the development environment), the application's user interface was created, containing a button for selecting one or more images, a list of names of the selected images and a label for displaying the indicated image.

Next, it was followed with the implementation for image selection, using the QFileDialog class and the getOpenFileNames method, restricting it to only accepting .bmp, .jpeg and .png files, as established as a requirement. The ListWiget class and its items were used to control the image selection, and it was display in the application with the QLabel and QPixmap classes.

Then, keyboard shortcuts were implemented to apply transformations on the displayed image. With the QShortcut class, shortcuts were connected with slots that called their functions when the key was activated. The image transformations (zoom, displacement, rotation and brightness) were implemented separately in a file (graphicsmanager.hpp), which was responsible for the different treatments of the image that came from QLabel.

## Difficulties
The main difficulties I encountered were related to good development practices for the C++ programming language and for the Qt environment. For a while I was mainly in web development and data analysis. It made it necessary for me, to remind of several good behaviors for programming in C++, yet I may have slipped up at some point, and done something not really recommended.

## Future improvements
For this image viewer project, and mainly for image transformation applications, I highlight some possible future implementations:
* **editor**: greater control over images. Allowing it to be saved/loaded into the application.
* **rotation**: smaller angle value, with smoother and more accurate rotation in the image.
* **zoom**: established limits for zooming. Zoom out intensively consumes a lot of application memory.
* **moving (pan)**: The application is currently not maintaining the new position of the image. Application performs the displacement, but does not save the position in case another transformation is called.
* **brightness**: set limits for brightness intensity. So if you get the level too high/low, won't lose the original image content.

## Result
The project image viewer with C++ and with Qt environment was a curious and challenging experience.
During development, some questions about best practices arose, but with research and discussions in the community, I believe I have arrived at an interesting solution. I believe I have met all the requirements established for this challenge, although many future improvements can be made to improve the application and make it more robust and more enjoyable.

## Development environment
* Qt Creator
* C++ 17
* Arch Linux
