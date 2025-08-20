### Fract'ol - Computer Graphics Fractals

## Description
Fract'ol is a project focused on creating a small fractal exploration program in C using the MiniLibX library. This program allows you to explore and visualize famous fractals such as the Julia set and the Mandelbrot set. Fractals are fascinating mathematical objects that exhibit self-similar patterns at every scale.

#Installation

Copy code
```git clone <repository_url>```

Compile the project using the provided Makefile:
```make```

Run the program with the desired fractal type and options:
```./fractol [fractal_type] [options]```

If no parameters are provided or if the parameter is invalid, the program will display a list of available parameters and exit.

## Usage
Use the mouse wheel to zoom in and out of the fractals, allowing for infinite exploration.
Different Julia sets can be created by passing different parameters to the program.
Explore rendering options by adding parameters to the command line.
Press ESC key to close the window and quit the program cleanly.
Click on the cross on the window's frame to close the window and quit the program cleanly.
Supported Fractals
***Julia Set***: A set of complex numbers related to the Mandelbrot set.
***Mandelbrot Set***: One of the most famous fractals, created using complex numbers.
***Burningship Set***: A fractal similar to the Mandelbrot set but with different shape characteristics.

## Features
Smooth window management for a seamless user experience.
Use of colors to display the depth of each fractal.
Psychedelic effects can be achieved for added visual appeal.
