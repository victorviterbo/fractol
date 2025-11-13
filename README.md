# Fractol - Fractal Explorer

A beautiful and interactive fractal explorer written in C using the MinilibX graphics library. This project demonstrates complex mathematical concepts and efficient graphical rendering.

## 🎨 Features
- Renders multiple fractal sets (Mandelbrot, Julia, Burning Ship)
- Smooth (de)zooming with mouse and panning with keyboard controls
- Real-time parameter adjustments
- Interactive Julia set with mouse movement

## 🕹️ Controls
- **Mouse Wheel**: Zoom in/out
- **Arrow Keys**: Pan around the fractal
- **c**: Change the coloring scheme
- **i**: print informations about currently displayed fractal in the terminal for reproductibility
- **ESC**: Exit program
- **Left Click**: For julia : set C0 to the values of the coordinates clikced

## 🚀 Usage

make
./fractol FT [nsteps winx winy re_min im_min re_max im_max [re_c0 im_c0] [color]]
Where
- FT is the fractal to display (available MANDELBROT, JULIA, BURNING_SHIP), parameter is not case-sensitive
- nsteps is the number of iterations to be performed per pixel
- winx, winy : horizontal and vertical size of window (respectively, in pixels)
- re_min, im_min : real and imaginary part of the bottom left corner
- re_max, im_max : real and imaginary part of the top right corner
- c0x, c0y : With Julia fractal only, the real and imaginary part of the starting point
- color: coloring scheme option passed as an int [0:6]

Defaults are 20 800 800 -1.0 -1.0 1.0 1.0 [-0.4, 0.6] [0]

If you do not feel like doing math, you can replace \<im_max\> with **auto** to ensure that proprtions are kept
          
### Available fractals: mandelbrot, julia, burningship

for Julia, you can specify the seed used by adding it's real followed by its imaginary part at the end of the arguments
