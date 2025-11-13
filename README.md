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
- **ESC**: Exit program

## 🚀 Usage

make
./fractol \<fractal_name\> \
          \<number of steps\> \
          \<window width\> <window height> \
          \<min real display> <min imaginary display> \
          \<max real display> <max imaginary display> \
          [\<c0x\> \<c0y\>] \
          <coloring_scheme>
          
# Available fractals: mandelbrot, julia, burningship

for Julia, you can specify the seed used by adding it's real followed by its imaginary part at the end of the arguments
